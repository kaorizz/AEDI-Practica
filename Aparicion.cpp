#include "Aparicion.hpp"

Aparicion::Aparicion(Libro *pl, int nc, int np) {
    this->pl=pl;
    num_capitulo=nc;
    num_parrafo=np;
}

void Aparicion::mostrar() {
    pl->mostrarCorto();
    cout << ", Cap. " << num_capitulo << ", par. " << num_parrafo << endl;
}

bool Aparicion::esMenor(Aparicion &otra) {
    if (pl->getIsbn()<otra.pl->getIsbn()|| (pl->getIsbn()==otra.pl->getIsbn()&&(num_capitulo<otra.num_capitulo||(num_capitulo==otra.num_capitulo&&num_parrafo<otra.num_parrafo)))) return true;
    return false;
}

bool Aparicion::esIgual(Aparicion &otra) {
    if (pl->getIsbn()==otra.pl->getIsbn() && num_capitulo==otra.num_capitulo && num_parrafo==otra.num_parrafo) return true;
    return false;
}