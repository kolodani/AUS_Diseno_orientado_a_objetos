#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#define ARCHIVO "cache.dat"

using namespace std;

template <class T>
class Registro{
    T objeto;
    string indice;
public:
    Registro(string ix,T obj){
        objeto=obj;
        indice=ix;
    };
    ~Registro(){};
};


template <class T>
class CacheManager
{
    // members ( private )
    int capacity;
    int MRU;
    map<string, pair<T, int>> cache_data; // < Clave , < Obj , Indice de Uso >>

    bool write_file(string indice, T objeto);

public:
    CacheManager(int); // recibe la capacidad en el int
    ~CacheManager();

    void insert(string key, T obj);
    T get(string key);
    // Agregar todas las funciones necesarias
};

// INSERT
template <class T>
void CacheManager<T>::insert(string key, T obj)
{
    if(cache_data.size() < capacity){
        // reemplazar si existe, si no agregar
        cache_data[key] = make_pair(obj,MRU++);
        write_file(key,obj);
        return;
    }
    auto it = cache_data.begin(); // iteradores
    auto aux = it;
    while(it != cache_data.end()){
        if(aux->second < it->second){
            aux = it;
        }
        it++;
    }
    cache_data.erase(aux);
    cache_data[key] = make_pair(obj,MRU++);
    write_file(key,obj);
}

template <class T>
CacheManager<T>::CacheManager(int cap)
{
    capacity = cap;
    MRU = 0;
}

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::write_file(string key, T obj)
{
    // cambiar el registro si existe, pisarlo
    Registro reg(key,obj);
    ofstream archivo("./cache.dat", ios::app);
    archivo.write(reinterpret_cast<char *>(&reg), sizeof(reg));
    archivo.close();
    return true;
}


template < class T >
T CacheManager <T >:: get( string key )
{

}
