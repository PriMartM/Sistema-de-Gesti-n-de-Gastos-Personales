/**************************************************************
 * TPI PE 2025 - Sistema de Gestion de Gastos Personales
 * Godoy, Tomas - 68081.
 * Martinez, Mariana Priscila - 67869.
 * Moreno, Francisco - 67617.
 * Scheuermann, Renata - 67613.
 *--------------------------------------------------------------
 ***************************************************************/ 
#include "estructuras.h"  
#include "funciones.h"  



// NOMBRES DE ARCHIVO

const char *ARCH_GASTOS = "gastos.dat";
const char *ARCH_INGRESOS = "ingresos.dat";
const char *ARCH_PAGOS = "pagos.dat";
const char *ARCH_CATEGORIAS = "categorias.dat";
const char *ARCH_PERSONAS = "personas.dat";

//PRESENTACION 
int g_uiAnim = 1;

/* ----------------------------- MAIN DEL PROGRAMA ------------------------------- */

	int main(){
	pantallaCarga();
	static Categoria categorias[MAX_CATEGORIAS];
    int nc_count = 0;
    int *nc = &nc_count;
    static Persona personas[MAX_PERSONAS];
    int np = 0;
    nc_count = cargarCategoriasStatic(categorias, MAX_CATEGORIAS);
    printf("TPI PE 2025 - Sistema de Gestion de Gastos Personales\n");
    menuPrincipal(categorias, nc, personas, &np);

	return 0;
}