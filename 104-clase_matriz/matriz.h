#ifndef __MATRIZ_H
#define __MATRIZ_H

template <class T>
class matriz
{
    T **m;
    unsigned xmax, ymax;

public:
    matriz(const matriz &mm);
    matriz(unsigned xmax, unsigned ymax);
    ~matriz();
    unsigned maxx() const
    {
        return xmax;
    }
    unsigned maxy() const
    {
        return ymax;
    }
    T *operator[](unsigned y) const {
        return m[y];
    }
};

// metodos de matriz
template <class T>
matriz<T>::matriz(const matriz<T> &mm)
{
    unsigned i, j;
    xmax = mm.xmax;
    ymax = mm.ymax;
    m = new T *[ymax];
    for (i = 0; i < ymax; i++)
        m[i] = new T[xmax];
    for (i = 0; i < ymax; i++)
        for (j = 0; j < xmax; j++)
            m[i][j] = mm.m[i][j];
}

template <class T>
matriz<T>::matriz(unsigned x, unsigned y)
{
    unsigned i;
    xmax = x;
    ymax = y;
    m = new T *[ymax];
    for (i = 0; i < ymax; i++)
        m[i] = new T[xmax];
}

template <class T>
matriz<T>::~matriz()
{
    unsigned i;
    for (i = 0; i < ymax; i++)
        delete[] m[i];
    delete[] m;
}

// operadores de matriz
template <class T>
ostream &operator<<(ostream &os, const matriz<T> &mm)
{
    unsigned i, j;
    for (i = 0; i < mm.ymax; i++)
    {
        for (j = 0; j < mm.xmax; j++)
            os << mm[i][j] << ' ';
        os << '\n';
    }
    return os;
}

template <class T>
istream &operator>>(istream &is, matriz<T> &mm)
{
    unsigned i, j;
    for (i = 0; i < mm.ymax; i++)
        for (j = 0; j < mm.xmax; j++)
            is >> mm[i][j];
    return is;
}


#endif