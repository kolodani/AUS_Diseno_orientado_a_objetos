#include <iostream>
#include <fstream> // flujo de archivo
#include <cstdlib> // funciones de exit

using namespace std;

int main()
{
    // el constructor de ofstream abre el archivo
    ofstream archivoClienteSalida("clientes.dat", ios::out );
    // sale del programa si no puede crear el archivo
    if (!archivoClienteSalida) // operador ! sobrecargado
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    } // fin de if

    cout << "Escriba la cuenta, nombre y saldo." << endl
         << "Escriba fin de archivo para terminar la entrada.\n?";

    int cuenta;
    char nombre[30];
    double saldo;

    // lle la cuenta, nombre y saldo de cin, y despues los coloca en el archivo
    while (cin >> cuenta >> nombre >> saldo)
    {
        archivoClienteSalida << cuenta << ' ' << nombre << ' ' << saldo << endl;
        cout << "?";
    } // fin de while

    return 0; // el destructor de ofstream cierra el archivo
};            // fin de main
