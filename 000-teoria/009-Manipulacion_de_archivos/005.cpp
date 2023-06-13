#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class DatosCliente
{
    int numeroCuenta;
    char apellidoPaterno[15];
    char primerNombre[10];
    double saldo;

public:
    // constructor predeterminado de DatosClientes
    DatosCliente(int = 0, string = "", string = "", double = 0.0);

    // funciones de acceso para numero cuenta
    void establecerNumeroCuenta(int);
    int obtenerNumeroCuenta() const;

    // funciones de acceso para apellidoPaterno
    void establecerApellidoPaterno(string);
    string obtenerApellidoPaterno() const;

    // funciones de acceso para primerNombre
    void establecerPrimerNombre(string);
    string obtenerPrimerNombre() const;

    // funciones de acceso para saldo
    void establecerSaldo(double);
    double obtenerSaldo() const;

}; // fin de la clase DatosCliente

// constructor predeterminado de DatosCliente
DatosCliente::DatosCliente(
    int valorNumeroCuenta,
    string valorApellidoPaterno,
    string valorPrimerNombre,
    double valorSaldo)
{
    establecerNumeroCuenta(valorNumeroCuenta);
    establecerApellidoPaterno(valorApellidoPaterno);
    establecerPrimerNombre(valorPrimerNombre);
    establecerSaldo(valorSaldo);
} // fin del constructor de DatosCliente

// obtiene el valor del numero de cuenta
int DatosCliente::obtenerNumeroCuenta() const
{
    return numeroCuenta;
} // fin de la funcion obtenerNumeroCuenta

// establece el valor del numero de cuenta
void DatosCliente::establecerNumeroCuenta(int valorNumeroCuenta)
{
    numeroCuenta = valorNumeroCuenta; // debe validar
} // fin de la funcion establecerNumeroCuenta

// obtiene el valor del apellidoPaterno
string DatosCliente::obtenerApellidoPaterno() const
{
    return apellidoPaterno;
} // fin de la funcion obtenerApellidoPaterno

// establece el valor del apellidoPaterno
void DatosCliente::establecerApellidoPaterno(string cadenaApellidoPaterno)
{
    // copia a los mas 15 caracteres de la cadena a apellidoPaterno
    const char *valorApellidoPaterno = cadenaApellidoPaterno.data();
    int longitud = cadenaApellidoPaterno.size();
    longitud = (longitud < 15 ? longitud : 14);
    strncpy(apellidoPaterno, valorApellidoPaterno, longitud);
    apellidoPaterno[longitud] = '\0'; // adjusta un caracter nulo a apellidoPaterno
} // fin de la funcion establecerApellidoPaterno

// obtiene el valor del primerNombre
string DatosCliente::obtenerPrimerNombre() const
{
    return primerNombre;
} // fin de la funcion obtenerPrimerNombre

// establece el valor del primerNombre
void DatosCliente::establecerPrimerNombre(string cadenaPrimerNombre)
{
    // copia a los mas 10 caracteres de la cadena a primerNombre
    const char *valorPrimerNombre = cadenaPrimerNombre.data();
    int longitud = cadenaPrimerNombre.size();
    longitud = (longitud < 10 ? longitud : 9);
    strncpy(primerNombre, valorPrimerNombre, longitud);
    primerNombre[longitud] = '\0'; // adjusta un caracter nulo a primerNombre
} // fin de la funcion establecerPrimerNombre

// obtiene el valor del saldo
double DatosCliente::obtenerSaldo() const
{
    return saldo;
} // fin de la funcion obtenerSaldo

// establece el valor del saldo
void DatosCliente::establecerSaldo(double valorSaldo)
{
    saldo = valorSaldo;
} // fin de la funcion establecerSaldo

int main()
{
    int numeroCuenta;
    char apellidoPaterno[15];
    char primerNombre[10];
    double saldo;

    fstream creditoSalida("credito.dat", ios::in | ios::out | ios::binary);

    // sale del programa si ofstream no puede crear el archivo
    if (!creditoSalida)
    {
        cerr << "No se pudo abrir el archivo." << endl;
        exit(1);
    } // fin de if

    cout << "Escriba el numero de cuenta (1 a 100, 0 para terminar la entrada).\n? ";
    // requiere que el usuario especifique el numero de cuenta
    DatosCliente cliente;
    cin >> numeroCuenta;

    // el usuario introduce informacion, la cual se copia en el archivo
    while (numeroCuenta > 0 && numeroCuenta <= 100)
    {
        // el usuario introduce el apellidoPaterno, primerNombre y saldo
        cout << "Escriba apellido Paterno, primer Nombre, saldo\n? ";
        cin >> setw(15) >> apellidoPaterno;
        cin >> setw(10) >> primerNombre;
        cin >> saldo;

        // establecer los valores de numeroCuenta, apellidoPaterno, primerNombre y saldo
        cliente.establecerNumeroCuenta(numeroCuenta);
        cliente.establecerApellidoPaterno(apellidoPaterno);
        cliente.establecerPrimerNombre(primerNombre);
        cliente.establecerSaldo(saldo);

        // buscar la posicion en el archivo del registro especificado por el usuario
        creditoSalida.seekp((cliente.obtenerNumeroCuenta() - 1) * sizeof(DatosCliente));

        // escribir la informacion especificada por el usuario en el archivo
        creditoSalida.write(reinterpret_cast<const char *>(&cliente), sizeof(DatosCliente));

        // permitir al usuario escribir otro numero de cuenta
        cout << "Escriba el numero de cuenta\n? ";
        cin >> numeroCuenta;
    } // fin de while

    return 0;
}; // fin de main