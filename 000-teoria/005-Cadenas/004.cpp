#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void g()
{
    string s1 = "Knould";
    string s2 = "Tod";

    s1 = s2;        // dos copias de "Tod"
    s2[1] = 'u';    // s2 = "Tud"
};

void f()
{
    string s;
    //string s = 'a';      // error!!!
    s = 'a';               // esto es correcto
    s = "a";               // esto es correcto
}

int main()
{
    g();
    f();

    return 0;
}