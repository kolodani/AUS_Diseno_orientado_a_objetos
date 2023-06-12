#include <iostream>
#include <string.h>

using namespace std;

class Estudiante
{
private:
    char* nombre;
    int edad;
    float promedio;
public:
    // constructor
    Estudiante(const char* nombre, int edad, float promedio)
    {
        this->nombre = new char[strlen(nombre) + 1];
        strcpy(this->nombre, nombre);
        this->edad = edad;
        this->promedio = promedio;
    };
    void print()
    {
        cout << nombre << " " << edad << " " << promedio << endl;
    };
    // destructor
    ~Estudiante()
    {
        delete(nombre);
    };
};

int main()
{
    Estudiante *P;
    Estudiante J("Daniel", 33, 8.8);
    J.print();

    P = new Estudiante("Macarena", 29, 7.5);
    P->print();
    return 0;
};