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
    archivo4.close();
    archivo5.close();

    cout << "segunda parte" << endl;
    // ahora abro el archivo original y guardo los datos del 3 perro en un objeto perro
    ifstream archivo6("perros.txt");
    string codigo;
    string nombre;
    int edad;
    string raza;
    while (archivo6 >> codigo >> nombre >> edad >> raza)
    {
        if (codigo == par3.first)
        {
            p3->setNombre(nombre);
            p3->setEdad(edad);
            p3->setRaza(raza);
        }
    }
    archivo6.close();
    // imprimo los datos del perro p3
    p3->mostrar();

    // voy a imprimir el tamaño de cada objeto perro
    cout << "Tamaño de p1: " << sizeof(*p1) << endl;
    cout << "Tamaño de p2: " << sizeof(*p2) << endl;
    cout << "Tamaño de p3: " << sizeof(*p3) << endl;
    cout << "Tamaño de p4: " << sizeof(*p4) << endl;
    cout << "Tamaño de p5: " << sizeof(*p5) << endl;
    // voy a imprimir el tamaño de cada par
    cout << "Tamaño de par1: " << sizeof(par1) << endl;
    cout << "Tamaño de par2: " << sizeof(par2) << endl;
    cout << "Tamaño de par3: " << sizeof(par3) << endl;
    cout << "Tamaño de par4: " << sizeof(par4) << endl;
    cout << "Tamaño de par5: " << sizeof(par5) << endl;

    // voy a guardar los pares en un archivo binario .dat
    ofstream archivo7("perros.dat", ios::binary);
    archivo7.write((char *)&par1, sizeof(par1));
    archivo7.write((char *)&par2, sizeof(par2));
    archivo7.write((char *)&par3, sizeof(par3));
    archivo7.write((char *)&par4, sizeof(par4));
    archivo7.write((char *)&par5, sizeof(par5));
    archivo7.close();

    // voy a leer los pares del archivo binario .dat hasta el fin del archivo
    ifstream archivo8("perros.dat", ios::binary);
    pair<string, perro *> par;
    while (archivo8.read((char *)&par, sizeof(par)))
    {
        cout << par.first << " " << par.second->getNombre() << " " << par.second->getEdad() << " " << par.second->getRaza() << endl;
    }
    archivo8.close();

    // voy a crear una copia del archivo binario .dat
    ifstream archivo9("perros.dat", ios::binary);
    ofstream archivo10("perrosCOPY.dat", ios::binary);
    while (archivo9.read((char *)&par, sizeof(par)))
    {
        archivo10.write((char *)&par, sizeof(par));
    }
    archivo9.close();
    archivo10.close();

    // ahora voy a modificar el perro p3
    p3->setNombre("firulais3");
    p3->setEdad(7);
    p3->setRaza("labrador3");
    // ahora voy a reescribir el archivo binario .dat sin el perro p3 usando el archivo de respaldo
    ifstream archivo11("perrosCOPY.dat", ios::binary);
    ofstream archivo12("perros.dat", ios::binary);
    while (archivo11.read((char *)&par, sizeof(par)))
    {
        if (par.first != par3.first)
        {
            archivo12.write((char *)&par, sizeof(par));
        }
    }
    // y ahora voy a agregar el perro p3 modificado al final del archivo binario .dat
    archivo12.write((char *)&par3, sizeof(par3));
    archivo11.close();
    archivo12.close();

    // voy a leer los pares del archivo binario .dat y voy a imprimir todos para ver si se modifico el perro p3
    ifstream archivo13("perros.dat", ios::binary);
    while (archivo13.read((char *)&par, sizeof(par)))
    {
        cout << par.first << " " << par.second->getNombre() << " " << par.second->getEdad() << " " << par.second->getRaza() << endl;
    }
    archivo13.close();

    // voy a modificar el perro p2
    p2->setNombre("firulais4");
    p2->setEdad(8);
    p2->setRaza("labrador4");
    // voy a buscar el par que tiene al perro p2 por su codigo y aviso si lo encontre o no
    ifstream archivo14("perros.dat", ios::binary);
    bool encontrado = false;
    while (archivo14.read((char *)&par, sizeof(par)))
    {
        if (par.first == par2.first)
        {
            encontrado = true;
            cout << "Encontre el perro p2" << endl;
        }
    }
    archivo14.close();
    // si lo encontre voy a reescribir el archivo binario .dat sin el perro p2 usando el archivo de respaldo
    if (encontrado)
    {
        ifstream archivo15("perrosCOPY.dat", ios::binary);
        ofstream archivo16("perros.dat", ios::binary);
        while (archivo15.read((char *)&par, sizeof(par)))
        {
            if (par.first != par2.first)
            {
                archivo16.write((char *)&par, sizeof(par));
            }
        }
        archivo15.close();
        archivo16.close();
    }
    // y ahora voy a agregar el perro p2 modificado al final del archivo binario .dat
    ofstream archivo17("perros.dat", ios::binary | ios::app);
    archivo17.write((char *)&par2, sizeof(par2));
    archivo17.close();

    // ultima prueba
    // 

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
