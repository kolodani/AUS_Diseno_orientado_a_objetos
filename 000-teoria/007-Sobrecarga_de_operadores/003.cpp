#include <iostream>

using namespace std;

void referencia(int& x)
{
    x = 25;
}

int main()
{
    int y = 5;

    cout << "y = " << y << endl;
    referencia(y);
    cout << "y = " << y << endl;
    return 0;
};