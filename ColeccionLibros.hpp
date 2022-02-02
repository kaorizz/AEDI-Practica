#ifndef COLECCIONLIBROS
#define COLECCIONLIBROS

#include "HashLibros.hpp"
#include "Arbol.hpp"

class ColeccionLibros {
    private:
        HashLibros tabla;
        ArbolTrie arbol;
    public:
        ColeccionLibros ();
        Libro * insertar (Libro *nuevo);
        Libro * consultar (long long isbn);
        void insertarPalabra (string cadena, Aparicion ap);
        list <Aparicion> * buscarPalabra (string cadena);
};

#endif