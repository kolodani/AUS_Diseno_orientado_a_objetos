#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#define ARCHIVO "cache.dat"

using namespace std;

/* estructura utilizada para guardar los objetos en 
 * el archivo
 * */
template<class T>
struct Block{
    bool valid = true;
    string key;
    T data;
};

template <class T>
class CacheManager
{
    size_t capacity;
    int MRU;
    map<string, pair<T, int>> cacheData; // < Clave , < Obj , Indice de Uso >>

public:
    CacheManager(size_t cap): capacity(cap),MRU(0){}; 
    ~CacheManager();

    void insert(string key,const T& obj);
    T get(string key);
    T getF(string key);
    void showCache();
    void showArchivo();
    void invalidate(string key);
    bool insertF(string key,const T& objeto);
};

/* Inserta el objeto dentro de la cache,
 * si luego de insertarlo, la cache supero la capacidad,
 * el objeto es enviado al archivo y se borra de la cache.
 * De esta manera no se supera la capacidad.
 * */
template <class T>
void CacheManager<T>::insert(string key,const T& obj)
{
    cacheData[key] = make_pair(obj,++MRU);
    if(cacheData.size() > capacity){
        // si la memoria esta llena, tengo que matar al de MRU mas bajo
        auto it = cacheData.begin();
        auto aux = it;
        while(it != cacheData.end()){
            // busqueda del objeto con menor MRU (menos utilizado)
            if(it->second.second < aux->second.second) 
                aux = it; 
            it++;
        }
        // insercion del objeto en el archivo
        insertF(aux->first, aux->second.first);
        // se remueve el objeto de la cache
        cacheData.erase(aux);
    }
}

template <class T>
CacheManager<T>::~CacheManager(){}

/* Se invalidan aquellos bloques que tengan la misma
 * key en el archivo, para luego insertar el bloque 
 * con el objeto al final del archivo
 * */
template <class T>
bool CacheManager<T>::insertF(string key, const T& obj)
{
    Block<T> bloque;
    bloque.key = key;
    bloque.data = obj; // copio en la estructura el objeto, no por referencia
    ofstream w(ARCHIVO, ios::app | ios::binary);
    if(!w) return false;
    showArchivo();
    invalidate(key);
    showArchivo();
    w.write(reinterpret_cast<char*>(&bloque), sizeof (Block<T>));
    w.close();
    return true;
}

/* Obtiene un objeto de la cache, utilizando una key.
 * Si la key no tiene asociado ningun objeto, no existe en la cache,
 * dado el caso se obtiene el objeto desde el archivo y se retorna.
 * */
template < class T >
T CacheManager <T>:: get(string key)
{
    /* map.find() itera por todo el map, devolviendo un iterador.
     * Si este es igual a map.end() el objeto no esta, si no, queda apuntando
     * a la entrada deseada.
     * */
    auto it = cacheData.find(key); 
    if(it == cacheData.end()){
        // no esta, se trae desde el archivo con getF el bloque, se reinserta y retorna
        T item = getF(key);
        insert(key,item);
        return item;
    }
    // si estaba ya en el iterador, saco el objeto
    return it->second.first;
}

template <class T>
T CacheManager <T>:: getF(string key)
{
    ifstream w(ARCHIVO, ios::in | ios::binary);
    Block<T> b; // bloque utilizado como pivot
    /* read ya tira error state flags en lectura despues del EOF,
     * lo puedo usar como condicion 
     * */
    bool infile = false;
    while(w.read(reinterpret_cast<char *>(&b), sizeof(Block<T>))){
        if(b.key == key && b.valid){
            infile = true;
            break;
        }
        // si un bloque del archivo coincide con la key, paro el loop 
    }

    if(!infile)
        cout << "no esta ni en la cache, ni en el archivo" << endl;

    w.close();
    return b.data;
}

template <class T>
void CacheManager <T>:: invalidate(string key){
    ifstream r(ARCHIVO, ios::binary | ios::in);
    ofstream w(ARCHIVO, ios::binary | ios::out);
    Block<T> aux;

    if(!(w && r)) {
        if(w.is_open())w.close();
        if(r.is_open())r.close();
        return;
    }

    /* encuentro el bloque dentro del archivo de lectura, y luego
     * le paso la posicion(stream pos) del puntero actual, 
     * al archivo de escritura
     * */
    streampos blockPosition = r.tellg();
    while(r.read(reinterpret_cast<char*>(&aux), sizeof(Block<T>))){
        if(aux.key == key && aux.valid){
            aux.valid = false;
            w.seekp(blockPosition);
            w.write(reinterpret_cast<char*>(&aux), sizeof(Block<T>));
        }
        blockPosition = r.tellg();
    }
    r.close();
    w.close();
}

template < class T >
void CacheManager <T>:: showCache()
{
    for(auto it = cacheData.begin(); it != cacheData.end(); it++)
        cout << it->first << " - " << it->second.first << endl;
}

template < class T >
void CacheManager <T>:: showArchivo()
{
    ifstream r(ARCHIVO,ios::binary | ios::in);
    Block<T> aux;
    while (r.read(reinterpret_cast<char*>(&aux), sizeof(Block<T>))) {
        cout << aux.data << endl;
    }
    r.close();
}
