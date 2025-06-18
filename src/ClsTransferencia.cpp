#include<iostream>
using namespace std;
#include "ClsTransferencia.h"
#include "Fecha.h"
#include <iomanip>
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
    cout<<"INGRESE ID JUGADOR: "; cin>> idJugador;
    cout<<"INGRESE MONTO: "; cin>> Monto;
    cout<<"INGRESE ID TRANSFERENCIA: "; cin>> IdTransferencia;
    cout<<"INGRESE ID CLUB ANTERIOR: "; cin>> idClubAnterior;
    cout<<"INGRESE ID CLUB DESTINO: "; cin>> idClubDestino;
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
