#include <iostream>

using namespace std;

class Punto
{
    int x, y;

public:
    Punto(int xx, int yy) : x{xx}, y{yy} {};
    Punto operator+(const Punto &b) const;
    int get_x()
    {
        return x;
    };
    int get_y()
    {
        return y;
    };
};

Punto Punto::operator+(const Punto &b) const
{
    return Punto(x + b.x, y + b.y);
};

int main()
{
    Punto a(5, 3);
    Punto b(2, 2);

    Punto c = a + b; // (7,5)
    cout << c.get_x() << " - " << c.get_y() << endl;

    return 0;
};