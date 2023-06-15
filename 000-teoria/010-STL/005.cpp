#include <iostream>
#include <utility>

using namespace std;

pair<int, int> sum_resra(int x, int y)
{
    return {x + y, x - y};
};

int main()
{
    pair<int, int> resultado = sum_resra(6, 2);

    cout << "Resultado\n";
    cout << "Suma: " << resultado.first << endl;
    cout << "Resta: " << resultado.second << endl;

    return 0;
}