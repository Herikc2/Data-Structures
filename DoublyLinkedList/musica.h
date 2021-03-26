#ifndef MUSICA_H
#define MUSICA_H

#include <iostream>
#include "string"
#include "lista.h"

#define NUM_MUSICAS 3

using namespace std;

struct Musica {
    string nome;
};

void ImprimirElemento(Musica m) {
    cout << m.nome << endl;
}

bool verificaExiste(TLista<Musica> l, Musica m){
    for(TElemento<Musica>* nav = l.inicio; nav != nullptr; nav = nav->proximo)
        if(nav->dado.nome == m.nome)
            return true;
    return false;
}

#endif // MUSICA_H
