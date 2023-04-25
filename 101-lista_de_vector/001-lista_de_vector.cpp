#include <iostream>

using namespace std;

class vec4
{
private:
    float v1, v2, v3, v4;

public:
    // constructor con ceros
    vec4()
    {
        v1 = 0.0;
        v2 = 0.0;
        v3 = 0.0;
        v4 = 0.0;
    };
    // costructor
    vec4(float a, float b, float c, float d)
    {
        v1 = a;
        v2 = b;
        v3 = c;
        v4 = d;
    }
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

class nodo
{
    private:
        vec4 vect;
        nodo* sig;
    public:
        nodo()
        {
            sig = NULL;
        };
        void set_nodo(vec4 a)
        {
            vect = a;
        };
        void set_sig(nodo* a)
        {
            sig = a;
        };
        bool si_esta(vec4 a)
        {
            if (vect.getv1() == a.getv1() &&
                vect.getv2() == a.getv2() &&
                vect.getv3() == a.getv3() &&
                vect.getv4() == a.getv4())
            {
                return true;
            } else {
                return false;
            }
        };
        void mostrar()
        {
            vect.mostrar();
        };
};

int main()
{
    vec4 Vector1;
    vec4 Vector2(2.4, 5.3, 4, 1.0);

    cout << "ingrese los valores del vector 1" << endl;
    float a, b, c, d;
    cout << "ingrese el valor de v1: ";
    cin >> a;
    cout << "ingrese el valor de v2: ";
    cin >> b;
    cout << "ingrese el valor de v3: ";
    cin >> c;
    cout << "ingrese el valor de v4: ";
    cin >> d;
    Vector1.setv1(a);
    Vector1.setv2(b);
    Vector1.setv3(c);
    Vector1.setv4(d);

    cout << "Vector 1: " << endl;
    Vector1.mostrar();

    cout << "Vector 2: " << endl;
    Vector2.mostrar();

    nodo* lista = new nodo;
    lista->set_nodo(Vector1);
    cout << "lista del nodo con el vector 1: " << endl;
    lista->mostrar();
    lista->set_sig(new nodo);
    lista->set_nodo(Vector2);
    cout << "lista del nodo con el vector 2: " << endl;
    lista->mostrar();
    lista->set_sig(new nodo);
    cout << "lista del nodo con el vector 1: " << endl;
    lista->mostrar();

    return 0;
}