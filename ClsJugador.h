#ifndef CLSJUGADOR_H
#define CLSJUGADOR_H


class Jugador
{
private:
    ///atributos
    char nombre[30];
    int edad;
    char posicion[20];
    float valorMercado;
    char clubActual[30];
    int id;

public:
///SETTERS AND GETTERS
    void setNombre(const char *n);
    void setEdad(int e);
    void setPosicion(const char *p);
    void setValorMercado(float v);
    void setClubActual(const char *c);
    void setId(int);


    const char *getNombre();
    int getEdad();
   const char* getPosicion();
    float getValorMercado();
    const char *getClubActual();
    int getId();
};
#endif // CLSJUGADOR_H
