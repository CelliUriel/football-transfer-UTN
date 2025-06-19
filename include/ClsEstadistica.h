#ifndef CLSESTADISTICA_H
#define CLSESTADISTICA_H


class Estadisticas{
private:
int idEstadistica;
int idJugador;
int temporada;
int goles;
int asistencias;
int partidosJugados;
bool estado;
public:

void setTemporada(int);
void setGoles(int);
void setIdJugador(int);
void setIdEstadistica(int);
void setEstado(bool);
void setAsistencias(int);
void setPartidosJugados(int);
int getTemporada();
int getGoles();
int getIdJugador();
int getIdEstadistica();
int getAsistencias();
int getPartidosJugados();
bool getEstado();
void cargar();
void modificarAltaEstadistica(int);
void mostrar();
};

#endif // CLSESTADISTICA_H
