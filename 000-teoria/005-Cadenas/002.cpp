#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void f()
{
    string s = "Snobol14";
    string s2(s, 100, 2);       // posicion del caracter mas alla del final de
                                // la cadena:: lanza error out_of_range()
    string s3(s, 2, 100);       // Recuento de caracter demasiado grande
                                // equivalente a s3(s, 2, s.size() - 2)
    string s4(s, 2, string::npos);   // los caracteres a parter de s[2]
};