#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
    sea un grado G = (V, E)
*/
class grafo
{
    vector<char> V;
    vector<pair<pair<char, char>, int>> E;
    const string nombre_archivo = "archivo.dat";

public:
    grafo(){};
    ~grafo(){};

    void insertar_vertice(const char &);
    void insertar_arista();

    void escribe_grafo();
    void lee_grafo();

    friend ostream &operator<<(ostream &, grafo);
};

void grafo::insertar_vertice(const char &vertice)
{
    V.push_back(vertice);
};

void grafo::insertar_arista()
{
    int c = 0;
    for (unsigned int x = 0; x <= V.size() - 1; x++)
    {
        for (unsigned int j = x + 1; j <= V.size() - 1; j++)
        {
            cout << "Ingrese costo para arista entre vertice " << V[x] << " y " << V[j] << " (0 si no existe arista): ";
            cin >> c;
            cout << endl;
            if (c != 0)
            {
                E.push_back(make_pair(make_pair(V[x], V[j]), c));
            }
        }
    };
};

void grafo::escribe_grafo()
{
    ofstream archivo(nombre_archivo, ios::out | ios::binary);

    // sale del programa si ofstream no puede abrir el archivo
    if (!archivo)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }; // fin de if

    for (auto x : E)
    {
        archivo << x.first.first << " " << x.first.second << " " << x.second << endl;
    };
    archivo.close();
};

void grafo::lee_grafo()
{
    ifstream archivo(nombre_archivo, ios::in | ios::binary);

    // sale del programa si ifstream no puede abrir el archivo
    if (!archivo)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(1);
    }; // fin de if

    char nodoOrigen, nodoDestino;
    int costo;

    cout << "Datos del archivo\n";
    archivo >> nodoOrigen >> nodoDestino >> costo;
    while (archivo && !archivo.eof())
    {
        cout << nodoOrigen << " - " << nodoDestino << ": costo = " << costo << endl;
        archivo >> nodoOrigen >> nodoDestino >> costo;
    };
    cout << nodoOrigen << " - " << nodoDestino << ": costo = " << costo << endl;
    archivo.close();
};

ostream &operator<<(ostream &os, grafo G)
{
    os << "El grafo es: \n";
    for (auto x : G.E)
    {
        os << x.first.first << " - " << x.first.second << ": costo = " << x.second << endl;
    };
    return os;
};

int main()
{
    grafo G;
    char x;
    cout << "ingrese las letras que representan a los vertices del grafo (0 para terminar): ";
    cin >> x;
    while (x != '0')
    {
        G.insertar_vertice(x);
        cin >> x;
    };

    G.insertar_arista();
    G.escribe_grafo();

    G.lee_grafo();

    cout << G;

    return 0;
};