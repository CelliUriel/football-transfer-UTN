#include <iostream>
using namespace std;
#include "cstring"
#include "ClsJugador.h"
#include "Fecha.h"
/// SETTERS INICIALIZA VALOR
///GETTERS ACCEDE A LOS VALORES
void Jugador::setNombre(const char* n) {
    strcpy(nombre, n);
}

void Jugador::setPosicion(const char* p) {
    strcpy(posicion, p);
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

float Jugador::getValorMercado() {
    return valorMercado;;
}
void Jugador:: cargar() {
    cout<<"INGRESE ID JUGADOR: "; cin>> id;
    cout<<"INGRESE NOMBRE DELL JUGADOR: "; cin>> nombre;
    cout<<"INGRESE POSICION DEL JUGADOR: "; cin>> posicion;
    cout<<"INGRESE VALOR DE MERCADO DEL JUGADOR: "; cin>> valorMercado;
    cout<<"INGRESE CLUB ACTUAL DEL JUGADOR: "; cin>> clubActual;
    fechaJugador.Cargar();
}

void Jugador::mostrar() {
    cout<< id;
    cout<< nombre;
    cout<< posicion;
    cout<<valorMercado;
    cout<<clubActual;
    fechaJugador.Mostrar();
}


