#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> runs;
    runs.emplace("Babe Ruth", 714);
    runs.insert(make_pair("Barry Bonds", 762));

    auto it = runs.emplace("Barry Bonds", 762); // guardo el iterador del elemento guardado
    // el siguiente elemento sera ubicado despues de "Barry Bonds", por lo tanto se insertara despues de 'it'
    runs.emplace_hint(it, "Babe Ruth", 714);
};