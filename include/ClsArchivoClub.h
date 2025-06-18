#ifndef CLSARCHIVOCLUB_H
#define CLSARCHIVOCLUB_H
#include "ClsClub.h"

class ArchivoClub
{
private:
    char nombreClub[30];
public:
        ArchivoClub(const char *n="Club.dat");
        Club leerRegistro(int);
        bool grabarRegistro(Club);
        bool modificarRegistro(Club, int);
        int contarRegistros();
        int buscarRegistro(int);
        void limpiar();

};

#endif // CLSARCHIVOCLUB_H
