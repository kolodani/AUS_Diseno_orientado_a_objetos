#include <iostream>

using namespace std;

class Persona
{
    int edad;

public:
    void hablar();
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
    void hablar();
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

int main()
{
    Estudiante e;
    e.hablar();   // desde Estudiante
    e.estudiar(); // desde Estudiante
    e.caminar();  // desde Persona

    Persona *p = new Estudiante();
    p->hablar();  // desde Persona
    p->caminar(); // desde Persona
    // p->estudiar();     // ERROR
};