#ifndef CLSESTADISTICA_H
#define CLSESTADISTICA_H


class Estadisticas{
private:
int idJugador;
int temporada;
int goles;
int asistencias;
int partidosJugados;
public:

void setTemporada(int);
void setGoles(int);
void setIdJugador(int);

void setAsistencias(int);
void setPartidosJugados(int);
int getTemporada();
int getGoles();
int getIdJugador();
int getAsistencias();
int getPartidosJugados();
void cargar();
void mostrar();
};

#endif // CLSESTADISTICA_H
