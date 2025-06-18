#include "ClsArchivoEstadistica.h"
#include <iostream>
using namespace std;
#include "cstring"
#include "cstdio"

ArchivoEstadistica::ArchivoEstadistica(const char *n){
    strcpy(nombre, n);
}

Estadisticas ArchivoEstadistica::leerRegistro(int pos){
    Estadisticas obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        obj.setIdJugador(-2);
        return obj;
    }
    obj.setIdJugador(-1);
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoEstadistica::grabarRegistro(Estadisticas obj){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoEstadistica::modificarRegistro(Estadisticas obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoEstadistica::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Estadisticas);
}

int ArchivoEstadistica::buscarRegistro(int id){
    Estadisticas obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getIdJugador() == id){
            return i;
        }
    }
    return -1;
}

void ArchivoEstadistica::limpiar(){
    FILE *p = fopen(nombre, "wb");
    if(p == nullptr) return;
    fclose(p);
}
