#include <iostream>

using namespace std;

class Punto
{
    // private (default)
    int m_x; // coordenada x
    int m_y; // coordenada y
public:
    Punto()
    {
        m_x = 0;
        m_y = 0;
        cout << "Point object initialized" << endl;
    };
    Punto(int, int); // otro constructor
    // resto de las funciones
};

Punto::Punto(int x, int y)
{
    m_x = x;
    m_y = y;
};

class Poligono
{
    int NoPuntos;
    Punto* aPuntos;
public:
    Poligono() : NoPuntos(0), aPuntos(NULL) {};
    Poligono(int);
// Destructor:
    ~Poligono();
};

/*
    Poligono() : NoPuntos(0), aPuntos(NULL) {};
    es equivalente a
    Poligono() {
        NoPuntos = 0;
        aPuntos = NULL;
    };
*/

Poligono::~Poligono()
{
    if (aPuntos != NULL)
        delete[] aPuntos;
};

Poligono::Poligono(int n)
{
    NoPuntos = n;
    aPuntos = new Punto[n];
};

int main()
{
    Poligono p1;
    Poligono p2(5);
    return 0;
}