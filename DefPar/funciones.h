#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

    char dni[10];
    int idTramite;

}eTramite;

#endif // FUNCIONES_H_INCLUDED
eTramite* new_tramite();
int setId(eTramite*,int);
int getId(eTramite*);

int setDni(eTramite*,char*);
char* getDni(eTramite*);

int mostarTramite(eTramite*);

int compararPorDni(void* ,void* );

int mostrarListaDeTramite(ArrayList* );

int cargarTramite(ArrayList*,int ,char*);

int atenderTramite(ArrayList*, ArrayList*);
