#ifndef FUNCIONES
#define FUNCIONES

#include <sstream>
#include "Aparicion.hpp"
#include "ColeccionLibros.hpp"

string normalizar(string cadena);
void LeerContenido(Libro nuevo);
void procesarInsertar();
void procesarConsulta();
void buscarAND();
void buscarOR();

void Interprete(char comando);

#endif