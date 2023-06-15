#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, size_t> fruits_count;
    map<string, size_t> fruits_list{{"lemon", 0}, {"olive", 0}, {"plum", 0}};

    fruits_count.insert(fruits_list.begin(), fruits_list.end());

    fruits_count["apple"] = 10;

    fruits_count.insert({{"apricot", 1}, {"jackfruit", 1}, {"lime", 1}, {"mango", 7}});
    
    return 0;
}