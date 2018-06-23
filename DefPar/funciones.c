#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

eTramite* new_tramite()
{
    eTramite* aux;

    aux=(eTramite*) malloc(sizeof(eTramite));

    return aux;
}

int setId(eTramite* this,int id)
{
    int seteo=-1;
    if(this!=NULL)
    {
        this->idTramite = id;
        seteo=0;
    }
    return seteo;
}

int getId(eTramite* this)
{
    int id;
    if(this!=NULL)
    {
        id=this->idTramite;
    }
    return id;
}

int setDni(eTramite* this,char* dni)
{
    int seteo=-1;
    if(this!=NULL && dni!=NULL)
    {
        strcpy(this->dni,dni);
        seteo=0;
    }
    return seteo;
}

char* getDni(eTramite* this)
{
    char* dni=NULL;
    if(this!=NULL)
    {
        dni=this->dni;
    }
    return dni;
}

int mostarTramite(eTramite* this)
{
    int mostro=-1;
    if(this!=NULL)
    {
        ///printf("%d------%s\n",this->idTramite,this->dni);
        printf("%d------%s\n",getId(this),getDni(this));
        mostro=0;
    }
    return mostro;
}

int compararPorDni(void* tramiteA,void* tramiteB)
{
    eTramite* tramite1;
    eTramite* tramite2;

    tramite1= (eTramite*) tramiteA;
    tramite2= (eTramite*) tramiteB;

    return strcmp(tramite1->dni,tramite2->dni);
}

int mostrarListaDeTramite(ArrayList* listado)
{
    int listo=-1;
    int i;
    int len;
    eTramite* tramite;
    if(listado!=NULL)
    {
        len=listado->len(listado);
        for(i=0;i<len;i++)
        {
            tramite= (eTramite*) listado->get(listado,i);
            mostarTramite(tramite);
        }
        listo=0;
    }
    return listo;
}
int cargarTramite(ArrayList* listado,int id,char* dni)
{
    eTramite* t;
    int cargo=-1;
    if(listado!=NULL && id>0 && dni!=NULL)
    {
        t=new_tramite();
        setId(t,id);
        setDni(t,dni);
        listado->add(listado,t);
        archivo(listado,id);
        cargo=0;
    }
    return cargo;
}

int atenderTramite(ArrayList* listadoP, ArrayList* listadoA)
{
    int atender=-1;
    eTramite* t;
    if(listadoP!=NULL && listadoA!=NULL)
    {
        t= (eTramite*) listadoP->pop(listadoP,0);

        listadoA->add(listadoA,t);

        mostarTramite(t);
    }
}

int archivo(ArrayList* listado,int id)
{
    FILE* archivos;
    int listo=-1;
    int i;
    int len;
    eTramite* tramite;
    if(listado!=NULL)
    {
        len=listado->len(listado);
        archivos=fopen("hola.csv","wb");
        for(i=0;i<len;i++)
        {
            tramite= (eTramite*) listado->get(listado,i);
            fwrite(tramite,sizeof(eTramite),1,archivos);
        }
        fclose(archivos);
        listo=0;
    }
    return listo;
}
