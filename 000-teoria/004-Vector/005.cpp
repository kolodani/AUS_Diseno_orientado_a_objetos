// itVector.cpp
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

    // Iteradores
    //
    // Son punteros
    vector<int>::iterator I;
    I = vInt_3.begin();

    cout << "vInt_3[0] = " << *I << endl;

    // como se ve, begin() retorna un iterador
    // entonces podemos hacer lo siguiente:
    //
    vector<int>::iterator I1, I2;
    I1 = vInt_3.begin();
    I2 = vInt_3.end();

    cout << endl << "Ordenado a traves de iteradores" << endl;

    sort(I1, I2);

    for (; I1 != I2; I1++)
    {
        cout << "vInt_3 = " << *I1 << endl;
    }

    return 0;
};