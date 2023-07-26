#include <iostream>
#include <string>

using namespace std;

int cmp_nocese(string s, string s2)
{
    string::const_iterator p = s.begin();
    string::const_iterator p2 = s2.begin();

    while (p != s.end() && p2 != s2.end())
    {
        if (toupper(*p) != toupper(*p2))
        {
            return (toupper(*p) < toupper(*p2)) ? -1 : 1;
        }
        ++p;
        ++p2;
    };

    return (s2.size() == s.size()) ? 0 : (s.size() < s2.size()) ? -1 : 1;
};

int main()
{
    string s = "Apple";
    string s2 = "apartment";

    cout << cmp_nocese(s, s2) << endl;

    return 0;
}