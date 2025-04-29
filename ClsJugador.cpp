#include <iostream>
using namespace std;
#include "cstring"
#include "ClsJugador.h"
/// SETTERS INICIALIZA VALOR
///GETTERS ACCEDE A LOS VALORES
void Jugador::setNombre(const char* n) {
    strcpy(nombre, n);
}

void Jugador::setPosicion(const char* p) {
    strcpy(posicion, p);
}

void Jugador::setEdad(int e) {
    edad=e;
}

void Jugador::setValorMercado(float v) {
    valorMercado=v;

}

void Jugador::setClubActual(const char* c) {
    strcpy(clubActual, c);

}
void Jugador::setId(int i) {
    id=i;
}

int Jugador::getId() {
    return id;
}

const char *Jugador::getNombre() {
    return nombre;
}
const char *Jugador::getPosicion() {
    return posicion;
}
const char * Jugador::getClubActual() {
    return clubActual;
}
int Jugador::getEdad() {
    return edad ;
}
float Jugador::getValorMercado() {
    return valorMercado;;
}


