#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int d = 1, int m = 1, int a = 2000);
    void setDia(int);
    void setMes(int);
    void setAnio(int);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    void Cargar();
    void Mostrar() const;
};

#endif // FECHA_H
