#ifndef HASHLIBROS
#define HASHLIBROS

#include "Libro.hpp"
#include <list>

class HashLibros {
    private:
        int M = 131;
        int nElem;
        list<Libro*> *T;
    public:
        HashLibros();
        ~HashLibros();
        Libro * insertar (Libro *nuevo);
        Libro * consultar (long long isbn);
        int getNElem (void);
        void reestructuracion();
};

#endif