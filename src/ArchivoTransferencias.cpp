#include<iostream>
using namespace std;
#include "cstring"
#include "cstdio"
#include "ArchivoTransferencias.h"
#include "ClsTransferencia.h"


ArchivoTransferencia::ArchivoTransferencia(const char *n){
    strcpy(nombre, n);
}
///busca en la el archivo y devuelve la posicion con fseek y lee
Transferencia ArchivoTransferencia::leerRegistro(int pos){
    Transferencia obj;
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        obj.setIdTransferencia(-2);
        return obj;
    }
    obj.setIdTransferencia(-1);
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
///guarda lo escrito
bool ArchivoTransferencia::grabarRegistro(Transferencia obj){
    FILE *p = fopen(nombre, "ab");
    if(p == nullptr){
        return false;
    }
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

bool ArchivoTransferencia::modificarRegistro(Transferencia obj, int pos){
    FILE *p = fopen(nombre, "rb+");
    if(p == nullptr){
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoTransferencia::contarRegistros(){
    FILE *p = fopen(nombre, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Transferencia);
}

int ArchivoTransferencia::buscarRegistro(int id){
    Transferencia obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getIdTransferencia() == id){
            return i;
        }
    }
    return -1;
}


