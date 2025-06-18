#ifndef CLSTRANSFERENCIA_H
#define CLSTRANSFERENCIA_H
#include "Fecha.h"
class Transferencia{
private:
int idJugador;
int IdTransferencia;
float Monto;
int idClubAnterior;
int idClubDestino;
bool estado;
Fecha fechaTrasferencia;
public:
void setEstado(bool e);
void setMonto(float);
void setIdTransferencia(int);
void setIdJugador(int);
void setIdClubAnterior(int);
void setIdClubDestino(int);
float getMonto();
int getIdTransferencia();
int getIdJugador();
int getIdClubAnterior();
int getIdClubDestino();
bool getEstado();
void cargar();
void mostrar();
};

#endif // CLSTRANSFERENCIA_H
