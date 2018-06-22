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
    ArrayList* atendidosUrgentes;
    ArrayList* atendidosRegulares;
    char seguir='s';

    listaUrgente=al_newArrayList();
    listaRegular=al_newArrayList();
    atendidosUrgentes=al_newArrayList();
    atendidosRegulares=al_newArrayList();

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
                if(!listaUrgente->isEmpty(listaUrgente))
                {
                    t= (eTramite*) listaUrgente->pop(listaUrgente,0);

                    printf("cliente a ser atendido (urgente): ");

                    atendidosUrgentes->add(atendidosUrgentes,t);

                    mostarTramite(t);
                }
                else
                {
                    if(!listaRegular->isEmpty(listaRegular))
                    {
                        t= (eTramite*) listaRegular->pop(listaRegular,0);
                        printf("cliente a ser atendido (regular): ");

                        atendidosRegulares->add(atendidosRegulares,t);

                        mostarTramite(t);
                    }
                }
               break;
            case 4:
                if(!listaUrgente->isEmpty(listaUrgente))
                {
                    len=listaUrgente->len(listaUrgente);
                    printf("Tramites Urgentes\n");
                    for(i=0;i<len;i++)
                    {
                        t=(eTramite*) listaUrgente->get(listaUrgente,i);
                        mostarTramite(t);
                    }

                }

                if(!listaRegular->isEmpty(listaRegular))
                {
                    len=listaRegular->len(listaRegular);
                    printf("Tramites Regulares\n");
                    for(i=0;i<len;i++)
                    {
                        t=(eTramite*) listaRegular->get(listaRegular,i);
                        mostarTramite(t);
                    }
                }

               break;
            case 5:
                if(!atendidosUrgentes->isEmpty(atendidosUrgentes))
                {
                    len=atendidosUrgentes->len(atendidosUrgentes);
                    atendidosUrgentes->sort(atendidosUrgentes,compararPorDni,0);
                    printf("Tramites Urgentes Atendidos\n");
                    for(i=0;i<len;i++)
                    {
                        t=(eTramite*) atendidosUrgentes->get(atendidosUrgentes,i);
                        mostarTramite(t);
                    }

                }

                if(!atendidosRegulares->isEmpty(atendidosRegulares))
                {
                    len=atendidosRegulares->len(atendidosRegulares);
                    atendidosRegulares->sort(atendidosRegulares,compararPorDni,0);
                    printf("Tramites Regulares Atendidos\n");
                    for(i=0;i<len;i++)
                    {
                        t=(eTramite*) atendidosRegulares->get(atendidosRegulares,i);
                        mostarTramite(t);
                    }
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
