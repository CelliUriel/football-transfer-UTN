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
#include <iomanip>


void menuPrincipal () {
    int opcion = -1;

    while (opcion != 0) {
        system("cls");
        cout << "==== MENU PRINCIPAL ====" << endl;
        cout << "1. Gestionar Transferencias" << endl;
        cout << "2. Gestionar Jugadores" << endl;
        cout << "3. Gestionar Estadisticas" << endl;
        cout << "4. Gestionar Clubes" << endl;
        cout << "5. Registros"<<endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: menuTransferencia(); break;
            case 2: menuJugador(); break;
            case 3: menuEstadistica(); break;
            case 4: menuClub(); break;
            case 5: menuRegistros(); break;
            case 0: cout << "Saliendo del programa..." << endl; break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                system("pause");
                break;
        }
    }

}

void menuRegistros(){
    int r = -1;
    while (r!=0) {
        cout<<"====MENU REGISTROS===="<<endl;
        cout<<"1. Club con mayor gasto"<<endl;
        cout<<"2. Ordenar clubes por gasto"<<endl;
        cout<<"3. Goles por jugador"<<endl;
        cout<<"4. Top 5 transferencias mas caras"<<endl;
        cout<<"0. Volver"<<endl;
        cin>>r;

        switch (r) {
        case 1: RegistroClubMayorGasto();
        break;
        case 2: ordenarClubesPorGasto();
        break;
        case 3: golesPorJugador();
        break;
        case 4: mostrarTop5TransferenciasMasCaras();
        break;
        case 0: break;
        default: cout<<"Opcion invalida. Intente de nuevo." << endl;
        system ("pause");
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
             break;
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

void RegistroClubMayorGasto() {
    ArchivoClub archivo("club.dat");
    int cantidadClubes = archivo.contarRegistros();

    if (cantidadClubes <= 0) {
        cout << "No hay clubes cargados." << endl;
        return;
    }

    ArchivoTransferencia archivot("transferencia.dat");
    int cantidadTransferencias = archivot.contarRegistros();

    if (cantidadTransferencias <= 0) {
        cout << "No hay transferencias cargadas." << endl;
        return;
    }

    // Reservamos memoria para almacenar gastos por club
    int* idClub = new int[cantidadClubes]{};
    float* gastosClub = new float[cantidadClubes]{};

    for (int i = 0; i < cantidadTransferencias; i++) {
        Transferencia registro = archivot.leerRegistro(i);
        int id = registro.getIdClubDestino();
        float monto = registro.getMonto();

        bool encontrado = false;
        for (int j = 0; j < cantidadClubes; j++) {
            if (idClub[j] == id) {
                gastosClub[j] += monto;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            for (int j = 0; j < cantidadClubes; j++) {
                if (idClub[j] == 0) {
                    idClub[j] = id;
                    gastosClub[j] = monto;
                    break;
                }
            }
        }
    }

    // Buscar el club con mayor gasto
    float maxGasto = 0.0f;
    int idMax = -1;
    for (int i = 0; i < cantidadClubes; i++) {
        if (gastosClub[i] > maxGasto) {
            maxGasto = gastosClub[i];
            idMax = idClub[i];
        }
    }

    if (idMax != -1) {
        cout << "El ID del club que mas gasto es " << idMax << ", con $" <<fixed<<setprecision(2)<<maxGasto << " gastados." << endl;
    } else {
        cout << "No se encontraron gastos registrados." << endl;
    }

    delete[] idClub;
    delete[] gastosClub;
}

void mostrarTop5TransferenciasMasCaras() {
    ArchivoTransferencia archivo;
    int cantidad = archivo.contarRegistros();

    if (cantidad == 0) {
        cout << "No hay transferencias cargadas." << endl;
        return;
    }

    //  Reservar memoria dinámica
    Transferencia* lista = new Transferencia[cantidad];

    //  Leer todas las transferencias del archivo
    for (int i = 0; i < cantidad; i++) {
        lista[i] = archivo.leerRegistro(i);
    }

    //   selection sort de mayor a menor por monto
    for (int i = 0; i < cantidad - 1; i++) {
        int posMax = i;
        for (int j = i + 1; j < cantidad; j++) {
            if (lista[j].getMonto() > lista[posMax].getMonto()) {
                posMax = j;
            }
        }

        if (posMax != i) {
            Transferencia aux = lista[i];
            lista[i] = lista[posMax];
            lista[posMax] = aux;
        }
    }

    //  Mostrar los 5 primeros
    cout << "==== TOP 5 FICHAJES MAS CAROS ====" << endl;
    for (int i = 0; i < 5 && i < cantidad; i++) {
        cout << "ID Transferencia: " << lista[i].getIdTransferencia()
             << " | Monto: $" <<fixed<<setprecision(2)<< lista[i].getMonto() << endl;
    }

    //  Liberar memoria
    delete[] lista;
}

void ordenarClubesPorGasto(){
        ArchivoClub archivo("club.dat");
    int cantidadClubes = archivo.contarRegistros();

    if (cantidadClubes <= 0) {
        cout << "No hay clubes cargados." << endl;
        return;
    }

    ArchivoTransferencia archivot("transferencia.dat");
    int cantidadTransferencias = archivot.contarRegistros();

    if (cantidadTransferencias <= 0) {
        cout << "No hay transferencias cargadas." << endl;
        return;
    }

    // Reservamos memoria para almacenar gastos por club
    int* idClub = new int[cantidadClubes]{};
    float* gastosClub = new float[cantidadClubes]{};

    for (int i = 0; i < cantidadTransferencias; i++) {
        Transferencia registro = archivot.leerRegistro(i);
        int id = registro.getIdClubDestino();
        float monto = registro.getMonto();

        bool encontrado = false;
        for (int j = 0; j < cantidadClubes; j++) {
            if (idClub[j] == id) {
                gastosClub[j] += monto;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            for (int j = 0; j < cantidadClubes; j++) {
                if (idClub[j] == 0) {
                    idClub[j] = id;
                    gastosClub[j] = monto;
                    break;
                }
            }
        }
    }



    // Ordenar clubes por gasto (de mayor a menor)
for (int i = 0; i < cantidadClubes - 1; i++) {
    int maxIndex = i;
    for (int j = i + 1; j < cantidadClubes; j++) {
        if (gastosClub[j] > gastosClub[maxIndex]) {
            maxIndex = j;
        }
    }
    if (maxIndex != i) {
        // Intercambiar gasto
        float auxGasto = gastosClub[i];
        gastosClub[i] = gastosClub[maxIndex];
        gastosClub[maxIndex] = auxGasto;

        // Intercambiar ID correspondiente
        int auxId = idClub[i];
        idClub[i] = idClub[maxIndex];
        idClub[maxIndex] = auxId;
    }
}

cout << "\nListado de clubes ordenado por gasto (mayor a menor):\n";
for (int i = 0; i < cantidadClubes; i++) {
    if (idClub[i] != 0) { // Solo mostramos IDs válidos
        cout << "ID Club: " << idClub[i]
             << " - Gasto: $" << fixed << setprecision(2) << gastosClub[i] << endl;
    }
}
    delete[] idClub;
    delete[] gastosClub;
}

void golesPorJugador(){
    ArchivoJugador archivoj("jugador.dat");
    int cantidadJugadores = archivoj.contarRegistros();
        if (cantidadJugadores <= 0) {
        cout << "No hay jugadores cargados." << endl;
        return;
    }
    ArchivoEstadistica archivo ("estadistica.dat");
    int cantidadEstadisticas = archivo.contarRegistros();
        if (cantidadEstadisticas <= 0) {
        cout << "No hay estadisticas cargadas." << endl;
        return;
    }
    int* idJugador = new int[cantidadJugadores]{};
    int* GolesPJugador = new int[cantidadJugadores]{};

        for (int i = 0; i < cantidadEstadisticas; i++) {
        Estadisticas registro = archivo.leerRegistro(i);
        int id = registro.getIdJugador();
        int goles = registro.getGoles();

        bool encontrado = false;
        for (int j = 0; j < cantidadEstadisticas; j++) {
            if (idJugador[j] == id) {
                GolesPJugador[j] += goles;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            for (int j = 0; j < cantidadEstadisticas; j++) {
                if (idJugador[j] == 0) {
                    idJugador[j] = id;
                    GolesPJugador[j] += goles;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < cantidadJugadores - 1; i++) {
    int maxIndex = i;
    for (int j = i + 1; j < cantidadJugadores; j++) {
        if (GolesPJugador[j] > GolesPJugador[maxIndex]) {
            maxIndex = j;
        }
    }
    if (maxIndex != i) {
        // Intercambiar gasto
        int auxGoles = GolesPJugador[i];
        GolesPJugador[i] = GolesPJugador[maxIndex];
        GolesPJugador[maxIndex] = auxGoles;

        // Intercambiar ID correspondiente
        int auxId = idJugador[i];
        idJugador[i] = idJugador[maxIndex];
        idJugador[maxIndex] = auxId;
    }
}
cout << "\nListado de jugadores ordenado por goles (mayor a menor):\n";
for (int i = 0; i < cantidadJugadores; i++) {
    if (idJugador[i] != 0) { // Solo mostramos IDs válidos
        cout << "ID jugador: " << idJugador[i]
             << " - goles: " << GolesPJugador[i] << endl;
    }
}
    delete[] idJugador;
    delete[] GolesPJugador;
}
