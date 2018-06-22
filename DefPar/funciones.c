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
