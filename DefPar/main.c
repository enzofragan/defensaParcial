#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    ArrayList* ClientesUrgentes;
    ArrayList* ClientesRegulares;
    eClienteUrgente urgente;
    int opcion;
    char seguir='s';

    ClientesUrgentes=al_newArrayList();
    ClientesRegulares=al_newArrayList();

     /*while(seguir=='s')
    {
        printf("1- \n");
        printf("2- \n");
        printf("3- \n");
        printf("4- \n");
        printf("5- \n");
        printf("6- \n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
               break;
            case 6:
                seguir = 'n';
                break;
        }
    }*/


    printf(opcion);

    return 0;
}
