#include <iostream>
using namespace std;
#include "cstring"
#include "ClsJugador.h"
#include "Fecha.h"
#include<iomanip>
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
void Jugador::setEstado(bool e) { estado = e; }


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

bool Jugador::getEstado(){ return estado;}

void Jugador:: cargar() {
     cout<<"INGRESE ID JUGADOR: ";
     cin>> id;
     cin.ignore();
    cout<<"INGRESE NOMBRE DEL JUGADOR: ";
    cin.getline(nombre, 30);
    cout<<"INGRESE POSICION DEL JUGADOR: ";
     cin.getline(posicion,20);
    cout<<"INGRESE VALOR DE MERCADO DEL JUGADOR: ";
    cin>> valorMercado;
    cin.ignore();
    cout<<"INGRESE CLUB ACTUAL DEL JUGADOR: ";
    cin.getline(clubActual,30);
    fechaJugador.Cargar();
    estado=true;
}

void Jugador::mostrar() {
    cout<<"ID DEL JUGADOR: "<< id<<endl;
    cout<<"NOMBRE DEL JUGADOR: "<< nombre<<endl;
    cout<<"POSCION DEL JUGADOR: "<< posicion<<endl;
    cout<<"VALOR DE MERCADO: "<<fixed<<setprecision(2)<< valorMercado<<endl;
    cout<<"CLUB: "<< clubActual<<endl;
    cout<<"FECHA DEL JUGADOR: "<<endl;
    fechaJugador.Mostrar();
    cout<<endl;
    system("pause");
}

