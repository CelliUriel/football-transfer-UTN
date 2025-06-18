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
Fecha fechaTrasferencia;
public:
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
void cargar();
void mostrar();
};

#endif // CLSTRANSFERENCIA_H
