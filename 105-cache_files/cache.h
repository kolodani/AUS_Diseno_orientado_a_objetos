#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#define ARCHIVO "cache.dat"

using namespace std;


template <class T>
class CacheManager
{
    int capacity;
    int MRU;
    map<string, pair<T, int>> cache_data; // < Clave , < Obj , Indice de Uso >>

    bool write_file(string indice, T objeto);

public:
    CacheManager():MRU(0){}; // constructor default
    CacheManager(int cap): capacity(cap),MRU(0){}; // recibe la capacidad en el int
    ~CacheManager();

    void insert(string key, T obj);
    T& get(string key);
    void showCache();
    // Agregar todas las funciones necesarias
};

// INSERT
template <class T>
void CacheManager<T>::insert(string key, T obj)
{
    cache_data[key] = make_pair(obj, MRU++); 
    // recordar que para meterlo en el map
    // el objeto debe tener constructor default

    if(cache_data.size() < (size_t)capacity){
        cache_data[key] = make_pair(obj,MRU++);
        return;
    }
    auto it = cache_data.begin(); // iteradores
    auto aux = it;
    while(it != cache_data.end()){
        if(aux->second.second < it->second.second){
            aux = it;
        }
        it++;
    }
    cache_data.erase(aux);
    cache_data[key] = make_pair(obj,MRU++);
    //write_file(key,obj);
}

//template <class T>
//CacheManager<T>::CacheManager(int cap)
//{
//    capacity = cap;
//    MRU = 0;
//}

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::write_file(string key, T obj)
{
    //pair<string,T> bloque(key,obj);
    //ifstream archivoBusqueda("./cache.dat", ios::in);
    return true;
}


template < class T >
T& CacheManager <T >:: get( string key )
{
    return cache_data[key].first;
}
template < class T >
void CacheManager <T >:: showCache(){
    // key -- objeto
    for(auto it = cache_data.begin(); it != cache_data.end(); it++){
        cout << it->first << endl;
    }
}
