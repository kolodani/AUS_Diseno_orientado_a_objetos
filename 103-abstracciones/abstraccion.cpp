#include <iostream>

using namespace std;

// clase abstracta animal
class Animal
{
public:
    string nombre;
    string especie;
    string raza;
    string habitat;
    virtual string getNombre() = 0;
    virtual string getEspecie() = 0;
    virtual string getRaza() = 0;
    virtual string getHabitat() = 0;
    virtual void setNombre(string nombre) = 0;
    virtual void setEspecie(string especie) = 0;
    virtual void setRaza(string raza) = 0;
    virtual void setHabitat(string habitat) = 0;
};

// clase caballo, hereda de animal
class Caballo : public Animal
{
private:
    string color;
    int patas;
    int edad;
public:
    Caballo(string nombre, string especie, string raza, string habitat, string color, int patas, int edad);
    string getNombre();
    string getEspecie();
    string getRaza();
    string getHabitat();
    string getColor();
    int getPatas();
    int getEdad();
    void setNombre(string nombre);
    void setEspecie(string especie);
    void setRaza(string raza);
    void setHabitat(string habitat);
    void setColor(string color);
    void setPatas(int patas);
    void setEdad(int edad);
};

// metodos de la clase caballo

Caballo::Caballo(string nombre, string especie, string raza, string habitat, string color, int patas, int edad)
{
    this->nombre = nombre;
    this->especie = especie;
    this->raza = raza;
    this->habitat = habitat;
    this->color = color;
    this->patas = patas;
    this->edad = edad;
};

string Caballo::getNombre()
{
    return nombre;
};

string Caballo::getEspecie()
{
    return especie;
};

string Caballo::getRaza()
{
    return raza;
};

string Caballo::getHabitat()
{
    return habitat;
};

string Caballo::getColor()
{
    return color;
};

int Caballo::getPatas()
{
    return patas;
};

int Caballo::getEdad()
{
    return edad;
};

void Caballo::setNombre(string nombre)
{
    this->nombre = nombre;
};

void Caballo::setEspecie(string especie)
{
    this->especie = especie;
};

void Caballo::setRaza(string raza)
{
    this->raza = raza;
};

void Caballo::setHabitat(string habitat)
{
    this->habitat = habitat;
};

void Caballo::setColor(string color)
{
    this->color = color;
};

void Caballo::setPatas(int patas)
{
    this->patas = patas;
};

void Caballo::setEdad(int edad)
{
    this->edad = edad;
};

int main()
{
    // creamos un objeto de la clase caballo
    Caballo caballo("Brunello", "Equino", "Andaluz", "Pradera", "Blanco", 4, 5);
    return 0;
}