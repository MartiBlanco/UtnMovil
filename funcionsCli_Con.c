#include "prototipadosYcabeceras.h"

///brief Funcion que retorna un Nro de Cliente al azar
///return int
int rangoRandom(int min,int max)
{
    return rand()%(max-min)+min;
}

int getNroCliente(){
    int repetido;
    int validacion;
    do{
    repetido=rangoRandom(1,99999);
    validacion=buscaUnNroClienteArchivo(repetido);
    }while(validacion!=0);

return repetido;
}

int getMovilCliente(){
  int repetido;
  int validacion;
  do{
    repetido=rangoRandom(223578434,223999999);
    validacion=buscaUnNroMovilArchivo(repetido);
  }while(validacion!=0);
  return repetido;
}

/*************************************************************//**
*
* \brief Funcion que asigna al string recibido un nombre al azar
* \return void
*
*****************************************************************/
void getNombre(char n[]){
    char nombres[][30] = {"Amalio","Juan","Roberto","Antonio","Fernando","Anibal","Mariano","Jose",
                           "Anastasio","Arturo","Mario","Tamaro","Adolfo","Pedro","Alfredo","Arnaldo",
                           "Mauro","Benicio","Ildefonso","Cuchuflito","Remilgo","Miguel","Reinaldo"};

    strcpy(n,nombres[rangoRandom(0,sizeof(nombres)/(sizeof(char)*30))]);
}

/*************************************************************//**
*
* \brief Funcion que asigna al string recibido un apellido al azar
* \return void
*
*****************************************************************/
void getApellido(char a[]){
    char apellidos[][30] = {"Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "San Martin", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "De Antonio", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "San Juan", "Bautista", "Anchorena", "Paso",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Black"};

    strcpy(a,apellidos[rangoRandom(0,sizeof(apellidos)/(sizeof(char)*30))]);
}

/*********************************************************//**
*
* \brief Funcion que retorna un DNI de Cliente al azar
* \return int
*
*************************************************************/
int getDNI(){
    return rangoRandom(549,1982)* rangoRandom(549,19801);
}

/*************************************************************//**
*
* \brief Funcion que asigna al string recibido una calle al azar
* \return void
*
*****************************************************************/
void getCalle(char c[]){
    char calles[][30] = {"San Juan","Funes","Gaboto","San Martin","Colon","Rivadavia", "Alsina", "Roca", "Mitre", "Belgrano",
                            "Paso", "11 de Septiembre", "3 de Febrero", "Balcarce", "Libertad", "Magallanes", "Irala", "Ayolas", "Moreno", "Brown",
                            "Bolivar", "Alberti", "Gascon", "La Rioja", "Catamarca", "Salta", "Jujuy", "XX de Septiembre", "14 de Julio", "Dorrego",
                            "Hernandarias","Don Orione","Juramento","Lanzilota","Estrada","Tierra del Fuego","Mendoza","Chubut","Rio Negro","Misiones","Edison"};

    strcpy(c,calles[rangoRandom(0,sizeof(calles)/(sizeof(char)*30))]);
}

/*********************************************************//**
*
* \brief Funcion que retorna un Nro de calle de Cliente al azar
* \return int
*
*************************************************************/
int getCalleNro(){
    return rangoRandom(50,10000);
}

stCliente cargoRegistroClienteRandom(){
    stCliente c;

    c.id=buscaUltimoId()+1;
    c.nroCliente=getNroCliente();
    getNombre(c.nombre);
    getApellido(c.apellido);
    c.dni=getDNI();
    strcpy(c.email,c.nombre);
    strcat(c.email,"_");
    strcat(c.email,c.apellido);
    strcat(c.email,"@gmail.com");

    getCalle(c.domicilio);
    char nro[5];
    strcat(c.domicilio," ");
    strcat(c.domicilio, itoa(getCalleNro(),nro,10));
    c.movil = getMovilCliente();
    c.baja=0;
    return c;
}

int funcion00(stCliente c[], int v, int dim){
    int ultimoid=0;
    int contador=0;
    printf("\n Cargando Clientes");
    ultimoid= buscaUltimoId()+1;
    c[v]=cargoRegistroClienteRandom();
    c[v].id = ultimoid;
    contador++;
    v++;
    while(v<dim){
        c[v]=cargoRegistroClienteRandom();
        fflush(stdin);
        c[v].id=ultimoid+contador++;
        v++;

    }
    arreglo2archivo(c,v);;

    printf("\n Cargados exitosamente...\n");
    return v;
}

void arreglo2archivo(stCliente a[],int v){
 FILE *pArchClientes = fopen(AR_CLIENTES,"ab");
 if(pArchClientes){
    fwrite(a,sizeof(stCliente),v,pArchClientes);
    fclose(pArchClientes);
 }
}


void menuPrincipal()
{
    system("color F");

    centrar_Texto("Seleccione:",5);
    centrar_Texto("1-Clientes",8);
    centrar_Texto("2-Consumos",11);

    centrar_Texto("Presione ESC para Salir",15);

}

void Menu()
{
    system("color A");

    printf("\n\t\tCLIENTES\n");

    printf("\n1-Cargar clientes\n");
    printf("\n2-Mostrar un distintos archivos clientes\n");
    printf("\n3-Contar numero de Registros\n");
    printf("\n4-Buscar Clientes por DNI\n");
    printf("\n5-Buscar Clientes por Apellido\n");
    printf("\n6-Ordenar Clientes por DNI (ACTIVOS)\n");
    printf("\n7-Ordenar Clientes por apellidos (ACTIVOS)\n");
    printf("\n8-Ordenar Clientes por E-Mails (INACTIVOS)\n");
    printf("\n9-Cargar Clientes Random.\n");

    printf("\nPresione ESC para Salir\n");


}
void consumoMenu()
{
    system("color E");

    printf("\n\t\tCONSUMOS\n");

    printf("\n1-Cargar consumos Por Teclado\n");
    printf("\n2-Cargar Consumos Aleatorios\n");
    printf("\n3-Mostrar todos los consumos\n");
    printf("\n4-Buscar Un Cliente por Fecha\n");
    printf("\n5-Cuenta Consumos\n");
    printf("\n6-Modificar Consumos\n");
    printf("\n7-Mostrar consumos por mes\n");
    printf("\n8-Estadisticas Consumos\n");
    printf("\n9-Ordenar Consumos por dia\n");
    printf("\na-Matriz muestra consumo activos y inactivos\n");
    printf("\nPresione ESC para Salir\n");


}
void Submenu()
{

    system("color B");
    printf("\n\t\tSubMenu\n");
    printf("\n1-Mostrar todos los Clientes\n");
    printf("\n2-Mostrar Clientes Activos \n");
    printf("\n3-Mostrar Clientes Inactivos\n");
    printf("\n4-Dar de baja un cliente\n");
    printf("\n5-Dar de alta un cliente\n");
    printf("\n6-Modificar Cliente\n");


    printf("\nPresione ESC para Volver al menu General\n");


}

///Primer pantalla
void gotoxy(int x, int y)
{
    HANDLE ubi;
    ubi = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(ubi,pos);
}

int whereX(){                                                                     /// Devuelve la posicion de X
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.X;
}

int whereY(){                                                                   /// Devuelve la posicion de Y
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.Y;
}
void centrar_Texto(const char *texto, int y)
{
    int size_texto=strlen(texto);
    gotoxy(45-(size_texto/2),y);
    printf("%s",texto);
}
///


stCliente cargaUnClienteConId()
{
    stCliente c;
    int repetido;
    int repetido2;
    int baja=0;///todos se cargan activos primeramente

    c.id=buscaUltimoId()+1;
    ///este ciclo sirve para validar la carga del numero de cliente
    do
    {
        printf("\nIngrese nro de Cliente.:");
        fflush(stdin);
        scanf("%d",&c.nroCliente);
        repetido=buscaUnNroClienteArchivo(c.nroCliente);
        if((c.nroCliente<0 ||  c.nroCliente>9999999) || repetido!=0)
        {

            printf("\n!!!!Error en la carga, Por favor intente nuevamente.\n");
        }
    }
    while((c.nroCliente<0 ||  c.nroCliente>9999999) || repetido!=0);


    printf("\nIngrese Nombre.........:");
    fflush(stdin);
    gets(c.nombre);
    printf("\nIngrese Apellido.......:");
    fflush(stdin);
    gets(c.apellido);

    do{
     printf("\nIngrese Dni............:");
     scanf("%d",&c.dni);
     repetido2=buscaUnClienteDNIArchivo(c.dni);
     if(repetido2!=0){
        printf("\n¡¡Error En la carga,intente Nuevamente Por favor.\n");
      }
    }while(repetido2!=0);
    ///con esto verifico que no haya dnis repetidos
    do
    {
        printf("\nIngrese el EMail...........: ");
        fflush(stdin);
        gets(c.email);
        if(!validaEmail(c.email))
        {
            printf("\n!!!!Error en la carga, Por favor intente nuevamente.\n");
        }
    }
    while(!validaEmail(c.email));
    printf("\nIngrese Domicilio......:");
    fflush(stdin);
    gets(c.domicilio);
    printf("\nIngrese Movil..........:");
    scanf("%d",&c.movil);
    c.baja=baja;

    return c;
}

void mostrarUnClienteId(stCliente c)
{

    printf("\n-----------------------\n");
    printf("\nNumero Id..:%d",c.id);
    printf("\nNroCliente.:%d",c.nroCliente);
    printf("\nNombre.....:%s",c.nombre);
    printf("\nApellido...:%s",c.apellido);
    printf("\nDni........:%d",c.dni);
    printf("\nEmail......:%s",c.email);
    printf("\nDomicilio..:%s",c.domicilio);
    printf("\nMovil......:%d",c.movil);
    printf("\nBaja.......:%d\n",c.baja);
    printf("\n-----------------------\n");
}

void cargaArchivoCLientes(stCliente c)
{

    FILE *archi=fopen(AR_CLIENTES,"ab");
    if(archi!=NULL)
    {
        fwrite(&c,sizeof(stCliente),1,archi);
        fclose(archi);
    }
}

void cargaCLientes()
{

    char opcion;

    while(opcion!=ESC)
    {
        system("cls");
        printf("\nCarga de Clientes\n");

        cargaArchivoCLientes(cargaUnClienteConId());
        ///primero se carga el cliente y luego se guarda en el archivo con cargaArhivosClientes

        printf("\nPresione ESC para dejar de cargar\n");
        fflush(stdin);
        opcion=getch();
    }

}


void mostrarArchivoClientes()
{
    stCliente c;

    FILE *archi=fopen(AR_CLIENTES,"rb");

    if(archi!=NULL)
    {

        while(fread(&c,sizeof(stCliente),1,archi) >0)
        {
            mostrarUnClienteId(c);
        }
        fclose(archi);
    }
}

void mostrarArchivoClientesActivos()
{
    stCliente c;

    FILE *archi=fopen(AR_CLIENTES,"rb");

    if(archi!=NULL)
    {

        while(fread(&c,sizeof(stCliente),1,archi) >0)
        {
            if(c.baja==0)
            {
                mostrarUnClienteId(c);
            }
        }
        fclose(archi);
    }
}
void mostrarArchivoClientesInactivos()
{
    stCliente c;

    FILE *archi=fopen(AR_CLIENTES,"rb");

    if(archi!=NULL)
    {

        while(fread(&c,sizeof(stCliente),1,archi) >0)
        {
            if(c.baja==1)
            {
                mostrarUnClienteId(c);
            }
        }
        fclose(archi);
    }
}

/*********************************************************************//**
*
* \brief Cuenta la cantidad de clientes en el archivo
* \param Recibe el archivo y dato es el sizeof del cliente
* \return Retorna la cantidad de elementos en el archivo
*
**************************************************************************/

int cuentaRegistro(char nombreArchivo[],int dato) ///dato va a ser el sizeof de stCliente
{

    int total=0;

    FILE *archi=fopen(nombreArchivo,"rb");

    if(archi!=NULL)
    {
        fseek(archi,0,SEEK_END);
        total=ftell(archi)/dato;

        fclose(archi);
    }
    return total;
}

int buscaUltimoId()
{
    stCliente c;
    int id=-1;

    FILE *archi=fopen(AR_CLIENTES,"rb");

    if(archi!=NULL)
    {

        fseek(archi,sizeof(stCliente)*-1,SEEK_END);
        if(fread(&c,sizeof(stCliente),1,archi)>0)
        {
            id=c.id;
        }
        fclose(archi);
    }

    return id;
}

int buscaUltimoIdConsumos()
{
    stConsumo g;
    int id=-1;

    FILE *archi=fopen(AR_CONSUMOS,"rb");

    if(archi!=NULL)
    {

        fseek(archi,sizeof(stConsumo)*-1,SEEK_END);
        if(fread(&g,sizeof(stConsumo),1,archi)>0)
        {
            id=g.id;
        }
        fclose(archi);
    }

    return id;
}

int buscaUnClienteDNIArchivo(int dni)
{
    int flag = 0;
    stCliente c;
    FILE *pArch = fopen(AR_CLIENTES, "rb");
    if(pArch!=NULL)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente),1,pArch) > 0)
        {
            if(c.dni==dni)
            {
                flag=1;
            }
        }
        fclose(pArch);
    }

    return flag;
}

int buscaUnNroClienteArchivo(int nroCliente){
    int flag = 0;
    stCliente c;
    FILE *pArch = fopen(AR_CLIENTES, "rb");
    if(pArch!=NULL)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente),1,pArch) > 0)
        {
            if(c.nroCliente==nroCliente)
            {
                flag=1;
            }
        }
        fclose(pArch);
    }

    return flag;
}

int buscaUnNroMovilArchivo(int movil)
{
    int flag = 0;
    stCliente c;
    FILE *pArch = fopen(AR_CLIENTES, "rb");
    if(pArch!=NULL)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente),1,pArch) > 0)
        {
            if(c.movil==movil)
            {
                flag=1;
            }
        }
        fclose(pArch);
    }

    return flag;
}




void modificarCliMenus()
{
    char opcion;
    do
    {
        system("cls");
        printf("\n MODIFICACION DE CLIENTES...\n");
        printf("\n 1-Modificar Nombre");///tenemos que pensar en poder modificar el NroCliente
        printf("\n 2-Modificar Apellido");
        printf("\n 3-Modificar DNI");
        printf("\n 4-Modificar email");
        printf("\n 5-Modificar Domicilio");
        printf("\n 6-Modificar Telefono Movil");
        printf("\n\n");
        printf("\n ESC para salir...");
        opcion=getch();
        switch(opcion)
        {
        case 49:
            modificarNombrex();
            break;
        case 50:
            ModificarApellidox();
            break;
        case 51:
            ModificarDNIx();
            break;
        case 52:
            ModificarEmailx();
            break;
        case 53:
            ModificarDomiciliox();
            break;
        case 54:
            ModificarMovilx();
            break;
        default:
            printf("\n Opcion incorrecta");
        }
        system("pause");
    }
    while(opcion!=27);
}


int buscaCliente(int id)
{
    int flag=-1;
    stCliente c;
    FILE *pArchClientes = fopen(AR_CLIENTES, "rb");
    if(pArchClientes)
    {
        while(flag == -1 && fread(&c, sizeof(stCliente), 1, pArchClientes) > 0)
        {
            if(c.id==id)
            {
                flag=1;
            }
        }
        fclose(pArchClientes);
    }
    return flag;
}
/*********************************************************************//**
*
* \brief Busca posicion del cliente por ID
* \param ID de cliente a buscar
* \return -1 si no existe - Retorna la posicion del cliente si existe
*
**************************************************************************/
int buscaPosicion(int id)
{
    int pos=-1;
    stCliente c;
    FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
    if(pArchClientes)
    {
        while(pos == -1 && fread(&c, sizeof(stCliente), 1, pArchClientes) > 0)
        {
            if(c.id == id)
            {
                pos = ftell(pArchClientes)/sizeof(stCliente)-1;
            }
        }
        fclose(pArchClientes);
    }

    return pos;
}
/*********************************************************************//**
*
* \brief Retorna el cliente a buscar
* \param Ingresa la ID del cliente a buscar
* \return int 0 si no existe - 1 si existe
*
**************************************************************************/

stCliente traeCliente(int id)
{
    stCliente c;
    int flag = 0;
    FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
    if(pArchClientes)
    {
        while(flag==0 && fread(&c,sizeof(stCliente),1,pArchClientes)>0)
        {
            if(c.id == id)
            {
                flag = 1;
            }
        }
        fclose(pArchClientes);
    }

    if(flag==1){
    return c;
    }
    else{
        printf("Id:%d no Existente.",id);
        printf("\nIngrese id correcto:");
        scanf("%d",&id);
        traeCliente(id);
    }
}


stConsumo traeConsumo(int id)
{
    stConsumo g;
    int flag = 0;
    FILE  *pArchConsumo = fopen(AR_CONSUMOS,"rb");
    if(pArchConsumo)
    {
        while(flag==0 && fread(&g,sizeof(stConsumo),1,pArchConsumo)>0)
        {
            if(g.id == id)
            {
                flag = 1;
            }
        }
        fclose(pArchConsumo);
    }
    if(flag==1){
        return g;
    }
    else{
       printf("\nError,ingrese id nuevamente.\n");
       scanf("%d",&id);
       traeConsumo(id);
    }
}
/*********************************************************************//**
*  FUNCIONES DE MODIFICACIONES
* \brief Modifica el campo de cliente que seleccine
*  SE SELECCIONA EL CAMPO A MODIFICAR DEL CLIENTE, LO TRAE POR ID Y
*  LO MODIFICA
**************************************************************************/

void modificarNombrex()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID de cliente a modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    modificarnombre(c);
}
void modificarnombre(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Nuevo nombre: ");
        fflush(stdin);
        gets(c.nombre);
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

void ModificarApellidox()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID de cliente a modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    ModificarApellido(c);
}

void ModificarApellido(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Nuevo apellido: ");
        fflush(stdin);
        gets(c.apellido);
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

void ModificarDNIx()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID de cliente a modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    ModificarDNI(c);
}

void ModificarDNI(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Nuevo DNI: ");
        scanf("%d",&c.dni);
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

void ModificarEmailx()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID de cliente a modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    ModificarEmail(c);
}

void ModificarEmail(stCliente c)
{
    int pos=0;
    pos=buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        do
        {
            printf("\nIngrese un nuevo EMAIL: ");
            fflush(stdin);
            gets(c.email);
        }
        while(!validaEmail(c.email));
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

void ModificarDomiciliox()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID de cliente a modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    ModificarDomicilio(c);
}

void ModificarDomicilio(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Nuevo Domicilio: ");
        fflush(stdin);
        gets(c.domicilio);
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

void ModificarMovilx()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID a Modificar: ");
    scanf("%d",&id);
    c = traeCliente(id);
    ModificarMovil(c);
}

void ModificarMovil(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Nuevo Movil: ");
        scanf("%d",&c.movil);
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

void DarDeAltax()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID para dar de alta: ");
    scanf("%d",&id);
    c = traeCliente(id);
    DarDeAlta(c);
}

void DarDeAlta(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\nCliente dado de alta exitosamente....\n");
        c.baja = 0;
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

void DarDeBajax()
{
    stCliente c;
    int id;
    printf("\n Ingrese ID para dar de baja: ");
    scanf("%d",&id);
    c = traeCliente(id);
    DarDeBaja(c);
}

void DarDeBaja(stCliente c)
{
    int pos=0;
    pos = buscaPosicion(c.id);
    FILE *pArchClientes = fopen(AR_CLIENTES,"r+b");
    if(pArchClientes)
    {
        fseek(pArchClientes,sizeof(stCliente)*pos,SEEK_SET);
        printf("\n Cliente dado de baja exitosamente.....\n\n");
        c.baja = 1;
        fwrite(&c,sizeof(stCliente),1,pArchClientes);
        fclose(pArchClientes);
    }
}

int validaEmail(char email[])
{
    int v=strlen(email);
    int i=0;
    int flag=0;
    while(i<v && flag == 0)
    {
        if(email[i]==64)/// =='@'
        {
            flag=1;
        }
        i++;
    }
    return flag;
}

stCliente buscaClientePorApellido(char apellido[])
{
    int flag=0;
    stCliente c;
    FILE *archi = fopen(AR_CLIENTES,"rb");
    if(archi)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente), 1,archi) > 0)
        {
            if(strcmp(c.apellido,apellido)==0)
            {
                flag=1;
            }
        }
        fclose(archi);
    }

    if(flag==0)
    {
        c.id=-1;
    }

    return c;
}

stCliente buscaClientePorDni(int dni)
{
    int flag=0;
    stCliente c;
    FILE *archi = fopen(AR_CLIENTES, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&c, sizeof(stCliente), 1,archi) > 0)
        {
            if(c.dni==dni)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    if(flag==0)
    {
        c.id=-1;
    }

    return c;
}



///Ordenamientos

void CambiaValoresCliente(stCliente *a,stCliente *b)
{
 stCliente aux;
 aux = *a;
 *a = *b;
 *b = aux;
}


int buscaMenorPosDni(stCliente a[],int v,int inicio)
{
    int posMenor=inicio;
    int i=inicio+1;
    while(i<v){
        if(a[i].dni < a[posMenor].dni){
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenarSelDni(stCliente a[],int v)
{
    int posMenor;
    int i=0;

    while(i<v-1){
        posMenor = buscaMenorPosDni(a,v,i);
        CambiaValoresCliente(&a[posMenor], &a[i]);
        i++;
    }
}

int buscaMenorPosApe(stCliente a[],int v,int inicio)
{
 int PosMenor = inicio;
 int i=inicio+1;
 while(i<v){
    if(strcmp(a[i].apellido,a[PosMenor].apellido)<0){
        PosMenor = i;
    }
    i++;
 }
  return PosMenor;
}

int buscaMenorPosEmail(stCliente a[],int v,int inicio)
{
 int PosMenor = inicio;
 int i=inicio+1;
 while(i<v){
    if(strcmp(a[i].email,a[PosMenor].email)<0){
        PosMenor=i;
    }
    i++;
 }
  return PosMenor;
}

void OrdenarSelEmail(stCliente a[],int v)
{
 int posMenor;
 stCliente aux;
 int i=0;

 while(i<v-1){
    posMenor = buscaMenorPosEmail(a,v,i);
    aux = a[posMenor];
    a[posMenor] = a[i];
    a[i] = aux;
    i++;
 }
}

void ordenarEmails(stCliente a)
{
 stCliente c[DIM_CLI];
 int v=0;
 FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
 if(pArchClientes){
    v = archivo2arrayBaja(a,c);
    fclose(pArchClientes);
 }
 OrdenarSelEmail(c,v);
 muestraClientes(c,v);
}

void ordenarSelApe(stCliente a[],int v)
{
 int posMenor;
 stCliente aux;
 int i=0;

 while(i<v-1){
    posMenor = buscaMenorPosApe(a,v,i);
    aux = a[posMenor];
    a[posMenor] = a[i];
    a[i] = aux;
    i++;
 }
}

void ordenarApellidos(stCliente a)
{
 stCliente c[DIM_CLI];
 int v=0;
 FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
 if(pArchClientes){
    v = archivo2arrayActivos(a,c);
    fclose(pArchClientes);
 }
 ordenarSelApe(c,v);
 muestraClientes(c,v);
}

int archivo2arrayBaja(stCliente a,stCliente c[DIM_CLI])
{
 int v=0;
 FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
 if(pArchClientes){
    while(fread(&a,sizeof(stCliente),1,pArchClientes)>0){
        if(a.baja == 1){
            c[v]=a;
            v++;
        }
    }
    fclose(pArchClientes);
 }

 return v;
}

int archivo2arrayActivos(stCliente a,stCliente c[DIM_CLI])
{
 int v=0;
 FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
 if(pArchClientes){
    while(fread(&a,sizeof(stCliente),1,pArchClientes)>0){
        if(a.baja == 0){
            c[v] = a;
            v++;
        }
    }
    fclose(pArchClientes);
 }
 return v;
}

void ordenarDNIS(stCliente a)
{
 stCliente c[DIM_CLI];
 int v=0;
 FILE *pArchClientes = fopen(AR_CLIENTES,"rb");
 if(pArchClientes){
      v = archivo2arrayActivos(a,c);
      fclose(pArchClientes);
}
  ordenarSelDni(c,v);
  muestraClientes(c,v);
 }

void muestraClientes(stCliente c[], int v)
{
    printf("\n\t\t Listado de Clientes");
    for(int i=0;i<v;i++){
        muestraUnCliente(c[i]);
    }
    printf("\n");
}

void muestraUnCliente(stCliente c)
{
    printf("\n  -----------------------------------------------------------------");
    printf("\n  ID......................: %d", c.id);
    printf("\n  Nro de Cliente..........: %d", c.nroCliente);
    printf("\n  Nombre..................: %s", c.nombre);
    printf("\n  Apellido................: %s", c.apellido);
    printf("\n  DNI.....................: %d", c.dni);
    printf("\n  EMail...................: %s", c.email);
    printf("\n  Calle...................: %s", c.domicilio);
    printf("\n  Nro de Celular..........: %d", c.movil);
    printf("\n  Estado de cliente.......: %d", c.baja);
    printf("\n  -----------------------------------------------------------------");
    printf("\n");
}




///En este apartado esta desarrolando una funcion para cargar consumos random, basandome bastante en la carga random de pilas
///de un proyecto anterior. el prototipo se encuentra al final y tiene en comentarios lo que le falta.


stConsumo cargarConsumosRandom()
{
    stConsumo g;
    stConsumo gRead;
    int dia;
    int pos;




    g.idCliente=rangoRandom(0,buscaUltimoId());

    g.anio=2020;
    g.mes=rangoRandom(1,7);
    dia=CalcularDias(g.mes,g.anio);
    g.dia=rangoRandom(1,dia);
    g.datosConsumidos=rangoRandom(30,1000);
    pos=existenConsumos(g.mes,g.dia,g.idCliente,g.baja);

    if(pos>-1){
       FILE *archi=fopen(AR_CONSUMOS,"r+b");
       if(archi) {
        fseek(archi,sizeof(stConsumo)*pos,SEEK_SET);
        fread(&g,sizeof(stConsumo),1,archi);
        gRead.datosConsumidos=gRead.datosConsumidos+g.datosConsumidos;
        ///si no anda probar anadiendole el otro fseek y una lectura.
        fclose(archi);
       }
    }
    else{
        FILE *archiAux=fopen(AR_CONSUMOS,"ab");
        if(archiAux){
         g.id=buscaUltimoIdConsumos()+1;
         fclose(archiAux);
        }
    }

    g.baja=0;

    return g;
}



int CalcularDias(int mes,int anio)
{
    int dias=0;
    switch(mes)
    {
    case 1:  // Enero
    case 3:  // Marzo
    case 5:  // Mayo
    case 7:  // Julio
    case 8:  // Agosto
    case 10:  // Octubre
    case 12: // Diciembre
        dias=31;
     break;
    case 4:  // Abril
    case 6:  // Junio
    case 9:  // Septiembre
    case 11: // Noviembre
        dias=30;
        break;
    case 2:  // Febrero
        if ( ((anio%100 == 0) && (anio%400 == 0)) ||((anio%100 != 0) && (anio%  4 == 0))   )
            dias=29;  // Año Bisiesto
        else
            dias=28;

    }
    return dias;
}

void mostrarUnConsumo(stConsumo g)
{

    printf("\n-----------------------\n");
    printf("\nNumero Id........:%d",g.id);
    printf("\nIdCliente........:%d",g.idCliente);
    printf("\nDatos consumidos.:%d",g.datosConsumidos);
    printf("\nA%co..............:%d",164,g.anio);
    printf("\nMes..............:%d",g.mes);
    printf("\nDia..............:%d",g.dia);
    printf("\nBaja.............:%d\n",g.baja);
    printf("\n-----------------------\n");
}

void cargaArchivoConsumos(stConsumo g)
{

    FILE *archi=fopen(AR_CONSUMOS,"ab");
    if(archi!=NULL)
    {
        fwrite(&g,sizeof(stConsumo),1,archi);
        fclose(archi);
    }
}

/*void cargaConsumos()
{

    char opcion;


    while(opcion!=ESC)
    {
        system("cls");
        printf("\nCarga de Consumos:\n");

        cargaArchivoConsumos(cargarConsumosRandom());

        printf("\nCargado Exitosamente\n");
        ///primero se carga el consumo y luego se guarda en el archivo de consumos

        printf("\nPresione Intro para Volver a cargar o ESC para dejar de cargar\n");
        fflush(stdin);
        opcion=getch();
        system("cls");
        system("pause");
    }

}*/
void cargaConsumos(int veces)
{

    stConsumo g;
    stConsumo gRead;
    int pos;
    int idTotal;

    idTotal=buscaUltimoIdConsumos()+1;

    printf("\nCarga de Consumos:\n");

    for(int i=0;i<veces;i++)
    {
        system("cls");


         g=cargarConsumosRandom();
         pos=existenConsumos(g.mes,g.dia,g.idCliente,g.baja);

       if(pos>-1) {
        FILE *archi=fopen(AR_CONSUMOS,"r+b");
       if(archi){
        fseek(archi,sizeof(stConsumo)*pos,SEEK_SET);
        fread(&gRead,sizeof(stConsumo),1,archi);
        gRead.datosConsumidos=gRead.datosConsumidos+g.datosConsumidos;

        fseek(archi,sizeof(stConsumo)*(-1),SEEK_CUR);
        g.datosConsumidos=gRead.datosConsumidos;

        fwrite(&gRead,sizeof(stConsumo),1,archi);
        fclose(archi);
       }
    }
    else{
        FILE *archi=fopen(AR_CONSUMOS,"a+b");
       if(archi){
         idTotal++;
         g.id=idTotal;
         fwrite(&g,sizeof(stConsumo),1,archi);
        fclose(archi);
       }
    }
        ///primero se carga el consumo y luego se guarda en el archivo de consumos

        fflush(stdin);
        system("cls");
    }
    printf("\nCargados Exitosamente\n");

 }

void mostrarArchivoConsumos()
{
    stConsumo g;

    FILE *archi=fopen(AR_CONSUMOS,"rb");

    if(archi!=NULL)
    {
        while(fread(&g,sizeof(stConsumo),1,archi)>0)
        {
            mostrarUnConsumo(g);
        }
        fclose(archi);
    }
}

stConsumo buscaConsumoPorFecha(int mes,int dia)
{
    int flag=0;
    stConsumo g;
    FILE *archi = fopen(AR_CONSUMOS, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&g, sizeof(stConsumo), 1,archi) > 0)
        {
            if(g.mes==mes &&  g.dia==dia)
            {
                flag=1;
            }
        }
        fclose(archi);
    }
    if(flag==0)
    {
        g.id=-1;
    }

    return g;
}

/*int existenConsumos(stConsumo g){


    FILE *archi=fopen(AR_CONSUMOS,"rb");

    if(archi!=NULL)
    {
        while(fread(&g,sizeof(stConsumo),1,archi)>0)
        {
            if((g.mes==mes)&&(g.dia==dia)&&(g.idCliente==idCliente)&&(g.baja==baja)){

                consumoPrevio=g.datosConsumidos;

            }
        }
        fclose(archi);
    }

return consumoPrevio;
}*/

int existenConsumos(int mes,int dia,int idCliente,int baja){

    int flag=-1;
    stConsumo g;

    FILE *archi=fopen(AR_CONSUMOS,"rb");

    if(archi!=NULL)
    {
        while(flag==-1 && fread(&g,sizeof(stConsumo),1,archi)>0)
        {
            if((g.mes==mes)&&(g.dia==dia)&&(g.idCliente==idCliente)&&(g.baja==baja)){

                flag=ftell(archi)/sizeof(stConsumo)-1;

            }
        }
        fclose(archi);
    }

return flag;
}

stConsumo cargaConsumoCliente()
{
    stConsumo g;
    int baja=0;
    int dias=0;



        do{
         printf("\ningrese El IdCliente.:");
         scanf("%d", &g.idCliente);


          if(g.idCliente<0 || g.idCliente>buscaUltimoId()){
            printf("\n¡¡Error,Ingrese un Id valido Por favor.\n");
         }

        }while(g.idCliente<0 || g.idCliente>buscaUltimoId());
         ///Con esto se verifica que el cliente al que se le va a cargar un consumo exista
        do{
         printf("\ningrese El Consumo.:");
         scanf("%d", &g.datosConsumidos);

         if(g.datosConsumidos<0 || g.datosConsumidos>9999999){
            printf("\n¡¡Error,Ingrese un consumo valido Por favor.\n");
         }
        }while(g.datosConsumidos<0 || g.datosConsumidos>9999999);
        ///con esto se verifica que el consumo sea positivo, y se le dio un tope el cual se supone que nunca se llegue
        do{
         printf("\ningrese el a%co......:",164);
        scanf("%d", &g.anio);
         if(g.anio!=2020){
            printf("\n¡¡Ese a%co no esta Disponible,Ingrese el a%co Actual Por favor.\n",164,164);
         }

        }while(g.anio!=2020);

      do{
         printf("\ningrese el mes.......:");
         scanf("%d", &g.mes);
          if(g.mes<1 || g.mes>6){
            printf("\n¡¡Ingrese Un mes Entre el 1(enero) al mes actual Por favor.\n");
         }
        }while(g.mes<1 || g.mes>6);

        dias=CalcularDias(g.mes,g.anio);
       do{
         printf("\ningrese un dia.......:");
         scanf("%d", &g.dia);
            if(g.dia<1 || g.dia>dias){
            printf("\n¡¡Ingrese Un dia Entre el periodo de 1 a %d Por favor.\n",dias);
         }

         }while(g.dia<1 || g.dia>dias);
         g.baja=baja;

     ///Revisar todo lo refirido a existen Consumos.

    return g;
}

/*void cargaConsumosTeclado()
{

    char opcion;



    while(opcion!=ESC)
    {
        system("cls");
        printf("\nCarga de Consumos:\n");

        cargaArchivoConsumos(cargaConsumoCliente());

        ///primero se carga el consumo y luego se guarda en el archivo de consumos
        printf("\nPresione ESC para dejar de cargar\n");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }

 }*/

void cargaConsumosTeclado()
{

    char opcion;

    stConsumo g;
    stConsumo gRead;
    int pos;
    int idTotal;
    idTotal=buscaUltimoIdConsumos();

     ///aca se verifica si el consumo no es creado previamente, por eso se usan 2 variables de consumo y si no esta creado
     ///se crea y se le añade un id, de esta manera no se duplican los consumos al acumularse
    while(opcion!=ESC)
    {
        system("cls");
        printf("\nCarga de Consumos:\n");

        g=cargaConsumoCliente();
        pos=existenConsumos(g.mes,g.dia,g.idCliente,g.baja);///esta funcion verifica si existe un consumo previo

      if(pos>-1) {///si pos es =-1 significa que no existian consumos previos y se va directamente al else
        FILE *archi=fopen(AR_CONSUMOS,"r+b");///abre el archivo en modo r+b para modificarlo
       if(archi){
        fseek(archi,sizeof(stConsumo)*pos,SEEK_SET);///encuentra el registro a modificar
        fread(&gRead,sizeof(stConsumo),1,archi);///con este fread se lee el registro del archivo
        gRead.datosConsumidos=gRead.datosConsumidos+g.datosConsumidos;/// y luego se acumulan con los del nuevo consumo

        fseek(archi,sizeof(stConsumo)*(-1),SEEK_CUR);///con fseek desde la posicion me muevo un registro para atras para quedar
                                                     ///por encima del registro a modicar
        g.datosConsumidos=gRead.datosConsumidos; ///aca cambio sus datos consumidos a los que serian acumulados los consumos

        fwrite(&gRead,sizeof(stConsumo),1,archi);/// aca finalmente escribo el registro
        fclose(archi);                           ///en si con todo esto lo que hice fue modificar(acumulando) el registro original
       }                                         /// en tiempo de ejecucion
    }
    else{
        FILE *archi=fopen(AR_CONSUMOS,"ab");///en este lugar se supone que el pos fue =-1 por lo tanto el consumo no existia
         if(archi){                         ///previamente, por eso lo creo abriendo en modo ab
         idTotal++;                         ///en la variable idTotal guardo el ultimo id y lo incremento para crear el consumo
         g.id=idTotal;                      ///luego ese valor se lo asigno a la id del consumo
         fwrite(&g,sizeof(stConsumo),1,archi);/// y al final escribo en el archivo ese consumo nuevo.
        fclose(archi);
       }
    }


        ///primero se carga el consumo y luego se guarda en el archivo de consumos
        printf("\nPresione ESC para dejar de cargar\n");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }

 }



///Modificar consumo

void modificarConsumo()
{
    stConsumo g;
    int id;
    printf("\n Ingrese ID de consumo a modificar: ");
    scanf("%d",&id);
    g = traeConsumo(id);
    modificaConsumo(g);
}

 void modificaConsumo(stConsumo g)
{
    int pos=0;
    pos = buscaPosicionConsumo(g.id);
    FILE *pArchConsumo = fopen(AR_CONSUMOS,"r+b");
    if(pArchConsumo)
    {
        fseek(pArchConsumo,sizeof(stConsumo)*pos,SEEK_SET);
        printf("\n Nuevo Consumo: ");
        scanf("%d",&g.datosConsumidos);
        fwrite(&g,sizeof(stConsumo),1,pArchConsumo);
        fclose(pArchConsumo);
    }
}

void modificarBajaConsumo(){
 stConsumo c;
 int id;
 printf("\n Ingrese ID consumo a dar de baja: ");
 scanf("%d",&id);
 c = traeConsumo(id);
 DarDeBajaConsumo(c);
}

void DarDeBajaConsumo(stConsumo g)
{
    int pos=0;
    pos = buscaPosicionConsumo(g.id);
    FILE *pArchConsumos = fopen(AR_CONSUMOS,"r+b");
    if(pArchConsumos)
    {
        fseek(pArchConsumos,sizeof(stConsumo)*pos,SEEK_SET);
        printf("\n Consumo dado de baja exitosamente.....\n\n");
        g.baja = 1;
        fwrite(&g,sizeof(stConsumo),1,pArchConsumos);
        fclose(pArchConsumos);
    }
}


void modificarConsumoAlta(){
    stConsumo g;
    int id;
    printf("\n Ingrese ID consumo a dar de alta: ");
    scanf("%d",&id);
    g = traeConsumo(id);
    DarDeAltaConsumo(g);
}


 void DarDeAltaConsumo(stConsumo g)
{
    int pos=0;
    pos = buscaPosicionConsumo(g.id);
    FILE *pArchConsumo = fopen(AR_CONSUMOS,"r+b");
    if(pArchConsumo)
    {
       fseek(pArchConsumo,sizeof(stConsumo)*pos,SEEK_SET);
        printf("\n Consumo dado de alta exitosamente.....\n\n");
        g.baja = 0;
        fwrite(&g,sizeof(stConsumo),1,pArchConsumo);
        fclose(pArchConsumo);
    }
}


int buscaPosicionConsumo(int id)
{
    int pos=-1;
    stConsumo c;
    FILE *pArchConsumo = fopen(AR_CONSUMOS,"rb");
    if(pArchConsumo)
    {
        while(pos == -1 && fread(&c, sizeof(stConsumo), 1, pArchConsumo) > 0)
        {
            if(c.id == id)
            {
                pos = ftell(pArchConsumo)/sizeof(stConsumo)-1;
            }
        }
        fclose(pArchConsumo);
    }

    return pos;
}

void modificarConsumosSubMenu()
{
    char opcion;
    do
    {
        system("cls");
        printf("\n MODIFICACION DE Consumos...\n");
        printf("\n 1-Modificar un consumo");
        printf("\n 2-Modificar Estado de Baja");
        printf("\n 3-Modificar Estado de Alta");
        printf("\n\n");
        printf("\n ESC para salir...");
        opcion=getch();
        switch(opcion)
        {
        case 49:
            modificarConsumo();
            break;
        case 50:
            modificarBajaConsumo();
            break;
        case 51:
            modificarConsumoAlta();
            break;
        default:
            printf("\n Opcion incorrecta");
        }
        system("pause");
    }
    while(opcion!=27);
}

int archivo2arrayConsumos(stConsumo a,stConsumo c[DIM_CLI],int dato){
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
    while(fread(&a,sizeof(stConsumo),1,pArchConsumos)>0){
        if(a.mes == dato){
            c[v] = a;
            v++;
        }
    }
    fclose(pArchConsumos);
 }
 return v;
}

int ordenarMES(stConsumo a,int dato){
 stConsumo c[DIM_CLI];
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayConsumos(a,c,dato);
      fclose(pArchConsumos);
}
  muestraConsumos(c,v);
  return v;
 }

void muestraConsumos(stConsumo c[], int v)
{
    if(v!=0){
    printf("\n\t----Listado Consumos----\n");
    for(int i=0;i<v;i++){
        muestraUnConsumo(c[i]);
    }
    printf("\n");
    }else{
    printf("\n\t---No se realizaron consumos este mes---\n");
    printf("\n");
    }
}
void muestraUnConsumo(stConsumo c)
{
    printf("\n  -----------------------------------------------------------------");
    printf("\n  ID......................: %d", c.id);
    printf("\n  ID de cliente...........: %d",c.idCliente);
    printf("\n  A%co....................: %d",164,c.anio);
    printf("\n  Mes.....................: %d", c.mes);
    printf("\n  Dia.....................: %d", c.dia);
    printf("\n  Datos Consumidos........: %d", c.datosConsumidos);
    printf("\n  Estado de consumo.......: %d", c.baja);
    printf("\n  -----------------------------------------------------------------");
    printf("\n");
}

int archivo2arrayDatos(stConsumo a,int c[DIM_CLI],int dato){
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
    while(fread(&a,sizeof(stConsumo),1,pArchConsumos)>0){
        if(a.mes == dato){
            c[v] = a.datosConsumidos;
            v++;
        }
    }
    fclose(pArchConsumos);
 }
 return v;
}

int sumadatos1(stConsumo a){
 int dato=1;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
}


int sumadatos2(stConsumo a){
 int dato=2;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
}

int sumadatos3(stConsumo a){
 int dato=3;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
}

int sumadatos4(stConsumo a){
 int dato=4;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
}

int sumadatos5(stConsumo a){
 int dato = 5;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 float porcentaje=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
 }

int sumadatos6(stConsumo a){
 int dato = 6;
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayDatos(a,c,dato);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
 }

 void muestraSumaDatos(stConsumo a){
  int enero,febrero,marzo,abril,mayo,junio;
  enero=sumadatos1(a);
  printf("\nMES ENERO(1): %d (%.2f%%)\n",enero,calcularporcentaje2(a,enero));
  febrero=sumadatos2(a);
  printf("\nMES FEBRERO(2): %d (%.2f%%)\n",febrero,calcularporcentaje2(a,febrero));
  marzo=sumadatos3(a);
  printf("\nMES MARZO(3): %d (%.2f%%)\n",marzo,calcularporcentaje2(a,marzo));
  abril=sumadatos4(a);
  printf("\nMES ABRIL(4): %d (%.2f%%)\n",abril,calcularporcentaje2(a,abril));
  mayo=sumadatos5(a);
  printf("\nMES MAYO(5): %d (%.2f)\n",mayo,calcularporcentaje2(a,mayo));
  junio=sumadatos6(a);
  printf("\nMES JUNIO(6): %d (%.2f%%)\n",junio,calcularporcentaje2(a,junio));
 }

int pasarArraySumaDatos(stConsumo a,int arraySumas[],int v){
int enero,febrero,marzo,abril,mayo,junio;

enero=sumadatos1(a);
arraySumas[0]=enero;

febrero=sumadatos2(a);
arraySumas[1]=febrero;

marzo=sumadatos3(a);
arraySumas[2]=marzo;

abril=sumadatos4(a);
arraySumas[3]=abril;

mayo=sumadatos5(a);
arraySumas[4]=mayo;

junio=sumadatos6(a);
arraySumas[5]=junio;

v=6;
return v;
 }

void mostrarArray(int a[],int v){

  for(int i=0;i<v;i++){
    printf("\n%d\n",a[i]);
  }

}


int sumadatosAll(stConsumo a){
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayAlldato(a,c);
      fclose(pArchConsumos);
}
  suma=sumararray(c,v);
  return suma;
 }

 int archivo2arrayAlldato(stConsumo a,int c[DIM_CLI]){
 int v=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
    while(fread(&a,sizeof(stConsumo),1,pArchConsumos)>0){
            c[v] = a.datosConsumidos;
            v++;
    }
    fclose(pArchConsumos);
    return v;
 }
}

float PorcentajeMesConsumo(int total){
 int mes =6;
 float porcentaje=0;
 porcentaje = (float)total / mes;
 return (float)porcentaje;
}

int sumararray(int a[],int validos){
 int i = 0;
 int suma =0;
 if(validos!=0){
 for(i=0;i<validos;i++){
  suma = suma + a[i];
  }
}
  return suma;
}


float calcularporcentaje2(stConsumo a,int dato){
 stConsumo c[DIM_CLI];
 int suma=0;
 int v=0;
 float porcentaje=0;
 FILE *pArchConsumos = fopen(AR_CONSUMOS,"rb");
 if(pArchConsumos){
      v = archivo2arrayAlldato(a,c);
      fclose(pArchConsumos);
 }
  suma=sumararray(c,v);
  porcentaje = (float)dato*100/suma;
  return (float)porcentaje;
 }


int archivo2ArrayConsumosEnteros(stConsumo g,stConsumo conArray[],int v,int dim)
{

    FILE *archi=fopen(AR_CONSUMOS,"rb");

    if(archi!=NULL)
    {
        while(fread(&g,sizeof(stConsumo),1,archi)>0)
        {
            conArray[v]=g;
            v++;
        }
        fclose(archi);
    }

    return v;
}

 void CambiaValoresConsumo(stConsumo *a,stConsumo *b)
{
 stConsumo aux;
 aux = *a;
 *a = *b;
 *b = aux;
}
int buscaMenorPosDia(stConsumo g[],int v,int inicio,int mes)
{
    int posMenor=inicio;
    int i=inicio+1;
      while(i<v){
        if(g[i].dia < g[posMenor].dia && g[posMenor].mes==g[i].mes){
            posMenor = i;
        }
        i++;
      }

    return posMenor;
}

void ordenarSelDia(stConsumo g[],int v)
{
    int posMenor;
    int i=0;

    while(i<v-1){
        posMenor = buscaMenorPosDia(g,v,i,i);
        CambiaValoresConsumo(&g[posMenor], &g[i]);
        i++;
    }
}

int ordenarArrayConsumosPorDiaYMes(stConsumo g[],int v,stConsumo arreglodias[]){///la idea es ordenarlo primeramente por mes

int i=0;

  for(i=0;i<v;i++){
    arreglodias[i]=g[i];
    }
return i;
}

int buscaMenorPosMes(stConsumo g[],int v,int inicio)
{
    int posMenor=inicio;
    int i=inicio+1;
    while(i<v){
        if(g[i].mes < g[posMenor].mes){
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenarArrayConsumosPorMes(stConsumo g[],int v){///la idea es ordenarlo primeramente por mes
   int posMenor;
    int i=0;

    while(i<v-1){
        posMenor = buscaMenorPosMes(g,v,i);
        CambiaValoresConsumo(&g[posMenor], &g[i]);
        i++;
    }
}
///Se busca el MENOR consumo por mes
int buscaPosMenorConsumoMes(int a[],int v){
  int i=0;
  int posMenor=i;
  i++;
    while(i<v){
        if(a[posMenor]>a[i])
        {
            posMenor=i;
        }
       i++;
    }

return posMenor;
}

///
int buscaMayorPosDdia(stConsumo g[],int v,int inicio,int mes)
{
    int posMayor=inicio;
    int i=inicio+1;
      while(i<v){
        if(g[i].dia < g[posMayor].dia && g[posMayor].mes==g[i].mes){
            posMayor = i;
        }
        i++;
      }

    return posMayor;
}

void ordenarSelDddia(stConsumo g[],int v)
{
    int posMayor;
    int i=0;

    while(i<v-1){
        posMayor = buscaMayorPosDdia(g,v,i,i);
        CambiaValoresConsumo(&g[posMayor], &g[i]);
        i++;
    }
}

int ordenarArrayConsumosPorDiaYMmes(stConsumo g[],int v,stConsumo arreglodias[]){///la idea es ordenarlo primeramente por mes

int i=0;

  for(i=0;i<v;i++){
    arreglodias[i]=g[i];
    }
return i;
}

int buscaMayorPosMmes(stConsumo g[],int v,int inicio)

{
    int posMayor=inicio;
    int i=inicio+1;
    while(i<v){
        if(g[i].mes < g[posMayor].mes){
            posMayor = i;
        }
        i++;
    }
    return posMayor;
}

void ordenarArrayConsumosPorMmmes(stConsumo g[],int v){///la idea es ordenarlo primeramente por mes
   int posMayor;
    int i=0;

    while(i<v-1){
        posMayor = buscaMayorPosMmes(g,v,i);
        CambiaValoresConsumo(&g[posMayor], &g[i]);
        i++;
    }
}
///Se busca el MAYOR consumo por mes
int buscaPosMayorConsumoMeees(int a[],int v)
{
  int i=0;
  int posMayor=i;
  i++;
    while(i<v){
        if(a[posMayor]<a[i])
        {
            posMayor=i;
        }
       i++;
    }

return posMayor;
}


int cuentaConsumosActivosMes(int mes){
stConsumo c;
FILE *archi=fopen(AR_CONSUMOS,"rb");
int i=0;
int contador=0;
if(archi){
    while(fread(&c,sizeof(stConsumo),1,archi)>0){
        if(c.mes == mes){
            if(c.baja == 0){
                contador++;
      }
      }
    }
  }
  return contador;
}

int cuentaConsumosInactivosMes(int mes){
stConsumo c;
FILE *archi=fopen(AR_CONSUMOS,"rb");
int i=0;
int contador=0;
if(archi){
    while(fread(&c,sizeof(stConsumo),1,archi)>0){
        if(c.mes == mes){
            if(c.baja == 1){
                contador++;
      }
      }
    }
  }
  return contador;
}

int cuentaClientesNegativos(){

stCliente c;
 FILE *archi=fopen(AR_CLIENTES,"rb");
 int i=0;
 if(archi){
    while(fread(&c,sizeof(stCliente),1,archi)>0){
        if(c.baja==1){
            i++;
        }
     }
  }
 return i;
}

int cuentaClientesPositivos(){

stCliente c;
 FILE *archi=fopen(AR_CLIENTES,"rb");
 int i=0;
 if(archi){
    while(fread(&c,sizeof(stCliente),1,archi)>0){
        if(c.baja==0){
            i++;
        }
     }
  }
 return i;
}


void porcentajeClientesActivos_Inactivos(){
float porcentajePositivos;
float porcentajeNegativos;
int positivos;
int negativos;
int total;

positivos=cuentaClientesPositivos();
negativos=cuentaClientesNegativos();

total=positivos+negativos;

if(positivos>0){
 porcentajePositivos=(float)positivos*100/total;
}

if(negativos>0){
porcentajeNegativos=(float)negativos*100/total;
}

printf("\nEl Porcentajes de Clientes es:\n");
printf("\nEl Porcentaje de activos es: %.2f%%\n",porcentajePositivos);
printf("\nEl Porcentaje de inactivos es: %.2f%%\n",porcentajeNegativos);
printf("\n\n");

}

int sumatoriaDeDias(){
stConsumo g;
int sumatoria=0;

 FILE *archi=fopen(AR_CONSUMOS,"rb");

 if(archi){

    while(fread(&g,sizeof(stConsumo),1,archi)>0){
        sumatoria=sumatoria+g.datosConsumidos;
    }
 }

  return sumatoria;
}

float promedioXdia(){
float promedio=0;
int contados;
int sumados;
 contados=cuentaRegistro(AR_CONSUMOS,sizeof(stConsumo));
 sumados=sumatoriaDeDias();

 if(contados>0){
    promedio=(float)sumados/contados;
 }
return promedio;
}
/*
void CargoMatrix(int fil,int col,int m[fil][col],stConsumo a){
 m = sumadatos1(a),sumadatos2(a),sumadatos3(a),sumadatos4(a),sumadatos5(a),sumadatos6(a),
     calcularporcentaje2(a,1),calcularporcentaje2(a,2),calcularporcentaje2(a,3),calcularporcentaje2(a,4),calcularporcentaje2(a,5),
     calcularporcentaje2(a,6),cuentaConsumosActivosMes(1),cuentaConsumosActivosMes(2),cuentaConsumosActivosMes(3),cuentaConsumosActivosMes(4),
     cuentaConsumosActivosMes(5),cuentaConsumosActivosMes(6),cuentaConsumosInactivosMes(1),cuentaConsumosInactivosMes(2),
     cuentaConsumosInactivosMes(3),cuentaConsumosInactivosMes(4),cuentaConsumosInactivosMes(5),cuentaConsumosInactivosMes(6);
}
*/
void CargoMatrix(int fil,int col,stConsumo a){
     float m[4][6] = {{sumadatos1(a),sumadatos2(a),sumadatos3(a),sumadatos4(a),sumadatos5(a),sumadatos6(a)},
     {calcularporcentaje2(a,sumadatos1(a)),calcularporcentaje2(a,sumadatos2(a)),calcularporcentaje2(a,sumadatos3(a)),calcularporcentaje2(a,sumadatos4(a)),calcularporcentaje2(a,sumadatos5(a)),calcularporcentaje2(a,sumadatos6(a))},
     {cuentaConsumosActivosMes(1),cuentaConsumosActivosMes(2),cuentaConsumosActivosMes(3),cuentaConsumosActivosMes(4),cuentaConsumosActivosMes(5),cuentaConsumosActivosMes(6)},
     {cuentaConsumosInactivosMes(1),cuentaConsumosInactivosMes(2),cuentaConsumosInactivosMes(3),cuentaConsumosInactivosMes(4),cuentaConsumosInactivosMes(5),cuentaConsumosInactivosMes(6)}};

     muestromatrizint(fil,col,m);

 }


void muestromatrizint(int filas,int columnas,float a[filas][columnas]){
    char meses[][10] = {"[enero]","[febrero]","[marzo]","[abril]","[mayo]","[junio]"};
     char refer[][30] = {"[Consumo]","[Porcentaje]","[ConsumosAct]","[Consumosinact]"};
    gotoxy(10,2);
    for(int z=0; z<6;z++)
    {
        gotoxy(whereX()+5,whereY());
        printf("%9s",meses[z]);

    }

    gotoxy(0,5);
    for(int h=0; h<4;h++)
    {
        printf("%s",refer[h]);
        gotoxy(0,whereY()+2);
    }
        gotoxy(10,5);
        for(int i=0;i<filas;i++){

            for(int j=0;j<columnas;j++){
                 gotoxy(whereX()+5,whereY());
                printf("%8.2f ",a[i][j]);

            }

            gotoxy(10,whereY()+2);
    }
}
