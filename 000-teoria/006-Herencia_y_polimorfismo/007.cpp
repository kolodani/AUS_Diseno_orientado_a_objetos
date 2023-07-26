#include <iostream>

using namespace std;

class Persona
{
    int edad;

public:
    virtual void hablar();
    void caminar();
};

void Persona::hablar()
{
    cout << "bla bla bla" << endl;
};

void Persona::caminar()
{
    cout << "caminando" << endl;
};

class Estudiante : public Persona
{
    int legajo;

public:
    virtual void hablar();
    void estudiar();
};

void Estudiante::hablar()
{
    cout << "Dando una leccion" << endl;
};

void Estudiante::estudiar()
{
    cout << "estudiando" << endl;
};

class Docente : public Persona
{
    int cuil;

public:
    virtual void hablar();
    void catedra();
};

void Docente::hablar()
{
    cout << "Dando una clase" << endl;
};

void Docente::catedra()
{
    cout << "catedra de la materia" << endl;
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