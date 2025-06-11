#include <iostream>
using namespace std;
#include "cstring"
#include "funciones.h"
#include "ClsTransferencia.h"
#include "ArchivoTransferencias.h"
#include "ClsArchivoEstadistica.h"
#include "ClsArchivoClub.h"
#include "ClsClub.h"
#include "ClsJugador.h"
#include "ClsEstadistica.h"
#include "ClsArchivoJugador.h"


void menuPrincipal () {
    int opcion = -1;

    while (opcion != 0) {
        system("cls");
        cout << "==== MENU PRINCIPAL ====" << endl;
        cout << "1. Gestionar Transferencias" << endl;
        cout << "2. Gestionar Jugadores" << endl;
        cout << "3. Gestionar Estadisticas" << endl;
        cout << "4. Gestionar Clubes" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: menuTransferencia(); break;
            case 2: menuJugador(); break;
            case 3: menuEstadistica(); break;
            case 4: menuClub(); break;
            case 0: cout << "Saliendo del programa..." << endl; break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                system("pause");
                break;
        }
    }

}

void menuTransferencia(){

}

void menuClub(){

}

void menuJugador(){

}

void menuEstadistica(){

}

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
   cout<< "INGRESE ID DE TRANSFERENCIA: "<<endl;
   cin>>id;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Transferencia no encontrada.";
        return;
    }
  Transferencia t = arc.leerRegistro(pos);
    t.setEstado(false);  // metodo que marca como inactiva
    arc.modificarRegistro(t, pos);
}

void modificarTransferencia(int id) {
    ArchivoTransferencia arc;
     cout<< "INGRESE ID DE TRANSFERENCIA: "<<endl;
   cin>>id;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Transferencia no encontrada.";
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

void altaJugador() {
    Jugador j;
    j.cargar();  // metodo que pide al usuario los datos

    ArchivoJugador arc;
    arc.grabarRegistro(j);
}

void bajaJugador(int id) {
   ArchivoJugador arc;
    cout<< "INGRESE ID DE JUGADOR: "<<endl;
   cin>>id;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Jugador no encontrado.\n";
        return;
    }
  Jugador j = arc.leerRegistro(pos);
    j.setEstado(false);  // metodo que marca como inactiva
    arc.modificarRegistro(j, pos);
    cout<<"JUGADOR DADO DE BAJA."<<endl;
}

void modificarJugador(int id) {
    ArchivoJugador arc;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Jugador no encontrado.\n";
        return;
    }

    Jugador j;
    j = arc.leerRegistro(pos);

    j.mostrar();  // mostrar actual
    cout<<"Ingrese los nuevos datos: "<<endl;
    j.cargar();  // metodo donde pedís nuevos datos
    arc.modificarRegistro(j, pos);
}

void listarJugador() {
    ArchivoJugador arc;
    int cantRegistros = arc.contarRegistros();

    for (int i = 0; i < cantRegistros; i++) {
        Jugador j = arc.leerRegistro(i);
        if (j.getEstado()) {  // muestra solo los verdaderos
            j.mostrar();
            cout << "--------------------------\n";
        }
    }
}


void altaClub() {
    Club c;
    c.cargar();  // metodo que pide al usuario los datos

    ArchivoClub arc;
    arc.grabarRegistro(c);
}


void bajaClub(int id) {
   ArchivoClub arc;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Club no encontrado.\n";
        return;
    }
  Club c = arc.leerRegistro(pos);
    c.setEstado(false);  // metodo que marca como inactiva
    arc.modificarRegistro(c, pos);
}

void modificarClub(int id) {
    ArchivoClub arc;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Jugador no encontrado.\n";
        return;
    }

    Club c;
    c = arc.leerRegistro(pos);

    c.mostrar();  // mostrar actual
    cout<<"Ingrese los nuevos datos: "<<endl;
    c.cargar();  // metodo donde pedís nuevos datos
    arc.modificarRegistro(c, pos);
}

void listarClub() {
    ArchivoClub arc;
    int cantRegistros = arc.contarRegistros();

    for (int i = 0; i < cantRegistros; i++) {
        Club c = arc.leerRegistro(i);
        if (c.getEstado()) {  // muestra solo los verdaderos
            c.mostrar();
            cout << "--------------------------\n";
        }
    }
}

void altaEstadisticas() {
    Estadisticas e;
    e.cargar();  // metodo que pide al usuario los datos

    ArchivoEstadistica arc;
    arc.grabarRegistro(e);
}

void bajaEstadisticas(int id) {
   ArchivoEstadistica arc;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Club no encontrado.\n";
        return;
    }
  Estadisticas e = arc.leerRegistro(pos);
    e.setEstado(false);  // metodo que marca como inactiva
    arc.modificarRegistro(e, pos);
}

void modificarEstadisticas(int id) {
    ArchivoEstadistica arc;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Jugador no encontrado.\n";
        return;
    }

    Estadisticas e;
    e = arc.leerRegistro(pos);

    e.mostrar();  // mostrar actual
    cout<<"Ingrese los nuevos datos: "<<endl;
    e.cargar();  // metodo donde pedís nuevos datos
    arc.modificarRegistro(e, pos);
}


void listarEstadisticas() {
    ArchivoEstadistica arc;
    int cantRegistros = arc.contarRegistros();

    for (int i = 0; i < cantRegistros; i++) {
        Estadisticas e = arc.leerRegistro(i);
        if (e.getEstado()) {  // muestra solo los verdaderos
            e.mostrar();
            cout << "--------------------------\n";
        }
    }
}


