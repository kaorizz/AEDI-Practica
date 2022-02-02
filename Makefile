a.out: Libro.o ColeccionLibros.o Funciones.o Aparicion.o HashLibros.o Nodo.o Arbol.o Main.o
	g++ Libro.o ColeccionLibros.o Funciones.o Aparicion.o HashLibros.o Nodo.o Arbol.o Main.o

Libro.o: Libro.cpp Libro.hpp
	g++ -c Libro.cpp

ColeccionLibros.o: ColeccionLibros.cpp ColeccionLibros.hpp HashLibros.hpp Arbol.hpp
	g++ -c ColeccionLibros.cpp
	
Funciones.o: Funciones.cpp Funciones.hpp Aparicion.hpp ColeccionLibros.hpp
	g++ -c Funciones.cpp
	
Aparicion.o: Aparicion.cpp Aparicion.hpp Libro.hpp
	g++ -c Aparicion.cpp
	
HashLibros.o: HashLibros.cpp HashLibros.hpp Libro.hpp
	g++ -c HashLibros.cpp
	
Nodo.o: Nodo.cpp Nodo.hpp Aparicion.hpp
	g++ -c Nodo.cpp
	
Arbol.o: Arbol.cpp Arbol.hpp Nodo.hpp
	g++ -c Arbol.cpp

Main.o: Main.cpp Funciones.hpp
	g++ -c Main.cpp
