#ifndef CLSARCHIVOJUGADOR_H
#define CLSARCHIVOJUGADOR_H
#include "ClsJugador.h"

class ArchivoJugador{
    private:
        char nombre[30];
    public:
        ArchivoJugador(const char *n="Jugador.dat");
        Jugador leerRegistro(int);
        bool grabarRegistro(Jugador);
        bool modificarRegistro(Jugador, int);
        int contarRegistros();
        int buscarRegistro(int);
        void limpiar();

};

#endif // CLSARCHIVOJUGADOR_H
