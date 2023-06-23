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


public:
    bool write_file(string indice, T objeto);
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
    cache_data[key] = make_pair(obj,++MRU);

    if(cache_data.size() > (size_t)capacity){
        // si la memoria esta llena, tengo que matar al de MRU mas bajo
        auto it = cache_data.begin(); // iteradores
        auto aux = it;
        auto indice = it->first;
        while(it != cache_data.end()){
            if(it->second.second < aux->second.second){
                aux = it; // hay que borrar aux
            }
            it++;
        }
        cache_data.erase(aux);
    }
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
    pair<string,T> *bloquePivot; // bloque a guardar en memoria
    pair<string,T> bloque(key,obj); // bloque a guardar en memoria
    ifstream archivoLectura("cache.dat", ios::in);
    ofstream archivoEscritura("cache.dat", ios::out);
    int auxiliar = 0;
    // ojo con que este escrito
    while(archivoLectura.read(reinterpret_cast<char *>(bloquePivot), sizeof(pair<string,T>))){
        if(bloquePivot->first == key){
            archivoEscritura.write(reinterpret_cast<char *>(&bloque), sizeof(pair<string,T>));
            auxiliar = 1;
        }
    }
    if(auxiliar == 0){
        archivoEscritura.write(reinterpret_cast<char *>(&bloque), sizeof(pair<string,T>));
    }
    archivoEscritura.close();
    archivoLectura.close();

    return true;
}


template < class T >
T& CacheManager <T >:: get( string key )
{
    return cache_data[key].second.first;
}
template < class T >
void CacheManager <T >:: showCache(){
    // key -- objeto
    for(auto it = cache_data.begin(); it != cache_data.end(); it++){
        cout << it->first << it->second.second << endl;
    }
}
