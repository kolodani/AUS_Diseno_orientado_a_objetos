#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <cstdio>
#define ARCHIVO "cache.dat"
#define ARCHIVO_AUX "aux.dat"

using namespace std;

template<class T>
struct Block{
    bool valid = true;
    string key;
    T data;
};

template <class T>
class CacheManager
{
    size_t bSize = sizeof(pair<string,T>);
    size_t capacity;
    int MRU;
    map<string, pair<T, int>> cacheData; // < Clave , < Obj , Indice de Uso >>

public:
    CacheManager(size_t cap): capacity(cap),MRU(0)
    {
        ofstream clearCache(ARCHIVO,ios::trunc);
        clearCache.close();
    }; 
    ~CacheManager();

    void insert(string key,const T& obj);
    T get(string key);
    T getF(string key);
    void showCache();
    void invalidate(string key);
    bool insertF(string key,const T& objeto);
};

template <class T>
void CacheManager<T>::insert(string key,const T& obj)
{
    cacheData[key] = make_pair(obj,++MRU);
    if(cacheData.size() > capacity){
        // si la memoria esta llena, tengo que matar al de MRU mas bajo
        auto it = cacheData.begin();
        auto aux = it;
        while(it != cacheData.end()){
            if(it->second.second < aux->second.second) 
                aux = it; 
            it++;
        }
        insertF(aux->first, aux->second.first);
        cacheData.erase(aux);
    }
}

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::insertF(string key, const T& obj)
{
    Block<T> bloque;
    bloque.key = key;
    bloque.data = obj;
    ofstream w(ARCHIVO, ios::binary | ios::app);
    if(!w) return false;
    invalidate(key);
    w.write(reinterpret_cast<char*>(&bloque), sizeof (Block<T>));
    w.close();
    return true;
}


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
    // si estaba ya en el iterado, saco el item
    return it->second.first;
}

template <class T>
T CacheManager <T>:: getF(string key)
{
    ifstream w(ARCHIVO, ios::in | ios::binary);
    Block<T> b;
    /* read ya tira error state flags en lectura despues del EOF,
     * lo puedo usar como condicion 
     * */
    while(w.read(reinterpret_cast<char *>(&b), sizeof(Block<T>))){
        if(b.key == key && b.valid)
            break;
    }
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
