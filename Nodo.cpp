#include "Nodo.hpp"

NodoTrie::NodoTrie() {
    sig = nullptr;
    ptr = nullptr;
    car = ' ';
}

NodoTrie::~NodoTrie() {
    delete ptr;
    delete sig;
}

list<Aparicion> * NodoTrie::getL() {
    return &l;
}

NodoTrie * NodoTrie::consulta(char letra) {
    NodoTrie *temporal = sig;
    while((temporal!=nullptr)&&(temporal->car<letra)) {
        temporal=temporal->sig;
    }
    if ((temporal!=nullptr)&&(temporal->car==letra)) {
        return temporal->ptr;
    }
    else return nullptr;
}

void NodoTrie::inserta(char l) {
    NodoTrie *temporal = this;

    while ((temporal->sig!=nullptr)&&(temporal->sig->car<l)) {
        temporal=temporal->sig;
    }    
    if ((temporal->sig==nullptr)||(temporal->sig->car!=l)) {
        NodoTrie *temporal2 = new NodoTrie();
        temporal2->car=l;
        temporal2->sig=temporal->sig;
        temporal2->ptr=new NodoTrie();
        temporal->sig=temporal2;
    }
}

bool NodoTrie::HayMarca() {
    return car=='$';
}

void NodoTrie::PonMarca() {
    car='$';
}

void NodoTrie::QuitaMarca() {
    car=' ';
}