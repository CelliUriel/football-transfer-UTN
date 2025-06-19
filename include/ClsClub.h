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
    bool estado;

public:
    void setNombreClub(const char *n);
    void setIdClub(int i);
    void setBalance(int b);
    void setCantJugadores(int c);
    void setAnioCreacion(int a);
    void setEstado(bool );
    const char *getNombreClub();
    int getIdClub();
    int getBalance();
    int getCantJugadores();
    int getAnioCreacion();
    bool getEstado();
    void cargar();
    void ModificarAltaClub(int idActual);
    void mostrar();
};

#endif // CLSCLUB_H
