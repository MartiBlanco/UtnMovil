#ifndef PROTOTIPADOSYCABECERAS_H_INCLUDED
#define PROTOTIPADOSYCABECERAS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>


#define ESC 27
#define DIM_CLI 100
#define AR_CLIENTES "clientes.dat"
#define AR_CONSUMOS "consumos.dat"

typedef struct
{
    int id;///unico y autoIncremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    int dni;
    char email[30];
    char domicilio[30];
    int movil;
    int baja;///0(activado o 1(elimando)
} stCliente;


typedef struct
{
    int id;  /// campo único y autoincremental
    int idCliente;
    int anio;///actual
    int mes; /// 1 a 12
    int dia; /// 1 a … dependiendo del mes
    int datosConsumidos;  /// expresados en mb.
    int baja; /// 0 si está activo - 1 si está eliminado
} stConsumo;



int getNroCliente();
void getNombre(char n[]);
void getApellido(char a[]);
int getDNI();
void getCalle(char c[]);
int getCalleNro();
stCliente cargoRegistroClienteRandom();
void menuPrincipal();
void Menu();
void Submenu();
void consumoMenu();
///funciones con structuras
stCliente cargaUnClienteConId();
void mostrarUnClienteId(stCliente c);

void cargaArchivoCLientes(stCliente c);
void cargaCLientes();

void mostrarArchivoClientes();
void mostrarArchivoClientesActivos();
void mostrarArchivoClientesInactivos();

int cuentaRegistro(char nombreArchivo[],int dato);

int buscaUltimoId();
int buscaUnClienteDNIArchivo(int dni);
int buscaUnNroClienteArchivo(int nroCliente);

///funciones de modificacion
void modificarCliMenus();
stCliente traeCliente(int id);
int buscaPosicion(int id);
int validaEmail(char email[]);
void modificarnombre(stCliente c);
void modificarNombrex();
void ModificarMovil();
void ModificarMovilx();
void ModificarDomicilio();
void ModificarDomiciliox();
void ModificarEmail();
void ModificarEmailx();
void ModificarDNI();
void ModificarDNIx();
void ModificarApellido(stCliente c);
void ModificarApellidox();
void DarDeBajax();
void DarDeBaja(stCliente c);
void DarDeAltax();
void DarDeAlta(stCliente c);
///busqueda
stCliente buscaClientePorApellido(char apellido[]);
stCliente buscaClientePorDni(int dni);
///Ordenamientos
void CambiaValoresCliente(stCliente *a,stCliente *b);
int buscaMenorPosDni(stCliente a[],int v,int inicio);
void ordenarSelDni(stCliente a[],int v);
int buscaMenorPosApe(stCliente a[],int v,int inicio);
int buscaMenorPosEmail(stCliente a[],int v,int inicio);
void OrdenarSelEmail(stCliente a[],int v);
void muestraClientes(stCliente c[], int v);
void ordenarDNIS(stCliente a);
int archivo2arrayActivos(stCliente a,stCliente c[DIM_CLI]);
int archivo2arrayBaja(stCliente a,stCliente c[DIM_CLI]);
void ordenarApellidos(stCliente a);
void ordenarSelApe(stCliente a[],int v);
 void ordenarEmails(stCliente a);
 void muestraUnCliente(stCliente c);
///Consumos
int rangoRandom(int min,int max);
stConsumo cargarConsumosRandom();
int buscaUltimoIdConsumos();
int CalcularDias(int mes,int anio);
void mostrarUnConsumo(stConsumo g);
void cargaArchivoConsumos(stConsumo g);

void cargaConsumos(int veces);
void mostrarArchivoConsumos();
stConsumo buscaConsumoPorFecha(int mes,int dia);
int existenConsumos(int mes,int dia,int idCliente,int baja);
//int existenConsumos(stConsumo g);
stConsumo cargaConsumoCliente();

void cargaClienteConsumos();
void cargaConsumosTeclado();
///Modificar Consumo
stConsumo traeConsumo(int id);
void modificaConsumo(stConsumo g);
void modificarConsumo();
void modificaEstadoBajaConsumo(stConsumo g);
void modificarConsumoBaja();
void modificaEstadoAltaConsumo(stConsumo g);
void modificarConsumoAlta();
void modificarConsumosSubMenu();
void muestraUnConsumo(stConsumo c);
void muestraConsumos(stConsumo c[], int v);
int ordenarMES(stConsumo a,int dato);
int archivo2arrayConsumos(stConsumo a,stConsumo c[DIM_CLI],int dato);
float calcularporcentaje2(stConsumo a,int dato);
float PorcentajeMesConsumo(int total);
int pasarArraySumaDatos(stConsumo a,int arraySumas[],int v);
void mostrarArray(int a[],int v);
int buscaPosMenorConsumoMes(int a[],int v);
///MAYOR
int buscaMayorPosDdia(stConsumo g[],int v,int inicio,int mes);
void ordenarSelDddia(stConsumo g[],int v);
int ordenarArrayConsumosPorDiaYMmes(stConsumo g[],int v,stConsumo arreglodias[]);
int buscaMayorPosMmes(stConsumo g[],int v,int inicio);
void ordenarArrayConsumosPorMmmes(stConsumo g[],int v);
int buscaPosMayorConsumoMeees(int a[],int v);
int buscaPosMenorConsumoMes(int a[],int v);
int cuentaClientesPositivos();
int cuentaClientesNegativos();
void porcentajeClientesActivos_Inactivos();
int sumatoriaDeDias();
float promedioXdia();
int funcion00(stCliente c[], int v, int dim);
void arreglo2archivo(stCliente a[],int v);
int buscaUnNroMovilArchivo(int movil);
int getMovilCliente();

///
void gotoxy(int x, int y);
void centrar_Texto(const char *texto, int y);




///los prototipados se ponen entre ifndef linea 1 y el end if de la linea de abajo
#endif // PROTOTIPADOSYCABECERAS_H_INCLUDED
