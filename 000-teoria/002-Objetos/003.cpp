#include <iostream>

using namespace std;

class Costo
{
private:
    int valor;
public:
    void setValor(int);
    Costo &incremento();
};

Costo& Costo::incremento()
{
    valor++;
    return *this;
}

void Costo::setValor(int valor)
{
    this->valor = valor;
}

int main()
{
    Costo c;
    c.setValor(20);
    c.incremento();
}