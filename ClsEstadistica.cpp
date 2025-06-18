#include<iostream>
using namespace std;
#include "ClsEstadistica.h"
void Estadisticas:: setTemporada(int t) {temporada=t;}
void Estadisticas::setGoles(int g) {goles=g;}
void Estadisticas::setIdJugador(int i){idJugador=i;}

void Estadisticas:: setAsistencias(int a){asistencias=a;}
void Estadisticas::setPartidosJugados(int p) {partidosJugados=p;}

int Estadisticas:: getTemporada(){return temporada;}
int Estadisticas:: getGoles(){return goles;}
int Estadisticas:: getIdJugador(){return idJugador;}
int Estadisticas:: getAsistencias(){return asistencias;}
int Estadisticas:: getPartidosJugados() {return partidosJugados;}


void Estadisticas:: cargar() {
    cout<<"INGRESE ID JUGADOR: "; cin>> idJugador;
    cout<<"INGRESE TEMPORADA: "; cin>> temporada;
    cout<<"INGRESE GOLES DEL JUGADOR: "; cin>> goles;
    cout<<"INGRESE ASISTENCIAS DEL JUGADOR: "; cin>> asistencias;
    cout<<"INGRESE PARTIDOS JUGADOS DEL JUGADOR: "; cin>> partidosJugados;
}

void Estadisticas::mostrar() {
    cout<<idJugador<<endl;
    cout<<temporada<<endl;
    cout<<goles<<endl;
    cout<<asistencias<<endl;
    cout<<partidosJugados<<endl;
}
