#include <iostream>
#include <string>
#include <cstring>

using namespace std;

template <class T>
const T &maximo(const T &a, const T &b)
{
    return (a > b) ? a : b;
};
const char *maximo(const char *a, const char *b)
{
    if (strcmp(a, b) > 0)
    {
        return a;
    }
    else
    {
        return b;
    }
};

int main()
{
    cout << "int mayor: " << maximo(4, 6) << endl;
    cout << "float mayor: " << maximo(4.5, 6.5) << endl;
    cout << "char mayor: " << maximo('a', 'b') << endl;
    cout << "string mayor: " << maximo("hola","adios") << endl;

    return 0;
}