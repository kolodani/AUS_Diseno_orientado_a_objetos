#include <iostream>

using namespace std;

class prueba
{
    int a;
};

int main()
{
    prueba X;
    //X.a = 10; // Error: a es privado
    return 0;
}