#include <iostream>

using namespace std;

class Objeto
{
    int x;
    int y;
public:
    Objeto()
    {
        x = 0;
        y = 0;
        cout << "Objeto inicializado" << endl;
    };
    Objeto(int, int);
    ~Objeto();
};

Objeto::Objeto(int x, int y)
{
    this->x = x;
    this->y = y;
};

int main()
{
    Objeto A; // se llama al constructor por default
    Objeto B(1, 5); // se llama al conductor especifico

    Objeto* C; // no invoca a ningun constructor
    C = new Objeto (); // se instancia el objeto

    delete(C); // se invoca al destructor
    /* se llama automaticamente los destructores de A y B */
    return 0;
};