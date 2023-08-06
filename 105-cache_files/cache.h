//  Vinzia, Daniel Alberto
//  Rojas, Elias Ezequiel
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <stdexcept>
#define ARCHIVO "cache.dat"
#define SIZE (sizeof(Block<T>))
#define R_CAST(e) (reinterpret_cast<char *>(e))
#define BUFFER_SIZE 64

using namespace std;

/*  Este objeto sera utilizado para guardar los objetos introducidos
 *  en los archivos
 * */
template <class T>
class Block
{
    char key[BUFFER_SIZE];
    T data;

public:
    Block() {}
    Block(string n, T dat)
    {
        n.copy(key, BUFFER_SIZE);
        key[n.length()] = '\0';
        this->data = dat;
    }
    // convierte el arreglo de caracteres en una string y la devuelve
    string getKey() { return string(key); }
    // devuelve el objeto contenido
    T getData() { return data; }
};

template <class T>
class CacheManager
{
    size_t capacity;
    int MRU;
    map<string, pair<T, int>> cacheData; // < Clave , < Obj , Indice de Uso >>
    T getF(string key);
    bool insertF(string key, T obj);

public:
    // se trunca el archivo comenzar con uno nuevo
    CacheManager(size_t cap) : capacity(cap), MRU(0)
    {
        ofstream a(ARCHIVO, ios::trunc);
        if (!a)
            return;
        a.close();
    };
    ~CacheManager();
    void insert(string key, const T &obj);
    T get(string key);
    void showCache();
};

/*
 *   Se inserta el objeto en la cache, si esta supero su limite, se procede
 *   a eliminar el menos utilizado recientemente para liberar espacio
 * */
template <class T>
void CacheManager<T>::insert(string key, const T &obj)
{
    cacheData[key] = make_pair(obj, ++MRU);

    if (cacheData.size() > capacity)
    {
        auto it = cacheData.begin();
        auto aux = it;
        while (it != cacheData.end())
        {
            // se busca el de menor MRU
            if (it->second.second < aux->second.second)
                aux = it;
            it++;
        }
        insertF(aux->first, aux->second.first);
        cacheData.erase(aux);
    }
    writeFile(key, obj);
}

template <class T>
CacheManager<T>::~CacheManager() {}

/*
 *   Se toma el objeto desde la cache y es devuelto, si este no esta, se busca en la memoria ram
 *   (archivo) con getF, si este esta en el archivo, se reinserta en la cache y sera devuelto.
 *   Si "no esta en el sistema", getF tira una excepcion que se volvera a tirar desde get.
 */
template <class T>
T CacheManager<T>::get(string key)
{
    auto it = cacheData.find(key);
    if (it == cacheData.end())
    {
        try
        {
            T item = getF(key);
            insert(key, item);
            return item;
        }
        catch (const invalid_argument &e)
        {
            throw;
        }
    }
    return it->second.first;
}

/*
 *   Busca en todo el archivo el ultimo elemento que tenga la clave
 *   requerida. Si las claves no coinciden, se tirara la excepcion
 *   de argumento invalido.
 * */
template <class T>
T CacheManager<T>::getF(string key)
{
    ifstream r(ARCHIVO, ios::in | ios::binary);
    Block<T> piv;
    Block<T> last;
    if (!r)
        return piv.getData();
    while (r.read(R_CAST(&piv), SIZE))
    {
        if (piv.getKey() == key)
        {
            last = piv;
        }
    }

    // si no se encontro el objeto en el archivo, tira error
    if (last.getKey() != key)
    {
        throw invalid_argument("El objeto deseado no esta en el sistema\n");
    }
    return last.getData();
}

// simplemente inserta el objeto al final del archivo, utilizando Block para luego reencontrarlo
template <class T>
bool CacheManager<T>::insertF(string key, T obj)
{
    ofstream w;
    Block<T> b(key, obj);
    w.open(ARCHIVO, ios::app | ios::binary);
    w.write(R_CAST(&b), SIZE);
    w.close();
    return true;
}

template <class T>
void CacheManager<T>::showCache()
{
    for (auto it = cacheData.begin(); it != cacheData.end(); it++)
        cout << it->first << " - " << it->second.first << endl;
}
