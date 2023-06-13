#include <iostream>

using namespace std;

class Persona
{
    int edad;

public:
    virtual void hablar();
    void caminar();
};

class Estudiante : public Persona
{
    int legajo;

public:
    virtual void hablar();
    void estudiar();
};

class Docente : public Persona
{
    int cuil;

public:
    virtual void hablar();
    void catedra();
};

int main()
{
    Persona *p = new Docente();

    cout << typeid(p).name() << endl;                  // Persona
    cout << typeid(*p).name() << endl;                 // Docente
    cout << (typeid(*p) == typeid(Docente *)) << endl; // Falso
    cout << (typeid(*p) == typeid(Persona *)) << endl; // Verdadero

    if (typeid(*p) == typeid(Docente))
    {
        Docente *d = (Docente *)p;
        d->catedra();
    };

    return 0;
};