#ifndef LISTA_ESTATICA
#define LISTA_ESTATICA

#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include "string"
using namespace std;

template<typename TIPO>
struct TElementoEstatica {
    TIPO dado;
};

template<typename T, int MAX>
struct TListaEstatica {
    TElementoEstatica<T> elementos[MAX];
    int quantidade;
};


template<typename TIPO, int MAX>
void inicializaEstatica(TListaEstatica<TIPO, MAX> &l) {
    l.quantidade = 0;
}

template<typename TIPO, int MAX>
void InsereListaInicioEstatica(TListaEstatica<TIPO, MAX> &l, TIPO dado) {
    TElementoEstatica<TIPO> elemento;
    elemento.dado = dado;
    for (int i = l.quantidade; i >= 0; i--)
        l.elementos[i + 1] = l.elementos[i];
    l.elementos[0] = elemento;
    l.quantidade++;
}
template<typename TIPO, int MAX>
void InsereListaFimEstatica(TListaEstatica<TIPO, MAX> &l, TIPO dado) {

    if (l.quantidade > MAX) {
        throw "Lista cheia - nao pode inserir";
    }
    TElementoEstatica<TIPO> elemento;
    elemento.dado = dado;

    l.elementos[l.quantidade] = elemento;
    l.quantidade++;
}
template<typename TIPO, int MAX>
void InsereListaPosEstatica(TListaEstatica<TIPO, MAX> &l, TIPO dado, int pos) {

    if (l.quantidade > MAX) {
        throw "Lista cheia - nao pode inserir";
    }
    TElementoEstatica<TIPO> elemento;
    elemento.dado = dado;
    for (int i = l.quantidade; i >= pos; i--)
        l.elementos[i + 1] = l.elementos[i];
    l.elementos[pos] = elemento;
    l.quantidade++;
}

template<typename TIPO, int MAX>
void RemoveListaInicioEstatica(TListaEstatica<TIPO, MAX> &l) {
    for (int i = 1; i <= l.quantidade; i++)
        l.elementos[i - 1] = l.elementos[i];
    l.quantidade--;
}
template<typename TIPO, int MAX>
void RemoveListaFimEstatica(TListaEstatica<TIPO, MAX> &l) {
    if (l.quantidade == 0) {
        throw "Lista vazia";
    }
    else {
        l.quantidade--;
    }

}
template<typename TIPO, int MAX>
void RemoveListaPosEstatica(TListaEstatica<TIPO, MAX> &l, int pos) {
    if (l.quantidade == 0) {
        throw "Lista vazia";
    }
    for (int i = pos + 1; i <= l.quantidade; i++)
        l.elementos[i - 1] = l.elementos[i];
    l.quantidade--;
}

template<typename TIPO, int MAX>
bool PertenceListaEstatica(TListaEstatica<TIPO, MAX> &l, TIPO dado) {
    for (int i = 0; i <= l.quantidade; i++)
        if (VerificaIgualEstatica(l.elementos[i].dado, dado))
            return true;
    return false;
}

template<typename TIPO>
bool VerificaIgualEstatica(TIPO dado1, TIPO dado2) {
    return VerificaIgualEstatica(dado1, dado2);
}

template<typename TIPO, int MAX>
TElementoEstatica<TIPO> ObtemListaEstatica(TListaEstatica<TIPO, MAX> l, int pos) {
    return l.elementos[pos];
}

template<typename TIPO, int MAX>
int DescobrirIndiceEstatica(TListaEstatica<TIPO, MAX> l, TIPO dado) {
    for (int i = 0; i <= l.quantidade; i++)
        if (VerificaIgualEstatica(l.elementos[i].dado, dado))
            return i;
    return -1;
}

#include <iostream>
template<typename TIPO, int MAX>
void ImprimirListaEstatica(TListaEstatica<TIPO, MAX> l) {
    //std::cout << "Quantidade: " << l.quantidade << std::endl;
    for (int i = 0; i < l.quantidade; i++)
        ImprimirElementoEstatica(l.elementos[i].dado);
}

template<typename TIPO>
void ImprimirElementoEstatica(TIPO dado) {
    ImprimirElementoEstatica(dado);
}

template<typename TIPO, int MAX>
void BubbleSortEstatica(TListaEstatica<TIPO, MAX> &l) {
    for (int i = 0; i < l.quantidade; i++) {
        for (int j = 0; j < l.quantidade - 1; j++) {
            if (l.elementos[j].dado.id > l.elementos[j + 1].dado.id) {
                TElementoEstatica<TIPO> aux;
                aux.dado = l.elementos[j].dado;
                l.elementos[j].dado = l.elementos[j + 1].dado;
                l.elementos[j + 1].dado = aux.dado;
            }
        }
    }
}

#endif //LISTA_ESTATICA
