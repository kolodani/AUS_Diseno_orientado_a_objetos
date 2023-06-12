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

int main()
{
    Punto p1;
    Punto *pPto;
    pPto = new Punto(2, 4);
    delete pPto;
    return 0;
}
