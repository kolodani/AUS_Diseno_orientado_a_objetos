#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> ranking{make_pair("stackoverflow", 2), make_pair("docs-beta", 1)};
    /*
     * ranking["stackoverflow"] = 2;
     * ranking["docs-beta"] = 1;
     */
    cout << ranking["stackoverflow"] << endl;
    cout << ranking.at("stackoverflow") << endl;

    return 0;
};