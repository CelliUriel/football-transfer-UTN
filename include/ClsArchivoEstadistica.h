#ifndef CLSARCHIVOESTADISTICA_H
#define CLSARCHIVOESTADISTICA_H
#include "ClsEstadistica.h"


class ArchivoEstadistica
{
private:
    char nombre[30];
public:
        ArchivoEstadistica(const char *n="Estadistica.dat");
        Estadisticas leerRegistro(int);
        bool grabarRegistro(Estadisticas);
        bool modificarRegistro(Estadisticas, int);
        int contarRegistros();
        int buscarRegistro(int);
        void limpiar();

};


#endif // CLSARCHIVOESTADISTICA_H
