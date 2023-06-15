#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> numeros;

    numeros.push_back(5);
    numeros.push_back(3);
    numeros.push_back(8);

    sort(numeros.begin(), numeros.end());

    for (auto x : numeros)
    {
        cout << x << endl;
    };

    return 0;
};