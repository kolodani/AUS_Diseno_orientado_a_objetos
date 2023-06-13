#include <iostream>

using namespace std;

template <class T>
const T &maximo(const T &a, const T &b)
{
    return (a > b) ? a : b;
};

int main()
{
    cout << "int mayor: " << maximo(4, 6) << endl;
    cout << "float mayor: " << maximo(4.5, 6.5) << endl;
    cout << "char mayor: " << maximo('a', 'b') << endl;
}