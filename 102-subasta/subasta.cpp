#include <iostream>

using namespace std;

class persona
{
    private:
        string nombre;
    public:
        persona(string nombre)
        {
            this->nombre = nombre;
        };
        string getNombre()
        {
            return nombre;
        };
};

int main()
{
    // persona creada de ejemplo
    persona p1("Juan");
    cout << "El nombre de la persona creada es: " << p1.getNombre() << endl;
}