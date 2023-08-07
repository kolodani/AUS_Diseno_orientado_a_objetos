#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
typedef pair<pair<char, char>, int> arista;
// ((a,b),3)

class MenorValor
{
public:
    bool operator()(arista a1, arista a2) { return a1.second > a2.second; }
};

typedef priority_queue<arista, vector<arista>, MenorValor> arbol;

typedef struct combina_encuentra
{
    map<char, pair<char, char>> vertices;
    map<char, pair<int, char>> componentesConEncabezado;
} conjunto_CE;

class Grafo
{
    vector<char> V;
    vector<arista> E;
    conjunto_CE CE;
    arbol aristas_ordenadas; // cola de prioridad
    vector<arista> arbol_minimo;

public:
    Grafo() {}
    ~Grafo() {}
    void insertar_vertice(const char &);                           //
    void insertar_arista(const char &, const char &, const int &); //
    // void insertar_arista();
    void inicial(const char &); //
    void combina(const char &, const char &);
    char encuentra(const char &);
    void kruskal();
    friend ostream &operator<<(ostream &, Grafo &);
};

int main(int argc, char *argv[])
{
    Grafo grafo;
    grafo.insertar_vertice('1');
    grafo.insertar_vertice('2');
    grafo.insertar_vertice('3');
    grafo.insertar_vertice('4');
    grafo.insertar_vertice('5');
    grafo.insertar_vertice('6');
    grafo.insertar_arista('2', '5', 3);
    grafo.insertar_arista('3', '6', 4);
    grafo.insertar_arista('3', '5', 6);
    grafo.insertar_arista('1', '4', 5);
    grafo.insertar_arista('1', '3', 1);
    grafo.insertar_arista('4', '6', 2);
    grafo.insertar_arista('3', '4', 5);
    grafo.insertar_arista('1', '2', 6);
    grafo.insertar_arista('2', '3', 5);
    grafo.insertar_arista('5', '6', 6);
    grafo.kruskal();
    cout << grafo << endl;
    return 0;
}

ostream &operator<<(ostream &os, Grafo &grafito)
{
    cout << "Vertices : " << endl;
    for (auto vert : grafito.V)
    {
        cout << vert << ", ";
    }
    cout << endl
        << "Aristas: \n";

    for (auto arista : grafito.E)
    {

        cout << "(" << arista.first.first << "," << arista.first.second << "), "
            << arista.second << endl;
    }

    cout << "Arbol minimo : " << endl;
    for (auto arista : grafito.arbol_minimo)
    {
        cout << "(" << arista.first.first << "," << arista.first.second << "), "
            << arista.second << "\t";
    }

    return os;
}

void Grafo::insertar_vertice(const char &vertice)
{
    for (char v : V)
    {
        if (v == vertice)
            return;
    }
    // si no hay vertice, para adentro
    V.push_back(vertice);
}

void Grafo::insertar_arista(const char &v1, const char &v2, const int &w)
{
    for (int i = 0; i < E.size(); i++)
    {
        // si los vertices ya tienen una arista, borrar la actual
        if (E[i].first.first == v1 && E[i].first.second == v2)
            E.erase(E.begin() + i);
    }
    bool v1InGraph = false;
    bool v2InGraph = false;
    for (auto vert : V)
    {
        if (v1 == vert)
            v1InGraph = true;
        if (v2 == vert)
            v2InGraph = true;
    }
    if (v1InGraph && v2InGraph)
    {
        arista a = make_pair(make_pair(v1, v2), w);
        aristas_ordenadas.push(a);
        E.push_back(a);
    }
}

void Grafo::inicial(const char &v)
{
    CE.vertices[v] = make_pair(v, NULL);
    // el vertice pertenece a la componente con su nombre
    CE.componentesConEncabezado[v] = make_pair(0, v);
}

char Grafo::encuentra(const char &v)
{
    // retorna el grupo al que pertenece el vertice
    return CE.vertices[v].first;
}

void Grafo::combina(const char &c1, const char &c2)
{
    int sizeC1 = CE.componentesConEncabezado[c1].first;
    int sizeC2 = CE.componentesConEncabezado[c2].first;
    // encabezado de la componente dominante
    char ecDom = CE.componentesConEncabezado[sizeC1 > sizeC2 ? c1 : c2].second;
    // encabezado de la componente absorbida
    char ecAbs = CE.componentesConEncabezado[sizeC1 <= sizeC2 ? c1 : c2].second;

    char aux = CE.componentesConEncabezado[ecAbs].second;
    while (CE.vertices[aux].second != (char)NULL)
    {
        // ahora el vertice del componente absorbido es parte del dominante
        CE.vertices[aux].first = ecDom;
        // y el siguiente tambien lo sera
        aux = CE.vertices[aux].second;
    }
    // ahora aux es el ultimo elemento del conjunto absorbido
    int menorSize = sizeC1 < sizeC2 ? sizeC1 : sizeC2;

    CE.vertices[ecDom].second = aux;
    CE.vertices[aux].first = ecDom;
    CE.componentesConEncabezado[ecAbs].first = 0;
    CE.componentesConEncabezado[ecAbs].second = (char)NULL;
    CE.componentesConEncabezado[ecDom].first += menorSize;
}

void Grafo::kruskal()
{
    for (auto v : V)
    {
        inicial(v);
    }

    while (!aristas_ordenadas.empty())
    {
        arista menorArista = aristas_ordenadas.top();
        aristas_ordenadas.pop();
        // componente 1, componente 2
        char c1 = encuentra(menorArista.first.first);
        char c2 = encuentra(menorArista.first.second);
        if (c1 != c2)
        {
            combina(c1, c2);
            arbol_minimo.push_back(menorArista);
        }
    }
}
