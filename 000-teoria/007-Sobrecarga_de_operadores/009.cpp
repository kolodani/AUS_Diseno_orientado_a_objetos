#include <iostream>

using namespace std;

class Amigable
{
private:
    int secreto;
    friend void FuncionAmiga(Amigable &o);
    friend class Amiga;
};

class Amiga
{
public:
    void mirar(Amigable &o)
    {
        o.secreto = 120;
        cout << o.secreto << endl;
    }
};

void FuncionAmiga(Amigable &o)
{
    o.secreto = 121;
    cout << o.secreto << endl;
}

int main()
{
    Amiga amiga;
    Amigable amigable;
    amiga.mirar(amigable);
    FuncionAmiga(amigable);

    return 0;
}