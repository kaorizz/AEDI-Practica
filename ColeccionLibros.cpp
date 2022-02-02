#include "ColeccionLibros.hpp"

ColeccionLibros::ColeccionLibros() {
}

Libro * ColeccionLibros::insertar (Libro *nuevo) {
    return tabla.insertar(nuevo);
}

Libro * ColeccionLibros::consultar (long long isbn) {
    return tabla.consultar(isbn);
}

void ColeccionLibros::insertarPalabra (string cadena, Aparicion ap) {
    arbol.insertar(cadena, ap);
}

list<Aparicion> * ColeccionLibros::buscarPalabra (string cadena) {
    return arbol.buscar(cadena);
}