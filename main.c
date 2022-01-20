#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>


#define FIL 4
#define COL 6
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


///funciones de menu
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

///
void gotoxy(int x, int y);
void centrar_Texto(const char *texto, int y);
void matrizDinamica(int mes,stConsumo g[],int v);
int pasarArreglodias(int a[],int dim,stConsumo g[],int mes);
void jefeOrdenador(int a[],int v,stConsumo g[]);


int main()
{
    float promedio;
    int cantRegistros;
    int dato;
    int dniBuscado;
    char apellidoBuscado[30];
    stCliente a;
    stConsumo g;



    stConsumo consumoArray[DIM_CLI];
    stConsumo arregloDeDias[DIM_CLI];
    int validosConsumo=0;
    int validosDias=0;
    int arregloSumas[10];
    int arregloConsumos[DIM_CLI];

    int validosSuma=0;
    int validosUltra=0;
    char arregloMeses[][DIM_CLI]={"Enero","Febrero","Marzo","Abril","Mayo","Junio"};

    int dia;
    int mes;
    int veces;
    int cantConsumo;
    float porcentajemesx=0;
    int sumatotaldatos=0;
    int posMenor;
    int posMayor;

    char opcionPricipal;
    char opcion;
    char opcion2;
    char opcionConsumo;

    stCliente clientes[DIM_CLI];
    int vClientes=0;
    int clientesrandom=0;

     gotoxy(15,10);

     system("color 70");
     centrar_Texto("UTMOVIL\n\n\n\n\n\n\n\n\n\n\n\n\n\n",8);
     system("pause");



    do
    {
        system("cls");
        menuPrincipal();
        opcionPricipal=getch();
        system("cls");
        switch(opcionPricipal)
        {
        case '1':
            do
            {
                system("cls");
                Menu();
                opcion=getch();
                system("cls");
                switch(opcion)
                {
                case '1':
                    cargaCLientes();
                    break;
                case '2':
                    do
                    {
                        system("cls");
                        Submenu();
                        opcion2=getch();
                        system("cls");
                        switch(opcion2)
                        {
                        case '1':
                            mostrarArchivoClientes();
                            break;
                        case '2':
                            mostrarArchivoClientesActivos();
                            break;
                        case '3':
                            mostrarArchivoClientesInactivos();
                            break;
                        case '4':
                            DarDeBajax();
                            break;

                        case '5':
                            DarDeAltax();
                            break;
                        case '6':
                            modificarCliMenus();
                        default:
                            printf("\nOpcion equivocada,Presione ESC para volver al menu General\n");
                            break;
                        }
                        system("pause");
                    }
                    while(opcion2!=ESC);
                    ///El submenu esta contenido en el case 1 del menu  de Clientes
                    break;
                case '3':
                    cantRegistros=cuentaRegistro(AR_CLIENTES,sizeof(stCliente));
                    printf("La Cantidad de registros es:%d \n",cantRegistros);
                    break;
                case '4':
                    printf("\nIngrese Numero de DNI a buscar\n");
                    scanf("%d",&dniBuscado);
                    a=buscaClientePorDni(dniBuscado);
                    if(a.id!=-1)
                    {
                        printf("\nEl cliente con el DNI %d Fue encontrado exitosamente.\n",dniBuscado);
                        mostrarUnClienteId(a);
                    }
                    else
                    {
                        printf("\nEl cliente con el DNI %d NO existe.\n",dniBuscado);
                    }
                    break;
                case '5':
                    printf("\nIngrese APELLIDO a buscar\n");
                    fflush(stdin);
                    gets(apellidoBuscado);
                    a=buscaClientePorApellido(apellidoBuscado);
                    if(a.id!=-1)
                    {
                        printf("\nEl cliente con el apellido %s Fue encontrado exitosamente.\n",apellidoBuscado);
                        mostrarUnClienteId(a);
                    }
                    else
                    {
                        printf("\nEl cliente con el apellido %s NO existe.\n",apellidoBuscado);
                    }
                    break;
                case '6':
                    ordenarDNIS(a);
                    break;
                case '7':
                    ordenarApellidos(a);
                    break;
                case '8':
                    ordenarEmails(a);
                    break;
                case '9':
                    printf("\n Cantidad de Clientes Random: ");
                    scanf("%d",&clientesrandom);
                    vClientes=funcion00(clientes,vClientes,clientesrandom);
                    break;
                default:
                    printf("\nOpcion equivocada,Presione ESC para Volver al Inicio.\n");
                    break;
                }
                system("pause");
            }
            while(opcion!=ESC);
            break;
        case '2':
            do
            {
                system("cls");
                consumoMenu();
                opcionConsumo=getch();
                system("cls");
                switch(opcionConsumo)
                {

                case '1':
                    cargaConsumosTeclado();
                    break;
                case '2':
                    printf("\nIngrese la Cantidad de consumos que quiera crear: ");
                    scanf("%d",&veces);
                    centrar_Texto("PRESIONE UNA TECLA Y ESPERE A QUE TERMINE DE CARGAR\n\n",8);
                    system("pause");
                    cargaConsumos(veces);
                    break;
                case '3':
                   mostrarArchivoConsumos();
                   break;
                case '4':
                     printf("\nIngrese Numero de mes:");
                    scanf("%d",&mes);
                    printf("\nIngrese Numero de dia:");
                    scanf("%d",&dia);
                    g=buscaConsumoPorFecha(mes,dia);

                    printf("\n");

                    if(g.id!=-1){
                    printf("La fecha %d/%d tiene el consumo\n",mes,dia);
                    mostrarUnConsumo(g);
                    }
                    else{
                        printf("La fecha %d/%d NO tiene consumos Registrados\n",mes,dia);
                    }

                    break;
               case '5':
                        cantConsumo=cuentaRegistro(AR_CONSUMOS, sizeof(stConsumo));
                        printf("La Cantidad de consumos es:%d \n",cantConsumo);
                    break;

               case '6':
                        modificarConsumosSubMenu();
                    break;

                default:
                    printf("\nOpcion equivocada,Presione ESC para Volver al Inicio.\n");
                  break;
               case '7':
                do{
                 printf("\nIngrese el mes para ver sus consumos: ");
                 scanf("%d",&dato);
                 if(dato<1 || dato>12)
                 {
                  printf("\nMes no valido, Por favor intente nuevamente.\n");
                 }
                 }while(dato<1 ||  dato>12);
                 ordenarMES(g,dato);
                 break;
               case '8':
                printf("\n");
                muestraSumaDatos(g);
                sumatotaldatos = sumadatosAll(g);
                printf("\nSUMA TOTAL DATOS: %d\n",sumatotaldatos);
                porcentajemesx = sumadatosAll(g);
                porcentajemesx = PorcentajeMesConsumo(porcentajemesx);
                printf("\nPromedio datos consumidos por mes: %.2fMBs\n",porcentajemesx);
                printf("\n\n");
                promedio=promedioXdia();
                printf("\nEl Promedio datos consumidos por dia: %.2fMBs\n",promedio);
                printf("\n\n");
                validosSuma=pasarArraySumaDatos(g,arregloSumas,validosSuma);
                posMenor=buscaPosMenorConsumoMes(arregloSumas,validosSuma);
                printf("\nEl mes con MENOR consumo:%s(%d): %dMBs\n",arregloMeses[posMenor],posMenor+1,arregloSumas[posMenor]);
                validosSuma=pasarArraySumaDatos(g,arregloSumas,validosSuma);
                posMayor=buscaPosMayorConsumoMeees(arregloSumas,validosSuma);
                printf("\nEl mes con MAYOR consumo:%s(%d): %dMBs\n",arregloMeses[posMayor],posMayor+1,arregloSumas[posMayor]);
                porcentajeClientesActivos_Inactivos();
                break;

                case '9':
                validosConsumo=archivo2ArrayConsumosEnteros(g,consumoArray,validosConsumo,DIM_CLI);
                ordenarArrayConsumosPorMes(consumoArray,validosConsumo);
                validosDias=ordenarArrayConsumosPorDiaYMes(consumoArray,validosConsumo,arregloDeDias);
                printf("\nConsumos Ordenados por dia-:\n");
                ordenarSelDia(arregloDeDias,validosDias);///en este tengo los dias, tecnicamente es una copia del otro arreglo,pero
                muestraConsumos(arregloDeDias,validosDias);///cuando tengamos que hacer la matriz, va a servir mucho tener copias.
                break;
                case 'a':
                    CargoMatrix(FIL,COL,g);
                    break;
                }

            system("pause");
            }while(opcionConsumo!=ESC);
         break;
        }

    }
    while(opcionPricipal!=ESC);

    return 0;
}
