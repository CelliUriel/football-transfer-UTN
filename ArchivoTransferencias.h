#ifndef ARCHIVOTRANSFERENCIAS_H
#define ARCHIVOTRANSFERENCIAS_H
#include "ClsTransferencia.h"

class ArchivoTransferencia{
    private:
        char nombre[30];
    public:
        ArchivoTransferencia(const char *n="Transferencia.dat");
        Transferencia leerRegistro(int);
        bool grabarRegistro(Transferencia);
        bool modificarRegistro(Transferencia, int);
        int contarRegistros();
        int buscarRegistro(int);


};

#endif // ARCHIVOTRANSFERENCIAS_H
