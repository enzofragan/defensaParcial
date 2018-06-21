#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

    int dni;
    char nombre[20];
    char apellido[20];
    int turno;
    int estado;

}eClienteUrgente;

typedef struct{

    int dni;
    char* nombre[20];
    char* apellido[20];
    int turno;
    int estado;

}eClienteRegular;
#endif // FUNCIONES_H_INCLUDED
int turnoAuto(eClienteUrgente* urgente,ArrayList* this);
