#include <iostream>

using namespace std;

class A
{
    int x;
public:
    int y;
    void setX(int i)
    {
        x = i;
    };
};

class B : public A
{
    int y;
public:
    void f()
    {
        y = 5;  //atributo local
        A::y = 4;  //atributo de la clase base
        // x = 9;  // ERROR!!! x es privado
        setX(9);  // OK: setX es publico
    };
};