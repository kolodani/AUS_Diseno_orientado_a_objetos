#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "abcde", s2 = "abcdf", s3 = "abc";

    cout << "usaremos compare..." << endl;
    if (!s.compare(s2)) // como retorna 0 si son iguales, usamos el !
    {
        cout << "son iguales" << endl;
    }
    else
    {
        cout << "son distintas" << endl;
    }

    cout << "usamos == ..." << endl;
    if (s == s2)
    {
        cout << "son iguales" << endl;
    }
    else
    {
        cout << "son distintas" << endl;
    }
    cout << "usamos compare para comparar los 3 primeros\n" << "caracteres con s2" << endl;
    if (s.compare(0, 3, s2) == 0)
    {
        cout << "son iguales" << endl;
    }
    else
    {
        cout << "son diferentes\n" << endl;
    }
    cout << "usamos compare para comparar los 3 primeros\n" << "caracteres con s3" << endl;
    if (s.compare(0, 3, s3) == 0)
    {
        cout << "son iguales" << endl;
    }
    else
    {
        cout << "son diferentes" << endl;
    }

    return 0;
};