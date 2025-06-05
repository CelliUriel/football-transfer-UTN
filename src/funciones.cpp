#include <iostream>
using namespace std;
#include "cstring"
#include "funciones.h"
#include "ClsTransferencia.h"
#include "ArchivoTransferencias.h"
#include "ClsArchivoClub.h"
#include "ClsClub.h"
#include "ClsJugador.h"
#include "ClsEstadistica.h"
#include "ClsArchivoJugador.h"

void cargarCadena(char *palabra, int tamano){
    int i=0;
    fflush(stdin);
    for (i=0; i<tamano; i++){
        palabra[i]=cin.get();
        if (palabra[i]=='\n'){
            break;
        }
    }
    palabra[i]='\0';
    fflush(stdin);
}

void altaTransferencia() {
    Transferencia t;
    t.cargar();  // metodo que pide al usuario los datos

    ArchivoTransferencia arc;
    arc.grabarRegistro(t);
}

void bajaTransferencia(int id) {
   ArchivoTransferencia arc;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Transferencia no encontrada.\n";
        return;
    }
  Transferencia t = arc.leerRegistro(pos);
    t.setEstado(false);  // metodo que marca como inactiva
    arc.modificarRegistro(t, pos);
}

void modificarTransferencia(int id) {
    ArchivoTransferencia arc;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Transferencia no encontrada.\n";
        return;
    }

    Transferencia t;
    t = arc.leerRegistro(pos);

    t.mostrar();  // mostrar actual
    cout<<"Ingrese los nuevos datos: "<<endl;
    t.cargar();  // metodo donde pedís nuevos datos
    arc.modificarRegistro(t, pos);
}


void listarTransferencias() {
    ArchivoTransferencia arc;
    int cantRegistros = arc.contarRegistros();

    for (int i = 0; i < cantRegistros; i++) {
        Transferencia t = arc.leerRegistro(i);
        if (t.getEstado()) {  // muestra solo los verdaderos
            t.mostrar();
            cout << "--------------------------\n";
        }
    }
}

