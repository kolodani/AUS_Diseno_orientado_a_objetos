#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char* cadena()
{
    char cad[25];
    strcpy(cad, "Hola");
    return cad;
};

int main()
{
    char *cad = cadena();
    cout << cad << endl;
    return 0;
}