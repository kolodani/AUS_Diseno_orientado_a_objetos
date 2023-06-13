#include <iostream>
#include <fstream> // flujo de archivo
#include <iomanip> // para setw y setprecision
#include <string>

using namespace std;

void imprimirLinea(int, const string, double); // prototipo

int main()
{
    // el constructor de ifstream abre el archivo
    ifstream archivoClientesEntrada("clientes.dat", ios::in);

    // sale del programa si ifstream no pudo abrir el archivo
    if (!archivoClientesEntrada)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        return 1;
    } // fin de if

    int cuenta;
    char nombre[30];
    double saldo;

    cout << left << setw(10) << "Cuenta" << setw(13)
        << "Nombre"
        << "Saldo" << endl
        << fixed << showpoint;

    // muestra cada registro en el archivo
    while (archivoClientesEntrada >> cuenta >> nombre >> saldo)
    {
        imprimirLinea(cuenta, nombre, saldo);
    }

    return 0; // el destructor de ifstream cierra el archivo
};            // fin de main

// muestra un solo registro del archivo
void imprimirLinea(int cuenta, const string nombre, double saldo)
{
    cout << left << setw(10) << cuenta << setw(13) << nombre
        << setw(7) << setprecision(2) << right << saldo << endl;
}  // fin de la funcion imprimirLinea