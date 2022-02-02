#include "HashLibros.hpp"

HashLibros::HashLibros(){
    T = new list<Libro*>[M];
}

HashLibros::~HashLibros(){
    delete [] T;
}

Libro * HashLibros::insertar(Libro *nuevo) {
    int key;
    key = nuevo->getIsbn() % M;
    list<Libro*>::iterator itLista = T[key].begin();
        if(T[key].empty()) {
            T[key].push_front(nuevo);
            nElem+=1;
            }
        else {
            while((itLista!=T[key].end()&&((*itLista)->getIsbn()<nuevo->getIsbn()))) {
            itLista++;
            }
            if (itLista==T[key].end()) {
            T[key].push_back(nuevo);
            nElem+=1;
            }
            else if (nuevo->getIsbn()<(*itLista)->getIsbn()) {
            T[key].insert(itLista, nuevo);
            nElem+=1;
            }
        }
    if (0.7*M<=nElem) {
        reestructuracion();
    }
    return nuevo;
}

Libro * HashLibros::consultar(long long isbn) {
    int key;
    key = isbn % M;
    int i=0;
    while((key!=i)&&(i<M)) {
        i++;
    }
    if (key==i) {
        list<Libro*>::iterator itLista = T[i].begin();
        while((itLista!=T[i].end())&&((*itLista)->getIsbn()<=isbn)) {
            if ((*itLista)->getIsbn()==isbn) return &(*(*itLista));
            itLista++;
        }
    }
    return NULL;
}

void HashLibros::reestructuracion() {

    int tamoriginal = M;  
    M = 1+M*2;
    int i=0;
    list<Libro*> *tablaaux = new list<Libro*>[M];
    list<Libro*>::iterator itListaoriginal;
    list<Libro*>::iterator itListatablaaux;

    while(i<tamoriginal) {
        itListaoriginal = T[i].begin();

        while (itListaoriginal!=T[i].end()) {
            int key = (*itListaoriginal)->getIsbn()%M;
            if (tablaaux[key].empty()) {
                tablaaux[key].push_front(*itListaoriginal);
            }
            else {
                itListatablaaux = tablaaux[key].begin();
                while ((itListatablaaux!=tablaaux[key].end())&&((*itListatablaaux)->getIsbn()<(*itListaoriginal)->getIsbn())) {
                    itListatablaaux++;
                }
                if (itListatablaaux==tablaaux[key].end()) {
                    tablaaux[key].push_back(*itListaoriginal);
                }
                else if ((*itListaoriginal)->getIsbn()<(*itListatablaaux)->getIsbn()) {
                    tablaaux[key].insert(itListatablaaux, *itListaoriginal);
                }
            }
            itListaoriginal++;
        }
        i++;
    }
    delete[] T;
    T = tablaaux;
}