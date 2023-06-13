#include <iostream>

using namespace std;

void duplica(int *x)
{
    *x *= 2;
};

int main()
{
    int y{10};
    int *p{nullptr};

    cout << "y = " << y << endl;
    duplica(&y);
    cout << "y = " << y << endl;
    p = &y;
    duplica(p);
    cout << "y = " << y << endl;

    return 0;
};