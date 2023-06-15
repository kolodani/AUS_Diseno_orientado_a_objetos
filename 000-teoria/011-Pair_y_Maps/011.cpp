#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    multimap<int, string> mmp2{make_pair(2, "stackoverflow"), make_pair(1, "docs-beta"), make_pair(2, "stackexchange")};
    // 1 docs-beta
    // 2 stackoverflow
    // 2 stackexchange

    // como map no admite repeticiones, y con prioridad de derecha a izquierda, stackexchange sera sobreescrito
    map<int, string> mp{make_pair(2, "stackoverflow"), make_pair(1, "docs-beta"), make_pair(2, "stackexchange")};
    // 1 docs-beta
    // 2 stackoverflow

    // pueden ser inicializados con iteradores
    multimap<int, int> mmp{{1, 2}, {3, 4}, {6, 5}, {8, 9}, {6, 8}, {3, 4}, {6, 7}};
    // {1, 2}, {3, 4}, {3, 4}, {6, 5}, {6, 7}, {6, 8}, {8, 9}
    auto it = mmp.begin();
    advance(it, 3);                  // mueve el cursor al primero {6, 5}
    map<int, int> mp2(it, mmp.end()); // {6, 5}, {8, 9}
    // inicializacion por un arreglo de pares
    pair<int, int> arr[10];
    arr[0] = {1, 3};
    arr[1] = {1, 5};
    arr[2] = {2, 5};
    arr[3] = {0, 1};
    map<int, int> mp3(arr, arr + 4); // {0, 1}, {1, 3}, {2, 5}

    // inicializacion por un vector de pares
    vector<pair<int, int>> v{
        {1, 5},
        {5, 1},
        {3, 6},
        {3, 2}};
    multimap<int, int> mmp3(v.begin(), v.end()); // {1, 5}, {3, 2}, {3, 6}, {5, 1}

    return 0;
};