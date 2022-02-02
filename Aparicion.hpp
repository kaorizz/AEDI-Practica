#ifndef APARICION
#define APARICION

#include "Libro.hpp"

class Aparicion {
    private:
        Libro * pl;
        int num_capitulo;
        int num_parrafo;
    public:
        Aparicion(Libro *pl, int num_capitulo, int num_parrafo);
        void mostrar();
        bool esMenor (Aparicion &otra);
        bool esIgual (Aparicion &otra);
};
#endif