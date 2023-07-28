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
    CacheManager() : MRU(0){}; // constructor default
    CacheManager(int cap) : blockSize(sizeof(pair<string, T>)), capacity(cap), MRU(0){};
    ~CacheManager();

    void insert(const string &key, const T &obj);
    T get(const string &key);
    T getFromMem(const string &key);
    void showCache();
    bool writeFile(const string &indice, const T &objeto);
};

template <class T>
void CacheManager<T>::insert(const string &key, const T &obj)
{
    cache_data[key] = make_pair(obj, ++MRU);

    if (cache_data.size() > (size_t)capacity)
    {
        // si la memoria esta llena, tengo que matar al de MRU mas bajo
        auto it = cache_data.begin(); // iteradores
        auto aux = it;
        while (it != cache_data.end())
        {
            if (it->second.second < aux->second.second)
                aux = it;
            it++;
        }
        cache_data.erase(aux);
    }
    writeFile(key, obj);
}

template <class T>
CacheManager<T>::~CacheManager() {}

template <class T>
bool CacheManager<T>::writeFile(const string &key, const T &obj)
{
    // bloque a guardar en memoria
    pair<string, T> block(key, obj);
    // bloque para realizar operaciones
    pair<string, T> bPivot;
    // primero leo el archivo para ver si ya existe la clave
    int numeroRenglo = 0;
    // abro el archivo para lectura, si no existe lo crea, si existe lo leo
    ifstream r(ARCHIVO, ios::in | ios::binary);
    if (!r.is_open())
    {
        // si no existe el archivo, lo creo
        ofstream w(ARCHIVO, ios::out | ios::binary);
        w.close();
        r.open(ARCHIVO, ios::in | ios::binary);
    }
    // read ya marca una lectura despues del EOF
    r.read(reinterpret_cast<char *>(&bPivot), blockSize);
    while (r.read(reinterpret_cast<char *>(&bPivot), blockSize))
    {
        if(bPivot.first == key)
        {
            break;
        }
        numeroRenglo++;
    }
    r.close();
    // si la clave ya existe, la sobreescribo
    if (bPivot.first == key)
    {
        // abro el archivo para escritura
        fstream w(ARCHIVO, ios::in | ios::out | ios::binary);
        // me posiciono en el renglon a sobreescribir
        w.seekp(numeroRenglo * blockSize);
        // escribo en el archivo
        w.write(reinterpret_cast<char *>(&block), blockSize);
        // cierro el archivo
        w.close();
        return true;
    }
    else
    {
        // agregar al final del archivo
        ofstream w(ARCHIVO, ios::app | ios::binary);
        w.write(reinterpret_cast<char *>(&block), blockSize);
        // escribo en el archivo un salto de linea
        w << endl;
        w.close();
        return true;
    }
}

template <class T>
T CacheManager<T>::get(const string &key)
{
    return cache_data[key].second.first;
}

template <class T>
T CacheManager<T>::getFromMem(const string &key)
{
    ifstream w(ARCHIVO, ios::in | ios::binary);
    pair<string, T> bPivot;
    // read ya marca una lectura despues del EOF
    w.read(reinterpret_cast<char *>(&bPivot), blockSize);
    while (w.read(reinterpret_cast<char *>(&bPivot), blockSize) && bPivot.first != key)
    {
    }
    w.close();
    // devuelvo por valor
    return bPivot.second;
}

template <class T>
void CacheManager<T>::showCache()
{
    for (auto it = cache_data.begin(); it != cache_data.end(); it++)
        cout << it->first << it->second.second << endl;
}

// template <class T>
// bool CacheManager<T>::writeFile(const string &key, const T &obj)
// {
//     pair<string, T> block(key, obj); // bloque a guardar en memoria
//     pair<string, T> bPivot;          // bloque para realizar operaciones

//     ifstream r(ARCHIVO, ios::in | ios::binary);
//     ofstream w(ARCHIVO_AUX, ios::out | ios::binary);

//     if (!(w && r))
//         return false;

//     // r.read(reinterpret_cast<char *>(&bPivot),blockSize);

//     // while (r.read(reinterpret_cast<char *>(&bPivot),blockSize))
//     // {
//     //     if(bPivot.first != key){
//     //         w.write(reinterpret_cast<char*>(&bPivot), blockSize);
//     //     }
//     // }

//     w.write(reinterpret_cast<char *>(&block), blockSize);
//     r.close();
//     w.close();

//     remove(ARCHIVO);
//     rename(ARCHIVO_AUX, ARCHIVO);

//     return true;
// }