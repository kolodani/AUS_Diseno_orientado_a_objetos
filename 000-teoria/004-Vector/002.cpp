#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // copia de vectores..
    // declaro e inicializo un vector con valores en 1
    vector<int> vInt_1(20,1);

    // No se inicializa
    vector<int> vInt_2;

    cout << "vInt_2 antes: " << vInt_2.size() <<endl;

    // Uso el igual para asignar, para hacer la copia
    vInt_2 = vInt_1;

    cout << "vInt_2 despues: " << vInt_2.size() <<endl;
    for(int i = 0; i < vInt_2.size(); i++)
    {
        cout << "vInt_2 = " << vInt_2[i] << endl;
    };
};