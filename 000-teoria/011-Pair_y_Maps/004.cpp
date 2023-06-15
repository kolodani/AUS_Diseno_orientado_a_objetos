#include <iostream>
#include <map>

using namespace std;

int main()
{
    multimap<int, string> mmp{make_pair(2, "stackoverflow"), make_pair(1, "docs-beta"), make_pair(2, "stackexchange")};

    auto it = mmp.begin();

    cout << it->first << " : " << it->second << endl;
    // output: "1 : docs-beta"
    it++;
    cout << it->first << " : " << it->second << endl;
    // output: "2 : stackoverflow"
    it++;
    cout << it->first << " : " << it->second << endl;
    // output: "2 : stackexchange"

    // Example using rbegin()

    map<int, string> mp{make_pair(2, "stackoverflow"), make_pair(1, "docs-beta"), make_pair(2, "stackexchange")};

    auto it2 = mp.rbegin();
    cout << it2->first << " : " << it2->second << endl;
    // output: "2 : stackoverflow"
    it2++;
    cout << it2->first << " : " << it2->second << endl;
    // output: "1 : docs-beta"

    return 0;
};