#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    map<int, string> ejemplo;

    ejemplo[0] = "Grover";
    ejemplo[1] = "Otro Gorver";

    cout << "Elementos\n";

    auto x = ejemplo.find(0);
    cout << "Clave " << x->first << " Dato: " << x->second << endl;

    return 0;
};