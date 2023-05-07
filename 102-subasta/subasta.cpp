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

class oferta
{
    private:
        float monto;
        persona* ofertante;
    public:
        oferta(float monto, persona ofertante)
        {
            this->monto = monto;
            this->ofertante = &ofertante;
        };
        float getMonto()
        {
            return monto;
        };
        persona getOfertante()
        {
            return *ofertante;
        }
};

int main()
{
    // persona creada de ejemplo
    persona p1("Juan");
    cout << "El nombre de la persona creada es: " << p1.getNombre() << endl;
    // oferta creada de ejemplo
    oferta o1(1234.56, p1);
    cout << "El monto de la oferta creada es: " << o1.getMonto() << endl;
    cout << "El nombre de la persona que hizo la oferta es: " << o1.getOfertante().getNombre() << endl;
}