/**************************************************************
 * TPI PE 2025 - Sistema de Gestion de Gastos Personales
 * 
 * Godoy, Tomas. 68081
 * Martinez, Mariana Priscila. 67869
 * Moreno, Francisco. 67617
 * Scheuermann, Renata. 67613
 * 
 **************************************************************/
#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

// ESTRUCTURAS 

typedef struct {
	int dia; 
	int mes; 
	int anio; 
}Fecha;

typedef struct {
    int cod;
	long dni;
    char nombre[50];
  	short status;
} Persona;

typedef struct {
    int codigo;                 
    char tipo[20];              
    char descripcion[50];
    char categoria[30];
    float monto;
    Fecha fecha;
    int cuotasTotales;   
    int cuotasPagadas;
	int cuotaActual;   
    Persona persona;
	char estado[30]; 
	short status;
} Gasto;

typedef struct {
    int codigo;
	char concepto[50];
    float monto;
    Fecha fecha;
    Persona persona;
    short status;
} Ingreso;

typedef struct {
    int gastoCodigo;     
    char medio[20];      
    float importe;
    Fecha fecha;
    short status;
} Pago;

typedef struct {
	int codigo;
	char nombre[30];
    
} Categoria;


#endif
