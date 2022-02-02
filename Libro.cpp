#include "Libro.hpp"

Libro::Libro() {
	isbn = 0;
	ano = 0;
	num_capitulos = 0;
	titulo = "NULL";
 	autores = "NULL";
    }
void Libro::leer() {
	cin >> isbn >> ano >> num_capitulos;
	getline(cin, titulo);
	getline(cin, titulo);
	getline(cin, autores);
        }
void Libro::mostrarCorto() {
	cout << titulo << ", " << autores << ", " << ano;
        }
void Libro::mostrarLargo(){
	cout << titulo << endl;
	cout << autores << ", " << ano << endl;
	cout << num_capitulos << " capítulos" << endl;
        }

int Libro::getNum_capitulos() {
    return num_capitulos;
}

long long Libro::getIsbn() {
	return isbn;
}