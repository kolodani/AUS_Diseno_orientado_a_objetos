#include <iostream>

using namespace std;

class Punto
{
    private:
        int cord_x;
        int cord_y;
        bool valida(int a)
        {
            if (a >= 0){
                return true;
            } else {
                return false;
            }
        };
    public:
        Punto(void)
        {
            set(0, 0);
        };
        bool set(int a, int b)
        {
            if (valida(a) && valida(b)){
                cord_x = a;
                cord_y = b;
                return true;
            } else {
                return false;
            }
        };
        void print(void)
        {
            cout << "x: " << cord_x << endl;
            cout << "y: " << cord_y << endl;
        };
};

class Rectangulo
{
    private:
        Punto tope_izq;
        Punto inf_der;
    public:
        Rectangulo(int a, int b, int c, int d)
        {
            tope_izq.set(a, b);
            inf_der.set(c, d);
        };
        void print(void)
        {
            cout << "Tope izquierdo: " << endl;
            tope_izq.print();
            cout << "Inferior derecho: " << endl;
            inf_der.print();
        };
};

int main()
{
    Rectangulo R(5,4,9,2);
    R.print();
}