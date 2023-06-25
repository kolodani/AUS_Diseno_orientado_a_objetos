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
    T& getFromCache( string key, T obj);
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
        while(it != cache_data.end()){
            if(it->second.second < aux->second.second){
                aux = it; // hay que borrar aux
            }
            it++;
        }
        cache_data.erase(aux);
    }
}

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::write_file(string key, T obj)
{
    // streampos -> tipo de dato para guardar posiciones de punteros de streams (archivos)
    // tellp -> dice la posicion en output stream (escritura)
    // tellg -> dice la posicion en input stream (lectura)
    // seekp -> el output stream se posiciona en ese puntero
    // seekg -> el input stream se posiciona en ese puntero

    pair<string,T> bloque(key,obj); // bloque a guardar en memoria
    pair<string,T> *bloquePivot = nullptr; // bloque a guardar en memoria
    ifstream lec("cache.dat",ios::in);
    ofstream esc("cache.dat",ios::out);
    streampos pEscritura;

    if(!lec || !esc) return false;
    
    do{
        pEscritura = lec.tellg();
        lec.read(reinterpret_cast<char *>(bloquePivot), sizeof(pair<string,T>));
        // leo hasta encontrar el objeto, si no lo encuentro,salgo en eof
        if(bloquePivot && bloquePivot->first == key) // leo solo si hay algo en el bloque
            break;
    }while(!lec.eof());
    lec.close();

    // escribo en eof o en el objeto, depende si encontre la key o no
    esc.seekp(pEscritura);
    esc.write(reinterpret_cast<char *>(&bloque), sizeof(bloque));
    esc.close();

    return true;
}


template < class T >
T& CacheManager <T >:: get( string key )
{
    return cache_data[key].second.first;
}

template <class T>
T& CacheManager <T >:: getFromCache( string key, T obj)
{
    ifstream lec("cache.dat",ios::binary);
    pair<string,T> *bloquePivot = nullptr;
    while(lec.read(reinterpret_cast<char *>(bloquePivot), sizeof(pair<string,T>))){
        cout << "droga" << endl;
        if(bloquePivot && bloquePivot->first == key){
            return bloquePivot->second;
        }
    }
    return bloquePivot->second;
}
template < class T >
void CacheManager <T >:: showCache(){
    // key -- objeto
    for(auto it = cache_data.begin(); it != cache_data.end(); it++){
        cout << it->first << it->second.second << endl;
    }
}
