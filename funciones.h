/**************************************************************
 * TPI PE 2025 - Sistema de Gestion de Gastos Personales
 * 
 * Godoy, Tomas. 68081
 * Martinez, Mariana Priscila. 67869
 * Moreno, Francisco. 67617
 * Scheuermann, Renata. 67613
 * 
 **************************************************************/

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h> 
#include <stddef.h> 
#include <math.h>   
#include <windows.h>
#include "estructuras.h"  




// LIMITACIONES 

enum {
    MAX_GASTOS = 1000,
    MAX_INGRESOS = 800,
    MAX_PAGOS = 1000,
    MAX_CATEGORIAS = 200,
    MAX_PERSONAS = 200
};
// NOMBRES DE ARCHIVO

extern const char *ARCH_GASTOS;
extern const char *ARCH_INGRESOS;
extern const char *ARCH_PAGOS;
extern const char *ARCH_CATEGORIAS;
extern const char *ARCH_PERSONAS;

//PRESENTACION 
extern int g_uiAnim;

/* ----------------------------- PROTOTIPOS DE FUNCIONES ------------------------------- */

// OBLIGATORIAS

int cargarGasto(Gasto gastos[], int max);
int guardarGasto(Gasto *g);
int cargarIngreso(Ingreso ingresos[], int max);
int guardarIngreso(Ingreso *ing);
int registrarPago(Pago *p);

//	MENUS

void menuPrincipal(Categoria categorias[], int *nc, Persona personas[], int *np);
void menuGestion(Categoria categorias[], int *nc, Persona personas[], int np);
void menuConsultas(Categoria categorias[], int nc);
void menuReportes(Categoria categorias[], int nc);
void menuAdministrar(Categoria categorias[], int *nc, Persona personas[],  int *np);

// INTERFAZ

void registrarGastoUI(Categoria categorias[], int *nc);
void registrarIngresoUI(Persona personas[], int np);
void registrarPagoUI();
int leerTodosGastosStatic(Gasto gastos[], int max);
int leerTodosIngresosStatic(Ingreso ingresos[], int max);
int leerTodosPagosStatic(Pago pagos[], int max);
void mostrarGastosStatic(Gasto gastos[], int ng, Categoria categorias[], int nc);
void mostrarIngresosStatic(Ingreso ingresos[], int ni);
void mostrarPagosStatic(Pago pagos[], int np);


//	ADMINISTRAR

void eliminarGastoUI();
void eliminarIngresoUI();
void eliminarPersonaUI(Persona personas[], int *np);
int personaPagoPendiente(long dni);


//	PERSONA

void registrarPersonaUI(Persona personas[], int *np);
int seleccionarPersonaUI(Persona *out);
int guardarPersona(Persona *p);
int leerTodasPersonasStatic(Persona personas[], int max);
void listarPersonasUI();
int personaGastoActivo(long);
int personaActiva(long dni, int *status);

//	CONSULTAS

void consultarGastosPorCategoriaStatic(Categoria categorias[], int nc);
void consultarGastosPorMesAnioStatic(Categoria categorias[], int nc);
void consultarIngresosPorPersonaStatic();
void consultarSaldoMensualStatic();
void consultarGastosPendientesStatic(Categoria categorias[], int nc);
void consultarPagosPorMedioStatic();
void consultarGastosConSaldoIncompletoStatic(Categoria categorias[], int nc);
void top3CategoriasCostosasStatic(Categoria categorias[], int nc);
void proyeccionMensualStatic(Categoria categorias[], int nc);
void resumenGeneralStatic(Categoria categorias[], int nc);
void consultaGastosPorTipo(Categoria categorias[], int nc);

// CATEGORIAS (estaticas)

int cargarCategoriasStatic(Categoria categorias[], int max);
int guardarCategoriaStatic(Categoria categorias[], int *nc, Categoria c);
int existeCategoriaStatic(Categoria categorias[], int nc, char *nombre);
void mostrarCategoriasStatic(Categoria categorias[], int nc);
void agregarCategoriaUI(Categoria categorias[], int *nc);
void eliminarCategoriaUI(Categoria categorias[], int *nc); 
int esCategoriaActiva(Categoria categorias[], int nc, char *nombreCategoriaGasto);
int crearCategoriasPorDefecto(Categoria categorias[], int max); 


//	FECHAS

int validarFechaStruct(Fecha f);
int parsearFecha(char *s, Fecha *f);
int compararFechas(Fecha f1, Fecha f2);
void imprimirFecha(Fecha f);
Fecha leerFecha(const char *);
int validarPagoFecha(const Gasto *g, const Pago *p, const Fecha *hoy);

// VALIDACIONES

void validarTXT(char *, char *, size_t );
long validarLONG(const char *);
int validarINT(const char *);
float validarFLOAT(const char *);

//	UTILIDADES

int pagoActivo(int );
int leerLinea(char *, size_t);
void normalizarTexto(char *);
float sumarTotalMesAnio(int , void *, int , int , int );
int generarCOD(const char * ,size_t ,size_t );
void ordenarGastosPorFechaStatic(Gasto *vec, int n);
void ordenarIngresosPorFechaStatic(Ingreso *vec, int n);
int generarReporteMensual(int mes, int anio, Categoria categorias[], int nc);
Gasto encontrarGastoPorCodigo(int codigo);
float calcularTotalPagadoCuota(int gastoCodigo, Pago pagos[], int np_pagos);
float calcularSaldoPendienteCuota(Gasto g, Pago pagos[], int np_pagos);
int nombreMesES(int mes, char *out, size_t outsz);
int archivoExiste(const char *path);
int generarNombreResumenMensual(Fecha fecha, char *out, size_t outsz);
int softDeletePlanDeCuotas(const Gasto *ref);
int existePagoActivoParaGastoCodigo(int gastoCodigo);
static int mismaClavePlan(const Gasto *g, const Gasto *ref);
int seleccionarGastoUI(Gasto *out, int modo);


// EXTRAS GRUPO DE 4

void consultaComparacionMes(Categoria categorias[], int nc);
void consultaGastosPorPersona();
void consultaProyeccionAnual();
void consultaEstadoGastoTemporal();


// VISUALES	
void pantallaCarga();
void animTransicionMenu();
void pantallaSalida();
void limpiar();
void gotoxy(int x, int y);
void setColor(int fg, int bg);
void dibujarMarco(int x1, int y1, int x2, int y2, int colorBorde, int colorFondo);
void uiSetAnimaciones(int on);
void uiTransicionEntrada(const char *titulo);

/* ----------------------------- FUNCIONES DEL PROGRAMA ------------------------------- */


//									--- PRINCIPAL ---

	void menuPrincipal(Categoria categorias[], int *nc, Persona personas[], int *np){
		int op = -1;
	    while (op != 0){
	        printf("\n--- MENU PRINCIPAL ---\n");
	        printf("1. Gestion de Datos (Gastos, Ingresos, Pagos)\n");
	        printf("2. Consultas\n");
	        printf("3. Reportes\n");
	        printf("4. Administrar\n");
	        printf("0. Salir\n");
			
			op = validarINT("Opcion: ");
			
			switch (op){
			    case 1:
			        uiTransicionEntrada("Gestion de Datos");
			        menuGestion(categorias, nc, personas, *np);

			        break;
			    case 2:
			        uiTransicionEntrada("Consultas");
			        menuConsultas(categorias, *nc);

			        break;
			    case 3:
			        uiTransicionEntrada("Reportes");
			        menuReportes(categorias, *nc);

			        break;
			    case 4:
			        uiTransicionEntrada("Administrar");
			        menuAdministrar(categorias, nc, personas, np);

			        break;
	            case 0:
	            	pantallaSalida();
	                break;
	            default:
	                printf("Opcion no valida. Intente de nuevo.\n");
	                break;
	        }
	    }
			
	}
	
//									---	GESTION ---

	void menuGestion(Categoria categorias[], int *nc, Persona personas[], int np){
		int op = -1;
        Gasto gastos[MAX_GASTOS];
        Ingreso ingresos[MAX_INGRESOS];
        Pago pagos[MAX_PAGOS];
	    while (op != 0){
	        printf("\n--- GESTION DE DATOS ---\n");
	        printf("1. Registrar Gasto\n");
	        printf("2. Registrar Ingreso\n");
	        printf("3. Registrar Pago\n");
	        printf("4. Listar Gastos\n");
	        printf("5. Listar Ingresos\n");
	        printf("6. Listar Pagos\n");
	        printf("7. Listar Categorias\n");    
	        printf("0. Volver\n");

	        op = validarINT("Opcion: ");
	         switch (op){
	            
				case 1:
	                registrarGastoUI(categorias, nc);
	                system("pause");
	                system ("cls");
	                break;
	                
	            case 2:
	                registrarIngresoUI(personas, np);
	                system("pause");
	                system ("cls");
	                break;
	                
	            case 3:
	                registrarPagoUI();
	                system("pause");
	                system ("cls");
	                break;
	                
	            case 4: {
	                mostrarGastosStatic(gastos, leerTodosGastosStatic(gastos, MAX_GASTOS), categorias, *nc);
	                system("pause");
	                system ("cls");
	                break;
	            }
	            
	            case 5: {
	                mostrarIngresosStatic(ingresos, leerTodosIngresosStatic(ingresos, MAX_INGRESOS));
	                system("pause");
	                system ("cls");
	                break;
	            }
	            
	            case 6: {
	                mostrarPagosStatic(pagos, leerTodosPagosStatic(pagos, MAX_PAGOS));
	                system("pause");
	                system ("cls");
	                break;
	            }
	            
	            case 7:
	                mostrarCategoriasStatic(categorias, *nc);
	                system("pause");
	                system ("cls");
	                break;
	                
	            case 0:
	            	uiTransicionEntrada("Volviendo a Menu anterior...");
	                break;
	                
	            default:
	                printf("Opcion no valida. Intente de nuevo.\n");
	                break;
	        }    
		}
	}
	
//									--- CONSULTAS ---	
	
void menuConsultas(Categoria categorias[], int nc){
    int op = -1;
    int op2; // indice de submenu nuevo
    while (op != 0) {
    	system ("cls");
        printf("\n--- CONSULTAS ---\n");
        printf("1. Filtrar gastos\n"); 		
        printf("2. Ingresos por Persona\n");
        printf("3. Saldo Mensual\n");
        printf("4. Pagos por Medio\n");
        printf("5. Top 3 Categorias mas costosas (mes reciente)\n");
        printf("6. Proyeccion Mensual de Gastos\n");
        printf("7. Resumen General\n");
        printf("8. Comparacion entre dos meses.\n");
        printf("9. Mostrar gastos por persona\n");
        printf("10. Proyeccion Anual\n");
        printf("11. Ver estado de gastos en cuotas\n");
        printf("0. Volver\n");
        
        op = validarINT("Opcion: ");
        
        switch (op) {
            case 1: 
            	limpiar();
            	op2 = -1;
				while(op2!=0){
					system ("cls");
					printf("FILTRAR GASTOS POR: \n");
	            	printf("1. Gastos por Categoria\n");
	       			printf("2. Gastos por Mes/Anio\n");
	        		printf("3. Gastos Pendientes \n");
	        		printf("4. Gastos con Saldo Incompleto(cuotas)\n");
	        		printf("5. Tipos de gastos\n");
	        		printf("0. Volver\n");
	        		op2 = validarINT("Opcion: ");
	        		switch(op2){
	        			case 0: break;
	        			case 1:
	        				consultarGastosPorCategoriaStatic(categorias, nc);
							system("pause");
	                		system ("cls"); 
						break;
						case 2: 
							consultarGastosPorMesAnioStatic(categorias, nc);
							system("pause");
	                		system ("cls"); 
						break;
						case 3: 
							consultarGastosPendientesStatic( categorias, nc);
							system("pause");
	                		system ("cls"); 
						break;
						case 4:
							consultarGastosConSaldoIncompletoStatic(categorias, nc);
							system("pause");
	                		system ("cls");
						break;
						case 5:
							consultaGastosPorTipo(categorias, nc);
							system("pause");
	                		system ("cls");
						break;
						default:
							printf("Opcion invalida. Intente nuevamente.n");
						break;
					}
				}
			break;
             case 2: 
				consultarIngresosPorPersonaStatic();
				system("pause");
	            system ("cls"); 
			break;
            case 3: 
				consultarSaldoMensualStatic();
				system("pause");
	            system ("cls");
			break;
            
            case 4: 
				consultarPagosPorMedioStatic();
				system("pause");
	            system ("cls");
			break;
            
            case 5: 
				top3CategoriasCostosasStatic(categorias, nc);
				system("pause");
	            system ("cls");
			break;
            case 6:
				proyeccionMensualStatic(categorias, nc);
				system("pause");
	            system ("cls");
			break;
            case 7: 
				resumenGeneralStatic(categorias, nc);
				system("pause");
	            system ("cls");
			break;
            case 8: 
				consultaComparacionMes(categorias, nc);
				system("pause");
	            system ("cls");
			break;
            case 9: 
				consultaGastosPorPersona();
				system("pause");
	            system ("cls");
			break;
            case 10: 
				consultaProyeccionAnual();
				system("pause");
	            system ("cls");
				break;
            case 11: 
				consultaEstadoGastoTemporal();
				system("pause");
	            system ("cls");
			break;
            case 0:
                uiTransicionEntrada("Volviendo a Menu anterior...");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
	        }	

    	}
}	
							//--- REPORTES ---
	
	void menuReportes(Categoria categorias[], int nc){
    int op = -1;
    int salir = 0;
    int anio, mes;
    char mesNombre[16];
    char base[128];
    char candidato[160];
    int i, count;
    char opciones[100][160];
    FILE *f;
    char line[256];

    (void)categorias;
    (void)nc;

    while (!salir) {
    	limpiar();
        printf("\n--- REPORTES ---\n");
        printf("1. Generar reporte mensual (archivo)\n");
        printf("2. Mostrar reporte (archivo)\n");
        printf("0. Volver\n");

        op = validarINT("Opcion: ");

        switch (op) {

        case 1: {
            while (1){
                mes = validarINT("Ingrese mes (1-12): ");
                if (mes >= 1 && mes <= 12) break;
                printf("Error! Mes invalido. Intente nuevamente.\n");
            }
            while (1){
                anio = validarINT("Ingrese anio (2020 - 2025): ");
                if (anio >= 2020 && anio <= 2025) break;
                printf("Error! Anio invalido. Intente nuevamente.\n");
            }

            (void)generarReporteMensual(mes, anio, categorias, nc);
            system("pause");
	        system ("cls");
            break;
        }

        case 2: {
            while (1){
                mes = validarINT("Ingrese mes (1-12): ");
                if (mes >= 1 && mes <= 12) break;
                printf("Error! Mes invalido. Intente nuevamente.\n");
            }
            while (1){
                anio = validarINT("Ingrese anio (2020 - 2025): ");
                if (anio >= 2020 && anio <= 2025) break;
                printf("Error! Anio invalido. Intente nuevamente.\n");
            }

            count = 0;

            if (!nombreMesES(mes, mesNombre, sizeof(mesNombre))){
                printf("Error: mes invalido.\n");
                break;
            }
            snprintf(base, sizeof(base), "resumen_%s_%04d", mesNombre, anio);
            snprintf(candidato, sizeof(candidato), "%s.txt", base);
            if (archivoExiste(candidato) && count < 100){
                strncpy(opciones[count], candidato, sizeof(opciones[count]) - 1);
                opciones[count][sizeof(opciones[count]) - 1] = '\0';
                count++;
            }

 
            for (i = 1; i <= 999 && count < 100; i++){
                char suf[8];
                snprintf(suf, sizeof(suf), "_%03d", i);
                snprintf(candidato, sizeof(candidato), "%s%s.txt", base, suf);
                if (archivoExiste(candidato)){
                    strncpy(opciones[count], candidato, sizeof(opciones[count]) - 1);
                    opciones[count][sizeof(opciones[count]) - 1] = '\0';
                    count++;
                } else {
                    break;
                }
            }

            if (count == 0){
                printf("No hay reportes para %s %d.\n", mesNombre, anio);
                break;
            }


            printf("\nReportes disponibles para %s %d:\n", mesNombre, anio);
            for (i = 0; i < count; i++){
                printf("%2d) %s\n", i + 1, opciones[i]);
            }
            printf("0) Cancelar\n");

            {
                int sel = -1;
                while (1){
                    sel = validarINT("Seleccione archivo: ");
                    if (sel == 0) break;
                    if (sel >= 1 && sel <= count) break;
                    printf("Opcion invalida.\n");
                }
                if (sel == 0) break;

 
                f = fopen(opciones[sel - 1], "r");
                if (f != NULL) {
                    printf("\n--- CONTENIDO DE %s ---\n", opciones[sel - 1]);
                    while (fgets(line, sizeof(line), f)) {
                        printf("%s", line);
                    }
                    printf("\n--------------------------\n");
                    fclose(f);
                } else {
                    printf("ERROR al abrir %s para lectura.\n", opciones[sel - 1]);
                }
            }
            system("pause");
	        system ("cls");
            break;
        }

        case 0:
            uiTransicionEntrada("Volviendo a Menu anterior...");
            salir = 1;
            break;

        default:
            printf("Opcion no valida. Intente de nuevo.\n");
            break;
        }
    }
}



//									--- ADMINISTRAR ---

void menuAdministrar(Categoria categorias[], int *nc, Persona personas[], int *np){
    int op = -1;

    while (op!=0){
        printf("\n=== MENU ADMINISTRAR ===\n");
        printf("1) Registrar Persona\n");
        printf("2) Agregar Categoria\n");
        printf("3) Eliminar Persona\n");
        printf("4) Eliminar Categoria\n");
        printf("5) Eliminar Gasto\n");
        printf("6) Eliminar Ingreso\n");
        printf("7) Listar Personas\n");
        printf("8) Listar Categorias\n");
        printf("0) Volver\n");

        op = validarINT("Opcion: ");

        switch (op){
        case 1: 
    		*np = leerTodasPersonasStatic(personas, MAX_PERSONAS); 
    		registrarPersonaUI(personas, np);
    		*np = leerTodasPersonasStatic(personas, MAX_PERSONAS); 
    		system("pause");
	        system ("cls");
    	break;

        case 2:
            agregarCategoriaUI(categorias, nc);
            *nc = cargarCategoriasStatic(categorias, MAX_CATEGORIAS);
            system("pause");
	        system ("cls");
            break;

        case 3:
            eliminarPersonaUI(personas, np);
            *np = leerTodasPersonasStatic(personas, MAX_PERSONAS);
            system("pause");
	        system ("cls");
            break;

        case 4:
            eliminarCategoriaUI(categorias, nc);
            *nc = cargarCategoriasStatic(categorias, MAX_CATEGORIAS);
            system("pause");
	        system ("cls");
            break;

        case 5:
            eliminarGastoUI();
			system("pause");
	        system ("cls");    
            break;

        case 6:
            eliminarIngresoUI();
			system("pause");
	        system ("cls"); 
            break;

        case 7:
            listarPersonasUI();
			system("pause");
	        system ("cls");    
            break;

        case 8:
            mostrarCategoriasStatic(categorias, *nc);
            system("pause");
	        system ("cls");
            break;

        case 0:
        	uiTransicionEntrada("Volviendo a Menu anterior...");
            break;

        default:
            printf("Opcion invalida.\n");
            break;
        }
    }
}

						
// ----------------------------------------------------------------------
//							GASTOS
// ----------------------------------------------------------------------

void registrarGastoUI(Categoria categorias[], int *nc){
	system ("cls");
    Gasto g;
    Categoria c;
    int op;
    int local_nc;
    int i;
    int busqueda = -1;
    int catValida = 0;
    int seleccion = -1;
    int tipoOk = 0;
    int totalCuotas = 0;
    int datosValidos = 0;
    int cuotaActualUsuario = 0;
    Fecha base;
    int dia, mes, anio;
    int k;

    float valorCuotaTemporal = 0.0f;

    int finalizado = 0;
    int confirmado = 0;
    int opEdit = 0;
    int fechaOk = 0;

    local_nc = cargarCategoriasStatic(categorias, MAX_CATEGORIAS);
    *nc = local_nc;

    printf("\n=== Registrar Gasto ===\n");
    g.codigo = generarCOD("gastos.dat", sizeof(Gasto), offsetof(Gasto,codigo));
	g.status = 1;
    if (!seleccionarPersonaUI(&g.persona)){
        printf("ERROR: no se pudo seleccionar persona.\n");
        finalizado = 1;
    }


    if (!finalizado){
        g.monto = validarFLOAT("Ingresar monto total: ");
        validarTXT("Ingresar descripcion: ", g.descripcion, sizeof(g.descripcion));
    }


    if (!finalizado){
        printf("\nCOD - CATEGORIA\n");
        for (i = 0; i < local_nc; i++) {
            if (strcmp(categorias[i].nombre, "SIN CATEGORIA") != 0) {
                printf("%d - %s\n", categorias[i].codigo, categorias[i].nombre);
            }
        }

        while (catValida == 0) {
            busqueda = validarINT("Ingrese codigo de categoria: ");

            seleccion = -1;
            for (i = 0; i < local_nc; i++) {
                if (categorias[i].codigo == busqueda) {
                    if (strcmp(categorias[i].nombre, "SIN CATEGORIA") != 0) {
                        seleccion = i;
                    }
                    break;
                }
            }

            if (seleccion == -1) {
                printf("Codigo invalido o categoria no seleccionable. Intente nuevamente.\n");
            } else {
                strncpy(g.categoria, categorias[seleccion].nombre, sizeof(g.categoria) - 1);
                g.categoria[sizeof(g.categoria) - 1] = '\0';
                catValida = 1;
            }
        }
    }


    if (!finalizado){
        g.fecha = leerFecha("Ingrese fecha: dd/mm/aaaa\nFecha: ");
    }


    if (!finalizado){
        while (tipoOk == 0) {
            printf("Seleccionar tipo de gasto:\n");
            printf("1- FIJO\n2- OCASIONAL\n3- TEMPORAL\n4- ANUAL\n");
            op = validarINT("Seleccionar tipo de gasto: ");

            switch (op) {
                case 1: 
                    strcpy(g.tipo, "FIJO");
                    g.cuotasTotales = 1;
                    g.cuotaActual = 1;
                    g.cuotasPagadas = 0;
                    strcpy(g.estado, "PENDIENTE");
                    tipoOk = 1;
                    break;

                case 2: 
                    strcpy(g.tipo, "OCASIONAL");
                    g.cuotasTotales = 1;
                    g.cuotaActual = 1;
                    g.cuotasPagadas = 0;
                    strcpy(g.estado, "PENDIENTE");
                    tipoOk = 1;
                    break;

                case 3: { 
                    strcpy(g.tipo, "TEMPORAL");

                    datosValidos = 0;
                    while (datosValidos == 0) {
                        totalCuotas = validarINT("Ingresar cantidad total de cuotas: ");
                        cuotaActualUsuario = validarINT("Ingrese cuantas cuotas ya estan pagadas (0 a total): ");
                        if (totalCuotas <= 1) {
                            printf("ERROR! El total de cuotas debe ser mayor a 1.\n");
                            continue;
                        }
                        if (cuotaActualUsuario < 0 || cuotaActualUsuario > totalCuotas) {
                            printf("ERROR! Las cuotas pagadas no pueden ser > al total o < 0.\n");
                            continue;
                        }
                        datosValidos = 1;
                    }

                    g.cuotasTotales = totalCuotas;
                    g.cuotasPagadas = cuotaActualUsuario;
                    g.cuotaActual = 1;
                    strcpy(g.estado, (g.cuotaActual <= g.cuotasPagadas) ? "PAGADA" : "PENDIENTE");

                    tipoOk = 1;
                    break; 
                }

                case 4:
                    strcpy(g.tipo, "ANUAL");
                    g.cuotasTotales = 1;
                    g.cuotaActual = 1;
                    g.cuotasPagadas = 0;
                    strcpy(g.estado, "PENDIENTE");
                    tipoOk = 1;
                    break;

                default:
                    printf("Opcion no valida. Intente de nuevo.\n");
                    break;
            }
        }
    }


    while (!finalizado && !confirmado){
        printf("\n--- RESUMEN DEL GASTO ---\n");
        printf("COD (provisorio): %d\n", g.codigo);
        printf("Persona: %ld - %s\n", g.persona.dni, g.persona.nombre);
        printf("Descripcion: %s\n", g.descripcion);
        printf("Tipo: %s\n", g.tipo);
        printf("Monto: $%.2f\n", g.monto);
        printf("Categoria: %s\n", g.categoria);
        printf("Cuotas: %d total | cuotaActual=%d | cuotasPagadas=%d\n",
               g.cuotasTotales, g.cuotaActual, g.cuotasPagadas);
        printf("Fecha: ");
        imprimirFecha(g.fecha);
        printf("\n");
        printf("EstadoPago: %s\n", g.estado);

        printf("\n1) Confirmar y guardar\n");
        printf("2) Modificar campos\n");
        printf("0) Cancelar\n");
        op = validarINT("Opcion: ");

        if (op == 1){
            confirmado = 1;
        } else if (op == 2){
            
            printf("\n--- EDITAR CAMPOS ---\n");
            printf(" 1) Monto\n");
            printf(" 2) Descripcion\n");
            printf(" 3) Categoria\n");
            printf(" 4) Tipo / Cuotas\n");
            printf(" 5) Fecha\n");
            printf(" 6) Persona\n");
            printf(" 9) Volver al resumen\n");
            opEdit = validarINT("Campo a editar: ");

            switch (opEdit){
                case 1:
                    g.monto = validarFLOAT("Nuevo monto: ");
                    break;

                case 2:
                    validarTXT("Nueva descripcion: ", g.descripcion, sizeof(g.descripcion));
                    break;

                case 3: {
                    int catVal = 0;
                    int sel = -1;
                    int code;
                    printf("\nCOD - CATEGORIA\n");
                    for (i = 0; i < local_nc; i++) {
                        if (strcmp(categorias[i].nombre, "SIN CATEGORIA") != 0) {
                            printf("%d - %s\n", categorias[i].codigo, categorias[i].nombre);
                        }
                    }
                    while (!catVal){
                        code = validarINT("Ingrese codigo de categoria: ");
                        sel = -1;
                        for (i = 0; i < local_nc; i++) {
                            if (categorias[i].codigo == code) {
                                if (strcmp(categorias[i].nombre, "SIN CATEGORIA") != 0) sel = i;
                                break;
                            }
                        }
                        if (sel == -1) {
                            printf("Codigo invalido o no seleccionable.\n");
                        } else {
                            strncpy(g.categoria, categorias[sel].nombre, sizeof(g.categoria)-1);
                            g.categoria[sizeof(g.categoria)-1] = '\0';
                            catVal = 1;
                        }
                    }
                } break;

                case 4: {
                  
                    printf("Tipo de gasto (redefinir):\n");
                    printf(" 1) FIJO\n 2) TEMPORAL\n 3) OCASIONAL\n 4) ANUAL\n");
                    op = validarINT("Opcion: ");
                    switch (op){
                        case 1:
                            strcpy(g.tipo, "FIJO");
                            g.cuotasTotales = 1;
                            g.cuotasPagadas = 0;
                            g.cuotaActual = 1;
                            strcpy(g.estado, "PENDIENTE");
                            break;
                        case 2:
                            strcpy(g.tipo, "TEMPORAL");
                            datosValidos = 0;
                            while (!datosValidos){
                                totalCuotas = validarINT("Ingresar cantidad total de cuotas: ");
                                cuotaActualUsuario = validarINT("Ingrese cuantas cuotas ya estan pagadas (0 a total): ");
                                if (totalCuotas <= 1){ 
									printf("Debe ser >1.\n");
									continue; }
                                if (cuotaActualUsuario < 0 || cuotaActualUsuario > totalCuotas){
                                    printf("Pagadas fuera de rango.\n");
									 continue;
                                }
                                datosValidos = 1;
                            }
                            g.cuotasTotales = totalCuotas;
                            g.cuotasPagadas = cuotaActualUsuario;
                            g.cuotaActual = 1;
                            strcpy(g.estado, (g.cuotaActual <= g.cuotasPagadas) ? "PAGADA" : "PENDIENTE");
                            break;
                        case 3:
                            strcpy(g.tipo, "OCASIONAL");
                            g.cuotasTotales = 1;
                            g.cuotasPagadas = 0;
                            g.cuotaActual = 1;
                            strcpy(g.estado, "PENDIENTE");
                            break;
                        case 4:
                            strcpy(g.tipo, "ANUAL");
                            g.cuotasTotales = 1;
                            g.cuotasPagadas = 0;
                            g.cuotaActual = 1;
                            strcpy(g.estado, "PENDIENTE");
                            break;
                        default:
                            printf("Opcion invalida.\n");
                            break;
                    }
                } break;

                case 5:
                    fechaOk = 0;
                    while (!fechaOk){
                        g.fecha = leerFecha("Ingrese fecha: dd/mm/aaaa\nFecha: ");
                        fechaOk = 1;
                    }
                    break;

                case 6:
                    if (!seleccionarPersonaUI(&g.persona)){
                        printf("ERROR: no se pudo seleccionar persona.\n");
                    }
                    break;

                case 9:
                    break;

                default:
                    printf("Opcion invalida.\n");
                    break;
            }
        } else if (op == 0){
            printf("Operacion cancelada. No se guardaron cambios.\n");
            finalizado = 1;
        } else {
            printf("Opcion invalida.\n");
        }
    }


    if (!finalizado && confirmado){
        if (strcmp(g.tipo, "TEMPORAL") != 0) {
            if (guardarGasto(&g))
                printf("Gasto guardado correctamente.\n");
            else
                printf("ERROR: no se pudo guardar gasto.\n");
        } else {
            if (guardarGasto(&g))
                printf("Gasto (cuota 1) guardado correctamente.\n");
            else
                printf("ERROR: no se pudo guardar gasto.\n");

          
            base = g.fecha;
            dia = base.dia;
            mes = base.mes;
            anio = base.anio;

            for (k = 2; k <= g.cuotasTotales; k++) {
                mes++;
                if (mes > 12) { mes = 1; anio++; }

                g.codigo = generarCOD(ARCH_GASTOS, sizeof(Gasto), offsetof(Gasto, codigo));
                g.status = 1;
                g.cuotaActual = k;
                g.fecha.dia = dia; g.fecha.mes = mes; g.fecha.anio = anio;

                if (k <= g.cuotasPagadas) strcpy(g.estado, "PAGADA");
                else strcpy(g.estado, "PENDIENTE");

                if (guardarGasto(&g) == 0)
                    printf("ERROR: no se pudo guardar cuota %d.\n", k);
            }

            valorCuotaTemporal = g.monto;
            if (g.cuotasTotales > 0) {
                valorCuotaTemporal = g.monto / g.cuotasTotales;
            }
            printf("Gasto temporal registrado: %d cuotas de $%.2f (pagadas: %d)\n",
                   g.cuotasTotales, valorCuotaTemporal, g.cuotasPagadas);
        }
    }
}

int guardarGasto(Gasto *g) {
	    int exito = 0;
	    FILE *f;
	    if (g != NULL) {
	        if ((f = fopen(ARCH_GASTOS, "ab")) != NULL) {
	            if (fwrite(g, sizeof(Gasto), 1, f) == 1) {
	                exito = 1;
	            } else {
	                printf("ERROR: Fallo al escribir en el archivo de gastos.\n");
	            }
	            fclose(f);
	        } else {
	            printf("ERROR al abrir el archivo %s para escritura.\n", ARCH_GASTOS);
	        }
	    }
	    return exito; 
	}
	
int cargarGasto(Gasto gastos[], int max){
    int cnt = 0;
    FILE *f = NULL;
    Gasto g;

    if ((f = fopen(ARCH_GASTOS, "rb")) != NULL){
        while (fread(&g, sizeof(Gasto), 1, f) == 1){
            if (g.codigo > 0 && g.status == 1){
                if (cnt < max){
                    gastos[cnt] = g;
                    cnt++;
                }
            }
        }
        fclose(f);
    }
    return cnt; 
}

int leerTodosGastosStatic(Gasto gastos[], int max){
		return cargarGasto(gastos, max);
	}
	
void mostrarGastosStatic(Gasto gastos[], int ng, Categoria categorias[], int nc){
	system ("cls");
    int i;
    Gasto *ptr_gasto = gastos;
    int finalizado = 0;
    const char* nombreCat;
    const char* estadoPago;
    Gasto gastoActual;
    float montoMostrado = 0.0f;

    FILE *f;
    Persona reg;
    size_t rcount;
    int statusActual;
    char nombrePersona[50];

    if (ng == 0){
        printf("No hay gastos registrados.\n");
        finalizado = 1;
    }

    if (finalizado == 0){
        ordenarGastosPorFechaStatic(gastos, ng);
        printf("\n--- GASTOS (orden fecha asc) ---\n");
        for (i = 0; i < ng; i++){
            gastoActual = (*(ptr_gasto + i));

            if (!esCategoriaActiva(categorias, nc, gastoActual.categoria))
                nombreCat = "SIN CATEGORIA";
            else
                nombreCat = gastoActual.categoria;

            if (strcmp(gastoActual.estado, "PAGADA") == 0 || strcmp(gastoActual.estado, "PAGADO") == 0)
                estadoPago = "PAGADO";
            else if (strcmp(gastoActual.estado, "PARCIALMENTE PAGADO") == 0 || strcmp(gastoActual.estado, "PAGADO PARCIALMENTE") == 0)
                estadoPago = "PAGADO PARCIALMENTE";
            else
                estadoPago = "NO PAGADO";

            montoMostrado = gastoActual.monto;

            statusActual = gastoActual.persona.status;
            strncpy(nombrePersona, gastoActual.persona.nombre, sizeof(nombrePersona)-1);
            nombrePersona[sizeof(nombrePersona)-1] = '\0';

            if ((f = fopen(ARCH_PERSONAS, "rb")) != NULL){
                while ((rcount = fread(&reg, sizeof(Persona), 1, f)) == 1u){
                    if (reg.dni == gastoActual.persona.dni){
                        statusActual = reg.status;
                        strncpy(nombrePersona, reg.nombre, sizeof(nombrePersona)-1);
                        nombrePersona[sizeof(nombrePersona)-1] = '\0';
                        break;
                    }
                }
                fclose(f);
            } else {
                printf("ERROR: no se pudo abrir el archivo.\n");
                finalizado = 1;
                break;
            }

            printf("Codigo:%d | Tipo:%s | %s | $%.2f | %s | ",
                   gastoActual.codigo, gastoActual.tipo,
                   gastoActual.descripcion, montoMostrado, nombreCat);

            imprimirFecha(gastoActual.fecha);
            printf(" | Estado: %s", estadoPago);

            if (gastoActual.cuotasTotales > 1)
                printf(" | Cuota: %d/%d | Pagadas (Total): %d",
                       gastoActual.cuotaActual, gastoActual.cuotasTotales, gastoActual.cuotasPagadas);
            else
                printf(" | (Pago Unico)");

            if (statusActual == 0){
                printf(" | Persona eliminada\n");
            } else {
                printf(" | DNI: %ld\n", gastoActual.persona.dni);
                printf(" | Nombre: %s\n", nombrePersona);
            }
        }
    }
    return;
}



void eliminarGastoUI(){
 
    FILE *f = NULL;
    Gasto g;
    int codigo = 0;
    int hecho = 0; 
    long back = 0;
    int esPagadoTotal;
    int esPagadoParcial, tienePagoActivo;


    Gasto gastos[MAX_GASTOS];
    Categoria categorias[MAX_CATEGORIAS];
    int ng = 0;
    int nc = 0;
    



    nc = cargarCategoriasStatic(categorias, MAX_CATEGORIAS);
    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);


    mostrarGastosStatic(gastos, ng, categorias, nc);


    if (ng > 0) { 
        
        
        codigo = validarINT("\nCodigo de gasto a eliminar: ");

        if ((f = fopen(ARCH_GASTOS, "r+b")) != NULL){
            while (fread(&g, sizeof(Gasto), 1, f) == 1){
                if (g.codigo == codigo){
                    if (g.cuotasTotales > 1){
                        int rplan = softDeletePlanDeCuotas(&g);
                        if (rplan == 1){
                            hecho = 1; 
                        } 
                        
                    } else {
                       
                        esPagadoTotal   = (strcmp(g.estado, "PAGADA") == 0);
                        esPagadoParcial = (strcmp(g.estado, "PARCIALMENTE PAGADO") == 0);
                         tienePagoActivo = existePagoActivoParaGastoCodigo(g.codigo);
    
                        if (esPagadoTotal || esPagadoParcial || tienePagoActivo == 1){
                            printf("ERROR: El gasto %d tiene pagos (total/parcial) y no puede eliminarse.\n", codigo);
                        } else if (tienePagoActivo < 0){
                            printf("ERROR: No se pudo verificar pagos del gasto %d.\n", codigo);
                        } else {
                            if (g.status == 0){
                                printf("Aviso: El gasto ya estaba desactivado.\n");
                            } else {
                                g.status = 0;
                                back = -(long)sizeof(Gasto);
                                if (fseek(f, back, SEEK_CUR) == 0 && fwrite(&g, sizeof(Gasto), 1, f) == 1){
                                    printf("OK: Gasto %d desactivado (soft delete).\n", codigo);
                                    hecho = 1;
                                } else {
                                    printf("Error: No se pudo escribir el registro.\n");
                                }
                            }
                        }
                    }
                    break; 
                }
            }
            fclose(f);
            
            if (!hecho && g.codigo != codigo){
                printf("No se encontro gasto con codigo %d.\n", codigo);
            }
        } else {
            printf("Error: No se pudo abrir '%s'.\n", ARCH_GASTOS);
        }
    } 

    return;
}

int softDeletePlanDeCuotas(const Gasto *ref){
    FILE *fg = NULL;
    Gasto g;
    int res = 0;      
    int fin = 0;
    int bloquea = 0;
    int modificados = 0;
    long back = 0;

    if ((fg = fopen(ARCH_GASTOS, "rb")) == NULL){
        printf("Error: No se pudo abrir '%s'.\n", ARCH_GASTOS);
        res = -1; fin = 1;
    }
    if (!fin){
        while (fread(&g, sizeof(Gasto), 1, fg) == 1){
            if (g.status == 1 && mismaClavePlan(&g, ref)){
                int esPagadoTotal   = (strcmp(g.estado, "PAGADA") == 0) ||
                                      (g.cuotasTotales > 0 && g.cuotasPagadas >= g.cuotasTotales);
                int esPagadoParcial = (strcmp(g.estado, "PARCIALMENTE PAGADO") == 0) ||
                                      (g.cuotasTotales > 0 && g.cuotasPagadas  > 0 && g.cuotasPagadas < g.cuotasTotales);
                int tienePagoActivo = existePagoActivoParaGastoCodigo(g.codigo);

                if (esPagadoTotal || esPagadoParcial || tienePagoActivo == 1){
                    bloquea = 1;
                    break;
                }
                if (tienePagoActivo < 0){
                    bloquea = 1; 
                    break;
                }
            }
        }
        fclose(fg); fg = NULL;
    }
    if (!fin && bloquea == 1){
        printf("ERROR: El plan de cuotas tiene pagos (parciales o totales). No se puede desactivar en lote.\n");
        res = 0; fin = 1;
    }
    if (!fin){
        if ((fg = fopen(ARCH_GASTOS, "r+b")) == NULL){
            printf("Error: No se pudo abrir '%s'.\n", ARCH_GASTOS);
            res = -1; fin = 1;
        }
    }
    if (!fin){
        while (fread(&g, sizeof(Gasto), 1, fg) == 1){
            if (g.status == 1 && mismaClavePlan(&g, ref)){
                g.status = 0;
                back = -(long)sizeof(Gasto);
                if (fseek(fg, back, SEEK_CUR) == 0 && fwrite(&g, sizeof(Gasto), 1, fg) == 1){
                    modificados++;
                    fflush(fg); 
                } else {
                    printf("Error: No se pudo escribir una cuota del plan.\n");
                    res = -1; 
                }
            }
        }
        fclose(fg); fg = NULL;

        if (modificados > 0 && res != -1){
            printf("OK: Desactivadas %d cuota(s) del plan.\n", modificados);
            res = 1;
        } else if (modificados == 0 && res == 0){
            printf("Aviso: No se encontraron cuotas activas para ese plan.\n");
            res = 0;
        }
    }
    
    return res; 
}
// ----------------------------------------------------------------------
//							INGRESOS
// ----------------------------------------------------------------------
	
	void registrarIngresoUI(Persona personas[], int np) {
	system ("cls");
    (void)personas;
    (void)np;

    Ingreso ing;
    int terminar = 0;
    int exito = 0;
    ing.codigo = generarCOD(ARCH_INGRESOS, sizeof(Ingreso), offsetof(Ingreso, codigo));
    ing.status = 1;

    printf("\n=== Registrar Ingreso ===\n");
    printf("Ejemplo de monto: 12500.50.\n");
    ing.monto = validarFLOAT("Monto: ");
    validarTXT("Concepto: ", ing.concepto, sizeof(ing.concepto));
    ing.fecha = leerFecha("Ingrese Fecha: dd/mm/aaaa.\nFecha: ");

    
    if (!terminar) {
        Persona perSel;
        if (seleccionarPersonaUI(&perSel)) {
            ing.persona = perSel; 
        } else {
            printf("Operacion cancelada: no se selecciono persona.\n");
            terminar = 1;
        }
    }

    
    if (!terminar) {
        if (guardarIngreso(&ing)) {
            exito = 1;
            printf("Ingreso guardado correctamente.\n");
            printf("Codigo:%d | Concepto:%s | $%.2f | ",
                   ing.codigo, ing.concepto, ing.monto);
            imprimirFecha(ing.fecha);
            printf(" | DNI:%ld | Nombre:%s\n", ing.persona.dni, ing.persona.nombre);
        } else {
            printf("ERROR: no se pudo guardar ingreso.\n");
        }
    }
}

	int guardarIngreso(Ingreso *ing) {
	    int exito = 0;
	    FILE *f;
	    if (ing != NULL) {
	        if ((f = fopen(ARCH_INGRESOS, "ab")) != NULL) {
	            if (fwrite(ing, sizeof(Ingreso), 1, f) == 1) {
	                exito = 1;	
	            } else {
	                printf("ERROR: Fallo al escribir en el archivo de ingresos.\n");
	            }
	            fclose(f);
	        } else {
	            printf("ERROR al abrir el archivo %s para escritura.\n", ARCH_INGRESOS);
	        }
	    }
	    return exito; 
	}
		
	int cargarIngreso(Ingreso ingresos[], int max){
    int cnt = 0;
    FILE *f = NULL;
    Ingreso in;
    if (( f = fopen(ARCH_INGRESOS, "rb")) != NULL){
        while (fread(&in, sizeof(Ingreso), 1, f) == 1){
            if (in.codigo > 0 && in.status == 1){
                if (cnt < max){
                    ingresos[cnt] = in;
                    cnt++;
                }
            }
        }
        fclose(f);
    }
    return cnt;
}

	int leerTodosIngresosStatic(Ingreso ingresos[], int max){
		return cargarIngreso(ingresos, max);
	}
	
void mostrarIngresosStatic(Ingreso ingresos[], int ni) {
		system ("cls");
	    int i;
	    Ingreso *ptr_ingreso = ingresos;
        int st; 
        int r;  
        
	    if (ni==0) { 
            printf("No hay ingresos registrados.\n"); 
        } else {
	        ordenarIngresosPorFechaStatic(ingresos, ni);
	        printf("\n--- INGRESOS (orden fecha asc) ---\n");
	        for (i = 0; i < ni; i++){
	            printf("Concepto:%s | $%.2f | ", (*(ptr_ingreso + i)).concepto, (*(ptr_ingreso + i)).monto);
	            imprimirFecha((*(ptr_ingreso + i)).fecha);


	            r = personaActiva((*(ptr_ingreso + i)).persona.dni, &st);
				
				if(r == 1 && st == 1){ 

					printf(" | DNI: %ld\n", (*(ptr_ingreso + i)).persona.dni);
                    printf(" | Nombre: %s\n", (*(ptr_ingreso + i)).persona.nombre);
				} else { 

					printf(" | Persona eliminada\n");
				}

               
	        }
        }
        return; 
	}


	void eliminarIngresoUI(){
	system ("cls");
    FILE *f = NULL;
    Ingreso in;
    int codigo = 0;
    int hecho = 0;
    long back = 0;
 	Ingreso ingresos[MAX_INGRESOS];
    int ni = leerTodosIngresosStatic(ingresos, MAX_INGRESOS);
    int i;
   
    
       
        if (ni == 0){
            printf("No hay ingresos registrados.\n");
        } else {
            printf("\n--- LISTA DE INGRESOS ---\n");
            for (i = 0; i < ni; i++){
                printf("Codigo:%d | Concepto:%s | $%.2f | ",
                       ingresos[i].codigo, ingresos[i].concepto, ingresos[i].monto);
                imprimirFecha(ingresos[i].fecha);
                printf(" | DNI:%ld | Nombre:%s\n", ingresos[i].persona.dni, ingresos[i].persona.nombre);
            }
        }
    

   
    codigo = validarINT("\nCodigo de ingreso a desactivar: ");

    if ((f = fopen(ARCH_INGRESOS, "r+b")) != NULL){
        while (fread(&in, sizeof(Ingreso), 1, f) == 1){
            if (in.codigo == codigo){
                if (in.status == 0){
                    printf("Aviso: El ingreso ya estaba desactivado.\n");
                } else {
                    in.status = 0; /* soft delete */
                    back = -(long)sizeof(Ingreso);
                    if (fseek(f, back, SEEK_CUR) == 0 && fwrite(&in, sizeof(Ingreso), 1, f) == 1){
                        printf("OK: Ingreso %d desactivado (soft delete).\n", codigo);
                        hecho = 1;
                        fflush(f); 
                    } else {
                        printf("Error: No se pudo escribir el registro.\n");
                    }
                }
                break;
            }
        }
        fclose(f);
        if (!hecho && in.codigo != codigo){
            printf("No se encontro ingreso con codigo %d.\n", codigo);
        }
    } else {
        printf("Error: No se pudo abrir '%s'.\n", ARCH_INGRESOS);
    }

    return; 
}
	
// ----------------------------------------------------------------------
//							PAGOS
// ----------------------------------------------------------------------	
	
int registrarPago(Pago *p){
    int exito = 0;
    Gasto g;

    Pago pagos[MAX_PAGOS];
    int np_pagos = 0;

    float cuotaValor = 0.0f;
    float totalPagadoAnteriormente = 0.0f;
    float nuevoTotalPagado = 0.0f;

    int debeSumarUnaCuota = 0;
    int pagoGuardado = 0;

    FILE *fp = NULL;      
    FILE *fg = NULL;      

    int continuar = 1;
    long back;

    if (continuar == 1){
        if (p == NULL){
            printf("ERROR: puntero Pago nulo.\n");
            continuar = 0;
        }
    }
    if (continuar == 1){
        if ((*p).gastoCodigo <= 0){
            printf("ERROR: gastoCodigo invalido.\n");
            continuar = 0;
        }
    }
    if (continuar == 1){
        if ((*p).importe <= 0.0f){
            printf("ERROR: importe debe ser positivo.\n");
            continuar = 0;
        }
    }
    if (continuar == 1){
       
        g = encontrarGastoPorCodigo((*p).gastoCodigo);
        if (g.codigo <= 0){
            printf("ERROR: No se encontro el gasto Codigo %d.\n", (*p).gastoCodigo);
            continuar = 0;
        } else if (g.status != 1){
            printf("ERROR: El gasto no esta activo.\n");
            continuar = 0;
        }
    }
    if (continuar == 1){
        np_pagos = leerTodosPagosStatic(pagos, MAX_PAGOS);
        totalPagadoAnteriormente = calcularTotalPagadoCuota(g.codigo, pagos, np_pagos);

        cuotaValor = g.monto;
        if (g.cuotasTotales > 1){
            cuotaValor = g.monto / (float)g.cuotasTotales;
        }

        nuevoTotalPagado = totalPagadoAnteriormente + (*p).importe;

        if (nuevoTotalPagado > cuotaValor + 0.0001f){
            printf("ERROR: El importe ($%.2f) excede el saldo pendiente ($%.2f).\n",
                   (*p).importe, (cuotaValor - totalPagadoAnteriormente));
            continuar = 0;
        }

 
        if (nuevoTotalPagado >= cuotaValor - 0.0001f){
            if (g.cuotasTotales > 1){
                if (g.cuotaActual == g.cuotasPagadas + 1){
                    debeSumarUnaCuota = 1;
                }
            } else {
                if (g.cuotasPagadas == 0){
                    debeSumarUnaCuota = 1;
                }
            }
        }
    }


    if (continuar == 1){
        fp = fopen(ARCH_PAGOS, "ab");
        if (fp != NULL){
            if (fwrite(p, sizeof(Pago), 1, fp) == 1){
                pagoGuardado = 1;
            } else {
                printf("ERROR: Fallo al escribir en el archivo de pagos.\n");
            }
            fclose(fp);
            fp = NULL;
        } else {
            printf("ERROR al abrir el archivo %s para escritura.\n", ARCH_PAGOS);
        }
    }


    if (continuar == 1 && pagoGuardado == 1){
        int pagoCompleto = debeSumarUnaCuota;
        int nuevasCuotasPagadas = g.cuotasPagadas + (pagoCompleto ? 1 : 0);
        int actualizados = 0;

        fg = fopen(ARCH_GASTOS, "r+b");
        if (fg == NULL){
            printf("ERROR CRITICO: No se pudo abrir %s en modo r+b. El pago se guardo, pero el estado del gasto no se actualizo.\n", ARCH_GASTOS);
            continuar = 0;
        }

        if (continuar == 1){
            Gasto gx;
            while (fread(&gx, sizeof(Gasto), 1, fg) == 1){
                int debeEscribir = 0;

                if (pagoCompleto){
 
                    if (gx.status == 1 &&
                        gx.cuotasTotales == g.cuotasTotales &&
                        gx.persona.dni == g.persona.dni &&
                        fabs(gx.monto - g.monto) < 0.001f &&
                        strcmp(gx.descripcion, g.descripcion) == 0)
                    {
                        gx.cuotasPagadas = nuevasCuotasPagadas;
                        if (gx.cuotaActual <= nuevasCuotasPagadas){
                            strcpy(gx.estado, "PAGADA");
                        } else {
                            strcpy(gx.estado, "PENDIENTE");
                        }
                        debeEscribir = 1;
                    }
                } else {
                    
                    if (gx.status == 1 && gx.codigo == g.codigo){
                        if (strcmp(gx.estado, "PENDIENTE") == 0){
                            strcpy(gx.estado, "PARCIALMENTE PAGADO");
                            debeEscribir = 1;
                        }
                    }
                }

                if (debeEscribir){
                    back = -(long)sizeof(Gasto);
                    if (fseek(fg, back, SEEK_CUR) == 0){
                        if (fwrite(&gx, sizeof(Gasto), 1, fg) == 1){
                            actualizados++;
                            fflush(fg);
                        } else {
                            printf("Error: No se pudo escribir el registro de gasto.\n");
                        }
                    } else {
                        printf("Error: No se pudo posicionar para escribir en el archivo de gastos.\n");
                    }
                }
            }
            fclose(fg);
            fg = NULL;

 
            exito = 1;
        }
    }

    return exito; 
}


void registrarPagoUI(void){
	system ("cls");
    int fin = 0;                  
    int modo = 0;
    Gasto gsel;
    Pago  p;
    int confirmado = 0;

    Pago pagos[MAX_PAGOS];
    int  np_pagos = 0;

    float saldo = 0.0f;
    float topePago = 0.0f;
    float importe = 0.0f;
    float minimoPago = 0.0f; 

    int opMedio = 0;

    time_t t;
    struct tm *ptm;
    Fecha hoy;
    
    
    Categoria categorias[MAX_CATEGORIAS]; 
    int nc = 0;                         
    const char *nombreCat = NULL;         

    printf("\n=== Registrar Pago ===\n");
    printf("1) Gastos pendientes hasta hoy\n");
    printf("2) Adelantar pagos (fecha futura)\n");


    while (!fin && (modo != 1 && modo != 2)){
        modo = validarINT("Opcion: ");
        if (modo != 1 && modo != 2){
            printf("Opcion invalida. Use 1 u 2.\n");
        }
    }


    if (!fin){
        if (!seleccionarGastoUI(&gsel, modo)){
            printf("Operacion cancelada o sin seleccion valida.\n");
            fin = 1;
        }
    }


    if (!fin){
        t = time(NULL);
        ptm = localtime(&t);
        hoy.dia  = (*ptm).tm_mday;
        hoy.mes  = (*ptm).tm_mon + 1;
        hoy.anio = (*ptm).tm_year + 1900;
        
        
        nc = cargarCategoriasStatic(categorias, MAX_CATEGORIAS); 
    }


    if (!fin){
        np_pagos = leerTodosPagosStatic(pagos, MAX_PAGOS);
        saldo    = calcularSaldoPendienteCuota(gsel, pagos, np_pagos);
        if (saldo <= 0.0001f){
            printf("No hay saldo pendiente para el gasto/cuota seleccionado.\n");
            fin = 1;
        } else {
            topePago = saldo;
        }
    }


    if (!fin){
  
        nombreCat = esCategoriaActiva(categorias, nc, gsel.categoria) ? gsel.categoria : "CATEGORIA ELIMINADA"; 
        
        printf("\n--- Gasto seleccionado ---\n");
        printf("Codigo: %d\n", gsel.codigo);
        printf("Descripcion: %s\n", gsel.descripcion);
        printf("Categoria: %s\n", nombreCat); 
        if (gsel.persona.status == 0) {
            printf("Persona: Persona eliminada\n");
        } else {
            printf("Persona: %ld - %s\n", gsel.persona.dni, gsel.persona.nombre);
        }
        printf("Fecha de cuota/gasto: "); imprimirFecha(gsel.fecha); printf("\n");
        if (gsel.cuotasTotales > 1)
            printf("Cuota: %d/%d\n", gsel.cuotaActual, gsel.cuotasTotales);
        else
            printf("Cuota: 1/1 (pago unico)\n");
        printf("Saldo pendiente: $%.2f\n", saldo);
    }

   
    if (!fin){
        
        float porcentajeMinimo = 0.20f; 
        minimoPago = topePago * porcentajeMinimo;

        printf("\nDebe pagar al menos el %.0f%% del saldo.\n", porcentajeMinimo * 100);
        printf("Monto minimo permitido: $%.2f\n", minimoPago);
        printf("Monto maximo permitido: $%.2f\n", topePago);

        while (1){
            importe = validarFLOAT("Importe a pagar: ");
            if (importe < minimoPago - 0.0005f){
                printf("ERROR: el importe debe ser al menos el 20%% del saldo ($%.2f).\n", minimoPago);
                continue;
            }
            if (importe > topePago + 0.0005f){
                printf("ERROR: no puede exceder el saldo pendiente ($%.2f).\n", topePago);
                continue;
            }
            break;
        }
    }

    
    if (!fin){
        opMedio = 0;
        while (opMedio < 1 || opMedio > 4){
            printf("Seleccione el Medio de Pago:\n");
            printf(" 1- Efectivo\n 2- Debito\n 3- Credito\n 4- Transferencia\n");
            opMedio = validarINT("Medio (1-4): ");
            if (opMedio < 1 || opMedio > 4) printf("Opcion invalida.\n");
        }
        switch (opMedio){
            case 1: strncpy(p.medio, "Efectivo", sizeof(p.medio)-1); break;
            case 2: strncpy(p.medio, "Debito", sizeof(p.medio)-1);   break;
            case 3: strncpy(p.medio, "Credito", sizeof(p.medio)-1);  break;
            default: strncpy(p.medio, "Transferencia", sizeof(p.medio)-1); break;
        }
        p.medio[sizeof(p.medio)-1] = '\0';
    }

    
    if (!fin){
        while (1){
            p.fecha = leerFecha("Fecha de pago (dd/mm/aaaa)\nFecha: "); 
            
            int esValida = 0;
            
            if (modo == 1) {
                if (validarPagoFecha(&gsel, &p, &hoy) == 1) { 
                    esValida = 1;
                } else {
                    printf("ERROR: La fecha de pago no puede ser anterior a la fecha del gasto (");
                    imprimirFecha(gsel.fecha);
                    printf(").\n");
                }
            } 
            else { 
                int cmp = compararFechas(p.fecha, hoy);
                if (cmp == 0) { 
                    esValida = 1; 
                } else { 
                    printf("ERROR: Para adelantar pagos, la fecha de pago debe ser la de hoy (");
                    imprimirFecha(hoy);
                    printf("). Usted ingreso una fecha anterior.\n");
                }
            }

            if (!esValida) {
                continue; 
            }
            break; 
        }
    }


    if (!fin){
        p.gastoCodigo = gsel.codigo;
        p.importe     = importe;
    }


    if (!fin){
        while (!confirmado && !fin){
            int op = -1;
            
 
            nombreCat = esCategoriaActiva(categorias, nc, gsel.categoria) ? gsel.categoria : "CATEGORIA ELIMINADA"; // <-- NUEVO
            
            printf("\n--- RESUMEN DEL PAGO ---\n");
            printf("Gasto COD: %d | %s\n", gsel.codigo, gsel.descripcion);
            if (gsel.persona.status == 0) {
                printf("Persona: Persona eliminada\n");
            } else {
                printf("Persona : %ld - %s\n", gsel.persona.dni, gsel.persona.nombre);
            }
            printf("Categoria: %s\n", nombreCat); 
            printf("Fecha de la cuota/gasto: "); imprimirFecha(gsel.fecha); printf("\n");
            if (gsel.cuotasTotales > 1)
                printf("Cuota: %d/%d\n", gsel.cuotaActual, gsel.cuotasTotales);
            else
                printf("Cuota: 1/1 (pago unico)\n");
            printf("Saldo pendiente actual: $%.2f\n", topePago);
            printf("Importe a registrar: $%.2f\n", p.importe);
            printf("Medio: %s\n", p.medio);
            printf("Fecha de pago: "); imprimirFecha(p.fecha); printf("\n");

            printf("\n1) Confirmar y guardar\n");
            printf("2) Modificar campos\n");
            printf("0) Cancelar\n");
            op = validarINT("Opcion: ");

            if (op == 1){
                confirmado = 1;
            } else if (op == 2){
                int editLoop = 1;
                while (editLoop){
                    int opEdit = -1;
                    printf("\n--- EDITAR ---\n");
                    printf(" 1) Importe\n");
                    printf(" 2) Medio\n");
                    printf(" 3) Fecha de pago\n");
                    printf(" 9) Volver al resumen\n");
                    printf(" 0) Cancelar\n");
                    opEdit = validarINT("Opcion: ");

                    if (opEdit == 1){
                        while (1){
                            float nuevo = validarFLOAT("Nuevo importe: ");
                            if (nuevo < minimoPago - 0.0005f){
                                printf("ERROR: el importe debe ser al menos el 20%% del saldo ($%.2f).\n", minimoPago);
                                continue;
                            }
                            if (nuevo > topePago + 0.0005f){
                                printf("ERROR: no puede exceder el saldo pendiente ($%.2f).\n", topePago);
                                continue;
                            }
                            p.importe = nuevo;
                            break;
                        }
                    } else if (opEdit == 2){
                        int o = 0;
                        while (o < 1 || o > 4){
                            printf("Medio:\n 1- Efectivo\n 2- Debito\n 3- Credito\n 4- Transferencia\n");
                            o = validarINT("Medio (1-4): ");
                        }
                        switch (o){
                            case 1: strncpy(p.medio, "Efectivo", sizeof(p.medio)-1); break;
                            case 2: strncpy(p.medio, "Debito", sizeof(p.medio)-1);   break;
                            case 3: strncpy(p.medio, "Credito", sizeof(p.medio)-1);  break;
                            default: strncpy(p.medio, "Transferencia", sizeof(p.medio)-1); break;
                        }
                        p.medio[sizeof(p.medio)-1] = '\0';
                    } else if (opEdit == 3){
                        while (1){
                            Fecha nueva = leerFecha("Nueva fecha de pago (dd/mm/aaaa)\nFecha: ");
                            Pago tmp = p; 
                            tmp.fecha = nueva;
                            
                            int esValida = 0;

                            if (modo == 1) {
                                if (validarPagoFecha(&gsel, &tmp, &hoy) == 1) {
                                    esValida = 1;
                                } else {
                                    printf("ERROR: La fecha de pago no puede ser anterior a la fecha del gasto (");
                                    imprimirFecha(gsel.fecha);
                                    printf(").\n");
                                }
                            } 
                            else { 
                                int cmp = compararFechas(nueva, hoy);
                                if (cmp == 0) { 
                                    esValida = 1; 
                                } else { 
                                    printf("ERROR: Para adelantar pagos, la fecha de pago debe ser la de hoy (");
                                    imprimirFecha(hoy);
                                    printf("). Usted ingreso una fecha anterior.\n");
                                }
                            }
                            
                            if (!esValida) {
                                continue;
                            }
                            
                            p.fecha = nueva; 
                            break;
                        }
                    } else if (opEdit == 9){
                        editLoop = 0;
                    } else if (opEdit == 0){
                        fin = 1;
                        editLoop = 0;
                    } else {
                        printf("Opcion invalida.\n");
                    }
                }
            } else if (op == 0){
                printf("Operacion cancelada. No se guardaron cambios.\n");
                fin = 1;
            } else {
                printf("Opcion invalida.\n");
            }
        }
    }

    
    if (!fin && confirmado){
        if (registrarPago(&p)){
            
        } else {
            printf("ERROR: no se pudo registrar pago.\n");
        }
    }

    return; 
}



	int leerTodosPagosStatic(Pago pagos[], int max){
		int cnt = 0;
	    FILE *f;
	    long size;

	    if ((f = fopen(ARCH_PAGOS, "rb")) != NULL){
	        fseek(f, 0, SEEK_END);
	        size = ftell(f);
	        cnt = (int)(size / sizeof(Pago));
	        if (cnt <= 0) {
	            cnt = 0;
	        } else {
	            if (cnt > max) cnt = max;
	            rewind(f);
	            fread(pagos, sizeof(Pago), cnt, f);
	        }
	        fclose(f);
	    } else {
	        cnt = 0;
	    }
	    return cnt; 
	}

	void mostrarPagosStatic(Pago pagos[], int np) {
		system ("cls");
	    int i;
	    Pago *ptr_pago = pagos;

	    if (np==0) { 
            printf("No hay pagos registrados.\n"); 
        } else {
	        printf("\n--- PAGOS ---\n");
	        for (i = 0; i < np; i++){
	            printf("GastoCodigo:%d | Medio:%s | $%.2f | ",(*(ptr_pago + i)).gastoCodigo,(*(ptr_pago + i)).medio,(*(ptr_pago + i)).importe);
	            imprimirFecha((*(ptr_pago + i)).fecha);
	            printf("\n");
	        }
        }
        return; 
	}

// ----------------------------------------------------------------------
//							PERSONSAS
// ----------------------------------------------------------------------

	void registrarPersonaUI(Persona personas[], int *np){
	system ("cls");
    Persona p;
    Persona reg;
    Persona match;
    FILE *f;
   	int terminar = 0, opcion = -1, i = 0, dni_ok = 0,encontrado_activo = 0,encontrado_inactivo = 0,reactivarOpcion = -1, editLoop = 0, opEdit = -1, okDni = 0,op2 = 0, agregado_mem = 0;
    long nuevo = 0;
    size_t rcount = 0, wcount = 0;
    f = NULL;
    memset(&p, 0, sizeof(Persona));
    memset(&reg, 0, sizeof(Persona));
    memset(&match, 0, sizeof(Persona));

	if ((f = fopen(ARCH_PERSONAS, "rb")) != NULL){
	    fclose(f);
	} else {
	    if ((f = fopen(ARCH_PERSONAS, "ab")) != NULL){
	        fclose(f);
	    } else {
	        printf("ERROR: no se pudo abrir el archivo.\n");
	        terminar = 1;
	    }
	}

    if (np == NULL){
        printf("ERROR: puntero a contador (np) nulo.\n");
        terminar = 1;
    }
    if (!terminar && (*np) >= MAX_PERSONAS){
        printf("AVISO: Limite de personas alcanzado (%d).\n", MAX_PERSONAS);
        terminar = 1;
    }

    while (!terminar){
        dni_ok = 0;
        printf("\n=== Registrar Persona ===\n");

        while (!terminar && !dni_ok){
            while (1){
                p.dni = validarLONG("Ingrese DNI: ");
                if (p.dni <= 9999999 || p.dni > 99999999){
                    printf("Error! DNI invalido. Debe tener 8 digitos.\n");
                    continue;
                }
                break;
            }
            
            if ((f = fopen(ARCH_PERSONAS, "rb")) != NULL){
                while ((rcount = fread(&reg, sizeof(Persona), 1, f)) == 1u){
                    if (reg.dni == p.dni){
                        if (reg.status == 1){
                            encontrado_activo = 1;
                            break;
                        } else {
                            encontrado_inactivo = 1;
                            match = reg;
                        }
                    }
                }
                fclose(f);
            } else {
                printf("ERROR: no se pudo abrir el archivo.\n");
                terminar = 1;
            }

            if (terminar == 1)
				 break;

            if (encontrado_activo){
                printf("ERROR: Ya existe una persona ACTIVA con DNI %ld.\n", p.dni);
                printf("1) Intentar con otro DNI\n");
                printf("0) Cancelar\n");
                opcion = validarINT("Opcion: ");
                if (opcion == 0){
                    terminar = 1;
                }
            } else if (encontrado_inactivo){
                printf("Existe una persona con ese DNI pero INACTIVA.\n");
                printf("Nombre guardado: %s\n", match.nombre);
                printf("1) Reactivar\n");
                printf("0) Cancelar\n");
                reactivarOpcion = validarINT("Opcion: ");
                if (reactivarOpcion == 1){
                    if ((f = fopen(ARCH_PERSONAS, "r+b")) != NULL){
                        while ((rcount = fread(&reg, sizeof(Persona), 1, f)) == 1u){
                            if (reg.dni == match.dni && reg.status == 0){
                                reg.status = 1;
                                if (fseek(f, -(long)sizeof(Persona), SEEK_CUR) == 0){
                                    wcount = fwrite(&reg, sizeof(Persona), 1, f);
                                    fflush(f);
                                }
                                break;
                            }
                        }
                        fclose(f);
                        f = NULL;
                    } else {
                        printf("ERROR: no se pudo abrir el archivo.\n");
                        terminar = 1;
                    }

                    if (terminar) break;

                    if (*np < MAX_PERSONAS){
                        personas[*np] = reg;
                        (*np)++;
                        agregado_mem = 1;
                    }
                    printf("Persona reactivada correctamente.\n");
                    terminar = 1;
                } else if (reactivarOpcion == 0){
                } else {
                    printf("Opcion invalida.\n");
                }
            } else {
                dni_ok = 1;
            }
        }

        if (terminar) break;

        validarTXT("Nombre y apellido: ", p.nombre, sizeof(p.nombre));
        p.status = 1;

        while (!terminar){
            printf("\nResumen:\n");
            printf("DNI: %ld\n", p.dni);
            printf("Nombre: %s\n", p.nombre);
            printf("1) Confirmar y guardar\n");
            printf("2) Editar datos\n");
            printf("0) Cancelar\n");
            opcion = validarINT("Opcion: ");

            if (opcion == 1){
                if (guardarPersona(&p)){
                    printf("Persona guardada correctamente.\n");
                    if (*np < MAX_PERSONAS){
                        personas[*np] = p;
                        (*np)++;
                    }
                } else {
                    printf("ERROR: no se pudo guardar la persona.\n");
                }
                terminar = 1;
            }
            else if (opcion == 2){
                editLoop = 1;
                while (editLoop && !terminar){
                    printf("\nEditar:\n");
                    printf("1) DNI\n");
                    printf("2) Nombre\n");
                    printf("9) Volver al resumen\n");
                    printf("0) Cancelar\n");
                    opEdit = validarINT("Opcion: ");

                    if (opEdit == 1){
                        okDni = 0;
                        while (!okDni && !terminar){
                            nuevo = validarLONG("Nuevo DNI: ");
                            if (nuevo <= 9999999 || nuevo > 99999999){
                                printf("Error! DNI invalido. Debe tener 8 digitos.\n");
                                continue;
                            }

                            encontrado_activo = 0;
                            encontrado_inactivo = 0;
                            memset(&match, 0, sizeof(Persona));

                            if ((f = fopen(ARCH_PERSONAS, "rb")) != NULL){
                                while ((rcount = fread(&reg, sizeof(Persona), 1, f)) == 1u){
                                    if (reg.dni == nuevo){
                                        if (reg.status == 1){
                                            encontrado_activo = 1;
                                            break;
                                        } else {
                                            encontrado_inactivo = 1;
                                            match = reg;
                                        }
                                    }
                                }
                                fclose(f);
                                f = NULL;
                            } else {
                                printf("ERROR: no se pudo abrir el archivo.\n");
                                terminar = 1;
                            }

                            if (terminar) break;

                            if (encontrado_activo){
                                printf("Ese DNI ya existe y esta ACTIVO.\n");
                                printf("1) Intentar con otro DNI\n");
                                printf("0) Cancelar cambio\n");
                                op2 = validarINT("Opcion: ");
                                if (op2 == 0){
                                    break;
                                } else {
                                    continue;
                                }
                            } else if (encontrado_inactivo){
                                printf("Ese DNI existe INACTIVO. No se permite editar hacia un DNI reactivable.\n");
                                printf("1) Intentar con otro DNI\n");
                                printf("0) Cancelar cambio\n");
                                op2 = validarINT("Opcion: ");
                                if (op2 == 0){
                                    break;
                                } else {
                                    continue;
                                }
                            } else {
                                p.dni = nuevo;
                                okDni = 1;
                            }
                        }
                    }
                    else if (opEdit == 2){
                        validarTXT("Nuevo nombre: ", p.nombre, sizeof(p.nombre));
                    }
                    else if (opEdit == 9){
                        editLoop = 0;
                    }
                    else if (opEdit == 0){
                        terminar = 1;
                        editLoop = 0;
                    }
                    else{
                        printf("Opcion invalida.\n");
                    }
                }
            }
            else if (opcion == 0){
                terminar = 1;
            }
            else{
                printf("Opcion invalida.\n");
            }
        }
    }

    return;
}

	int guardarPersona(Persona *p){
    int ok = 0;
    if (p != NULL){
        FILE *f = fopen(ARCH_PERSONAS,"rb");
        Persona tmp;
        if (f){
            while (fread(&tmp,sizeof(Persona),1,f)==1){
                if (tmp.status==1 && tmp.dni==p->dni){
                    printf("ERROR: DNI %ld ya existe.\n", p->dni);
                    fclose(f);
                   	ok = 0; 
                }
            }
            fclose(f);
        }
        f = fopen(ARCH_PERSONAS,"ab");
        if (f){
            ok = (fwrite(p,sizeof(Persona),1,f)==1);
            fclose(f);
        } else {
            printf("ERROR: no se pudo abrir %s.\n", ARCH_PERSONAS);
        }
    }
    return ok;
}
	
	int leerTodasPersonasStatic(Persona personas[], int max){
	    int n = 0;
	    FILE *f = NULL;
	    Persona tmp;
	    if ((f = fopen(ARCH_PERSONAS, "rb")) != NULL){
	        while (n < max && fread(&tmp, sizeof(Persona), 1, f) == 1){
	            if (tmp.status == 1){
	                personas[n] = tmp;
	                n++;
	            }
	        }
	        fclose(f);
	    }
	    return n; 
	}
	
	int seleccionarPersonaUI(Persona *out){
    Persona personas[MAX_PERSONAS];
    int np = 0;
    int num;
    long dni_busca;
    int exito = 0;
    int terminar = 0;
    int opcion = -1;
    int i, idx;

    if (out == NULL){
        terminar = 1;
    }

    if (!terminar){
        np = leerTodasPersonasStatic(personas, MAX_PERSONAS);
    }

    while (!terminar){
        if (np <= 0){
            printf("\nNo hay personas registradas.\n");
            printf("1) Registrar una persona ahora\n");
            printf("0) Cancelar\n");
            opcion = validarINT("Opcion: ");
            switch(opcion){
                case 1:
                    registrarPersonaUI(personas, &np);
                    np = leerTodasPersonasStatic(personas, MAX_PERSONAS);
                    break;
                case 0:
                    terminar = 1;
                    break;
                default:
                    printf("Opcion invalida.\n");
                    break;
            }
        } else {
            printf("\n-- PERSONAS REGISTRADAS --\n");
            for (i = 0; i < np; i++){
                printf("%2d) DNI:%ld | %s\n", i+1, personas[i].dni, personas[i].nombre);
            }
            printf("0) Cancelar\n");
            printf("\nOpciones:\n");
            printf(" 1) Seleccionar por numero de la lista\n");
            printf(" 2) Buscar por DNI\n");
            printf(" 3) Registrar NUEVA persona\n");

            opcion = validarINT("Opcion: ");
            switch(opcion){
                case 0:
                    terminar = 1;
                    break;

                case 1:
                    num = validarINT("Seleccionar numero: ");
                    if (num >= 1 && num <= np){
                        *out = personas[num - 1];
                        exito = 1;
                        terminar = 1;
                    } else {
                        printf("Opcion fuera de rango.\n");
                    }
                    break;

                case 2:
                    dni_busca = validarLONG("Ingresar DNI: ");
                    idx = -1;
                    for (i = 0; i < np; i++){
                        if (personas[i].dni == dni_busca){
                            idx = i;
                            break;
                        }
                    }
                    if (idx != -1){
                        *out = personas[idx];   
                        exito = 1;
                        terminar = 1;
                    } else {
                        printf("No se encontro una persona con ese DNI.\n");
                    }
                    break;

                case 3:
                    registrarPersonaUI(personas, &np);
                    np = leerTodasPersonasStatic(personas, MAX_PERSONAS);
                    break;

                default:
                    printf("Opcion invalida.\n");
                    break; 
            }
        }
    }

    return exito;
}

void listarPersonasUI(){ 
	system ("cls");
    Persona vec[MAX_PERSONAS];
    int i, np = leerTodasPersonasStatic(vec, MAX_PERSONAS);
    if (np == 0){
        printf("No hay personas registradas.\n");
    } else {
        printf("\n-- PERSONAS --\n");
        for (i = 0; i < np; i++){
            if (vec[i].status == 1){
                printf("%d) DNI:%ld | %s\n", i+1, vec[i].dni, vec[i].nombre);
            } else {
                printf("%d) Persona eliminada\n", i+1);
            }
        }
    }
}
	
	int personaGastoActivo(long dni){
    FILE *fg = NULL;
    Gasto g;
    int pend = 0;   
    int fin = 0;
    int rpag = 0;
	
	if ((fg = fopen(ARCH_GASTOS, "rb")) != NULL){
		while (fread(&g, sizeof(Gasto), 1, fg) == 1){
            if ((*(&g)).status == 1 && (*(&g)).persona.dni == dni){
                if ((*(&g)).cuotasTotales > 0){
                    if ((*(&g)).cuotasPagadas < (*(&g)).cuotasTotales){
                        pend = 1;
                        break;
                    }
                } else {
                    rpag = pagoActivo((*(&g)).codigo);
                    if (rpag == 0){
                        pend = 1;
                        break;
                    } else if (rpag < 0){
                        pend = 1; 
                        break;
                    }
                }
            }
        }
        fclose(fg);
	}else {
        pend = -1;
         printf("Error: No se pudo abrir '%s'.\n", ARCH_GASTOS);
	}
    return pend;
}

	void eliminarPersonaUI(Persona personas[], int *np){
	system ("cls");	
    FILE *f = NULL;
    Persona per;
    long dni = 0;
    int hecho = 0;
    long back = 0;
    int tienePendientes = 0;

    Gasto gastos[MAX_GASTOS];
    int ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
    int i;

    listarPersonasUI();

    dni = validarLONG("\nDNI de la persona a eliminar: ");

    
    tienePendientes=personaGastoActivo(dni) == 1 ? 1 : 0;
    if (tienePendientes){
        printf("ERROR: La persona %ld tiene gastos PENDIENTES. No puede eliminarse.\n", dni);
    }

    if (!tienePendientes){
        if ((f = fopen(ARCH_PERSONAS, "r+b")) != NULL){
            while (fread(&per, sizeof(Persona), 1, f) == 1){
                if (per.dni == dni){
                    if (per.status == 0){
                        printf("Aviso: La persona ya estaba desactivada.\n");
                    } else {
                        per.status = 0;
                        back = -(long)sizeof(Persona);
                        if (fseek(f, back, SEEK_CUR) == 0 && fwrite(&per, sizeof(Persona), 1, f) == 1){
                            printf("OK: Persona desactivada (soft delete).\n");
                            hecho = 1;
                            fflush(f); 
                        } else {
                            printf("Error: No se pudo escribir el registro.\n");
                        }
                    }
                    break;
                }
            }
            fclose(f);
            if (!hecho && per.dni != dni){
                printf("No se encontro persona con DNI %ld.\n", dni);
            }
        } else {
            printf("Error: No se pudo abrir '%s'.\n", ARCH_PERSONAS);
        }
    }


    if (np != NULL){
        *np = leerTodasPersonasStatic(personas, MAX_PERSONAS);
    }

    return; 
}

int personaActiva(long dni, int *status){
    FILE *f;
    Persona reg;
    size_t r;
    int exito;

    exito = 0;

    if ((f = fopen(ARCH_PERSONAS, "rb")) != NULL){
        while ((r = fread(&reg, sizeof(Persona), 1, f)) == 1u){
            if (reg.dni == dni){
                if (status) *status = reg.status;
                exito = 1;
                break;
            }
        }
        fclose(f);
    } else {
        printf("ERROR: no se pudo abrir el archivo.\n");
        exito = -1;
    }

    return exito;
}

// ----------------------------------------------------------------------
//							CONSULTAS 
// ----------------------------------------------------------------------

void consultarGastosPorCategoriaStatic(Categoria categorias[], int nc){
	system ("cls");
    int finalizado = 0;
    char cat[30], catNorm[30];
    Gasto gastos[MAX_GASTOS];
    int ng = 0;
    int found = 0;

    int i, st, r;
    int catActiva;
    float montoMostrado = 0.0f;

    validarTXT("Ingrese categoria a filtrar (exacto): ", cat, sizeof(cat));


    strncpy(catNorm, cat, sizeof(catNorm)-1);
    catNorm[sizeof(catNorm)-1] = '\0';
    normalizarTexto(catNorm);

    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
    if (ng == 0){
        printf("No hay gastos.\n");
        finalizado = 1;
    }

    if (finalizado == 0){
        printf("\nGastos en categoria '%s':\n", cat);

        for (i = 0; i < ng; i++){
            char nombreCat[30];
            char catGastoComparar[30];
            if (gastos[i].categoria[0] == '\0'){
                strncpy(nombreCat, "SIN CATEGORIA", sizeof(nombreCat)-1);
                nombreCat[sizeof(nombreCat)-1] = '\0';
            } else {
                catActiva = esCategoriaActiva(categorias, nc, gastos[i].categoria);
                if (catActiva){
                    int k, foundMatch = 0;
                    for (k = 0; k < nc; k++){
                        char a[30], b[30];
                        strncpy(a, categorias[k].nombre, sizeof(a)-1); a[sizeof(a)-1] = '\0'; normalizarTexto(a);
                        strncpy(b, gastos[i].categoria, sizeof(b)-1);   b[sizeof(b)-1]   = '\0'; normalizarTexto(b);
                        if (strcmp(a, b) == 0){
                            strncpy(nombreCat, categorias[k].nombre, sizeof(nombreCat)-1);
                            nombreCat[sizeof(nombreCat)-1] = '\0';
                            foundMatch = 1;
                            break;
                        }
                    }
                    if (!foundMatch){
                        strncpy(nombreCat, gastos[i].categoria, sizeof(nombreCat)-1);
                        nombreCat[sizeof(nombreCat)-1] = '\0';
                    }
                } else {
                    strncpy(nombreCat, "SIN CATEGORIA", sizeof(nombreCat)-1);
                    nombreCat[sizeof(nombreCat)-1] = '\0';
                }
            }
            strncpy(catGastoComparar, nombreCat, sizeof(catGastoComparar)-1);
            catGastoComparar[sizeof(catGastoComparar)-1] = '\0';
            normalizarTexto(catGastoComparar);

            if (strcmp(catGastoComparar, catNorm) == 0){
                found = 1;
                montoMostrado = gastos[i].monto;
                if (gastos[i].cuotasTotales > 1){
                    montoMostrado = gastos[i].monto / (float)gastos[i].cuotasTotales;
                }

                printf("Codigo:%d | Tipo:%s | %s | $%.2f | ",
                       gastos[i].codigo, gastos[i].tipo, gastos[i].descripcion, montoMostrado);
                printf("%s | ", nombreCat);
                imprimirFecha(gastos[i].fecha);

                if (gastos[i].cuotasTotales > 1){
                    printf(" | Cuotas: %d/%d", gastos[i].cuotasPagadas, gastos[i].cuotasTotales);
                }
                st = gastos[i].persona.status;
                r  = personaActiva(gastos[i].persona.dni, &st);
                if (r == 1 && st == 1){
                    printf(" | DNI: %ld", gastos[i].persona.dni);
                    printf(" | Nombre: %s", gastos[i].persona.nombre);
                } else if (r == 1 && st == 0){
                    printf(" | Persona eliminada");
                }
                printf("\n");
            }
        }

        if (!found){
            printf("No se encontraron gastos para esa categoria.\n");
        }
    }

    return;
}



// muestra SOLO los gastos del tipo elegido 
void consultaGastosPorTipo(Categoria categorias[], int nc){
	system ("cls");
    int finalizado = 0;
    int op = 0;
    const char *tipoFiltro = NULL;

    Gasto gastos[MAX_GASTOS];
    int ng = 0;

    int i, st, r;
    int found = 0;
    const char *nombreCat = NULL;
    float montoMostrado = 0.0f;

    while (1){
        printf("\n--- Filtrar gastos por TIPO ---\n");
        printf("1) FIJO\n");
        printf("2) OCASIONAL\n");
        printf("3) TEMPORAL (en cuotas)\n");
        printf("4) ANUAL\n");
        op = validarINT("Opcion (1-4): ");
        if (op >= 1 && op <= 4) break;
        printf("Opcion invalida. Intente nuevamente.\n");
    }

    switch (op){
        case 1: tipoFiltro = "FIJO";      break;
        case 2: tipoFiltro = "OCASIONAL"; break;
        case 3: tipoFiltro = "TEMPORAL";  break;
        default:tipoFiltro = "ANUAL";     break;
    }

    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
    if (ng == 0){
        printf("No hay gastos.\n");
        finalizado = 1;
    }

    if (finalizado == 0){
        printf("\nGastos del tipo '%s':\n", tipoFiltro);
        ordenarGastosPorFechaStatic(gastos, ng);

        for (i = 0; i < ng; i++){
            if (strcmp(gastos[i].tipo, tipoFiltro) != 0) continue;

            found = 1;

            if (esCategoriaActiva(categorias, nc, gastos[i].categoria))
                nombreCat = gastos[i].categoria;
            else
                nombreCat = "SIN CATEGORIA";

            montoMostrado = gastos[i].monto;
            if (gastos[i].cuotasTotales > 1){
                montoMostrado = gastos[i].monto / (float)gastos[i].cuotasTotales;
            }

            printf("Codigo:%d | Tipo:%s | %s | $%.2f | %s | ",
                   gastos[i].codigo,
                   gastos[i].tipo,
                   gastos[i].descripcion,
                   montoMostrado,
                   nombreCat);

            imprimirFecha(gastos[i].fecha);

            if (gastos[i].cuotasTotales > 1){
                printf(" | Cuota: %d/%d (Pagadas:%d)",
                       gastos[i].cuotaActual,
                       gastos[i].cuotasTotales,
                       gastos[i].cuotasPagadas);
            } else {
                printf(" | (Pago unico)");
            }

            st = gastos[i].persona.status;
            r  = personaActiva(gastos[i].persona.dni, &st);
            if (r == 1 && st == 1){
                printf(" | DNI:%ld | Nombre:%s", gastos[i].persona.dni, gastos[i].persona.nombre);
            } else if (r == 1 && st == 0){
                printf(" | Persona eliminada");
            }
            printf("\n");
        }

        if (!found){
            printf("No se encontraron gastos del tipo seleccionado.\n");
        }
    }

    return; /* single return */
}



	
void consultarGastosPorMesAnioStatic(Categoria categorias[], int nc) {
		system ("cls");
	    int finalizado = 0;
	    int mes = 0, anio = 0;
	    Gasto gastos[MAX_GASTOS];
	    int ng = 0;
	    int found = 0;
	    int i,st,r;
	    const char* nombreCat;
        
        float montoMostrado = 0.0f;
	
	    while (1) {
	        mes = validarINT("Ingrese mes (1-12): ");
	        if (mes >= 1 && mes <= 12) break;
	        printf("Mes invalido. Intente nuevamente.\n");
	    }
	
	    while (1) {
	        anio = validarINT("Ingrese anio (2020-2025): ");
	        if (anio >= 2020 && anio <= 2025) break;
	        printf("Anio invalido. Intente nuevamente.\n");
	    }
	
	    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
	
	    if (ng == 0) {
	        printf("No hay gastos.\n");
	        finalizado = 1;
	    }
	
	    if (finalizado == 0) {
	        printf("\nGastos en %02d/%04d:\n", mes, anio);
	        for (i = 0; i < ng; i++) {
	            if (gastos[i].fecha.mes == mes && gastos[i].fecha.anio == anio) {
	                found = 1;
	                st = gastos[i].persona.status;
	                r = personaActiva(gastos[i].persona.dni, &st);
	                nombreCat = gastos[i].categoria;
	                if (!esCategoriaActiva(categorias, nc, gastos[i].categoria)) {
	                    nombreCat = "SIN CATEGORIA";
	                }
	
                    montoMostrado = gastos[i].monto;
                    if (gastos[i].cuotasTotales > 1) {
                        montoMostrado = gastos[i].monto / (float)gastos[i].cuotasTotales;
                    }
                    
	                printf("Codigo:%d | Tipo:%s | %s | $%.2f | %s | ",
	                       gastos[i].codigo, gastos[i].tipo, gastos[i].descripcion, montoMostrado, nombreCat);

	                imprimirFecha(gastos[i].fecha);
	
	                if (gastos[i].cuotasTotales > 1) 
	                    printf(" | Cuotas: %d/%d", gastos[i].cuotasPagadas, gastos[i].cuotasTotales);
	                if(r == 1 && st == 1){
	                	printf(" | DNI: %ld\n", gastos[i].persona.dni);
	                	printf(" | Nombre: %s\n", gastos[i].persona.nombre);
					}else{
						if(r == 1 && st == 0){
							printf(" | Persona eliminada");
						}
					}
	            }
	        }
	        if (!found) printf("No se encontraron gastos en ese mes/anio.\n");
	    }
	
	    return; 
}

	
void consultarIngresosPorPersonaStatic() { 
	system ("cls");
    int finalizado = 0; 
    Persona sel;
    int ok = 0;
    Ingreso ingresos[MAX_INGRESOS]; 
    int ni = 0; 
    int found = 0; 
    int i; 
    int st = 1; 
    int r = 0; 

    ok = seleccionarPersonaUI(&sel);
    if (ok != 1){
        printf("No se selecciono una persona valida.\n");
        finalizado = 1;
    }

    if (!finalizado){
        r = personaActiva(sel.dni, &st);
        if (r == 1 && st == 0){
            printf("No se pueden mostrar ingresos: la persona fue eliminada.\n");
            finalizado = 1;
        } else if (r == -1){
            printf("No se pueden mostrar ingresos: error al leer personas.\n");
            finalizado = 1;
        }
    }

    if (!finalizado){
        ni = leerTodosIngresosStatic(ingresos, MAX_INGRESOS); 
        if (ni == 0) { 
            printf("No hay ingresos.\n"); 
            finalizado = 1; 
        }
    }

    if (!finalizado){
        for (i = 0; i < ni; i++){ 
            if (ingresos[i].persona.dni == sel.dni){ 
                found = 1; 
                printf("Concepto:%s | $%.2f | ", ingresos[i].concepto, ingresos[i].monto); 
                imprimirFecha(ingresos[i].fecha); 
                printf("\n"); 
            } 
        } 
        if (!found){
            printf("No se encontraron ingresos para esa persona.\n");
        }
    }
}

void consultarSaldoMensualStatic() {
		system ("cls");
	    int finalizado = 0;
	    int mes = 0, anio = 0;
	    Gasto gastos[MAX_GASTOS];
	    int ng = 0;
	    Ingreso ingresos[MAX_INGRESOS];
	    int ni = 0;
	    float sumG, sumI;
	
	    while (1) {
	        mes = validarINT("Ingrese mes (1-12): ");
	        if (mes >= 1 && mes <= 12) break;
	        printf("Mes invalido. Intente nuevamente.\n");
	    }
	
	    while (1) {
	        anio = validarINT("Ingrese anio (2020-2025): ");
	        if (anio >= 2020 && anio <= 2025) break;
	        printf("Anio invalido. Intente nuevamente.\n");
	    }
	
	    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
	    ni = leerTodosIngresosStatic(ingresos, MAX_INGRESOS);
	
	    if (ng == 0 && ni == 0) {
	        printf("No hay datos para calcular el saldo.\n");
	        finalizado = 1;
	    }
	
	    if (finalizado == 0) {
	        sumG = sumarTotalMesAnio(1, gastos, ng, mes, anio);
	        sumI = sumarTotalMesAnio(2, ingresos, ni, mes, anio);
	
	        printf("\nSaldo %02d/%04d:\n", mes, anio);
	        printf("Total de Ingresos: $%.2f\n", sumI);
	        printf("Total de Gastos:   $%.2f\n", sumG);
	        printf("Saldo Neto:        $%.2f\n", sumI - sumG);
	    }
	
	    return; 
}



	
void consultarGastosPendientesStatic(Categoria categorias[], int nc) { 
	system ("cls");
    int finalizado = 0;
    Gasto gastos[MAX_GASTOS];
    int ng = 0;
    int found = 0;
    int i, r;
    int status;
    float montoMostrado = 0.0f;
    const char *nombreCat; 

    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
    if (ng == 0) {
        printf("No hay gastos.\n");
        finalizado = 1;
    }

    if (finalizado == 0) {
        printf("\nGastos con cuotas pendientes:\n");
        for (i = 0; i < ng; i++){
            if (gastos[i].cuotasPagadas < gastos[i].cuotasTotales) {
                found = 1;

                if (esCategoriaActiva(categorias, nc, gastos[i].categoria))
                    nombreCat = gastos[i].categoria;
                else
                    nombreCat = "SIN CATEGORIA";

                montoMostrado = gastos[i].monto;
                if (gastos[i].cuotasTotales > 1)
                    montoMostrado = gastos[i].monto / (float)gastos[i].cuotasTotales;

                printf("Codigo:%d | Tipo:%s | %s | $%.2f | %s | ",
                       gastos[i].codigo, gastos[i].tipo, gastos[i].descripcion, montoMostrado, nombreCat);

                imprimirFecha(gastos[i].fecha);

                if (gastos[i].cuotasTotales > 1)
                    printf(" | Cuota: %d/%d (Pagadas: %d)",
                           gastos[i].cuotaActual, gastos[i].cuotasTotales, gastos[i].cuotasPagadas);

                status = 0; 
                r = personaActiva(gastos[i].persona.dni, &status);
                if (r == 1 && status == 1) {
                    printf(" | Nombre %s", gastos[i].persona.nombre);
                    printf(" | DNI %ld", gastos[i].persona.dni);
                } else {
                    printf(" | Persona inactiva/eliminada");
                }
                printf("\n");
            }
        }
        if (!found) printf("No se encontraron gastos con cuotas pendientes.\n");
    }
    return; 
}



void consultarPagosPorMedioStatic() {
		system ("cls");
	    int finalizado = 0;
	    char medio[20], medioNorm[20];
	    Pago pagos[MAX_PAGOS]; 
	    int np = 0;
	    int found = 0;
        int i; 
        char m[20];
	
	    printf("Medios validos: Efectivo / Debito / Credito / Transferencia\n");
	    validarTXT("Ingrese medio de pago: ", medio, sizeof(medio));
	    strncpy(medioNorm, medio, sizeof(medioNorm)-1);
	    medioNorm[sizeof(medioNorm)-1] = '\0';
	    normalizarTexto(medioNorm);
	
	    np = leerTodosPagosStatic(pagos, MAX_PAGOS);

	    if (np == 0) {
	        printf("No hay pagos.\n");
	        finalizado = 1;
	    }
	
	    if (finalizado == 0) {
	        printf("\nPagos por medio '%s':\n", medio);
	        for (i = 0; i < np; i++){ 
	            strncpy(m, pagos[i].medio, sizeof(m)-1);
	            m[sizeof(m)-1] = '\0';
	            normalizarTexto(m);
	
	            if (strcmp(m, medioNorm) == 0) {
	                found = 1;
	                printf("GastoCodigo:%d | Medio:%s | $%.2f | ",
	                       pagos[i].gastoCodigo, pagos[i].medio, pagos[i].importe);
	                imprimirFecha(pagos[i].fecha);
	                printf("\n");
	            }
	        }
	        if (!found) printf("No se encontraron pagos con ese medio.\n");
	    }
	
	    return; 
}

	
void consultarGastosConSaldoIncompletoStatic(Categoria categorias[], int nc) {
		system ("cls");
	    int finalizado = 0;
	    Gasto gastos[MAX_GASTOS];
	    int ng = 0;
	    int found = 0;
	    int i, st, r;
        
        float montoMostrado = 0.0f;
        const char *nombreCat;
	
	    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
	
	    if (ng == 0) {
	        printf("No hay gastos.\n");
	        finalizado = 1;
	    }
	
	    if (finalizado == 0) {
	        printf("\nGastos con saldo incompleto (cuotas pagadas > 0 pero < totales):\n");
	        for (i = 0; i < ng; i++){
	            if (gastos[i].cuotasTotales > 1 && 
	                gastos[i].cuotasPagadas > 0 && 
	                gastos[i].cuotasPagadas < gastos[i].cuotasTotales){
	                found = 1;

                    montoMostrado = gastos[i].monto;
                    if (gastos[i].cuotasTotales > 1) {
                        montoMostrado = gastos[i].monto / (float)gastos[i].cuotasTotales;
                    }

                    
                    if (!esCategoriaActiva(categorias, nc, gastos[i].categoria)) {
                        nombreCat = "SIN CATEGORIA";
                    } else {
                        nombreCat = gastos[i].categoria;
                    }

	                printf("Codigo:%d | Tipo:%s | %s | $%.2f | %s | ",
	                       gastos[i].codigo, gastos[i].tipo, gastos[i].descripcion, montoMostrado, nombreCat);

	                imprimirFecha(gastos[i].fecha);
	                
	                printf(" | Cuota: %d/%d (Pagadas: %d)", gastos[i].cuotaActual, gastos[i].cuotasTotales, gastos[i].cuotasPagadas);
	                
	               
	                st = gastos[i].persona.status;
	                r = personaActiva(gastos[i].persona.dni, &st); 
	                if(r == 1 && st == 1){
	                 	printf(" | DNI: %ld\n", gastos[i].persona.dni);
	                    printf(" | Nombre: %s\n", gastos[i].persona.nombre);	
					}else{
						if(r == 1 && st == 0){
							printf(" | Persona eliminada\n");
						}
					}
	                   
	                }
	            }
	        }
	    if (!found) printf("No se encontraron gastos con saldo incompleto.\n");
}

	    


	
void top3CategoriasCostosasStatic(Categoria categorias[], int nc) {
	system ("cls");
    int finalizado = 0;
    Gasto gastos[MAX_GASTOS];
    int ng = 0;
    int i, j;
    time_t t;
    struct tm *ptm;
    int mesActual, anioActual;
    
    typedef struct {
        char nombre[30];
        float total;
    } CatTotal;
    
    CatTotal totales[MAX_CATEGORIAS];
    int numTotales = 0;
    int idx;
    int hayActivas = 0; 
    int puedeMostrar = 1; 

    t = time(NULL);
    ptm = localtime(&t);
    mesActual = (*ptm).tm_mon + 1;
    anioActual = (*ptm).tm_year + 1900;

    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);

    if (ng == 0) {
        printf("No hay gastos para analizar.\n");
        finalizado = 1;
    }

    if (finalizado == 0) {
        for (i = 0; i < nc; i++) {
            strncpy(totales[i].nombre, categorias[i].nombre, sizeof(totales[i].nombre) - 1);
            totales[i].nombre[sizeof(totales[i].nombre) - 1] = '\0';
            totales[i].total = 0.0f;
        }
        numTotales = nc;

        for (i = 0; i < ng; i++) {
            if (gastos[i].fecha.mes == mesActual && gastos[i].fecha.anio == anioActual) {

 
                if (!esCategoriaActiva(categorias, nc, gastos[i].categoria)) {
                    continue;
                }
                hayActivas = 1;


                idx = -1;
                for (j = 0; j < numTotales; j++) {
                    if (strcmp(gastos[i].categoria, totales[j].nombre) == 0) {
                        idx = j;
                        break;
                    }
                }

                if (idx != -1) {
                    if (gastos[i].cuotasTotales > 1)
                        totales[idx].total += (gastos[i].monto / gastos[i].cuotasTotales);
                    else
                        totales[idx].total += gastos[i].monto;
                }
            }
        }

        
        if (!hayActivas) {
            printf("No se puede calcular el Top 3: no hay categorias activas con gastos en el mes.\n");
            puedeMostrar = 0;
        }
        

        if (puedeMostrar) {
            for (i = 0; i < numTotales - 1; i++) {
                for (j = i + 1; j < numTotales; j++) {
                    if (totales[i].total < totales[j].total) {
                        CatTotal temp = totales[i];
                        totales[i] = totales[j];
                        totales[j] = temp;
                    }
                }
            }
            printf("\n--- Top 3 Categorias mas costosas (%02d/%04d) ---\n", mesActual, anioActual);
            int found = 0; 

            for (i = 0; i < numTotales && i < 3; i++) {
                if (totales[i].total > 0.0f) {
                    found = 1;
                    printf("%d. %s: $%.2f\n", i + 1, totales[i].nombre, totales[i].total);
                }
            }
            if (!found)
                printf("No se registraron gastos en el mes de %02d/%04d.\n", mesActual, anioActual);
        }
    }
    return; 
}



void proyeccionMensualStatic(Categoria categorias[], int nc) {
		system ("cls");
        int finalizado = 0;
        Gasto gastos[MAX_GASTOS];
        int ng = 0;
        int i, j;
        time_t t;
        
 
        struct tm *ptm; 
        
        int mesActual, anioActual;
        float totalProyectado = 0.0f;
        float totalCuotas = 0.0f;
        float totalFijos = 0.0f;

        t = time(NULL);
        ptm = localtime(&t); 
        
 

        mesActual = (*ptm).tm_mon + 1;
        

        anioActual = (*ptm).tm_year + 1900;

        ng = leerTodosGastosStatic(gastos, MAX_GASTOS);

        if (ng == 0) {
            printf("No hay gastos para proyectar.\n");
            finalizado = 1;
        }

        if (finalizado == 0) {
            for (i = 0; i < ng; i++) {
                if ((strcmp(gastos[i].tipo, "FIJO") == 0 || strcmp(gastos[i].tipo, "ANUAL") == 0) &&
                    gastos[i].fecha.mes == mesActual && gastos[i].fecha.anio == anioActual) 
                {
                    totalFijos += gastos[i].monto;
                }

                if (strcmp(gastos[i].tipo, "TEMPORAL") == 0 &&
                    gastos[i].fecha.mes == mesActual && gastos[i].fecha.anio == anioActual) 
                {
                    if (gastos[i].cuotasTotales > 0) {
                        totalCuotas += (gastos[i].monto / (float)gastos[i].cuotasTotales);
                    }
                }
            }

            totalProyectado = totalFijos + totalCuotas;

            printf("\n--- Proyeccion Mensual de Gastos (%02d/%04d) ---\n", mesActual, anioActual);
            printf("Gastos Fijos y Anuales Proyectados: $%.2f\n", totalFijos);
            printf("Gastos en Cuotas (Temporales) Proyectados: $%.2f\n", totalCuotas);
            printf("Total Proyectado (Gastos Fijos + Cuotas): $%.2f\n", totalProyectado);
            printf("\nNOTA: La proyeccion no incluye gastos OCASIONALES o TEMPORALES no registrados para este mes.\n");
        }
        return; 
    }
	
	void resumenGeneralStatic(Categoria categorias[], int nc) {
		system ("cls");
	    int finalizado = 0;
	    Gasto gastos[MAX_GASTOS];
	    int ng = 0;
	    Ingreso ingresos[MAX_INGRESOS];
	    int ni = 0;
	    float totalGastoHistorico = 0.0f;
	    float totalIngresoHistorico = 0.0f;
	    int i;
	    
	    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
	    ni = leerTodosIngresosStatic(ingresos, MAX_INGRESOS);
	
	    if (ng == 0 && ni == 0) {
	        printf("No hay datos historicos.\n");
	        finalizado = 1;
	    }
	
	    if (finalizado == 0) {
	        
	        for (i = 0; i < ng; i++) {
                if (gastos[i].cuotasTotales > 1) {
	                totalGastoHistorico += (gastos[i].monto / (float)gastos[i].cuotasTotales);
	            } else {
	                totalGastoHistorico += gastos[i].monto;
	            }
	        }
	        
	        for (i = 0; i < ni; i++) {
	            totalIngresoHistorico += ingresos[i].monto;
	        }
	        
	        printf("\n--- Resumen General Historico ---\n");
	        printf("Total de Ingresos Registrados: $%.2f\n", totalIngresoHistorico);
	        printf("Total de Gastos Registrados:   $%.2f\n", totalGastoHistorico);
	        printf("Saldo Neto Historico:          $%.2f\n", totalIngresoHistorico - totalGastoHistorico);
	    }
	    
	    return; 
	}
	
// ----------------------------------------------------------------------
//							CATEGORIAS
// ----------------------------------------------------------------------

	int cargarCategoriasStatic(Categoria categorias[], int max){
	    int cnt = 0;
	    FILE *f;
	    long size;
	
	    if ((f = fopen(ARCH_CATEGORIAS, "rb")) != NULL) {
	        fseek(f, 0, SEEK_END);
	        size = ftell(f);
	        cnt = (int)(size / sizeof(Categoria));
	        
	        if (cnt <= 0) {
	            cnt = crearCategoriasPorDefecto(categorias, max);
	        } else {
	            if (cnt > max) cnt = max;
	            rewind(f);
	            fread(categorias, sizeof(Categoria), cnt, f);
	        }
	        fclose(f);
	    } else {
	        cnt = crearCategoriasPorDefecto(categorias, max);
	    }
	    return cnt; 
	}
	
	int crearCategoriasPorDefecto(Categoria categorias[], int max) {
	    int cnt = 0;
	    Categoria c;
	    
	    if (max >= 6) {
	        c.codigo = 1; strncpy(c.nombre, "VIVIENDA", sizeof(c.nombre)); c.nombre[sizeof(c.nombre)-1] = '\0';
	        if (guardarCategoriaStatic(categorias, &cnt, c)) cnt++;
	
	        c.codigo = 2; strncpy(c.nombre, "SALUD", sizeof(c.nombre)); c.nombre[sizeof(c.nombre)-1] = '\0';
	        if (guardarCategoriaStatic(categorias, &cnt, c)) cnt++;
	        
	        c.codigo = 3; strncpy(c.nombre, "EDUCACION", sizeof(c.nombre)); c.nombre[sizeof(c.nombre)-1] = '\0';
	        if (guardarCategoriaStatic(categorias, &cnt, c)) cnt++;
	
	        c.codigo = 4; strncpy(c.nombre, "ENTRETENIMIENTO", sizeof(c.nombre)); c.nombre[sizeof(c.nombre)-1] = '\0';
	        if (guardarCategoriaStatic(categorias, &cnt, c)) cnt++;
	
	        c.codigo = 5; strncpy(c.nombre, "TRANSPORTE", sizeof(c.nombre)); c.nombre[sizeof(c.nombre)-1] = '\0';
	        if (guardarCategoriaStatic(categorias, &cnt, c)) cnt++;
	        
	        c.codigo = 6; strncpy(c.nombre, "SIN CATEGORIA", sizeof(c.nombre)); c.nombre[sizeof(c.nombre)-1] = '\0';
	        if (guardarCategoriaStatic(categorias, &cnt, c)) cnt++;
	    }
	    
	    if (cnt > 0) {
	        cnt = cargarCategoriasStatic(categorias, max);
	    }
	    
	    return cnt;
	}

	int guardarCategoriaStatic(Categoria categorias[], int *nc, Categoria c){
	    int exito = 0;
	    FILE *f;
	    
	    if ((*nc) < MAX_CATEGORIAS) {
	        if ((f = fopen(ARCH_CATEGORIAS, "ab")) != NULL) {
	            if (fwrite(&c, sizeof(Categoria), 1, f) == 1) {
	                exito = 1;
	                categorias[*nc] = c;
	                (*nc)++;
	            } else {
	                printf("ERROR: Fallo al escribir en el archivo de categorias.\n");
	            }
	            fclose(f);
	        } else {
	            printf("ERROR al abrir el archivo %s para escritura.\n", ARCH_CATEGORIAS);
	        }
	    } else {
	        printf("ADVERTENCIA: Limite de categorias alcanzado (%d).\n", MAX_CATEGORIAS);
	    }
	    return exito; 
	}
	
	int existeCategoriaStatic(Categoria categorias[], int nc, char *nombre){
	    int i;
	    char nomNorm[30], nomCat[30];
	    
	    strncpy(nomNorm, nombre, sizeof(nomNorm)-1);
	    nomNorm[sizeof(nomNorm)-1] = '\0';
	    normalizarTexto(nomNorm);
	    
	    for (i = 0; i < nc; i++) {
	        strncpy(nomCat, categorias[i].nombre, sizeof(nomCat)-1);
	        nomCat[sizeof(nomCat)-1] = '\0';
	        normalizarTexto(nomCat);
	        
	        if (strcmp(nomCat, nomNorm) == 0) return 1;
	    }
	    return 0; 
	}

	void mostrarCategoriasStatic(Categoria categorias[], int nc){
		system ("cls");
	    int i;
	    int found = 0;
	    
	    if (nc == 0) {
	        printf("No hay categorias registradas.\n");
	    } else {
	        printf("\n--- CATEGORIAS ---\n");
	        for (i = 0; i < nc; i++){
	            if (strcmp(categorias[i].nombre, "SIN CATEGORIA") != 0 && strcmp(categorias[i].nombre, "CATEGORIA ELIMINADA") != 0) {
	                printf("Codigo:%d | Nombre:%s\n", categorias[i].codigo, categorias[i].nombre);
	                found = 1;
	            }
	        }
	        if (!found) printf("No hay categorias definidas por el usuario.\n");
	    }
	    return; 
	}
	
	void agregarCategoriaUI(Categoria categorias[], int *nc) {
		system ("cls");
    	Categoria c;
    	int ultimoCodigo = 0;
    	int i;
    	char nombre[30];
    	int puedeContinuar = 1; 


    	if ((*nc) >= MAX_CATEGORIAS) {
        	printf("ERROR: Limite maximo de categorias alcanzado (%d).\n", MAX_CATEGORIAS);
        	puedeContinuar = 0; 
    	}

    	if (puedeContinuar) {

        	for (i = 0; i < (*nc); i++) {
            	if (categorias[i].codigo > ultimoCodigo) {
                ultimoCodigo = categorias[i].codigo;
            	}
        	}
        	c.codigo = ultimoCodigo + 1;
        
        while (1) {
            validarTXT("Ingrese nuevo nombre de categoria: ", nombre, sizeof(nombre));
            
            if (existeCategoriaStatic(categorias, *nc, nombre)) {
                printf("ERROR: La categoria '%s' ya existe. Intente con otro nombre.\n", nombre);
            } else {
                strncpy(c.nombre, nombre, sizeof(c.nombre) - 1);
                c.nombre[sizeof(c.nombre) - 1] = '\0';
                break;
            }
        }
        
        if (guardarCategoriaStatic(categorias, nc, c)) {
            printf("Categoria '%s' (Codigo %d) guardada correctamente.\n", c.nombre, c.codigo);
        } else {
            printf("ERROR: No se pudo guardar la categoria.\n");
        }
    }

    return; 
	}

	void eliminarCategoriaUI(Categoria categorias[], int *nc) {
		system ("cls");
	    int codigoSel = 0;
	    int idx = -1;
	    int i;
	    int finalizado = 0;
	    char nomCat[30];
	    int puedeContinuar = 1; 
	
	    
	    if ((*nc) <= 0) {
	        printf("No hay categorias para eliminar.\n");
	        puedeContinuar = 0; 
	    }
	
	    
	    if (puedeContinuar) {
	        mostrarCategoriasStatic(categorias, *nc);
	        
	        while (idx == -1) {
	            codigoSel = validarINT("Ingrese CODIGO de categoria a eliminar: ");
	            
	            if (codigoSel <= 0) {
	                printf("ERROR: el codigo debe ser positivo.\n");
	                continue;
	            }
	            
	            for (i = 0; i < (*nc); i++) {
	                if (categorias[i].codigo == codigoSel) {
	                    if (strcmp(categorias[i].nombre, "SIN CATEGORIA") == 0) {
	                        printf("ERROR: La categoria 'SIN CATEGORIA' no puede ser eliminada.\n");
	                        finalizado = 1;
	                        break;
	                    }
	                    idx = i;
	                    break;
	                }
	            }
	            
	            if (finalizado == 1) break;
	            
	            if (idx == -1) {
	                printf("ERROR: Codigo no encontrado. Intente de nuevo.\n");
	            }
	        }
	        
	        
	        if (finalizado == 0) {
	            strncpy(nomCat, categorias[idx].nombre, sizeof(nomCat)-1);
	            nomCat[sizeof(nomCat)-1] = '\0';
	            
	            strncpy(categorias[idx].nombre, "CATEGORIA ELIMINADA", sizeof(categorias[idx].nombre) - 1);
	            categorias[idx].nombre[sizeof(categorias[idx].nombre) - 1] = '\0';
	            
	            FILE *f = fopen(ARCH_CATEGORIAS, "wb");
	            if (f != NULL) {
	                if (fwrite(categorias, sizeof(Categoria), *nc, f) == (size_t)(*nc)) {
	                    printf("Categoria '%s' (Codigo %d) marcada como inactiva/eliminada.\n", nomCat, codigoSel);
	                    printf("Los gastos asociados a esta categoria ahora apareceran como 'SIN CATEGORIA'.\n");
	                } else {
	                    printf("ERROR: Fallo al reescribir el archivo de categorias.\n");
	                }
	                fclose(f);
	            } else {
	                printf("ERROR: No se pudo abrir el archivo de categorias para reescritura.\n");
	            }
	        }
	    }
	
	
	    return;
	}
	
int esCategoriaActiva(Categoria categorias[], int nc, char *nombreCategoriaGasto) {
    int i;
    char nomCat[30];
    char nomGasto[30];
    int resultado = 0; 
    strncpy(nomGasto, nombreCategoriaGasto, sizeof(nomGasto) - 1);
    nomGasto[sizeof(nomGasto) - 1] = '\0';
    normalizarTexto(nomGasto);
    if (strcmp(nomGasto, "SIN CATEGORIA") == 0) {
        resultado = 1; 
    } else if (strcmp(nomGasto, "CATEGORIA ELIMINADA") == 0) {
        resultado = 0; 
    } else {
        for (i = 0; i < nc; i++) {
            strncpy(nomCat, categorias[i].nombre, sizeof(nomCat) - 1);
            nomCat[sizeof(nomCat) - 1] = '\0';
            normalizarTexto(nomCat); 
            if (strcmp(nomGasto, nomCat) == 0) { 
              
                resultado = 1;
                break; 
            }
        }
    }

    return resultado; 
}

// ----------------------------------------------------------------------
//							FECHAS
// ----------------------------------------------------------------------

int validarFechaStruct(Fecha f) {
    int esAnioYMesValido = (f.anio >= 2020 && f.anio <= 2025 && f.mes >= 1 && f.mes <= 12);

    int esDiaValidoEnMes30 = 1; 
    if (f.mes == 4 || f.mes == 6 || f.mes == 9 || f.mes == 11) {
        if (f.dia > 30) {
            esDiaValidoEnMes30 = 0;
        }
    }


    int esDiaValidoEnFebrero = 1; 
    if (f.mes == 2) {
        int bisiesto = (f.anio % 4 == 0 && f.anio % 100 != 0) || (f.anio % 400 == 0);
        if (bisiesto) {
            if (f.dia > 29) {
                esDiaValidoEnFebrero = 0;
            }
        } else {
            if (f.dia > 28) {
                esDiaValidoEnFebrero = 0;
            }
        }
    }
    
    int esDiaGeneralValido = (f.dia >= 1 && f.dia <= 31);


    int resultado = esAnioYMesValido && esDiaValidoEnMes30 && esDiaValidoEnFebrero && esDiaGeneralValido;

    return resultado;
}
	
int parsearFecha(char *s, Fecha *f){
		    int d,m,a;
		    int exito = 0;
		    Fecha tmp;
		
		    if (exito == 0 && sscanf(s, "%d/%d/%d", &d, &m, &a) == 3) {
		        tmp.dia = d; tmp.mes = m; tmp.anio = a;
		        if (validarFechaStruct(tmp) == 1) {
		            *f = tmp;
		            exito = 1;
		        }
		    }
		    if (exito == 0 && sscanf(s, "%d %d %d", &d, &m, &a) == 3) {
		        tmp.dia = d; tmp.mes = m; tmp.anio = a;
		        if (validarFechaStruct(tmp) == 1) {
		            *f = tmp;
		            exito = 1;
		        }
		    }
		    if (exito == 0 && sscanf(s, "%d%*c%d%*c%d", &d, &m, &a) == 3) {
		        tmp.dia = d; tmp.mes = m; tmp.anio = a;
		        if (validarFechaStruct(tmp) == 1) {
		            *f = tmp;
		            exito = 1;
		        }
		    }
		    return exito; 
}

int compararFechas(Fecha f1, Fecha f2) {
		    int resultado = 0;
		    if (f1.anio != f2.anio) {
		        resultado = (f1.anio < f2.anio) ? -1 : 1;
		    } else if (f1.mes != f2.mes) {
		        resultado = (f1.mes < f2.mes) ? -1 : 1;
		    } else if (f1.dia != f2.dia) {
		        resultado = (f1.dia < f2.dia) ? -1 : 1;
		    }
		    return resultado; 
}

void imprimirFecha(Fecha f) {
	printf("%02d/%02d/%04d", f.dia, f.mes, f.anio);
	    return; 
}

Fecha leerFecha(const char *msg){
		
		    Fecha f, hoy;
		    char buffer[40];
		    time_t t;
		    struct tm *p_tm;
		    int ok = 0;
		    int cmp;
		
		    t = time(NULL);
		    p_tm = localtime(&t);
		
		    hoy.dia  = (*p_tm).tm_mday;
		    hoy.mes  = (*p_tm).tm_mon + 1;
		    hoy.anio = (*p_tm).tm_year + 1900;
		
		    while (ok == 0) {
		        printf("%s", msg);
		        leerLinea(buffer, sizeof(buffer));
		
		        if (parsearFecha(buffer, &f) == 1) {
		            cmp = compararFechas(f, hoy);
		            if (cmp == 1) {
		                printf("ERROR: La fecha no puede ser mayor a la actual (%02d/%02d/%04d).\n", hoy.dia, hoy.mes, hoy.anio);
	            } else  if(cmp == -1){
		            	printf("ERROR: La fecha no puede ser menor a la actual (%02d/%02d/%04d).\n", hoy.dia, hoy.mes, hoy.anio);
		            }else {
		            	 ok = 1; 
		            }
		        } else {
		            printf("ERROR: Fecha invalida o formato incorrecto (use dd/mm/aaaa, dd-mm-aaaa o dd mm aaaa).\n");
		        }
		    }
		
		    return f; 
}

int validarPagoFecha(const Gasto *g, const Pago *p, const Fecha *hoy){

    return (compararFechas((*p).fecha, (*g).fecha) >= 0 && 
            compararFechas((*p).fecha, (*hoy)) <= 0) ? 1 : 0;
    
}

// ----------------------------------------------------------------------
//							VALIDACIONES
// ----------------------------------------------------------------------

void validarTXT(char *msg, char *buffer, size_t len){
	    int listo = 0;
	
	    while (listo != 1){
	        printf("%s", msg);
	
	        if (!leerLinea(buffer, len)){
	            buffer[0] = '\0';
	            printf("ERROR! No puede estar vacio.\n");
	            continue;  
	        } else {
	            size_t largo = strlen(buffer);
	            int valido = 1;
	            int tieneLetra = 0;
	            size_t i;
	            unsigned char c;
	
	            if (largo == 0){
	                printf("ERROR! No puede estar vacio.\n");
	                valido = 0;
	            } else {
	                for (i = 0; i < largo; i++){
	                    c = (unsigned char) buffer[i];
	                    if (isalpha(c)){
	                        tieneLetra = 1;
	                    } else if (c != ' '){
	                        printf("ERROR! Solo se permiten letras (A-Z) y espacios.\n");
	                        valido = 0;
	                        break;
	                    }
	                }
	
	                if (!tieneLetra && valido){
	                    printf("ERROR! Debe contener al menos una letra.\n");
	                    valido = 0;
	                }
	
	                if (valido){
	                    normalizarTexto(buffer);
	                    listo = 1;  
	                }
	            }
	        }
	    }
}
	
long validarLONG(const char *msg){
		char buffer[100], *endptr;
    	long num;
	    while (1) {
	        printf("%s", msg);
	        if (!fgets(buffer, sizeof(buffer), stdin)) continue;
	        char *p = buffer;
	        while (*p == ' ') p++;
	        if (*p == '\n' || *p == '\0') {
	            printf("\aError! No se permiten ingresos en blanco.\n");
	            continue;
	        }
	        buffer[strcspn(buffer, "\n")] = '\0';
	        num = strtol(p, &endptr, 10);
	        if (*endptr != '\0') {
	            printf("\aError! No se permiten letras o caracteres especiales.\n");
	            continue;
	        }
	        if (num < 0) {
	            printf("\aError! No se permiten numeros negativos.\n");
	            continue;
	        }
	        return num;
	    }

	}
	
	int validarINT(const char *msg){
		char buffer[100], *endptr;
	    long num;
	    while(1){
	        printf("%s", msg);
	        if (!fgets(buffer, sizeof(buffer), stdin)) continue;
	        char *p = buffer;
	        while (*p == ' ') p++;
	        if (*p == '\n' || *p == '\0') {
	            printf("\aError! No se permiten ingresos en blanco.\n");
	            continue;
	        }
	        buffer[strcspn(buffer, "\n")] = '\0';
	        num = strtol(p, &endptr, 10);
	        if (*endptr != '\0') {
	            printf("\aError! No se permiten letras o caracteres especiales.\n");
	            continue;
	        }
	        if (num < 0) {
	            printf("\aError! No se permiten numeros negativos.\n");
	            continue;
	        }
	        return (int)num;
	    }
}

	float validarFLOAT(const char *msg){
		char buffer[100], *endptr;
	    float num = 0.00;
	    while (1) {
	        printf("%s", msg);
	        if (!fgets(buffer, sizeof(buffer), stdin)) continue;
	        char *p = buffer;
	        while (*p == ' ') p++;
	        if (*p == '\n' || *p == '\0') {
	            printf("\aError! No se permiten ingresos vacios.\n");
	            continue;
	        }
	        buffer[strcspn(buffer, "\n")] = '\0';
	        num = strtof(p, &endptr);
	        if (*endptr != '\0') {
	            printf("\aError! No se permiten letras o caracteres especiales.\n");
	            continue;
	        }
	        if (num <= 0) {
	            printf("\aError! No se permiten numeros negativos.\n");
	            continue;
	        }
	        return num;
	    }
	}
// ----------------------------------------------------------------------
//							UTILIDADES
// ----------------------------------------------------------------------

	int leerLinea(char *buffer, size_t size) {
    
    int exito = 0; 
    
    
    if (fgets(buffer, size, stdin) != NULL) {
        
        exito = 1; 
        
        size_t len = strlen(buffer);
        
        
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
    
    return exito; 
}

	void normalizarTexto(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        s[i] = toupper((unsigned char)s[i]);
    }
    return; 
}

	float sumarTotalMesAnio(int tipo, void *vec, int n, int mes, int anio) {
    float total = 0.0f;
    int i;

    if (tipo == 1) { 
        Gasto *gastos = (Gasto *)vec;
        for (i = 0; i < n; i++) {
            if (gastos[i].fecha.mes == mes && gastos[i].fecha.anio == anio) {
                if (gastos[i].cuotasTotales > 1) {
                    total += (gastos[i].monto / gastos[i].cuotasTotales);
                } else {
                    total += gastos[i].monto;
                }
            }
        }
    } 
    else if (tipo == 2) {   
        Ingreso *ingresos = (Ingreso *)vec;
        for (i = 0; i < n; i++) {
            if (ingresos[i].fecha.mes == mes && ingresos[i].fecha.anio == anio) {
                total += ingresos[i].monto;
            }
        }
    }

    return total; 
}

	int generarCOD(const char *archivo, size_t tamRegistro, size_t offsetCodigo) {
    FILE *f;

    int codigo = 1; 
    
    long tam;
    long pos;
    int ultimo = 0;
    char buffer[1024]; 
    
    int archivoAbierto = 0;


    if ((f = fopen(archivo, "rb")) != NULL) {
        archivoAbierto = 1;
        
        fseek(f, 0, SEEK_END);
        tam = ftell(f);
        
        if (tam > 0) {
            
            if (tamRegistro > sizeof(buffer) || tam < (long)tamRegistro) {
                printf("ADVERTENCIA: Fallo de tamRegistro o tamArchivo en generarCOD. Usando codigo=1.\n");
            } else {
                pos = tam - (long)tamRegistro;
                
                if (fseek(f, pos, SEEK_SET) == 0) {
                    if (fread(buffer, 1, tamRegistro, f) == tamRegistro) {
                        memcpy(&ultimo, buffer + offsetCodigo, sizeof(int)); 
                        codigo = ultimo + 1;
                    }
                }
            }
        }
        
        fclose(f);
    } 
    else {
        FILE *f_test = fopen(archivo, "wb");
        if (f_test != NULL) {
            fclose(f_test);
        }
    }
    
    return codigo; 
}

	void ordenarGastosPorFechaStatic(Gasto *vec, int n) {
	    int i, j;
        Gasto tmp;
	    for (i = 0; i < n - 1; i++) {
	        for (j = i + 1; j < n; j++) {
	            if (compararFechas((*(vec + i)).fecha, (*(vec + j)).fecha) > 0) {
	                tmp = *(vec + i);
	                *(vec + i) = *(vec + j);
	                *(vec + j) = tmp;
	            }
	        }
	    }
	    return; 
}
	
	void ordenarIngresosPorFechaStatic(Ingreso *vec, int n) {
        int i, j;
        Ingreso tmp;
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (compararFechas((*(vec + i)).fecha, (*(vec + j)).fecha) > 0) {
                    tmp = *(vec + i);
                    *(vec + i) = *(vec + j);
                    *(vec + j) = tmp;
                }
            }
        }
        return; 
}
	
int generarReporteMensual(int mes, int anio, Categoria categorias[], int nc) { 
	system ("cls");
    FILE *f;
    Gasto gastos[MAX_GASTOS];
    Ingreso ingresos[MAX_INGRESOS];
    int ng = 0;
    int ni = 0;
    float sumG = 0.0f, sumI = 0.0f;
    int i;
    int exito = 0;
    float montoMostrado = 0.0f;
    char nombreArchivo[160];
    Fecha fechaRep;
    int st, r;
    const char *nombrePersona;
    long dniMostrar;
    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
    ni = leerTodosIngresosStatic(ingresos, MAX_INGRESOS);
    sumG = sumarTotalMesAnio(1, gastos, ng, mes, anio);
    sumI = sumarTotalMesAnio(2, ingresos, ni, mes, anio);
    fechaRep.dia = 1;
    fechaRep.mes = mes;
    fechaRep.anio = anio;
    generarNombreResumenMensual(fechaRep, nombreArchivo, sizeof(nombreArchivo));
    if ((f = fopen(nombreArchivo, "w"))!= NULL) {
        fprintf(f, "--- REPORTE MENSUAL: %02d/%04d ---\n\n", mes, anio);
        fprintf(f, "RESUMEN FINANCIERO\n");
        fprintf(f, "--------------------------------\n");
        fprintf(f, "Total Ingresos: $%.2f\n", sumI);
        fprintf(f, "Total Gastos:   $%.2f\n", sumG);
        fprintf(f, "Saldo Neto:     $%.2f\n\n", sumI - sumG);

        fprintf(f, "DETALLE DE INGRESOS\n");
        fprintf(f, "--------------------------------\n");
        for (i = 0; i < ni; i++) {
            if (ingresos[i].fecha.mes == mes && ingresos[i].fecha.anio == anio) {
                st = ingresos[i].persona.status;
                r  = personaActiva(ingresos[i].persona.dni, &st);
                if (r == 1 && st == 0){
                    nombrePersona = "Persona eliminada";
                    dniMostrar = 0L;
                } else {
                    nombrePersona = ingresos[i].persona.nombre;
                    dniMostrar = ingresos[i].persona.dni;
                }
                fprintf(
                    f,
                    "DNI:%ld | Nombre:%s | Concepto:%s | $%.2f | %02d/%02d/%04d\n",
                    dniMostrar,
                    nombrePersona,
                    ingresos[i].concepto,
                    ingresos[i].monto,
                    ingresos[i].fecha.dia,
                    ingresos[i].fecha.mes,
                    ingresos[i].fecha.anio
                );
            }
        }

        fprintf(f, "\n");
        fprintf(f, "DETALLE DE GASTOS\n");
        fprintf(f, "--------------------------------\n");
        for (i = 0; i < ng; i++) {
            if (gastos[i].fecha.mes == mes && gastos[i].fecha.anio == anio) {
                const char *nombreCat = gastos[i].categoria;
                if (!esCategoriaActiva(categorias, nc, gastos[i].categoria)) {
                    nombreCat = "SIN CATEGORIA";
                }

                st = gastos[i].persona.status;
                r  = personaActiva(gastos[i].persona.dni, &st);
                if (r == 1 && st == 0){
                    nombrePersona = "Persona eliminada";
                    dniMostrar = 0L;
                } else {
                    nombrePersona = gastos[i].persona.nombre;
                    dniMostrar = gastos[i].persona.dni;
                }

                montoMostrado = gastos[i].monto;
                if (gastos[i].cuotasTotales > 1) {
                    montoMostrado = gastos[i].monto / (float)gastos[i].cuotasTotales;
                }

                fprintf(
                    f,
                    "Cod:%d | Tipo:%s | Cat:%s | $%.2f | Desc:%s | %02d/%02d/%04d",
                    gastos[i].codigo,
                    gastos[i].tipo,
                    nombreCat,
                    montoMostrado,
                    gastos[i].descripcion,
                    gastos[i].fecha.dia,
                    gastos[i].fecha.mes,
                    gastos[i].fecha.anio
                );

                if (gastos[i].cuotasTotales > 1) {
                    fprintf(
                        f,
                        " | Cuotas:%d/%d (Pagadas:%d)",
                        gastos[i].cuotaActual,
                        gastos[i].cuotasTotales,
                        gastos[i].cuotasPagadas
                    );
                }

                if (r == 1 && st == 0){
                    fprintf(f, " | Persona eliminada\n");
                } else {
                    fprintf(f, " | DNI:%ld | Nombre:%s\n", dniMostrar, nombrePersona);
                }
            }
        }

        fprintf(f, "\n--- FIN DE REPORTE ---\n");
        fclose(f);
        printf("Reporte mensual guardado exitosamente en el archivo '%s'.\n", nombreArchivo);
        exito = 1;
    } else {
        printf("ERROR al crear el archivo de reporte '%s'.\n", nombreArchivo);
    }

    return exito; 
}



	int generarNombreResumenMensual(Fecha fecha, char *out, size_t outsz){
	    int ok = 0;
	    char mesNombre[16];
	    char base[128];
	    char candidato[160];
	    int i;
	
	    if (out == NULL || outsz == 0){
	    	ok = 0;
		} 
	
	    if (!nombreMesES(fecha.mes, mesNombre, sizeof(mesNombre))){
	    	ok = 0;
		}
	    
	    snprintf(base, sizeof(base), "resumen_%s_%04d", mesNombre, fecha.anio);
	    snprintf(candidato, sizeof(candidato), "%s.txt", base);
	    if (!archivoExiste(candidato)){
	        strncpy(out, candidato, outsz - 1);
	        out[outsz - 1] = '\0';
	        ok = 1;
	    } else {
	        for (i = 1; i <= 999 && ok == 0; i++){
	            char suf[8];
	            snprintf(suf, sizeof(suf), "_%03d", i);
	            snprintf(candidato, sizeof(candidato), "%s%s.txt", base, suf);
	            if (!archivoExiste(candidato)){
	                strncpy(out, candidato, outsz - 1);
	                out[outsz - 1] = '\0';
	                ok = 1;
	            }
	        }
	    }
    return ok; 
}

	int archivoExiste(const char *path){
    int existe = 0;
    FILE *f;
    if ((f = fopen(path, "rb")) != NULL){
            fclose(f);
            existe = 1;
        }
    
    return existe; 
}

	int nombreMesES(int mes, char *out, size_t outsz){
    int ok = 0;
    const char *nombres[13] = {
        "", "enero","febrero","marzo","abril","mayo","junio",
        "julio","agosto","septiembre","octubre","noviembre","diciembre"
    };
    if (out != NULL && outsz > 0 && mes >= 1 && mes <= 12){
        strncpy(out, nombres[mes], outsz - 1);
        out[outsz - 1] = '\0';
        ok = 1;
    }
    return ok; 
}

	Gasto encontrarGastoPorCodigo(int codigo){
    Gasto g_vacia; 
    g_vacia.codigo = -1;      
    g_vacia.status = 0;

    Gasto resultado = g_vacia;
    FILE *f = fopen(ARCH_GASTOS, "rb");
    if (f != NULL){
        Gasto temp;
        while (fread(&temp, sizeof(Gasto), 1, f) == 1){
            if (temp.codigo == codigo && temp.status == 1){
                resultado = temp;
                break;
            }
        }
        fclose(f);
    }
    return resultado; 
}

	float calcularTotalPagadoCuota(int gastoCodigo, Pago pagos[], int np_pagos) {
    float totalPagado = 0.0f;
    int i;
    for (i = 0; i < np_pagos; i++) {
        if (pagos[i].gastoCodigo == gastoCodigo) {
            totalPagado += pagos[i].importe;
        }
    }
    return totalPagado;
}

	float calcularSaldoPendienteCuota(Gasto g, Pago pagos[], int np_pagos) {
    float valorCuota = g.monto;
    if (g.cuotasTotales > 1) {
        valorCuota = g.monto / (float)g.cuotasTotales;
    }
    
    float totalPagado = calcularTotalPagadoCuota(g.codigo, pagos, np_pagos);
    
    float saldo = valorCuota - totalPagado;
    
    return (saldo < 0.0001f) ? 0.0f : saldo;
}

	int pagoActivo(int gastoCodigo){
    int res = -1;                     
    Gasto g;
    Pago pagos[MAX_PAGOS];
    int np = 0;
    float cuotaValor = 0.0f;
    float totalPagado = 0.0f;

    g = encontrarGastoPorCodigo(gastoCodigo);
    if (g.codigo > 0 && g.status == 1){
        np = leerTodosPagosStatic(pagos, MAX_PAGOS);

        
        cuotaValor = g.monto;
        if (g.cuotasTotales > 1){
            if (g.cuotasTotales != 0){
                cuotaValor = g.monto / (float)g.cuotasTotales;
            }
        }

        
        totalPagado = calcularTotalPagadoCuota(gastoCodigo, pagos, np);

        if (totalPagado >= (cuotaValor - 0.0001f))
            res = 1;   
        else
            res = 0;   
    }
    return res; 
}

static int mismaClavePlan(const Gasto *g, const Gasto *ref){
    int ok = 0;
    if (g != NULL && ref != NULL){

        if ((*g).persona.dni == (*ref).persona.dni &&
            strcmp((*g).descripcion, (*ref).descripcion) == 0 &&
            fabs((*g).monto - (*ref).monto) < 0.001f &&
            (*g).cuotasTotales == (*ref).cuotasTotales)
        {
            ok = 1;
        }
    }
    return ok; 
}

	int existePagoActivoParaGastoCodigo(int gastoCodigo){
    FILE *fp = NULL;
    Pago p;
    int res = 0; 
    int fin = 0;

    if ((fp = fopen(ARCH_PAGOS, "rb")) == NULL){
        fin = 1;
    }
    if (!fin){
        while (fread(&p, sizeof(Pago), 1, fp) == 1){
            if (p.gastoCodigo == gastoCodigo){
                res = 1;     
                break;
            }
        }
        fclose(fp);
    }
    return res; 
}

int seleccionarGastoUI(Gasto *out, int modo){
    int ok = 0;                 
    int fin = 0;
    int listado = 0;
    int i, idx = -1;
    int ng = 0, np = 0;

    Gasto gastos[MAX_GASTOS];
    Pago  pagos[MAX_PAGOS];

    time_t t;
    struct tm *ptm;
    Fecha hoy;


    Categoria categorias[MAX_CATEGORIAS]; 
    int nc_cat = 0;                 
 


    if (out == NULL){
        printf("ERROR: puntero de salida nulo.\n");
        fin = 1;
    }
    if (!fin){
        if (modo != 1 && modo != 2){
            printf("ERROR: modo de seleccion invalido.\n");
            fin = 1;
        }
    }
    if (!fin){
        ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
        np = leerTodosPagosStatic(pagos,  MAX_PAGOS);
        if (ng <= 0){
            printf("No hay gastos registrados.\n");
            fin = 1;
        }
    }


    if (!fin){
        nc_cat = cargarCategoriasStatic(categorias, MAX_CATEGORIAS); 
    }


    if (!fin){
        t = time(NULL);
        ptm = localtime(&t);
        hoy.dia  = (*ptm).tm_mday;
        hoy.mes  = (*ptm).tm_mon + 1;
        hoy.anio = (*ptm).tm_year + 1900;

       
        for (i = 0; i < ng; i++){
            int pasa = 1;
            float saldo = 0.0f;

            if (gastos[i].status != 1)            pasa = 0;              
            if (pasa && strcmp(gastos[i].estado, "PAGADA") == 0) pasa = 0;

            if (pasa){
                int cmp = compararFechas(gastos[i].fecha, hoy);
                if (modo == 1 && !(cmp <= 0)) pasa = 0;  
                if (modo == 2  && !(cmp  > 0)) pasa = 0;  
            }

            if (pasa){
                
                if (gastos[i].cuotasTotales > 1){
                    if (!(gastos[i].cuotaActual == gastos[i].cuotasPagadas + 1)){
                        pasa = 0;
                    }
                } else {
                    if (gastos[i].cuotasPagadas >= gastos[i].cuotasTotales){
                        pasa = 0; 
                    }
                }
            }

            if (pasa){
                saldo = calcularSaldoPendienteCuota(gastos[i], pagos, np);
                if (saldo <= 0.0001f) pasa = 0;
            }

            if (pasa){
                float totalParcial = calcularTotalPagadoCuota(gastos[i].codigo, pagos, np);
                float montoPorCuota = (gastos[i].cuotasTotales > 1)
                                        ? gastos[i].monto / (float)gastos[i].cuotasTotales
                                        : gastos[i].monto;

                const char *marcaParcial = (totalParcial > 0.0001f) ? " ": " ";
                const char *estadoVisible = (totalParcial > 0.0001f) ? "PAGADO PARCIAL" : "NO PAGADO";

                if (!listado){
                    if (modo == 1)
                        printf("\nGastos pendientes HASTA HOY:\n");
                    else
                        printf("\nGastos para ADELANTAR (fecha futura):\n");

                    printf("Codigo | Descripcion                      | Categoria                 | Saldo Pend | Fecha      | Cuota   | Estado\n");
                    printf("-------+----------------------------------+---------------------------+------------+------------+---------+----------------\n");
                    listado = 1;
                }


                const char *nombreCat = NULL; 
                nombreCat = esCategoriaActiva(categorias, nc_cat, gastos[i].categoria) ? gastos[i].categoria : "CATEGORIA ELIMINADA";
                
                printf("%5d  | %-32s | %-25s | $%9.2f | ",
                       gastos[i].codigo, gastos[i].descripcion, nombreCat, saldo); 


                imprimirFecha(gastos[i].fecha);
                if (gastos[i].cuotasTotales > 1)
                    printf(" | %2d/%-2d | %s%s\n", gastos[i].cuotaActual, gastos[i].cuotasTotales, estadoVisible, marcaParcial);
                else
                    printf(" |  1/1   | %s%s\n", estadoVisible, marcaParcial);

                (void)montoPorCuota; 
            }
        }

        if (!listado){
            if (modo == 1)
                printf("No hay gastos pendientes con fecha <= hoy.\n");
            else
                printf("No hay gastos para adelantar (fecha > hoy).\n");
            fin = 1;
        }
    }

    
    if (!fin){
        int codigo = 0;
        int valido = 0;
        char resp[16];

        while (!valido && !fin){
            codigo = validarINT("Ingrese CODIGO a pagar (0 para cancelar): ");
            if (codigo == 0){
                fin = 1;
            } else if (codigo < 0){
                printf("ERROR: codigo invalido.\n");
            } else {
                
                for (i = 0; i < ng; i++){
                    int pasa = 1;
                    float saldo = 0.0f;

                    if (gastos[i].codigo != codigo) continue;

                    if (gastos[i].status != 1)            pasa = 0;
                    if (pasa && strcmp(gastos[i].estado, "PAGADA") == 0) pasa = 0;

                    if (pasa){
                        int cmp = compararFechas(gastos[i].fecha, hoy);
                        if (modo == 1 && !(cmp <= 0)) pasa = 0;
                        if (modo == 2  && !(cmp  > 0)) pasa = 0;
                    }

                    if (pasa){
                        if (gastos[i].cuotasTotales > 1){
                            if (!(gastos[i].cuotaActual == gastos[i].cuotasPagadas + 1)){
                                pasa = 0;
                            }
                        } else {
                            if (gastos[i].cuotasPagadas >= gastos[i].cuotasTotales){
                                pasa = 0;
                            }
                        }
                    }

                    if (pasa){
                        saldo = calcularSaldoPendienteCuota(gastos[i], pagos, np);
                        if (saldo <= 0.0001f) pasa = 0;
                    }

                    if (pasa){
                        idx = i;
                        valido = 1;
                        break;
                    }
                }

                if (!valido){
                    printf("ERROR: codigo inexistente en el listado/seleccion.\n");
                    printf("ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã‚Â¢ÃƒÂ¢Ã¢â‚¬Å¡Ã‚Â¬Ãƒâ€¦Ã‚Â¡ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¿Intentar otro? (S/N): ");
                    if (!leerLinea(resp, sizeof(resp))){
                        fin = 1;
                    } else {
                        normalizarTexto(resp);
                        if (strcmp(resp, "N") == 0 || strcmp(resp, "NO") == 0) fin = 1;
                    }
                }
            }
        }
    }

    if (!fin && idx >= 0){
        (*out) = gastos[idx];
        ok = 1;
    }

    return ok; 
}


//					 EXTRAS POR GRUPO DE 4

void consultaComparacionMes(Categoria categorias[], int nc){ 
	system ("cls");
    int m1 = 0, a1 = 0, m2 = 0, a2 = 0;
    Gasto gastos[MAX_GASTOS];
    int ng = 0;

    char cats[MAX_CATEGORIAS][30];
    float tot1_por_cat[MAX_CATEGORIAS];
    float tot2_por_cat[MAX_CATEGORIAS];
    int ncat = 0;

    float total1 = 0.0f, total2 = 0.0f;
    float dif = 0.0f, variacion = 0.0f;

    int i, j;
    int foundEnMes = 0; 
    const char *catClave;

    while (1){
        m1 = validarINT("Mes 1 (1-12): ");
        if (m1 >= 1 && m1 <= 12) break;
        printf("Mes invalido.\n");
    }
    while (1){
        a1 = validarINT("Anio 1: ");
        if (a1 >= 2020 && a1 <= 2025) break;
        printf("Anio invalido.\n");
    }
    while (1){
        m2 = validarINT("Mes 2 (1-12): ");
        if (m2 >= 1 && m2 <= 12) break;
        printf("Mes invalido.\n");
    }
    while (1){
        a2 = validarINT("Anio 2: ");
        if (a2 >= 2020 && a2 <= 2025) break;
        printf("Anio invalido.\n");
    }

    for (i = 0; i < MAX_CATEGORIAS; i++){
        tot1_por_cat[i] = 0.0f;
        tot2_por_cat[i] = 0.0f;
        cats[i][0] = '\0';             
    }

    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
    if (ng == 0){
        printf("No hay gastos registrados en el sistema.\n");
        return;
    }

    for (i = 0; i < ng; i++){
        int esMes1 = ((*(gastos + i)).fecha.mes == m1 && (*(gastos + i)).fecha.anio == a1);
        int esMes2 = ((*(gastos + i)).fecha.mes == m2 && (*(gastos + i)).fecha.anio == a2);

        if (!(esMes1 || esMes2)) continue;
        foundEnMes = 1;

        catClave = (*(gastos + i)).categoria;
        if (!esCategoriaActiva(categorias, nc, (*(gastos + i)).categoria)) {
            catClave = "SIN CATEGORIA";
        }

        int idx = -1;
        for (j = 0; j < ncat; j++){
            if (strncmp(cats[j], catClave, sizeof(cats[j])) == 0){ idx = j; break; }
        }
        if (idx == -1 && ncat < MAX_CATEGORIAS){
            strncpy(cats[ncat], catClave, sizeof(cats[ncat]) - 1);
            cats[ncat][sizeof(cats[ncat]) - 1] = '\0';
            idx = ncat;
            ncat++;
        }
        if (idx != -1){
            float costo = (*(gastos + i)).monto;
            if ((*(gastos + i)).cuotasTotales > 1){
                costo /= (float)(*(gastos + i)).cuotasTotales;
            }

            if (esMes1){
                tot1_por_cat[idx] += costo;   
                total1            += costo;
            }
            if (esMes2){
                tot2_por_cat[idx] += costo;
                total2            += costo;
            }
        }
    }

    if (!foundEnMes){
        printf("No hay gastos en los meses seleccionados.\n");
        return;
    }
    if (ncat == 0){
        printf("No se puede realizar la comparacion intermensual: no hay categorias para esos meses.\n");
        return;
    }

    dif = total2 - total1;
    if (total1 > 0.0001f) variacion = (dif / total1) * 100.0f;
    else variacion = 0.0f;

    printf("\n--- COMPARACION INTERMENSUAL ---\n");
    printf("%02d/%04d: $%.2f\n", m1, a1, total1);
    printf("%02d/%04d: $%.2f\n", m2, a2, total2);
    printf("Diferencia: $%.2f | Variacion: %.2f%%\n", dif, variacion);

    {
        float max_inc = -1.0e30f; int idx_inc = -1;
        float max_red =  1.0e30f; int idx_red = -1;
        for (i = 0; i < ncat; i++){
            float aux = tot2_por_cat[i] - tot1_por_cat[i];
            if (aux > max_inc){ max_inc = aux; idx_inc = i; }
            if (aux < max_red){ max_red = aux; idx_red = i; }
        }
        if (idx_inc != -1){
            printf("Mayor incremento: %s  (M1:$%.2f -> M2:$%.2f, +$%.2f)\n",
                   cats[idx_inc], tot1_por_cat[idx_inc], tot2_por_cat[idx_inc], max_inc);
        }
        if (idx_red != -1){
            printf("Mayor reduccion:  %s  (M1:$%.2f -> M2:$%.2f, $%.2f)\n",
                   cats[idx_red], tot1_por_cat[idx_red], tot2_por_cat[idx_red], max_red);
        }
    }
}





void consultaGastosPorPersona(){
	system ("cls");
    int finalizado = 0;

    const int usarValorCuotaEnTemporales = 1; 

    Gasto gastos[MAX_GASTOS];
    int ng = 0;


    Categoria categoriasMaestro[MAX_CATEGORIAS];
    int nc_maestro = 0;

    long dnis[MAX_PERSONAS];
    float total_por_dni[MAX_PERSONAS];
    int ndni = 0;

    char cats[MAX_CATEGORIAS][30];   
    int ncat = 0;

    float matriz[MAX_PERSONAS][MAX_CATEGORIAS]; 

    float total_global = 0.0f;

    int i, j, k;

    int aviso_tope_dni_emitido = 0;
    int aviso_tope_cat_emitido = 0;

    int st, r;

    for (i = 0; i < MAX_PERSONAS; i++){
        dnis[i] = 0;
        total_por_dni[i] = 0.0f;
    }
    for (i = 0; i < MAX_PERSONAS; i++){
        for (j = 0; j < MAX_CATEGORIAS; j++){
            matriz[i][j] = 0.0f;
        }
    }
    for (j = 0; j < MAX_CATEGORIAS; j++){
        cats[j][0] = '\0';
    }

    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
    if (ng == 0){
        printf("No hay gastos.\n");
        finalizado = 1;
    }

    if (!finalizado){
 
        nc_maestro = cargarCategoriasStatic(categoriasMaestro, MAX_CATEGORIAS);

        for (i = 0; i < ng; i++){
            long dni = gastos[i].persona.dni;


            int id = -1;
            for (j = 0; j < ndni; j++){
                if (dnis[j] == dni){
                    id = j;
                    break;
                }
            }
            if (id == -1){
                if (ndni < MAX_PERSONAS){
                    dnis[ndni] = dni;
                    id = ndni;
                    ndni++;
                } else {
                    if (!aviso_tope_dni_emitido){
                        printf("AVISO: Se alcanzo el maximo de personas (%d). Algunos DNIs adicionales no seran contabilizados.\n", MAX_PERSONAS);
                        aviso_tope_dni_emitido = 1;
                    }
                }
            }


            char nombreCat[30];
            if (gastos[i].categoria[0] == '\0'){

                strncpy(nombreCat, "SIN CATEGORIA", sizeof(nombreCat)-1);
                nombreCat[sizeof(nombreCat)-1] = '\0';
            } else {

                int foundMatch = 0;
                char gNorm[30];
                strncpy(gNorm, gastos[i].categoria, sizeof(gNorm)-1);
                gNorm[sizeof(gNorm)-1] = '\0';
                normalizarTexto(gNorm);

                for (k = 0; k < nc_maestro; k++){
                    char mNorm[30];
                    strncpy(mNorm, categoriasMaestro[k].nombre, sizeof(mNorm)-1);
                    mNorm[sizeof(mNorm)-1] = '\0';
                    normalizarTexto(mNorm);

                    if (strcmp(gNorm, mNorm) == 0){
 
                        strncpy(nombreCat, categoriasMaestro[k].nombre, sizeof(nombreCat)-1);
                        nombreCat[sizeof(nombreCat)-1] = '\0';
                        foundMatch = 1;
                        break;
                    }
                }
                if (!foundMatch){
 
                    strncpy(nombreCat, "SIN CATEGORIA", sizeof(nombreCat)-1);
                    nombreCat[sizeof(nombreCat)-1] = '\0';
                }
            }

 
            int ic = -1;
            if (id != -1){
                for (j = 0; j < ncat; j++){
                    if (strncmp(cats[j], nombreCat, sizeof(cats[j])) == 0){
                        ic = j;
                        break;
                    }
                }
                if (ic == -1){
                    if (ncat < MAX_CATEGORIAS){
                        strncpy(cats[ncat], nombreCat, sizeof(cats[ncat]) - 1);
                        cats[ncat][sizeof(cats[ncat]) - 1] = '\0';
                        ic = ncat;
                        ncat++;
                    } else {
                        if (!aviso_tope_cat_emitido){
                            printf("AVISO: Se alcanzo el maximo de categorias (%d). Algunas categorias adicionales no seran contabilizadas.\n", MAX_CATEGORIAS);
                            aviso_tope_cat_emitido = 1;
                        }
                    }
                }
            }


            if (id != -1 && ic != -1){
                float m = gastos[i].monto;
                if (usarValorCuotaEnTemporales == 1){
                    if (gastos[i].cuotasTotales > 1){
                        if (gastos[i].cuotasTotales != 0){
                            m = m / (float)(gastos[i].cuotasTotales); 
                        }
                    }
                }
                total_por_dni[id] += m;
                matriz[id][ic] += m;
                total_global += m;
            }
        }

        if (ndni == 0){
            printf("No hay DNIs asociados a gastos.\n");
            finalizado = 1;
        }
    }

    if (!finalizado){
        int idx_mayor = -1;
        float mayor_total = -1.0f;

        printf("\n--- DISTRIBUCION DE GASTOS POR PERSONA ---\n");
        printf("(Total general: $%.2f)\n", total_global);

        for (i = 0; i < ndni; i++){
            float pct_global = 0.0f;
            if (total_global > 0.0001f){
                pct_global = (total_por_dni[i] * 100.0f) / total_global;
            }

            {
                int personaEliminada = 1;
                st = 1;
                r = personaActiva(dnis[i], &st);
                if (r == 1){
                    personaEliminada = (st == 0);
                } else {
                    for (j = 0; j < ng; j++){
                        if (gastos[j].persona.dni == dnis[i] && gastos[j].persona.status == 1){
                            personaEliminada = 0;
                            break;
                        }
                    }
                }

                if (personaEliminada){
                    printf("\nPersona eliminada  | Total: $%.2f  | Participacion: %.2f%%\n",
                           total_por_dni[i], pct_global);
                } else {
                    printf("\nDNI: %ld  | Total: $%.2f  | Participacion: %.2f%%\n",
                           dnis[i], total_por_dni[i], pct_global);
                }
            }

            if (total_por_dni[i] > 0.0001f){
                int ic_max = -1;
                float cat_max = -1.0f;

                for (j = 0; j < ncat; j++){
                    if (matriz[i][j] > 0.0f){
                        float pct_persona = (matriz[i][j] * 100.0f) / total_por_dni[i];
                        printf("   - %-20s  $%9.2f  (%6.2f%%)\n", cats[j], matriz[i][j], pct_persona);
                        if (matriz[i][j] > cat_max){
                            cat_max = matriz[i][j];
                            ic_max = j;
                        }
                    }
                }

                if (ic_max != -1){
                    printf("   > Rubro principal: %s ($%.2f)\n", cats[ic_max], cat_max);
                }
            } else {
                printf("   - Sin consumo registrado.\n");
            }

            if (total_por_dni[i] > mayor_total){
                mayor_total = total_por_dni[i];
                idx_mayor = i;
            }
        }

        if (idx_mayor != -1){
            int ic_max = -1;
            float cat_max = -1.0f;
            for (j = 0; j < ncat; j++){
                if (matriz[idx_mayor][j] > cat_max){
                    cat_max = matriz[idx_mayor][j];
                    ic_max = j;
                }
            }
            printf("\nMayor nivel de gasto: ");
            {
                int personaEliminada = 1;
                st = 1;
                r = personaActiva(dnis[idx_mayor], &st);
                if (r == 1){
                    personaEliminada = (st == 0);
                } else {
                    for (j = 0; j < ng; j++){
                        if (gastos[j].persona.dni == dnis[idx_mayor] && gastos[j].persona.status == 1){
                            personaEliminada = 0;
                            break;
                        }
                    }
                }
                if (personaEliminada){
                    printf("Persona eliminada  | Total $%.2f", mayor_total);
                } else {
                    printf("DNI %ld  | Total $%.2f", dnis[idx_mayor], mayor_total);
                }
            }
            if (ic_max != -1){
                printf("  | Rubro principal: %s ($%.2f)\n", cats[ic_max], cat_max);
            } else {
                printf("\n");
            }
        }
    }

    return; 
}



	
	void consultaProyeccionAnual(){
		system ("cls");
		int finalizado = 0;
	    Ingreso ingresos[MAX_INGRESOS];
	    Gasto gastos[MAX_GASTOS];
	    int ni = 0, ng = 0;
	
	    int i;
	
	    time_t t = time(NULL);
	    struct tm *ptm = localtime(&t);
	    int mes_hoy = (*ptm).tm_mon + 1;
	    int anio_hoy = (*ptm).tm_year + 1900;
	
	    int meses[3], anios[3];
	    for (i = 0; i < 3; i++){
	        int m = mes_hoy - i, a = anio_hoy;
	        if (m <= 0){ m += 12; a -= 1; }
	        meses[i] = m; anios[i] = a;
	    }
	
	    ni = leerTodosIngresosStatic(ingresos, MAX_INGRESOS);
	    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
	
	    if (ni == 0 && ng == 0){
	        printf("No hay datos suficientes.\n");
	        finalizado = 1;
	    }
	
	    if (!finalizado){
	        float sumaIng = 0.0f, sumaGast = 0.0f;
	
	        for (i = 0; i < ni; i++){
	            int k;
	            for (k = 0; k < 3; k++){
	                if ((*(ingresos + i)).fecha.mes == meses[k] && (*(ingresos + i)).fecha.anio == anios[k]){
	                    sumaIng += (*(ingresos + i)).monto; break;
	                }
	            }
	        }
	        for (i = 0; i < ng; i++){
	            int k;
	            for (k = 0; k < 3; k++){
	                if ((*(gastos + i)).fecha.mes == meses[k] && (*(gastos + i)).fecha.anio == anios[k]){
	                    sumaGast += (*(gastos + i)).monto; break;
	                }
	            }
	        }
	
	        float promIng = sumaIng / 3.0f;
	        float promGas = sumaGast / 3.0f;
	        float saldoProm = promIng - promGas;
	
	        printf("\n--- PROYECCION ANUAL (12 meses desde el proximo) ---\n");
	        printf("Promedios ultimos 3 meses -> Ingresos:$%.2f  Gastos:$%.2f  Saldo:$%.2f\n", promIng, promGas, saldoProm);
	
	        int m = mes_hoy + 1, a = anio_hoy;
	        if (m > 12){ m = 1; a++; }
	
	        float mejor = -999999999.0f; int mm = -1, aa = -1;
	        float peor  =  999999999.0f; int mp = -1, ap = -1;
	
	        for (i = 0; i < 12; i++){
	            printf("%02d/%04d  | Saldo estimado: $%.2f\n", m, a, saldoProm);
	            if (saldoProm > mejor){ mejor = saldoProm; mm = m; aa = a; }
	            if (saldoProm < peor ){ peor  = saldoProm; mp = m; ap = a; }
	            m++; if (m > 12){ m = 1; a++; }
	        }
	
	        if (saldoProm >= 0.0f){
	            printf("Mes con mayor ahorro estimado: %02d/%04d  ($%.2f)\n", mm, aa, mejor);
	        } else {
	            printf("Posible deficit mensual constante. Peor mes estimado: %02d/%04d  ($%.2f)\n", mp, ap, peor);
	        }
	    }	
	}
	
void consultaEstadoGastoTemporal() {
	system ("cls");
    Gasto g;
    Gasto gastos[MAX_GASTOS];
    int ng = 0;
    float total = 0.0f; 
    float valorCuota = 0.0f;
    int h; 
    Pago pagos[MAX_PAGOS];
    int np = 0;
    int repBaseCode[MAX_GASTOS];
    char repDesc[MAX_GASTOS][50];
    long repDni[MAX_GASTOS];
    int repCuotasTot[MAX_GASTOS];
    int repCount = 0; 
    float planTotal = 0.0f;
    float totalPagado = 0.0f;
    float cuotaUnidad = 0.0f;
    int pagadasCalc = 0;
    float restoCuota = 0.0f;
    int incluyeEnCurso = 0;
    int pendientes = 0;
    int i, j;
    int valido = 0;     
    int continuarEjecucion = 1; 


    ng = leerTodosGastosStatic(gastos, MAX_GASTOS);
    if (ng == 0) {
        printf("No hay gastos registrados en el sistema.\n");
        continuarEjecucion = 0; 
    }


    if (continuarEjecucion == 1) {
        for (i = 0; i < ng; i++) {

            if (gastos[i].cuotasTotales > 1) {
                
                int base = gastos[i].codigo - (gastos[i].cuotaActual - 1);
                
                
                int existe = 0;
                for (j = 0; j < repCount; j++) {
                    if (repBaseCode[j] == base) { 
                        existe = 1; 
                        break; 
                    }
                }
                
                
                if (!existe && repCount < MAX_GASTOS) {
                    repBaseCode[repCount] = base;
                    
                    strncpy(repDesc[repCount], gastos[i].descripcion, 49);
                    repDesc[repCount][49] = '\0';
                    
                    repDni[repCount] = gastos[i].persona.dni;
                    repCuotasTot[repCount] = gastos[i].cuotasTotales;
                    repCount++;
                }
            }
        }

        if (repCount == 0) {
            printf("No hay gastos temporales (con cuotas) para listar.\n");
            continuarEjecucion = 0; 
        }
    }


    
    if (continuarEjecucion == 1) {
        printf("\n-- GASTOS TEMPORALES (PLANES DISPONIBLES) --\n");
        printf("COD  | DNI         | Cuotas | Valor cuota | Total | Descripcion\n");
        
        for (j = 0; j < repCount; j++) {
            
            Gasto gBase = encontrarGastoPorCodigo(repBaseCode[j]);
            
            if (gBase.codigo > 0) {
                total = gBase.monto;
                valorCuota = (repCuotasTot[j] > 0) ? 
                             total / (float)repCuotasTot[j] : total;
                
                printf("%-4d | %-9ld | %2d     | $%10.2f | $%.2f | %s\n",
                       repBaseCode[j], repDni[j], repCuotasTot[j], valorCuota, total, repDesc[j]);
            }
        }
    }


    
    if (continuarEjecucion == 1) {
        int codigoSeleccionado;
        valido = 0;
        do {
            codigoSeleccionado = validarINT("Seleccione CODIGO de plan (Base): ");
            for (j = 0; j < repCount; j++) {
                if (codigoSeleccionado == repBaseCode[j]) { 
                    valido = 1; 
                    break; 
                }
            }
            if (valido == 0) { 
                 printf("Codigo invalido. Intente nuevamente.\n");
            }
        } while (valido == 0);

       
        g = encontrarGastoPorCodigo(codigoSeleccionado);
        if (g.codigo <= 0 || g.cuotasTotales <= 1) {
            printf("Error: El gasto base seleccionado es inconsistente o no es un plan.\n");
            continuarEjecucion = 0; 
        }
    }

    
    
    if (continuarEjecucion == 1) {
        np = leerTodosPagosStatic(pagos, MAX_PAGOS);
        if (np < 0) np = 0;
        
        
        planTotal = g.monto;
        cuotaUnidad = (g.cuotasTotales > 0) ? planTotal / (float)g.cuotasTotales : planTotal;
        totalPagado = 0.0f;
        
       
        int codPlan[g.cuotasTotales];
        int ncod = 0;
        for (i = 0; i < g.cuotasTotales && ncod < g.cuotasTotales; i++) {
            codPlan[ncod++] = g.codigo + i; 
        }

        
        for (i = 0; i < np; i++) {
            for (j = 0; j < ncod; j++) {
                if (pagos[i].gastoCodigo == codPlan[j]) {
                    totalPagado += pagos[i].importe;
                    break;
                }
            }
        }
        
       

        if (totalPagado > planTotal - 0.001f) {
            totalPagado = planTotal;
        }

        pagadasCalc = 0;
        restoCuota = 0.0f;
        

        float epsilon = 0.005f; 

        if (cuotaUnidad > 0.0f) {
            
 
            pagadasCalc = (int)floor(totalPagado / cuotaUnidad);
            
 
            restoCuota = totalPagado - ((float)pagadasCalc * cuotaUnidad);


            if (cuotaUnidad - restoCuota < epsilon && pagadasCalc < g.cuotasTotales) {
                pagadasCalc++;      
                restoCuota = 0.0f;  
            }

            if (pagadasCalc > g.cuotasTotales) {
                 pagadasCalc = g.cuotasTotales;
            }
        }
        
        

        incluyeEnCurso = (restoCuota > epsilon) ? 1 : 0; 
        pendientes = g.cuotasTotales - pagadasCalc;
        
        if (incluyeEnCurso) {
            pendientes--; 
        }
        
        if (pendientes < 0) {
            pendientes = 0;
        }

    }


    
    if (continuarEjecucion == 1) {
        printf("\n--- HISTORIAL GASTO TEMPORAL (PLAN %d) ---\n", g.codigo);
        printf("Descripcion: %s | Responsable: %s | DNI: %ld\n",
               g.descripcion, g.persona.nombre, g.persona.dni);
        printf("Total Plan: $%.2f | Cuotas Totales: %d | Valor cuota: $%.2f\n",
               planTotal, g.cuotasTotales, cuotaUnidad);
        printf("-----------------------------------------------------------------\n");
        printf("Total Pagado (reconstruido): $%.2f\n", totalPagado);
        printf("Cuotas completas pagadas: %d\n", pagadasCalc);
        
        if (pagadasCalc < g.cuotasTotales) {
            if (incluyeEnCurso) {
                printf("Cuota %d EN CURSO | Restante por pagar: $%.2f\n",
                       pagadasCalc + 1, (cuotaUnidad - restoCuota));
            }
            printf("Cuotas pendientes de iniciar: %d\n", pendientes);
            printf("Saldo total restante: $%.2f\n", (planTotal - totalPagado));
            
            if (planTotal > 0.0001f) {
                printf("Avance total: %.2f%%\n", (totalPagado * 100.0f / planTotal));
            } else {
                printf("Avance total: 0.00%%\n");
            }
        } else {
            printf("Estado: TODAS LAS CUOTAS HAN SIDO CANCELADAS. (Avance: 100.00%%)\n");
        }
    }


    
    return;
}

// VISUALES
void pantallaCarga(void){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int ancho, centroX, centroY;
    const int MARCO_ANCHO = 60;
    const int MARCO_ALTO  = 15;
    const int BARRA_LEN   = 20;

    int x1, x2, y1, y2;
    int barraX, tituloX, msgX;
    int i;

    limpiar();


    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    ancho   = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    centroX = ancho / 2;
    centroY = 10;

    x1 = centroX - (MARCO_ANCHO/2);
    x2 = centroX + (MARCO_ANCHO/2);
    y1 = centroY - (MARCO_ALTO/2);
    y2 = centroY + (MARCO_ALTO/2);

    barraX  = centroX - (BARRA_LEN/2) - 1;  
    tituloX = centroX - 10;                  
    msgX    = centroX - 16;                  

    system("color 5E");
    dibujarMarco(x1, y1, x2, y2, 14, 5);

    
    setColor(14, 5);
    gotoxy(tituloX, y1 + 3);
    printf("CARGANDO SISTEMA...");


    gotoxy(barraX, y1 + 6); printf("[");
    for (i = 0; i < BARRA_LEN; i++) putchar(' ');
    putchar(']');


    for (i = 0; i <= BARRA_LEN; i++){

        gotoxy(barraX + 1 + i, y1 + 6);
        if (i < BARRA_LEN) putchar(219); 
        fflush(stdout);


        gotoxy(barraX + BARRA_LEN + 3, y1 + 6);
        printf("%3d%%", (i * 100) / BARRA_LEN);


        gotoxy(msgX, y1 + 8);
        if      (i == 0)                printf("Inicializando modulos...      ");
        else if (i == BARRA_LEN*1/4)    printf("Cargando datos de usuario...  ");
        else if (i == BARRA_LEN*2/4)    printf("Verificando archivos...       ");
        else if (i == BARRA_LEN*3/4)    printf("Preparando interfaz...        ");
        else if (i == BARRA_LEN)        printf("Listo para comenzar!          ");

        Sleep(120);
    }


    limpiar();
    dibujarMarco(centroX - 30, centroY - 3, centroX + 30, centroY + 3, 10, 0);
    setColor(10, 0);
    gotoxy(centroX - 17, centroY);
    printf("BIENVENIDO AL SISTEMA DE GESTION");
    Sleep(1200);

 
    setColor(15, 0);
    system("color 07");
    limpiar();
}

void animTransicionMenu(const char *mensaje){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int anchoCon, centroX, centroY;
    int cajaAncho, cajaAlto = 7;
    int x1, x2, y1, y2;
    int msgX, msgY;
    int i, pasos = 28;       
    const char spinner[] = "|/-\\";
    int len = (int)strlen(mensaje);

 
    cajaAncho = len + 12;
    if (cajaAncho < 42) cajaAncho = 42;

 
    limpiar();
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    anchoCon = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    centroX  = anchoCon / 2;
    centroY  = 10;

    x1 = centroX - (cajaAncho/2);
    x2 = centroX + (cajaAncho/2);
    y1 = centroY - (cajaAlto/2);
    y2 = centroY + (cajaAlto/2);

   
    dibujarMarco(x1, y1, x2, y2, 14, 0);
    setColor(14, 0);
    msgX = centroX - (len/2);
    msgY = y1 + 2;
    gotoxy(msgX, msgY);
    printf("%s", mensaje);

   
    setColor(11, 0);
    for (i = 0; i < pasos; i++){
       
        gotoxy(msgX - 2, msgY);
        putchar(spinner[i % 4]);

        
        gotoxy(msgX + len, msgY);
        switch (i % 4){
            case 0: printf("    "); break;
            case 1: printf(".   "); break;
            case 2: printf("..  "); break;
            default:printf("... "); break;
        }

       
        {
            int w = cajaAncho - 6;
            int baseX = x1 + 3;
            int yBar  = y1 + 4;
            int pos   = (i % (w-3));
            int j;

            gotoxy(baseX, yBar);
            for (j = 0; j < w; j++) putchar(' ');
            gotoxy(baseX + pos, yBar);   putchar(219);
            gotoxy(baseX + pos + 1, yBar); if (pos + 1 < w) putchar(219);
            gotoxy(baseX + pos + 2, yBar); if (pos + 2 < w) putchar(219);
        }

        Sleep(50);
    }

    setColor(10, 0);
    gotoxy(centroX - 9, y2); printf("Listo. Continuando...");
    Sleep(200);
    setColor(15, 0);
    limpiar();
}

void pantallaSalida(void){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int anchoCon, centroX, centroY;
    int cajaAncho, cajaAlto = 9;
    int x1, x2, y1, y2;
    int i, pasos = 60;              
    const char spinner[] = "|/-\\";
    const char *titulo   = "Saliendo del sistema";
    const char *sub      = "Gracias por usar el gestor";


    limpiar();
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    anchoCon = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    centroX  = anchoCon / 2;
    centroY  = 10;


    {
        int need = (int)strlen(sub) + 12;
        cajaAncho = need < 50 ? 50 : need;
    }

    x1 = centroX - (cajaAncho/2);
    x2 = centroX + (cajaAncho/2);
    y1 = centroY - (cajaAlto/2);
    y2 = centroY + (cajaAlto/2);


    dibujarMarco(x1, y1, x2, y2, 14, 0);


    setColor(14, 0);
    gotoxy(centroX - (int)strlen(titulo)/2, y1 + 2);
    printf("%s", titulo);


    setColor(11, 0);
    gotoxy(centroX - (int)strlen(sub)/2, y1 + 3);
    printf("%s", sub);


    {
        int baseX = x1 + 3;
        int w     = cajaAncho - 6;
        int yBar  = y1 + 5;


        setColor(8, 0);
        gotoxy(baseX, yBar);
        for (i = 0; i < w; i++) putchar(176); 

 
        setColor(10, 0);
        for (i = 0; i < pasos; i++){
            int fill = (i * w) / (pasos - 1);
            int k;

            gotoxy(baseX, yBar);
            for (k = 0; k < fill; k++) putchar(219);  

 
            setColor(14, 0);
            gotoxy(baseX + w + 2, yBar);
            putchar(spinner[i % 4]);

 
            gotoxy(centroX + (int)strlen(titulo)/2 + 1, y1 + 2);
            switch (i % 4){
                case 0: printf("    "); break;
                case 1: printf(".   "); break;
                case 2: printf("..  "); break;
                default:printf("... "); break;
            }

            setColor(10, 0);
            Sleep(25);
        }
    }


    setColor(10, 0);
    gotoxy(centroX - 8, y2);
    printf("Cerrando... OK");

    Sleep(300);
    setColor(15, 0);
    limpiar();
    return; 
}

void limpiar(void){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD numCells = 0, written = 0;
    COORD home = {0, 0};

    if (GetConsoleScreenBufferInfo(hOut, &csbi)){
        numCells = (DWORD)csbi.dwSize.X * (DWORD)csbi.dwSize.Y;
        FillConsoleOutputCharacterA(hOut, ' ', numCells, home, &written);
        FillConsoleOutputAttribute(hOut, csbi.wAttributes, numCells, home, &written);
        SetConsoleCursorPosition(hOut, home);
    }
    return; 
}

void gotoxy(int x, int y){
    COORD c;
    c.X = (SHORT)(x < 0 ? 0 : x);
    c.Y = (SHORT)(y < 0 ? 0 : y);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return; 
}

void setColor(int fg, int bg){
    WORD attr = (WORD)(((bg & 0x0F) << 4) | (fg & 0x0F));
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
    return; 
}

void dibujarMarco(int x1, int y1, int x2, int y2, int colorBorde, int colorFondo){
    const unsigned char TL = 201; 
    const unsigned char TR = 187; 
    const unsigned char BL = 200; 
    const unsigned char BR = 188; 
    const unsigned char H  = 205; 
    const unsigned char V  = 186; 

    int x, y, w, h;


    if (x2 < x1){ int t = x1; x1 = x2; x2 = t; }
    if (y2 < y1){ int t = y1; y1 = y2; y2 = t; }

    w = x2 - x1;
    h = y2 - y1;
    if (w < 2 || h < 2){
        
        setColor(colorBorde, colorFondo);
        for (y = y1; y <= y2; y++){
            for (x = x1; x <= x2; x++){
                gotoxy(x, y); putchar(' ');
            }
        }
        return; 
    }


    setColor(colorBorde, colorFondo);
    gotoxy(x1, y1); putchar(TL);
    for (x = x1 + 1; x < x2; x++){ putchar(H); }
    putchar(TR);


    for (y = y1 + 1; y < y2; y++){
        gotoxy(x1, y); putchar(V);

        
        setColor(colorBorde, colorFondo);
        for (x = x1 + 1; x < x2; x++){ putchar(' '); }

        setColor(colorBorde, colorFondo);
        putchar(V);
    }

 
    gotoxy(x1, y2); putchar(BL);
    for (x = x1 + 1; x < x2; x++){ putchar(H); }
    putchar(BR);

   
    setColor(15, 0);
    return; 
}

void uiSetAnimaciones(int on){
    g_uiAnim = (on ? 1 : 0);
}

void uiTransicionEntrada(const char *titulo){
    if (!g_uiAnim) return;               
    char msg[128];
    snprintf(msg, sizeof(msg), "Ingresando a %s", titulo);
    animTransicionMenu(msg);             
}




#endif
