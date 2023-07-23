#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <cstdio>
#define ARCHIVO "cache.dat"
#define ARCHIVO_AUX "aux.dat"

using namespace std;

template <class T>
class CacheManager
{
    size_t blockSize;
    int capacity;
    int MRU;
    map<string, pair<T, int>> cache_data; // < Clave , < Obj , Indice de Uso >>

public:
    CacheManager():MRU(0){}; // constructor default
    CacheManager(int cap): blockSize(sizeof(pair<string,T>)),capacity(cap),MRU(0){}; 
    ~CacheManager();

    void insert(const string& key,const T& obj);
    T get(const string& key);
    T getFromCache(const string& key);
    void showCache();
    bool writeFile(const string& indice,const T& objeto);
};

template <class T>
void CacheManager<T>::insert(const string& key,const T& obj)
{
    cache_data[key] = make_pair(obj,++MRU);

    if(cache_data.size() > (size_t)capacity){
        // si la memoria esta llena, tengo que matar al de MRU mas bajo
        auto it = cache_data.begin(); // iteradores
        auto aux = it;
        while(it != cache_data.end()){
            if(it->second.second < aux->second.second) 
                aux = it; 
            it++;
        }
        cache_data.erase(aux);
    }
}

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::writeFile(const string& key, const T& obj)
{
    pair<string,T> block(key,obj); // bloque a guardar en memoria
    pair<string,T> bPivot; // bloque para realizar operaciones
    ofstream w;
    ifstream r;
    r.open(ARCHIVO, ios::binary | ios::in);
    w.open(ARCHIVO_AUX, ios::app | ios::out);

    if(!(w && r)) return false;
    // si no se pudieron abrir, retorno false

    // copio todo el archivo en aux.dat excepto el bloque de cache que debo actualizar
    // agregandolo al final

    r.read(reinterpret_cast<char*>(&bPivot), blockSize);
    //while(r.read(reinterpret_cast<char*>(&bPivot), blockSize)){
    //    cout << "holas" << endl;
    //    if(bPivot.first != key)
    //        w.write(reinterpret_cast<char*>(&bPivot), blockSize);
    //}
    //w.write(reinterpret_cast<char*>(&block), blockSize);

    //w.close();
    //r.close();

    //remove(ARCHIVO);
    //rename(ARCHIVO_AUX,ARCHIVO);

    return true;
}


template < class T >
T CacheManager <T>:: get(const string& key)
{
    return cache_data[key].second.first;
}

template <class T>
T CacheManager <T>:: getFromCache(const string& key)
{
    ifstream w(ARCHIVO,ios::in | ios::binary);
    pair<string,T> bPivot;
    // read ya marca una lectura despues del EOF
    while(w.read(reinterpret_cast<char *>(&bPivot), blockSize)
            && bPivot.first != key){}
    w.close();
    // devuelvo por valor
    return bPivot.second;
}

template < class T >
void CacheManager <T >:: showCache()
{
    for(auto it = cache_data.begin(); it != cache_data.end(); it++)
        cout << it->first << it->second.second << endl;
}
