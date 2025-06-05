#ifndef CLSJUGADOR_H
#define CLSJUGADOR_H
#include "Fecha.h"

class Jugador
{
private:
    ///atributos
    char nombre[30];
    Fecha fechaJugador;
    char posicion[20];
    float valorMercado;
    char clubActual[30];
    int id;
    bool estado;

public:
///SETTERS AND GETTERS
    void setNombre(const char *n);
    void setPosicion(const char *p);
    void setValorMercado(float v);
    void setClubActual(const char *c);
    void setId(int);
    void setEstado(bool) ;


    const char *getNombre();
   const char* getPosicion();
    float getValorMercado();
    const char *getClubActual();
    int getId();

    bool getEstado();
    void cargar();
    void mostrar();
};
#endif // CLSJUGADOR_H
