#ifndef CLSCLUB_H
#define CLSCLUB_H


class Club
{
private:
    char nombre[30];
    int idClub;
    int balance;
    int cantJugadores;
    int anioCreacion;
public:
    void setNombreClub(const char *n);


};

#endif // CLSCLUB_H
