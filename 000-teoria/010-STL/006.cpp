#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/*
    Sea un grafo G = (V, E)
*/

class grafo
{
    vector<char> V;
    vector<pair<pair<char, char>, int>> E;

public:
    grafo(){};
    ~grafo(){};

    void insertar_vetice(const char &);
    void insertar_arista(const char &, const char &, const int &);

    friend ostream &operator<<(ostream &, grafo);
};