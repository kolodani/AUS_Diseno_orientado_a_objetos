#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, size_t> fruits_count;
    string fruit;
    while(cin >> fruit)
    {
        // Inserta un elemnto 'fruit' como clave y '1' de valor
        // (if the key is already stored in fruits_count, insert does nothing)
        auto ret = fruits_count.insert({fruit, 1});
        if(!ret.second)
        {   // 'fruit' is already in the map
            ++ret.first->second;  // increment the counter
        }
    };

    return 0;
}