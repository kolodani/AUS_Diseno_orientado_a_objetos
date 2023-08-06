#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void f(char* p, vector<char> v)
{
    string s0;          // la string esta vacia
    string s00 = "";    // la string esta vacia

    // string s1 = 'a';     // error!!! no se puede convertir un caracter en strig
    // string s2 = 7;       // error!!! no hay conversion de int a string
    // string s3(7);        // error!!! no hay constructor que tome un int

    string s4(7, 'a');   // crea un string con 7 copias de a, osea, "aaaaaaa"
    string s5("Frodo");  // copia de "Frodo"
    string s6 = s5;      // copia de s5

    string s7(s5, 3, 2);    // s5[3] y s5[4] osea copia de "do"
    string s8(p+7, 3);      // p[7], p[8] y p[9]
    string s9(p, 7, 3);     // String(string(p), 7, 3) no es recomendable
    string s10(v.begin(), v.end()); // copiat todos los caracteres de v
};

int main()
{
    char* p = "DanielAlbertoVinzia";
    vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

    f(p, v);

    return 0;
};