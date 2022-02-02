#ifndef ARBOL
#define ARBOL

#include "Nodo.hpp"
#include "Aparicion.hpp"
#include <iostream>
using namespace std;

class ArbolTrie {
    private:
        NodoTrie * raiz;
    public:
        ArbolTrie();
        ~ArbolTrie();
        void insertar (string cadena, Aparicion ap);
        list<Aparicion> *  buscar (string cadena);
};
#endif