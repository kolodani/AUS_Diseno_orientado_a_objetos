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
    void hablar();
    void estudiar();
};

int main()
{
    Estudiante e;
    e.hablar();   // desde Estudiante
    e.estudiar(); // desde Estudiante
    e.caminar();  // desde Persona

    Persona *p = new Estudiante();
    p->hablar();  // desde Estudiante
    p->caminar(); // desde Persona
    // p->estudiar();     // ERROR
};