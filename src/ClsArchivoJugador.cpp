#include <iostream>
using namespace std;
#include "cstring"
#include "cstdio"
#include "ClsArchivoJugador.h"

ArchivoJugador::ArchivoJugador(const char *n){
    strcpy(nombre, n);
}
///busca en la el archivo y devuelve la posicion con fseek y lee
Jugador ArchivoJugador::leerRegistro(int pos){
    Jugador obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        obj.setId(-2);
        return obj;
    }
    obj.setId(-1);
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
///guarda lo escrito
bool ArchivoJugador::grabarRegistro(Jugador obj){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoJugador::modificarRegistro(Jugador obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoJugador::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Jugador);
}

int ArchivoJugador::buscarRegistro(int id){
    Jugador obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getId() == id){
            return i;
        }
    }
    return -1;
}

void ArchivoJugador::limpiar(){
    FILE *p = fopen(nombre, "wb");
    if(p == nullptr) return;
    fclose(p);
}
