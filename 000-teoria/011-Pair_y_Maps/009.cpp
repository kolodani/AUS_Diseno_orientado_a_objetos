#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap<int, int> mmp{{1, 2}, {3, 4}, {6, 5}, {8, 9}, {3, 4}, {6, 7}};
    auto it = mmp.find(6);

    if (it != mmp.end())
    {
        cout << it->first << ", " << it->second << endl; // imprime 6, 5
    }
    else
    {
        cout << "EL valor no existe!" << endl;
    };
    it = mmp.find(66);

    if (it != mmp.end())
    {
        cout << it->first << ", " << it->second << endl;
    }
    else
    {
        cout << "EL valor no existe!" << endl; // Esta es la linea que se mostrará
    };

    return 0;
};