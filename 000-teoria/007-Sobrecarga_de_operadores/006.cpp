#include <iostream>

using namespace std;

class Punto
{
    int x, y;

public:
    Punto(int xx, int yy) : x{xx}, y{yy} {};
    friend Punto operator+(const Punto &a, const Punto &b);
    int get_x()
    {
        return x;
    };
    int get_y()
    {
        return y;
    };
};

Punto operator+(const Punto &a, const Punto & b)
{
    return Punto(a.x + b.x, a.y + b.y);
};

int main()
{
    Punto a(5, 3);
    Punto b(2, 2);

    Punto c = a + b; // (7,5)
    cout << c.get_x() << " - " << c.get_y() << endl;

    return 0;
};