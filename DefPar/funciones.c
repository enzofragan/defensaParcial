#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

int turnoAuto(eClienteUrgente* urgente,ArrayList* this)
{
    int i;
    int returnAux=0;
    for(i=0;i<this->len(this);i++)
    {
        if((urgente->estado+i)==0)
        {
            returnAux=i+1;
        }
    }
    return returnAux;
}
