#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{
    eTramite* t;
    int opcion;
    int i;
    int len;
    int idTramiteUrgente=0;
    int idTramiteRegular=0;
    int id;
    char dni[10];
    ArrayList* listaUrgente;
    ArrayList* listaRegular;
    ArrayList* atendidosUrgentes;
    ArrayList* atendidosRegulares;
    char seguir='s';

    listaUrgente=al_newArrayList();
    listaRegular=al_newArrayList();
    atendidosUrgentes=al_newArrayList();
    atendidosRegulares=al_newArrayList();

    idTramiteUrgente=parse(listaUrgente,idTramiteUrgente);

    while(seguir=='s')
    {
        printf("1- Tramite Uregente\n");
        printf("2- Tramite Regular\n");
        printf("3- Proximo\n");
        printf("4- Listar Pendientes\n");
        printf("5- Informar Atendidos \n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                idTramiteUrgente++;
                printf("ingrese dni: ");
                fflush(stdin);
                gets(dni);
                cargarTramite(listaUrgente,idTramiteUrgente,dni);
                archivoUrgente(listaUrgente);
                break;
            case 2:
                idTramiteRegular++;
                printf("ingrese dni: ");
                fflush(stdin);
                gets(dni);
                cargarTramite(listaRegular,idTramiteRegular,dni);
                archivoRegular(listaRegular);
                break;
            case 3:
                if(!listaUrgente->isEmpty(listaUrgente))
                {

                    printf("cliente a ser atendido (urgente): ");

                    atenderTramite(listaUrgente,atendidosUrgentes);

                }
                else
                {
                    if(!listaRegular->isEmpty(listaRegular))
                    {
                        printf("cliente a ser atendido (regular): ");

                        atenderTramite(listaRegular,atendidosRegulares);
                    }
                    else
                    {
                        printf("no hay clientes por atender\n");
                    }
                }
               break;
            case 4:
                if(!listaUrgente->isEmpty(listaUrgente))
                {
                    printf("Tramites Urgentes\n");
                    mostrarListaDeTramite(listaUrgente);

                }

                if(!listaRegular->isEmpty(listaRegular))
                {
                    printf("Tramites Regulares\n");
                    mostrarListaDeTramite(listaRegular);
                }

               break;
            case 5:
                if(!atendidosUrgentes->isEmpty(atendidosUrgentes))
                {
                    atendidosUrgentes->sort(atendidosUrgentes,compararPorDni,0);
                    printf("Tramites Urgentes Atendidos\n");
                    mostrarListaDeTramite(atendidosUrgentes);

                }

                if(!atendidosRegulares->isEmpty(atendidosRegulares))
                {
                    atendidosRegulares->sort(atendidosRegulares,compararPorDni,0);
                    printf("Tramites Regulares Atendidos\n");
                    mostrarListaDeTramite(atendidosRegulares);
                }
                break;
            case 6:
                seguir = 'n';
                break;
        }
        system("pause");

        system("cls");
    }

    return 0;
}
