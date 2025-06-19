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
    int t = -1;
    int idTransferencia;

    while (t!=0) {
        system("cls");
        cout<<"==== MENU TRANSFERENCIAS ===="<<endl;
        cout<<"1. Alta Transferencia"<<endl;
        cout<<"2. Baja Transferencia"<<endl;
        cout<<"3. Modificar Transferencia"<<endl;
        cout<<"4. Listar Transferencias"<<endl;
        cout<<"0. Volver"<<endl;
        cin>>t;

        switch (t) {
        case 1: altaTransferencia();
        break;
        case 2:  cout<<"Ingrese el ID de transferencia: "<<endl;
        cin>> idTransferencia;
            bajaTransferencia(idTransferencia);
            break;
        case 3: cout<<"Ingrese el ID de transferencia: "<<endl;
        cin>> idTransferencia;
             modificarTransferencia(idTransferencia);
        case 4: listarTransferencias();
        break;
        case 0: break;
        default: cout<<"Opcion invalida. Intente de nuevo." << endl;
        system ("pause");
        }
    }
}

void menuClub(){
    int c = -1;
    int idClub;

    while (c!=0) {
        system("cls");
        cout<<"==== MENU CLUB ===="<<endl;
        cout<<"1. Alta Club"<<endl;
        cout<<"2. Baja Club"<<endl;
        cout<<"3. Modificar Club"<<endl;
        cout<<"4. Listar Clubes"<<endl;
        cout<<"0. Volver"<<endl;
        cin>>c;
                switch (c) {
        case 1: altaClub();
        break;
        case 2: cout<<"Ingrese el ID del club a dar de baja"<<endl;
        cin>> idClub;
        bajaClub(idClub);
        break;
        case 3: cout<<"Ingrese el ID del club a modificar "<<endl;
        cin>> idClub;
        modificarClub(idClub);
        break;
        case 4: system("cls");
        listarClub();
        system("pause");
        break;
        case 0: break;
        default: cout<<"Opcion invalida. Intente de nuevo." << endl;
        system ("pause");
        }
}
}

void menuJugador(){
    int j = -1;
    int idJugador;

    while (j!=0) {
        system("cls");
        cout<<"==== MENU JUGADOR ===="<<endl;
        cout<<"1. Alta Jugador"<<endl;
        cout<<"2. Baja Jugador"<<endl;
        cout<<"3. Modificar Jugador"<<endl;
        cout<<"4. Listar Jugadores"<<endl; //NO ANDA BIEN
        cout<<"0. Volver"<<endl;
        cin>>j;
                switch (j) {
        case 1: altaJugador();
        break;
        case 2: cout<<"Ingrese el ID del jugador a dar de baja"<<endl;
        cin>>idJugador;
        bajaJugador(idJugador);
        break;
        case 3: cout<<"Ingrese el ID del jugador a modificar"<<endl;
        cin>>idJugador;
        modificarJugador(idJugador);
        break;
        case 4: listarJugador(); //NO ANDA BIEN, NO SE XQ

        break;
        case 0: break;
        default: cout<<"Opcion invalida. Intente de nuevo." << endl;
        system ("pause");
        }
}
}

void menuEstadistica(){
    int e = -1;

    while (e!=0) {
        system("cls");
        int idJugador;
        cout<<"==== MENU ESTADISTICA ===="<<endl;
        cout<<"1. Alta Estadistica"<<endl;
        cout<<"2. Baja Estadistica"<<endl;
        cout<<"3. Modificar Estadistica"<<endl;
        cout<<"4. Listar Estadisticas"<<endl;
        cout<<"0. Volver"<<endl;
        cin>>e;
                switch (e) {
        case 1: altaEstadisticas();
        break;
        case 2: cout<<"Ingrese el ID del jugador a dar de baja"<<endl;
        cin>>idJugador;
             bajaEstadisticas(idJugador);
             break;
        case 3:cout<<"Ingrese el ID del jugador a modificar"<<endl;
        cin>>idJugador;
             modificarEstadisticas(idJugador);
        case 4: listarEstadisticas();
        break;
        case 0: break;
        default: cout<<"Opcion invalida. Intente de nuevo." << endl;
        system ("pause");
        }
}
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
t.setEstado(true);
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
         system("pause");
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
         system("pause");
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
    j.setEstado(true);
    ArchivoJugador arc;
    arc.grabarRegistro(j);
}

void bajaJugador(int id) {
   ArchivoJugador arc;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Jugador no encontrado.\n";
         system("pause");
        return;
    }
  Jugador j = arc.leerRegistro(pos);
    j.setEstado(false);  // metodo que marca como inactiva
    arc.modificarRegistro(j, pos);
    cout<<"JUGADOR DADO DE BAJA."<<endl;
    system("pause");
}

void modificarJugador(int id) {
    ArchivoJugador arc;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Jugador no encontrado."<<endl;
        system("pause");
        return;
    }

    Jugador j;
    j = arc.leerRegistro(pos);

    j.mostrar();  // mostrar actual
    cout<<"Ingrese los nuevos datos: "<<endl;
    j.modificarAltaJugador();  // metodo donde pedís nuevos datos
    arc.modificarRegistro(j, pos);
}

void listarJugador() {
    ArchivoJugador arc;
    Jugador obj;
    int cantRegistros = arc.contarRegistros();

    for (int i = 0; i < cantRegistros; i++) {
        obj = arc.leerRegistro(i);
          if (obj.getEstado()) {
             obj.mostrar();
            cout << "--------------------------\n";

          }// muestra solo los verdaderos


    }
}

void altaClub() {
    Club c;
    c.cargar();  // metodo que pide al usuario los datos
c.setEstado(true);
    ArchivoClub arc;
    arc.grabarRegistro(c);
}

void bajaClub(int id) {
   ArchivoClub arc;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Club no encontrado."<<endl;
        system("pause");
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
        cout << "Club no encontrado."<<endl;
       system("pause");
       return;

    }


    Club c;
    c = arc.leerRegistro(pos);

    c.mostrar();  // mostrar actual
    cout<<"Ingrese los nuevos datos: "<<endl;
    c.ModificarAltaClub(id);  // metodo donde pedís nuevos datos
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
e.setEstado(true);
    ArchivoEstadistica arc;
    arc.grabarRegistro(e);
}

void bajaEstadisticas(int id) {
   ArchivoEstadistica arc;
    int pos = arc.buscarRegistro(id);
    if (pos == -1) {
        cout << "Club no encontrado.\n";
         system("pause");
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
         system("pause");
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
    Estadisticas obj;
    int cantRegistros = arc.contarRegistros();

    for (int i = 0; i < cantRegistros; i++) {
        obj = arc.leerRegistro(i);

        if (obj.getEstado()==true) {

             obj.mostrar();
            cout << "--------------------------\n";
        }
          // muestra solo los verdaderos


    }
}
