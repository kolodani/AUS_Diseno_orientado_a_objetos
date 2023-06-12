// sortVector.cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vInt_3(10);

    for (int i = 0, j = 10; i < 10; i++, j--)
    {
        vInt_3[i] = j + 1;
    }
    cout << "El tamaño de vInt_3 es " << vInt_3.size() << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < vInt_3.size(); i++)
    {
        cout << "vInt_3 = " << vInt_3[i] << endl;
    }
    // con los contenedores podemos usar una funcion
    // de la libreria algorithm muy util. antes hay que
    // incluir la libreria #include <algorithm>
    sort(vInt_3.begin(), vInt_3.end());
    cout << endl;
    for (int i = 0; i < vInt_3.size(); i++)
    {
        cout << "vInt_3 = " << vInt_3[i] << endl;
    }
    vector<string> Nombres;
    Nombres.push_back("Pablo");
    Nombres.push_back("Juan");
    Nombres.push_back("alicia");
    for (int i = 0; i < Nombres.size(); i++)
    {
        cout << Nombres[i] << " ";
    }
    cout << endl;

    sort(Nombres.begin(), Nombres.end());

    for (int i = 0; i < Nombres.size(); i++)
    {
        cout << Nombres[i] << " ";
    }
    cout << endl;
};