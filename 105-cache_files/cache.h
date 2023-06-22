#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>

using namespace std;

template <class T>
class CacheManager
{
    // members ( private )
    int capacity;
    map<string, pair<T, int>> cache_data; // < Clave , < Obj , Indice de Uso >>

    bool write_file(string, T);

public:
    CacheManager(int); // recibe la capacidad en el int
    ~CacheManager();

    void insert(string key, T obj);
    T get(string key);
    // Agregar todas las funciones necesarias
};

template <class T>
CacheManager<T>::CacheManager(int cap)
{
    capacity = cap;
}

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::write_file(string key, T obj)
{
    return true;
}

// INSERT
template <class T>
void CacheManager<T>::insert(string key, T obj)
{
}

template < class T >
T CacheManager <T >:: get ( string key )
{
}