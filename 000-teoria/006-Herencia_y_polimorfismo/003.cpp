#include <iostream>

using namespace std;

class A
{
    int x;
public:
    A(int ax)
    {
        x = ax;
    };
    void setX(int i)
    {
        x = i;
    };
};

class B : public A
{
    int y;
public:
    B(int bx, int by): A(bx)
    {
        y = by;
    };
};