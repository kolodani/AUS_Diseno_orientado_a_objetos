#include <iostream>

using namespace std;

class Persona
{
protected:
    int edad;
public:
    Persona()
    {
        edad = 0;
    }
    void habla();
    void init();
};

class Alumno
{
    int legajo;
public:
    Alumno()
    {
        legajo = 0;
    };
    void init();  // sobrecargado
    void estudia();
};