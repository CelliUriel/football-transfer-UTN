#include <iostream>
using namespace std;
#include "cstring"
#include "cstdio"
#include "ClsArchivoClub.h"
ArchivoClub::ArchivoClub(const char *n){
    strcpy(nombreClub, n);
}

Club ArchivoClub::leerRegistro(int pos){
    Club obj;
    FILE *p = fopen(nombreClub, "rb");
    if(p == nullptr){
        obj.setIdClub(-2);
        return obj;
    }
    obj.setIdClub(-1);
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

//Si no funciona cambiar "nombre" por "nombreClub", creo q asi esta bien igual
bool ArchivoClub::grabarRegistro(Club obj){
    FILE *p = fopen(nombreClub, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoClub::modificarRegistro(Club obj, int pos){
    FILE *p = fopen(nombreClub, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoClub::contarRegistros(){
    FILE *p = fopen(nombreClub, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Club);
}

int ArchivoClub::buscarRegistro(int id){
    Club obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getIdClub() == id){
            return i;
        }
    }
    return -1;
}

void ArchivoClub::limpiar(){
    FILE *p = fopen(nombreClub, "wb");
    if(p == nullptr) return;
    fclose(p);
}


