#include "Funciones.hpp"

ColeccionLibros dic;

string normalizar(string cadena) {
        string salida;

        for(unsigned i=0;i<cadena.length();i++){
            if ((cadena[i]>='a') && (cadena[i]<='z')) {
                salida+=cadena[i];
            }
            else if ((cadena[i]>='A') && (cadena[i]<='Z')) {
                salida+=towlower(cadena[i]);
            }
            else if (cadena[i]==(char)0xC3) {
                if ((cadena[i+1]==(char)0x81) || (cadena[i+1]==(char)0xA1)) {
                    salida+='a';
                }
                else if ((cadena[i+1]==(char)0x89) || (cadena[i+1]==(char)0xA9)) {
                    salida+='e';
                }
                else if ((cadena[i+1]==(char)0x8D) || (cadena[i+1]==(char)0xAD)) {
                    salida+='i';
                }
                else if ((cadena[i+1]==(char)0x93) || (cadena[i+1]==(char)0xB3)) {
                    salida+='o';
                }
                else if ((cadena[i+1]==(char)0x9A) || (cadena[i+1]==(char)0xBA) || (cadena[i+1]==(char)0x9C) || (cadena[i+1]==(char)0xBC)) {
                    salida+='u';
                }
                else if ((cadena[i+1]==(char)0x91) || (cadena[i+1]==(char)0xB1)) {
                    salida+=(char)0xC3;
                    salida+=(char)0xB1;
                }
                else salida+=' ';
                i++;
            }
            else salida+=' ';
        }
        return salida;
    }

void LeerContenido(Libro *nuevo) {
    
    int num_capitulo=1;
    int verparrafo=0;
    int num_parrafos=0;
    int num_palabras=0;
    int nparrafo=1;
    while (num_capitulo<=nuevo->getNum_capitulos()) {
        string cadena;
        getline(cin, cadena);
        cadena=normalizar(cadena);
        istringstream iss(cadena);
        string palabra;
        while(iss>>palabra) {
            if (palabra=="findecapitulo") {
                num_capitulo+=1;
                num_parrafos+=1;
                nparrafo=1;
                verparrafo=0;
            }
            else {
                verparrafo=0;
                num_palabras+=1;
                Aparicion aparicionpalabra = Aparicion(nuevo, num_capitulo, nparrafo);
                dic.insertarPalabra(palabra, aparicionpalabra);
            }
        }
        verparrafo++;
        if (verparrafo==2) {
            num_parrafos+=1;
            nparrafo+=1;
        }
    }
    nuevo->mostrarLargo();
    cout << num_parrafos << " párrafos" << endl;
    cout << num_palabras << " palabras" << endl;
}


void procesarInsertar() {
    Libro *libro = new Libro;
    libro->leer();
    LeerContenido(dic.insertar(libro));
}

void procesarConsulta() {
    long long isbn;
    cin >> isbn;
    Libro *pl = dic.consultar(isbn);
    if (pl==NULL) cout << "ISBN " << isbn << " no encontrado" << endl;
    else {
        cout << "ISBN " << isbn << " encontrado" << endl;
        pl->mostrarLargo();
    }
}

void buscarAND() {

    string cadenaelegida;
    getline(cin.ignore(), cadenaelegida);
    cadenaelegida = normalizar(cadenaelegida);
    list<Aparicion> * lista = dic.buscarPalabra(cadenaelegida);
    cout << "a " << cadenaelegida << endl;
    if (lista!=nullptr) {
        list<Aparicion>::iterator itLista = lista->begin();
        int tamano = lista->size();
        int napariciones=0;
        cout << "Total: " << tamano << " resultados" << endl;
        while(itLista!=lista->end()) {
            napariciones+=1;
            cout << napariciones << ". ";
            itLista->mostrar();
            itLista++;
        }
    }
    else cout << "Total: 0 resultados" << endl;
}

void buscarOR() {

    string cadenaelegida;
    getline(cin.ignore(), cadenaelegida);
    cadenaelegida = normalizar(cadenaelegida);
    list<Aparicion> * lista = dic.buscarPalabra(cadenaelegida);
    cout << "o " << cadenaelegida << endl;
    if (lista!=nullptr) {
        list<Aparicion>::iterator itLista = lista->begin();
        int tamano = lista->size();
        int napariciones=0;
        cout << "Total: " << tamano << " resultados" << endl;
        while(itLista!=lista->end()) {
            napariciones+=1;
            cout << napariciones << ". ";
            itLista->mostrar();
            itLista++;
        }
    }
    else cout << "Total: 0 resultados" << endl;
}

void Interprete(char comando) {
    if (comando == 'i') {
        procesarInsertar();
    }
    else if (comando == 'c') {
        procesarConsulta();
    }
    else if (comando == 'a') {
        buscarAND();
    }
    else if (comando == 'o') {
        buscarOR();
    }
}