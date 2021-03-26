#ifndef MUSICA_H
#define MUSICA_H

#include <iostream>
#include "lista.h"

#define NUM_MUSICAS 10

using namespace std;

struct Musica{
    string nome;
};

void ImprimirElemento(Musica m) {
    cout << m.nome.c_str() << endl;
}

bool verificaExiste(TLista<Musica> l, Musica m){
    for(TElemento<Musica>* nav = l.inicio; nav != nullptr; nav = nav->prox)
        if(nav->dado.nome == m.nome)
            return true;
    return false;
}


#endif // MUSICA_H
