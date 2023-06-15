#include <iostream>
#include <utility>

using namespace std;

int main()
{
    pair<int, int> p = make_pair(1, 2);         // se crea el par
    cout << p.first << " " << p.second << endl; // accedo a los elementos

    // Se puede hacer en dos tiempos
    pair<int, int> p1;
    p1.first = 3;
    p1.second = 4;
    cout << p1.first << " " << p1.second << endl;
    // Si usamos el constructor
    pair<int, int> p2 = pair<int, int>(5, 6);
    cout << p2.first << " " << p2.second << endl;

    return 0;
};