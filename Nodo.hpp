#ifndef NODO
#define NODO

#include <list>
#include "Aparicion.hpp"

class NodoTrie {
    private:
        char car;
        NodoTrie *sig, *ptr;
        list<Aparicion> l;
    public:
        NodoTrie();
        ~NodoTrie();
        list<Aparicion> * getL();
        NodoTrie *consulta (char letra);
        void inserta (char l);
        bool HayMarca();
        void PonMarca();
        void QuitaMarca();
};
#endif