#ifndef LIBRO
#define LIBRO

#include <iostream>
using namespace std;

class Libro 
{
    private:
        long long isbn;
        int ano, num_capitulos;
        string titulo;
        string autores;
    public:
        Libro();
        void leer();
        void mostrarCorto();
        void mostrarLargo();
        int getNum_capitulos();
        long long getIsbn();
};
#endif