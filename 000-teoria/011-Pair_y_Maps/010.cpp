#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> mp{{1, 2}, {3, 4}, {6, 5}, {8, 9}, {3, 4}, {6, 7}};
    if (mp.count(3) > 0) // existen 2 elementos con esa clave
    {
        cout << "La clave existe!" << endl; // esta será la linea ejecutada
    }
    else
    {
        cout << "La clave no existe!" << endl;
    };

    auto eqr = mp.equal_range(6);
    auto st = eqr.first, en = eqr.second;
    for (auto it = st; it != en; ++it)
    {
        cout << it->first << ", " << it->second << endl;
    }; // prints 6, 5 and 6, 7

    return 0;
};