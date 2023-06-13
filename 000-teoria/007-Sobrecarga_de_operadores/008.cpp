#include <iostream>

using namespace std;

class Camion;

class Auto
{
    int pasajeros, velocidad;

public:
    Auto(int cant, int vel) : pasajeros(cant), velocidad(vel) {}
    int operator-(const Camion &c) const;
};

class Camion
{
    int peso, velocidad;

public:
    Camion(int p, int v) : peso(p), velocidad(v) {}
    friend int Auto::operator-(const Camion &c) const;
};

int Auto::operator-(const Camion &c) const
{
    return velocidad - c.velocidad;
};

int main()
{
    Auto a(5, 230);
    Camion c(1500, 180);

    cout << a - c << endl; // 50
    return 0;
};