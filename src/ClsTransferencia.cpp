#include<iostream>
using namespace std;
#include "ClsTransferencia.h"
#include "Fecha.h"
#include <iomanip>
#include "ClsArchivoClub.h"
#include "ClsArchivoJugador.h"
#include "ArchivoTransferencias.h"
void Transferencia::setMonto(float m){
    Monto = m;
}

void Transferencia::setIdTransferencia(int i){
    IdTransferencia = i;
}
void Transferencia::setIdJugador(int j){
    idJugador = j;
}
void Transferencia::setIdClubAnterior(int a){
    idClubAnterior = a;
}
void Transferencia::setIdClubDestino(int d){
    idClubDestino = d;
}
float Transferencia::getMonto(){return Monto;}
int Transferencia::getIdTransferencia(){return IdTransferencia;}
int Transferencia::getIdJugador(){return idJugador;}
int Transferencia::getIdClubAnterior(){return idClubAnterior;}
int Transferencia::getIdClubDestino(){return idClubDestino;}
void Transferencia::setEstado(bool e) { estado = e; }
bool Transferencia::getEstado(){ return estado;}

void Transferencia::cargar(){
    ArchivoClub arC;
    ArchivoJugador arcJ;
    ArchivoTransferencia arcT;
    while (true) {
    cout<<"INGRESE ID JUGADOR: "; cin>> idJugador;
    if (arcJ.buscarRegistro(idJugador)!=-1) {
        break; //sigue
    }
    cout<<"EL ID JUGADOR NO EXISTE, INTENTELO DE NUEVO."<<endl;
    }
     while (true) {
    cout<<"INGRESE MONTO: "; cin>> Monto;
    if (Monto>0) {
        break; //sigue
    }
    cout<<"INGRESE UN NUMERO POSITIVO, PORFAVOR."<<endl;
     }
      while (true) {
    cout<<"INGRESE ID TRANSFERENCIA: "; cin>> IdTransferencia;
    if (arcT.buscarRegistro(IdTransferencia)==-1) {
        break; //sigue
    }
    cout<<"ID DE TRANSFERENCIA EXISTENTE. PORFAVOR, INTENTELO DE NUEVO."<<endl;
      }
       while (true) {
    cout<<"INGRESE ID CLUB ANTERIOR: "; cin>> idClubAnterior;
    if (arC.buscarRegistro(idClubAnterior)!=-1) {
        break; //sigue
    }
    cout<< "ID DE CLUB NO EXISTENTE. INTENTELO DE NUEVO."<<endl;
       }
        while (true) {
    cout<<"INGRESE ID CLUB DESTINO: "; cin>> idClubDestino;
    if (arC.buscarRegistro(idClubDestino) == -1) {
            cout << "EL ID CLUB DESTINO NO EXISTE, INTENTELO DE NUEVO." << endl;
        } else if (idClubDestino == idClubAnterior) {
            cout << "EL CLUB DESTINO NO PUEDE SER IGUAL AL CLUB ANTERIOR, INGRESE OTRO." << endl;
        } else {
            break;
        }
        }
    fechaTrasferencia.Cargar();
}
void Transferencia::mostrar(){
    cout<<"ID DEL JUGADOR: "<< idJugador<<endl;
    cout<<"MONTO DE LA TRANSERENCIA: "<<fixed<<setprecision(2)<< Monto<<endl;
    cout<<"ID DE TRANSERENCIA: "<< IdTransferencia<<endl;
    cout<<"ID DEL CLUB ANTERIOR: "<< idClubAnterior<<endl;
    cout<<"ID DE CLUB DESTINO: "<< idClubDestino<<endl;
    cout<<"FECHA DE TRANSFERENCIA: "<<endl;
    fechaTrasferencia.Mostrar();
    cout<<endl;
    system("pause");
}
