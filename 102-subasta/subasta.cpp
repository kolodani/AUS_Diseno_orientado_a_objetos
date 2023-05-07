#include <iostream>
#include <vector>

using namespace std;

// clase persona
class Persona
{
private:
    string nombre;
public:
    Persona(string nombre);
    string getNombre();
};

// metodos de la clase persona
Persona::Persona(string nombre)
{
    this->nombre = nombre;
};

string Persona::getNombre()
{
    return nombre;
};

// clase oferta
class Oferta
{
private:
    float monto;
    Persona* ofertante;
public:
    Oferta(float monto, Persona *ofertante);
    float getMonto();
    Persona *getOfertante();
};

// metodos de la clase oferta
Oferta::Oferta(float monto, Persona *ofertante)
{
    this->monto = monto;
    this->ofertante = ofertante;
};

float Oferta::getMonto()
{
    return monto;
};

Persona *Oferta::getOfertante()
{
    return ofertante;
};

// clase lote
class Lote
{
private:
    string nombre;
    int numero;
    Oferta* ofertaMayor = nullptr;
public:
    Lote(string nombre, int numero);
    string getNombre();
    int getNumero();
    void setOfertaMayor(Oferta *nuevaOferta);
    Oferta *getOfertaMayor();
};

// metodos de la clase lote
Lote::Lote(string nombre, int numero)
{
    this->nombre = nombre;
    this->numero = numero;
};

string Lote::getNombre()
{
    return nombre;
};

int Lote::getNumero()
{
    return numero;
};

void Lote::setOfertaMayor(Oferta *nuevaOferta)
{
    if(ofertaMayor == nullptr)
    {
        this->ofertaMayor = nuevaOferta;
        return;
    };
    if(ofertaMayor->getMonto() < nuevaOferta->getMonto())
    {
        this->ofertaMayor = nuevaOferta;
    };
};

Oferta *Lote::getOfertaMayor()
{
    return ofertaMayor;
};

// clase subasta
class Subasta
{
private:
    vector<Lote *> lotes;
public:
    void agregarLote(Lote *nuevoLote);
    void agregarOferta(Oferta *nuevaOferta, int loteDeseado);
    void mostrarLotes();
    Lote *buscarLote(int numeroLote);
};

// metodos de la clase subasta
void Subasta::agregarLote(Lote *nuevoLote)
{
    lotes.push_back(nuevoLote);
};

void Subasta::agregarOferta(Oferta *nuevaOferta, int loteDeseado)
{
    for (int i = 0; i < lotes.size(); i++)
    {
        if (lotes[i]->getNumero() == loteDeseado)
        {
            if(lotes[i]->getOfertaMayor() == nullptr)
            {
                lotes[i]->setOfertaMayor(new Oferta(nuevaOferta->getMonto(), nuevaOferta->getOfertante()));
            } else if (lotes[i]->getOfertaMayor()->getMonto() < nuevaOferta->getMonto())
            {
                lotes[i]->setOfertaMayor(new Oferta(nuevaOferta->getMonto(), nuevaOferta->getOfertante()));
            }
        }
    }
};

void Subasta::mostrarLotes()
{
    for (int i = 0; i < lotes.size(); i++)
    {
        cout << "Lote " << lotes[i]->getNumero() << ": " << lotes[i]->getNombre() << endl;
        if (lotes[i]->getOfertaMayor() == nullptr)
        {
            cout << "No hay ofertas" << endl;
        }
        else
        {
            cout << "Oferta mayor: " << lotes[i]->getOfertaMayor()->getMonto() << endl;
            cout << "Ofertante: " << lotes[i]->getOfertaMayor()->getOfertante()->getNombre() << endl;
        }
    }
};

Lote *Subasta::buscarLote(int numeroLote)
{
    for (int i = 0; i < lotes.size(); i++)
    {
        if (lotes[i]->getNumero() == numeroLote)
        {
            cout << "lote encontrado" << endl;
            return lotes[i];
        }
    }
    cout << "no existe un lote con ese numero" << endl;
    return nullptr;
}

// main
int main()
{
    // personas creadas de ejemplo
    Persona p1("Juan");
    Persona p2("Daniel");
    Persona p3("Pedro");
    cout << "El nombre de la persona creada es: " << p1.getNombre() << endl;
    cout << "El nombre de la persona creada es: " << p2.getNombre() << endl;
    // ofertas creadas de ejemplo
    Oferta o1(1234.56, &p1);
    cout << "El monto de la oferta creada es: " << o1.getMonto() << endl;
    cout << "El nombre de la persona que hizo la oferta es: " << o1.getOfertante()->getNombre() << endl;
    Oferta o2(2000.20, &p2);
    Oferta o3(3000.30, &p3);
    // lotes creados de ejemplo
    Lote l1("Pintura", 8008);
    cout << "El nombre del lote creado es: " << l1.getNombre() << endl;
    cout << "El numero del lote creado es: " << l1.getNumero() << endl;
    // seteo de oferta mayor
    l1.setOfertaMayor(&o1);
    cout << "El monto de la oferta mayor es: " << l1.getOfertaMayor()->getMonto() << endl;
    cout << "El nombre de la persona que hizo la oferta mayor es: " << l1.getOfertaMayor()->getOfertante()->getNombre() << endl;
    l1.setOfertaMayor(&o2);
    cout << "El monto de la oferta mayor es: " << l1.getOfertaMayor()->getMonto() << endl;
    cout << "El nombre de la persona que hizo la oferta mayor es: " << l1.getOfertaMayor()->getOfertante()->getNombre() << endl;
    // subasta creada de ejemplo
    Subasta s1;
    s1.agregarLote(&l1);
    s1.mostrarLotes();
    s1.agregarOferta(&o2, 8008);
    s1.mostrarLotes();
    s1.agregarOferta(&o3, 8008);
    s1.mostrarLotes();
    return 0;
}