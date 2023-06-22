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
       // cout << "Destructor" << endl;
    };
    void mostrar()
    {
      //  cout << "Nombre: " << nombre << endl;
      //  cout << "Edad: " << edad << endl;
      //  cout << "Raza: " << raza << endl;
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

int main() {
    // creo un archivo para guardar mis objetos perro
    perro *p = new perro("Firulais", 5, "Chihuahua");
    perro *p1 = new perro("Jorge", 4, "Doberman");
    // creo un archivo
    ofstream archivo("perros.dat", ios::binary);
    // creo un par con un int y un perro
    pair<int, int> par1(323, 123);
    pair<int, int> par2(666, 456);
    pair<int, int> *parpivot; // epa
    // guardo el par en el archivo
    archivo.write(reinterpret_cast<const char *>(&par1), sizeof(pair<int, int>));
    archivo.write(reinterpret_cast<const char *>(&par2), sizeof(pair<int, int>));
    // cierro el archivo
    archivo.close();
    // leo el archivo
    ifstream archivo1("perros.dat", ios::binary);
    // imprimo el par

    archivo1.read(reinterpret_cast<char *>(parpivot), sizeof(pair<int, int>));
    //std :: cout << parpivot->first << endl;
    //archivo1.read(reinterpret_cast<char *>(parpivot), sizeof(parpivot));
    //cout << parpivot->first << endl;

    // //escribo el objeto en el archivo
    // archivo.write(reinterpret_cast<const char *>(p), sizeof(perro));
    // archivo.write(reinterpret_cast<const char *>(p1), sizeof(perro));
    // // cierro el archivo
    // archivo.close();
    // // leo el archivo
    // ifstream archivo2("perros.dat", ios::binary);
    // // imprimo el objeto
    // perro *p2 = new perro("", 0, "");
    // archivo2.read(reinterpret_cast<char *>(p2), sizeof(perro));
    // p2->mostrar();
    // // reinicio el puntero del archivo
    // archivo2.seekg(0);
    // perro *p3 = new perro("", 0, "");
    // archivo2.read(reinterpret_cast<char *>(p3), sizeof(perro));
    // p3->mostrar();
    // p2->mostrar();
    // // correr el puntero del archivo 1 objeto
    // archivo2.seekg(sizeof(perro));
    // perro *p4 = new perro("", 0, "");
    // archivo2.read(reinterpret_cast<char *>(p4), sizeof(perro));
    // p4->mostrar();
    // archivo2.close();
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