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
    Persona** p = new Persona*[2];
    p[0] = new Estudiante();
    p[1] = new Docente();\

    for (int i = 0; i < 2; i++)
    {
        p[i]->hablar();
    };

    return 0;
};