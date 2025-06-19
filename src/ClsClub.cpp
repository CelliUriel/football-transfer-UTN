#include <iostream>
using namespace std;
#include "cstring"
#include "ClsClub.h"
#include "ClsArchivoClub.h"


void Club::setNombreClub(const char* n){
    strcpy(nombreClub, n);
}

void Club::setIdClub(int i){
    idClub=i;
}

void Club::setBalance(int b){
    balance=b;
}

void Club::setCantJugadores(int c){
    cantJugadores=c;
}

void Club::setAnioCreacion(int a){
    anioCreacion=a;
}
void Club::setEstado(bool e) { estado = e; }


const char *Club::getNombreClub() {
    return nombreClub;
}

int Club::getIdClub(){
    return idClub;
}

int Club::getBalance(){
    return balance;
}

int Club::getCantJugadores(){
    return cantJugadores;
}

int Club::getAnioCreacion(){
    return anioCreacion;
}

bool Club::getEstado(){ return estado;}

void Club::cargar(){
    ArchivoClub arC;
    cout<<"INGRESE EL NOMBRE DEL CLUB: ";
    cin.ignore();
    cin.getline(nombreClub, 30);
    while (true) {
    cout<<"INGRESE EL ID DEL CLUB: "; cin>> idClub;
    if (arC.buscarRegistro(idClub)==-1) {
        break; //sigue
    }
    cout<<"ID DE CLUB EXISTENTE. PORFAVOR INTENTALO DE NUEVO."<<endl;
    }
    cout<<"INGRESE BALANCE: "; cin>> balance;
    cout<<"INGRESE LA CANTIDAD DE JUGADORES: "; cin>> cantJugadores;
    cout<<"INGRESE EL ANIO DE CREACION: "; cin>> anioCreacion;
    estado=true;
}
void Club::ModificarAltaClub(int idActual) {
    ArchivoClub arc;
    cin.ignore();

        cout << "INGRESE NUEVO NOMBRE DEL CLUB: ";
        cin.getline(nombreClub, 30);


       while (true) {
        cout << "INGRESE NUEVO ID DEL CLUB (ACTUAL: " << idActual << "): ";
        cin >> idClub;

        if (idClub == idActual || arc.buscarRegistro(idClub) == -1) {
            break;  // Acepta el mismo o uno que no existe
        }

        cout << "YA EXISTE UN CLUB CON ESE ID. INGRESE OTRO." << endl;
    }
        cout << "INGRESE NUEVO BALANCE: ";
        cin >> balance;
        cout << "INGRESE NUEVA CANTIDAD DE JUGADORES: ";
        cin >> cantJugadores;
        cout << "INGRESE NUEVO ANIO DE CREACION: ";
        cin >> anioCreacion;
        estado = true;
}

void Club::mostrar(){
    cout<<"NOMBRE DEL CLUB: "<< nombreClub<<endl;
    cout<<"ID "<<idClub<<endl;
    cout<<"BALANCE: $"<<balance<<endl;
    cout<<"JUGADORES: "<<cantJugadores<<endl;
    cout<<"CREADO EN EL ANIO "<<anioCreacion<<endl;
}
