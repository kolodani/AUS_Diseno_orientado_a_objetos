#include <iostream>

using namespace std;

class vec4
{
private:
    float v1, v2, v3, v4;

public:
    // costructor
    vec4(float a, float b, float c, float d)
    {
        v1 = a;
        v2 = b;
        v3 = c;
        v4 = d;
    }
    // constructor con ceros
    void vec4cero()
    {
        v1 = 0.0;
        v2 = 0.0;
        v3 = 0.0;
        v4 = 0.0;
    };
    // get y set para v1
    float getv1()
    {
        return v1;
    };
    void setv1(float a)
    {
        v1 = a;
    };
    // get y set para v2
    float getv2()
    {
        return v2;
    };
    void setv2(float a)
    {
        v2 = a;
    };
    // get y set para v3
    float getv3()
    {
        return v3;
    };
    void setv3(float a)
    {
        v3 = a;
    };
    // get y set para v4
    float getv4()
    {
        return v4;
    };
    void setv4(float a)
    {
        v4 = a;
    };
    void mostrar()
    {
        cout << "valor de v1: " << getv1() << endl;
        cout << "valor de v2: " << getv2() << endl;
        cout << "valor de v3: " << getv3() << endl;
        cout << "valor de v4: " << getv4() << endl;
    };
};

int main()
{
    return 0;
}