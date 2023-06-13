#include <iostream>
#include <string>

using namespace std;

template <class T>
const T &maximo(const T &a, const T &b)
{
    return (a > b) ? a : b;
};

int main()
{
    cout << "con int (5 - 10): " << maximo(5, 10) << endl;
    cout << "con string: " << maximo<std::string>("Hola", "zorro") << endl;

    return 0;
}