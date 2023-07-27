#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class perro
{
    string nombre;
    int edad;
    string raza;

public:
    perro()
    {
        nombre = "";
        edad = 0;
        raza = "";
    };
    perro(string nombre, int edad, string raza)
    {
        this->nombre = nombre;
        this->edad = edad;
        this->raza = raza;
    };
    ~perro()
    {
        std::cout << "Destructor" << endl;
    };
    void mostrar()
    {
        std::cout << "Nombre: " << nombre << endl;
        std::cout << "Edad: " << edad << endl;
        std::cout << "Raza: " << raza << endl;
    };
    void setNombre(string nombre)
    {
        this->nombre = nombre;
    };
    void setEdad(int edad)
    {
        this->edad = edad;
    };
    void setRaza(string raza)
    {
        this->raza = raza;
    };
    string getNombre()
    {
        return nombre;
    };
    int getEdad()
    {
        return edad;
    };
    string getRaza()
    {
        return raza;
    };
};

int main()
{
    cout << "primera parte" << endl;
    // creo 5 punteros a perro
    perro *p1 = new perro("firulais", 5, "labrador");
    perro *p2 = new perro("boby", 3, "pastor aleman");
    perro *p3 = new perro("scooby", 10, "gran danes");
    perro *p4 = new perro("snoopy", 7, "beagle");
    perro *p5 = new perro("pluto", 2, "fox terrier");
    // creo 5 pares de string y puntero a perro
    pair<string, perro *> par1("A1A1A", p1);
    pair<string, perro *> par2("B2B2B", p2);
    pair<string, perro *> par3("C3C3C", p3);
    pair<string, perro *> par4("D4D4D", p4);
    pair<string, perro *> par5("E5E5E", p5);
    // creo un archivo txt y guardo los pares
    ofstream archivo("perros.txt");
    archivo << par1.first << " " << par1.second->getNombre() << " " << par1.second->getEdad() << " " << par1.second->getRaza() << endl;
    archivo << par2.first << " " << par2.second->getNombre() << " " << par2.second->getEdad() << " " << par2.second->getRaza() << endl;
    archivo << par3.first << " " << par3.second->getNombre() << " " << par3.second->getEdad() << " " << par3.second->getRaza() << endl;
    archivo << par4.first << " " << par4.second->getNombre() << " " << par4.second->getEdad() << " " << par4.second->getRaza() << endl;
    archivo << par5.first << " " << par5.second->getNombre() << " " << par5.second->getEdad() << " " << par5.second->getRaza() << endl;
    archivo.close();
    // creo un archivo txt de respaldo copiando el original
    ifstream archivo2("perros.txt");
    ofstream archivo3("perrosCOPY.txt");
    string linea;
    while (getline(archivo2, linea))
    {
        archivo3 << linea << endl;
    }
    archivo2.close();
    archivo3.close();
    // modifico ahora al perro p1
    p1->setNombre("firulais2");
    p1->setEdad(6);
    p1->setRaza("labrador2");
    // imprimo los datos del perro p1
    p1->mostrar();
    // ahora reescribo el archivo original con los datos modificados
    ifstream archivo4("perrosCOPY.txt");
    ofstream archivo5("perros.txt");
    while (getline(archivo4, linea))
    {
        if (linea.find(par1.first) != string::npos)
        {
            archivo5 << par1.first << " " << p1->getNombre() << " " << p1->getEdad() << " " << p1->getRaza() << endl;
        }
        else
        {
            archivo5 << linea << endl;
        }
    }

    return 0;
}

/*
(001-objeto) -> 16bytes
(002-objeto) -> 16bytes
(003-objeto)

(001-objeto)


string s = "hola";

const char *c = s.c_str();

*/
