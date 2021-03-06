//LIBRERIAS O PAQUETES
#include <stdio.h>
#include <stdlib.h>
#define num 50

//FUNCIONES
void menu();
void menuFutbol();
void registroFutbol();
void mostrarFutbol();
void maximoGoleador();
void mejorEquipoFutbol();
void menuBaloncesto();
void registroBaloncesto();
void mostrarBaloncesto();
void maximoTriplista();
void mejorEquipoBaloncesto();

//VARIABLES GLOBALES
int vacioFutbol = 0, vacioBaloncesto = 0, cantidadLigaFutbol, cantidadLigaBaloncesto;
int numero; // ESTA VARIABLE NOS PERMITE TOMAR EL VALOR DE LOS FOR PARA EXTRAER EL NOMBRE DEL STRUCT
int puntos; // CANTIDAD DE PUNTOS COSECHADOS EN LA LIGA FUTBOL

//STRUCT LIGA 1# FUTBOL
struct ligaFutbol
{
    char nombreEquipo[num];

    int numVictorias;
    int numDerrotas;
    int numEmpates;

    int numGolesFavor;
    int numGolesContra;

    char nombreGoleador[num];
    int golesGoleador;

};ligaFutbol futbol[num],*p_futbol=futbol;

//STRUCT LIGA 2# BALONCESTO
struct ligaBaloncesto
{
    char nombreEquipo[num];

    int numVictorias;
    int numDerrotas;

    int numPerdidasBalon;
    int numRebotesCogidos;

    char nombreMejorTriplista[num];
    int numMejorTriplista;

};ligaBaloncesto baloncesto[num],*p_baloncesto=baloncesto;

int main()
{
    menu();
    return 0;
}

void menu(){
    int opcion = 0;
    do{
        
        
       
        printf("\n 1. LIGA FUTBOL ");
        printf("\n 2. LIGA BALONCEST ");
        printf("\n 0. CERRAR ");
        
        
        printf("\n\nESCOJA UNA OPCION: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 0:
                system("cls");
                printf("Muchas gracias por ustilizar el programa G,R y asociados\n");
                exit(0);
            case 1:
                system("cls");
                menuFutbol();
                break;
            case 2:
                system("cls");
                menuBaloncesto();
                break;
            default:
                system("cls");
                printf("La opcion que ustede eligio no es correcta por favor intente de nuevo.\n");
        }
    }while(opcion != 0);
}

void menuFutbol(){
    if(vacioFutbol == 0){
        printf("\n\n Numero de equipos que participan en la liga?: ");
        scanf("%d", &cantidadLigaFutbol);
        vacioFutbol = 1;
    }else{
        int opcion = 0;
        do{
            
            printf("\n 1. AGREGAR INFO ");
            printf("\n 2. VER INFO ");
            printf("\n 3. MEJOR ANOTADOR ");
            printf("\n 4. MEJOR EQUIPO ");
            printf("\n 0. CERRAR ");
            printf("\n");
            printf("\n\nESCOJA UNA OPCION: ");
            scanf("%d", &opcion);
            switch(opcion){
                case 0:
                    system("cls");
                    menu();
                case 1:
                    system("cls");
                    registroFutbol();
                    break;
                case 2:
                    system("cls");
                    mostrarFutbol();
                    break;
                 case 3:
                    system("cls");
                    maximoGoleador();
                    break;
                 case 4:
                    system("cls");
                    mejorEquipoFutbol();
                    break;
                default:
                    system("cls");
                    printf("La opcion que ustede eligio no es correcta por favor intente de nuevo.\n");
            }
        }while(opcion != 0);
    }
}

void registroFutbol(){
    printf("\nINFORMACION A REGISTRAR\n\n");
    for(int i=0;i<cantidadLigaFutbol;i++){
        printf("INGRESE NOMBRE DEL EQUIPO: ");
        scanf("%s", &(*(p_futbol+i)).nombreEquipo);
        printf("INGRESE NUMERO VICTORIAS: ");
        scanf("%d", &(*(p_futbol+i)).numVictorias);
        printf("INGRESE NUMERO DERROTAS: ");
        scanf("%d", &(*(p_futbol+i)).numDerrotas);
        printf("INGRESE NUMERO EMPATES: ");
        scanf("%d", &(*(p_futbol+i)).numEmpates);
        printf("INGRESE NUMERO DE GOLES REALIZADOS: ");
        scanf("%d", &(*(p_futbol+i)).numGolesFavor);
        printf("INGRESE NUMERO DE GOLES RECIBIDOS: ");
        scanf("%d", &(*(p_futbol+i)).numGolesContra);
        printf("INGRESE NOMBRE DEL GOLEADOR: ");
        scanf("%s", &(*(p_futbol+i)).nombreGoleador);
        printf("INGRESE NUMERO DE GOLES: ");
        scanf("%d", &(*(p_futbol+i)).golesGoleador);
        printf("\n");
    }
}

void mostrarFutbol(){
    printf("\nINFORMACION A MOSTRAR\n");
    for(int i=0;i<cantidadLigaFutbol;i++){
        printf("\nINFORMACION EQUIPO NUMERO #%d\n", i+1);
        printf("NOMBRE EQUIPO: %s", (*(p_futbol+i)).nombreEquipo);
        printf("\nNUMERO VICTORIAS: %d", (*(p_futbol+i)).numVictorias);
        printf("\nNUMERO DERROTAS: %d", (*(p_futbol+i)).numDerrotas);
        printf("\nNUMERO EMPATES: %d", (*(p_futbol+i)).numEmpates);
        printf("\nNUMERO GOLES REALIZADOS: %d", (*(p_futbol+i)).numGolesFavor);
        printf("\nNUMERO GOLES RECIBIDOS: %d", (*(p_futbol+i)).numGolesContra);
        printf("\nNOMBRE GOLEADOR: %s", (*(p_futbol+i)).nombreGoleador);
        printf("\nNUMERO GOLES: %d", (*(p_futbol+i)).golesGoleador);
        printf("\n");
    }
    printf("\n");
}

void maximoGoleador(){
    int mayorGoleador;

    mayorGoleador = (*(p_futbol+0)).golesGoleador;
    for(int i=0;i<cantidadLigaFutbol;i++){
        if((*(p_futbol+i)).golesGoleador > mayorGoleador){
            mayorGoleador = (*(p_futbol+i)).golesGoleador;
            numero = i;
        }
    }

    printf("\nGOLES CONSEGUIDOS: %d", mayorGoleador);
    printf("\nNOMBRE MEJOR GOLEADOR: %s", (*(p_futbol+numero)).nombreGoleador);
    printf("\n");
}

void mejorEquipoFutbol(){
    int mEquipoFutbol;

    mEquipoFutbol = (*(p_futbol+0)).numVictorias;
    for(int i=0;i<cantidadLigaFutbol;i++){
        if((*(p_futbol+i)).numVictorias > mEquipoFutbol){
            mEquipoFutbol = (*(p_futbol+i)).numVictorias;
            numero = i;
        }
    }

    puntos = (mEquipoFutbol*3) + ((*(p_futbol+numero)).numEmpates);

    printf("\nPUNTOS COSECHADOS: %d PUNTOS", puntos);
    printf("\nVICTORIAS CONSEGUIDAS: %d", mEquipoFutbol);
    printf("\nNOMBRE EQUIPO GANADOR: %s", (*(p_futbol+numero)).nombreEquipo);
    printf("\n");
}

void menuBaloncesto(){
    if(vacioBaloncesto == 0){
        printf("\n\n Numero de equipos que participan en la liga?: ");
        scanf("%d", &cantidadLigaBaloncesto);
        vacioBaloncesto = 1;
    }else{
        int opcion = 0;
        do{
            
            printf("\n 1. AGREGAR INFO ");
            printf("\n 2. VER INFO ");
            printf("\n 3. MEJOR TRIPLISTA ");
            printf("\n 4. MEJOR EQUIPO ");
            printf("\n 0. CERRAR ");
            
            printf("\n");
            printf("\n\n ESCOJA UNA OPCION: ");
            scanf("%d", &opcion);
            switch(opcion){
                case 0:
                    system("cls");
                    menu();
                case 1:
                    system("cls");
                    registroBaloncesto();
                    break;
                case 2:
                    system("cls");
                    mostrarBaloncesto();
                    break;
                case 3:
                    system("cls");
                    maximoTriplista();
                    break;
                case 4:
                    system("cls");
                    mejorEquipoBaloncesto();
                    break;
                default:
                    system("cls");
                    printf("La opcion que ustede eligio no es correcta por favor intente de nuevo.\n");
            }
        }while(opcion != 0);
    }
}

void registroBaloncesto(){
    printf("\nINFORMACION A REGISTRAR\n\n");
    for(int i=0;i<cantidadLigaBaloncesto;i++){
        printf("INGRESE NOMBRE DEL EQUIPO: ");
        scanf("%s", &(*(p_baloncesto+i)).nombreEquipo);
        printf("INGRESE NUMERO VICTORIAS: ");
        scanf("%d", &(*(p_baloncesto+i)).numVictorias);
        printf("INGRESE NUMERO DERROTAS: ");
        scanf("%d", &(*(p_baloncesto+i)).numDerrotas);
        printf("INGRESE NUMERO DE PERDIDAS DE BALON: ");
        scanf("%d", &(*(p_baloncesto+i)).numPerdidasBalon);
        printf("INGRESE NUMERO DE REBOTES COGIDOS: ");
        scanf("%d", &(*(p_baloncesto+i)).numRebotesCogidos);
        printf("INGRESE NOMBRE DEL MEJOR TRIPLISTA: ");
        scanf("%s", &(*(p_baloncesto+i)).nombreMejorTriplista);
        printf("INGRESE NUMERO DE TRIPLES REALIZADOS: ");
        scanf("%d", &(*(p_baloncesto+i)).numMejorTriplista);
        printf("\n");
    }
}

void mostrarBaloncesto(){
    printf("\nINFORMACION A MOSTRAR\n");
    for(int i=0;i<cantidadLigaBaloncesto;i++){
        printf("\nINFORMACION EQUIPO NUMERO #%d\n", i+1);
        printf("NOMBRE EQUIPO: %s", (*(p_baloncesto+i)).nombreEquipo);
        printf("\nNUMERO VICTORIAS: %d", (*(p_baloncesto+i)).numVictorias);
        printf("\nNUMERO DERROTAS: %d", (*(p_baloncesto+i)).numDerrotas);
        printf("\nNUMERO PERDIDAS DE BALON: %d", (*(p_baloncesto+i)).numPerdidasBalon);
        printf("\nNUMERO REBOTES COGIDOS: %d", (*(p_baloncesto+i)).numRebotesCogidos);
        printf("\nNOMBRE MEJOR TRIPLISTA: %s", (*(p_baloncesto+i)).nombreMejorTriplista);
        printf("\nNUMERO TRIPLES: %d", (*(p_baloncesto+i)).numMejorTriplista);
        printf("\n");
    }
    printf("\n");
}

void maximoTriplista(){
    int mayorTriplista;

    mayorTriplista = (*(p_baloncesto+0)).numMejorTriplista;
    for(int i=0;i<cantidadLigaBaloncesto;i++){
        if((*(p_baloncesto+i)).numMejorTriplista > mayorTriplista){
            mayorTriplista = (*(p_baloncesto+i)).numMejorTriplista;
            numero = i;
        }
    }

    printf("\n TRIPLES CONSEGUIDOS: %d", mayorTriplista);
    printf("\n NOMBRE MEJOR TRPLISTA: %s", (*(p_baloncesto+numero)).nombreMejorTriplista);
    printf("\n");
}

void mejorEquipoBaloncesto(){
    int mEquipoBaloncesto;

    mEquipoBaloncesto = (*(p_baloncesto+0)).numVictorias;
    for(int i=0;i<cantidadLigaBaloncesto;i++){
        if((*(p_baloncesto+i)).numVictorias > mEquipoBaloncesto){
            mEquipoBaloncesto = (*(p_baloncesto+i)).numVictorias;
            numero = i;
        }
    }

    printf("\n VICTORIAS CONSEGUIDAS: %d", mEquipoBaloncesto);
    printf("\n NOMBRE EQUIPO GANADOR: %s", (*(p_baloncesto+numero)).nombreEquipo);
    printf("\n");
}
