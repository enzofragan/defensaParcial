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
    char dni[10];
    ArrayList* listaUrgente;
    ArrayList* listaRegular;
    char seguir='s';

    listaUrgente=al_newArrayList();
    listaRegular=al_newArrayList();

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
                t=new_tramite();
                idTramiteUrgente++;
                setId(t,idTramiteUrgente);
                printf("ingrese dni: ");
                fflush(stdin);
                gets(dni);
                setDni(t,dni);
                listaUrgente->add(listaUrgente,t);
                break;
            case 2:
                t=new_tramite();
                idTramiteRegular++;
                setId(t,idTramiteRegular);
                printf("ingrese dni: ");
                fflush(stdin);
                gets(dni);
                setDni(t,dni);
                listaRegular->add(listaRegular,t);
                break;
            case 3:
               break;
            case 4:
                len=listaUrgente->len(listaUrgente);
                printf("Tramites Urgentes\n");
                for(i=0;i<len;i++)
                {
                    t=(eTramite*) listaUrgente->get(listaUrgente,i);
                    mostarTramite(t);
                }

                len=listaRegular->len(listaRegular);
                printf("Tramites Regulares\n");
                for(i=0;i<len;i++)
                {
                    t=(eTramite*) listaRegular->get(listaRegular,i);
                    mostarTramite(t);
                }
               break;
            case 6:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
