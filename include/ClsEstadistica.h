#ifndef CLSESTADISTICA_H
#define CLSESTADISTICA_H


class Estadisticas{
private:
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
void setEstado(bool);
void setAsistencias(int);
void setPartidosJugados(int);
int getTemporada();
int getGoles();
int getIdJugador();
int getAsistencias();
int getPartidosJugados();
bool getEstado();
void cargar();
void mostrar();
};

#endif // CLSESTADISTICA_H
