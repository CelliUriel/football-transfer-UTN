#ifndef CLSCLUB_H
#define CLSCLUB_H


class Club
{
private:
    char nombreClub[30];
    int idClub;
    int balance;
    int cantJugadores;
    int anioCreacion;

public:
    void setNombreClub(const char *n);
    void setIdClub(int i);
    void setBalance(int b);
    void setCantJugadores(int c);
    void setAnioCreacion(int a);

    const char *getNombreClub();
    int getIdClub();
    int getBalance();
    int getCantJugadores();
    int getAnioCreacion();

    void cargar();
    void mostrar();
};

#endif // CLSCLUB_H
