#include <iostream>
#include <fstream>

using namespace std;

class perro
{
    string nombre;
    int edad;
    string raza;

public:
    perro(string nombre, int edad, string raza)
    {
        this->nombre = nombre;
        this->edad = edad;
        this->raza = raza;
    };
    ~perro()
    {
        cout << "Destructor" << endl;
    };
    void mostrar()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Raza: " << raza << endl;
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
    // creo un archivo para guardar mis objetos perro
    perro *p1 = new perro("Firulais", 5, "Chihuahua");
    perro *p2 = new perro("Jorge", 4, "Doberman");
    perro *p3 = new perro("Marcos", 3, "Beagle");
    perro *p4 = new perro("Morena", 2, "Rotweiler");
    // creo un archivo
    ofstream archivo("perros.dat", ios::binary);
    // creo un par con un int y un perro
    pair<int, perro> par1(1, *p1);
    pair<int, perro> par2(2, *p2);
    pair<int, perro> par3(3, *p3);
    pair<int, perro> par4(4, *p4);
    // guardo el par en el archivo
    archivo.write(reinterpret_cast<const char *>(&par1), sizeof(pair<int, perro>));
    archivo.write(reinterpret_cast<const char *>(&par2), sizeof(pair<int, perro>));
    archivo.write(reinterpret_cast<const char *>(&par3), sizeof(pair<int, perro>));
    archivo.write(reinterpret_cast<const char *>(&par4), sizeof(pair<int, perro>));
    // cierro el archivo
    archivo.close();
    // leo el archivo
    ifstream archivo1("perros.dat", ios::binary);
    // creo un par para leer el archivo
    pair<int, perro> *parpivot = new pair<int, perro>(0, *p1);
    // imprimo el objeto
    archivo1.read(reinterpret_cast<char *>(parpivot), sizeof(pair<int, perro>));
    cout << parpivot->first << endl;
    cout << parpivot->second.getNombre() << endl;
    cout << parpivot->second.getEdad() << endl;
    cout << parpivot->second.getRaza() << endl;
    // manipulo otro objeto
    archivo1.read(reinterpret_cast<char *>(parpivot), sizeof(pair<int, perro>));
    cout << parpivot->first << endl;
    cout << parpivot->second.getNombre() << endl;
    cout << parpivot->second.getEdad() << endl;
    cout << parpivot->second.getRaza() << endl;
    // salteo un objeto
    archivo1.seekg(sizeof(pair<int, perro>), ios::cur);
    // manipulo otro objeto
    archivo1.read(reinterpret_cast<char *>(parpivot), sizeof(pair<int, perro>));
    cout << parpivot->first << endl;
    cout << parpivot->second.getNombre() << endl;
    cout << parpivot->second.getEdad() << endl;
    cout << parpivot->second.getRaza() << endl;
    // cierra el archivo
    archivo1.close();
    
    cout << "----------------------------------------" << endl;
    
    // ahora vamos a hacer otra secuencia para hacer pares distintos
    // creo un archivo
    ofstream archivo2("perros2.dat", ios::binary);
    // creo un par con un string y un perro
    pair<string, perro> par5("1", *p1);
    pair<string, perro> par6("2", *p2);
    pair<string, perro> par7("3", *p3);
    pair<string, perro> par8("4", *p4);
    // guardo el par en el archivo
    archivo2.write(reinterpret_cast<const char *>(&par5), sizeof(pair<string, perro>));
    archivo2.write(reinterpret_cast<const char *>(&par6), sizeof(pair<string, perro>));
    archivo2.write(reinterpret_cast<const char *>(&par7), sizeof(pair<string, perro>));
    archivo2.write(reinterpret_cast<const char *>(&par8), sizeof(pair<string, perro>));
    // cierro el archivo
    archivo2.close();
    // leo el archivo
    ifstream archivo3("perros2.dat", ios::binary);
    // creo un par para leer el archivo
    pair<string, perro> *parpivot2 = new pair<string, perro>("0", *p1);
    // imprimo el objeto
    archivo3.read(reinterpret_cast<char *>(parpivot2), sizeof(pair<string, perro>));
    cout << parpivot2->first << endl;
    cout << parpivot2->second.getNombre() << endl;
    cout << parpivot2->second.getEdad() << endl;
    cout << parpivot2->second.getRaza() << endl;
    // manipulo otro objeto
    archivo3.read(reinterpret_cast<char *>(parpivot2), sizeof(pair<string, perro>));
    cout << parpivot2->first << endl;
    cout << parpivot2->second.getNombre() << endl;
    cout << parpivot2->second.getEdad() << endl;
    cout << parpivot2->second.getRaza() << endl;
    // salteo un objeto
    archivo3.seekg(sizeof(pair<string, perro>), ios::cur);
    // manipulo otro objeto
    archivo3.read(reinterpret_cast<char *>(parpivot2), sizeof(pair<string, perro>));
    cout << parpivot2->first << endl;
    cout << parpivot2->second.getNombre() << endl;
    cout << parpivot2->second.getEdad() << endl;
    cout << parpivot2->second.getRaza() << endl;
    // cierra el archivo
    archivo3.close();

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