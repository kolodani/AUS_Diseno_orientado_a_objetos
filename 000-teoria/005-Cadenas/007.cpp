// lexicographical_compare

#include <iostream>  // std::cout
#include <algorithm> // std::lexicographical_compare
#include <cctype>    // std::tolower

using namespace std;

bool mi_comparador(char c1, char c2)
{
    return (tolower(c1) < tolower(c2));
}

int main()
{
    string s = "Apple";
    string s2 = "apartment";
    string::iterator i = s.begin();
    string::iterator e = s.end();
    string::iterator i2 = s2.begin();
    string::iterator e2 = s2.end();

    cout << boolalpha; // setea la salia en pantalla para mostrar true o false;

    cout << "Comparando s y s2 lexicograficamente (s < s2): ";
    cout << lexicographical_compare(i, e, i2, e2) << endl;

    cout << "Usando la funcion mi_comparador: ";
    cout << lexicographical_compare(i, i + 5, i2, i2 + 9, mi_comparador) << endl;

    return 0;
}