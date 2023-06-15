#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string, size_t> fruits_count;

    fruits_count.insert({"grapes", 20});
    fruits_count.insert({"orange", 30});
    fruits_count.insert(pair<string, size_t>("banana", 40));
    fruits_count.insert(map<string, size_t>::value_type("cherry", 50));

    auto success = fruits_count.insert({"grapes", 20});
    if (!success.second)
    {                                // we alreadu have 'grapes' in the map
        success.first->second += 20; // access the iterator to update the value
    }

    return 0;
};