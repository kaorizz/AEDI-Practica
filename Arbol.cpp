#include "Arbol.hpp"

ArbolTrie::ArbolTrie() {
    raiz = new NodoTrie();
}

ArbolTrie::~ArbolTrie() {
    delete raiz;
}


void ArbolTrie::insertar(string cadena, Aparicion ap) {
    int i=0;
    NodoTrie * posicion = raiz;
    while (cadena[i]!='\0') {
        if (posicion->consulta(cadena[i])==nullptr) {
            posicion->inserta(cadena[i]);
        }
        posicion=posicion->consulta(cadena[i]);
        i++;
    }
    posicion->PonMarca();
    
    list<Aparicion> * lista = posicion->getL();
    list<Aparicion>::iterator itLista = lista->begin();

    if(lista->empty()) {
        lista->push_front(ap);
    }
    else {
        while((itLista!=lista->end()&&(itLista->esMenor(ap)))) {
            itLista++;
        }
        if (itLista==lista->end()) {
            lista->push_back(ap);
        }
        else if (!itLista->esIgual(ap)) {
            lista->insert(itLista, ap);
        }
    }
}

list<Aparicion> * ArbolTrie::buscar(string cadena) {
    int i=0;
    NodoTrie * posicion = raiz;
    while(cadena[i]!='\0') {
        if (posicion->consulta(cadena[i])==nullptr) return nullptr;
        posicion=posicion->consulta(cadena[i]);
        i++;
    }
    if (posicion->HayMarca()) {
        return posicion->getL();
    }
    return nullptr;
}