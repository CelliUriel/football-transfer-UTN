#include<iostream>
using namespace std;
#include "ClsEstadistica.h"
#include "ClsArchivoEstadistica.h"
#include "ClsArchivoJugador.h"
void Estadisticas:: setTemporada(int t) {temporada=t;}
void Estadisticas::setGoles(int g) {goles=g;}
void Estadisticas::setIdJugador(int i){idJugador=i;}
void Estadisticas::setIdEstadistica(int idE){idEstadistica=idE;}
void Estadisticas:: setAsistencias(int a){asistencias=a;}
void Estadisticas::setPartidosJugados(int p) {partidosJugados=p;}
void Estadisticas::setEstado(bool e) { estado = e; }
int Estadisticas:: getTemporada(){return temporada;}
int Estadisticas:: getGoles(){return goles;}
int Estadisticas:: getIdJugador(){return idJugador;}
int Estadisticas:: getAsistencias(){return asistencias;}
int Estadisticas:: getPartidosJugados() {return partidosJugados;}
bool Estadisticas::getEstado(){ return estado;}

void Estadisticas:: cargar() {
    ArchivoEstadistica arcE;
    ArchivoJugador arcJ;
    while (true) {
    cout<< "INGRESE ID ESTADISTICA";cin>> idEstadistica;
    if (arcE.buscarRegistro(idEstadistica)==-1) {
        break; //sigue
    }
    cout<<"ID ESTADISTICA EXISTENTE. INTENTE NUEVAMENTE"<<endl;
    }
     while (true) {
    cout<<"INGRESE ID JUGADOR: "; cin>> idJugador;
    cin.ignore();
    if(arcJ.buscarRegistro(idJugador)!=-1) {
        break;
    }
    cout<<"ID JUGADOR INEXISTENTE. INTENTE NUEVAMENTE."<<endl;
     }
    cout<<"INGRESE TEMPORADA: "; cin>> temporada;
    cout<<"INGRESE GOLES DEL JUGADOR: "; cin>> goles;
    cout<<"INGRESE ASISTENCIAS DEL JUGADOR: "; cin>> asistencias;
    cout<<"INGRESE PARTIDOS JUGADOS DEL JUGADOR: "; cin>> partidosJugados;
}

void Estadisticas::modificarAltaEstadistica(int idEstActual) {
    ArchivoEstadistica arcE;
    ArchivoJugador arcJ;

    int nuevoIdEstadistica;

    // Cambiar ID de estadística
    while (true) {
        cout << "INGRESE NUEVO ID DE ESTADISTICA (O EL MISMO): ";
        cin >> nuevoIdEstadistica;

        if (nuevoIdEstadistica == idEstActual || arcE.buscarRegistro(nuevoIdEstadistica) == -1) {
            idEstadistica = nuevoIdEstadistica;
            break;
        }
        cout << "YA EXISTE UNA ESTADISTICA CON ESE ID. INGRESE OTRO." << endl;
    }

    // Verificar que el jugador exista
    while (true) {
        cout << "INGRESE ID JUGADOR: ";
        cin >> idJugador;

        if (arcJ.buscarRegistro(idJugador) != -1) {
            break;
        }

        cout << "ID JUGADOR INEXISTENTE. INTENTE NUEVAMENTE." << endl;
    }

    cout << "INGRESE TEMPORADA: ";
    cin >> temporada;

    cout << "INGRESE GOLES DEL JUGADOR: ";
    cin >> goles;

    cout << "INGRESE ASISTENCIAS DEL JUGADOR: ";
    cin >> asistencias;

    cout << "INGRESE PARTIDOS JUGADOS DEL JUGADOR: ";
    cin >> partidosJugados;

    estado = true;
}


void Estadisticas::mostrar() {
    cout<<"ID DE ESTADISTICA: "<< idEstadistica;
    cout<<"ID DEL JUGADOR: "<< idJugador<<endl;
    cout<<"ESTADISTICA DE LA TEMPORADA "<< temporada<<endl;
    cout<<"GOLES DEL JUGADOR EN LA TEMPORADA: "<< goles<<endl;
    cout<<"ASISTENCIAS EN LA TEMPORADA: "<< asistencias<<endl;
    cout<<"PARTIDOS JUGADOS EN LA TEMPORADA: "<< partidosJugados<<endl;
    system("pause");
}
