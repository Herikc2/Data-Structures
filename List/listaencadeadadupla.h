#ifndef LISTA_ENCADEADA_DUPLA
#define LISTA_ENCADEADA_DUPLA

template<typename T>
struct TElementoDupla {
    T dado;
    TElementoDupla<T> * anterior;
    TElementoDupla<T> * proximo;
};

template<typename T>
struct TListaDupla {
    TElementoDupla<T> * inicio;
    TElementoDupla<T> * fim;
};

template<typename T>
void inicializaListaDupla(TListaDupla<T> &l) {
    l.inicio = nullptr;
    l.fim = nullptr;
}

template<typename T>
int quantidadeElementosListaDupla(TListaDupla<T> l) {
    int cont = 0;
    TElementoDupla<T> *nav = l.inicio;
    while (nav != nullptr) {
        nav = nav->proximo;
        cont++;
    }
    return cont - 1;
}

template<typename T>
TElementoDupla<T>* criarNovoElementoDupla(T dado) {
    TElementoDupla<T> *N = new TElementoDupla<T>();
    N->proximo = nullptr;
    N->anterior = nullptr;
    N->dado = dado;
    return N;
}

#include <iostream>
using namespace std;

template<typename T>
TElementoDupla<T>* navegadorDupla(TListaDupla<T> l, int pos) {
    TElementoDupla<T> *nav = l.inicio;
    int i = 0;
    while (nav != nullptr && i < pos - 1) {
        nav = nav->proximo;
        i++;
    }
    return nav;
}

template<typename T>
bool insereListaDupla(TListaDupla<T> &l, T dado, int pos) {
    if (pos == 0) {
        TElementoDupla<T> *novo = criarNovoElementoDupla(dado);
        novo->proximo = l.inicio;
        l.inicio = novo;
        if (quantidadeElementosListaDupla(l) == 0)
            l.fim = novo;
        return true;
    }
    else {
        TElementoDupla<T> *nav = navegadorDupla(l, pos);
        if (nav == nullptr) {
            return false;
        }
        else {
            TElementoDupla<T> *novo = criarNovoElementoDupla(dado);
            novo->proximo = nav->proximo;
            novo->anterior = nav;

            nav->proximo = novo;
            if (novo->proximo != NULL)
                novo->proximo->anterior = novo;
            if (quantidadeElementosListaDupla(l) == pos)
                l.fim = novo;
            return true;
        }
    }
}

template<typename T>
bool removerListaDupla(TListaDupla<T> &l, int pos) {
    if (l.inicio == NULL)
        return false;
    if (pos == 0) {
        TElementoDupla<T> *removido = l.inicio;
        l.inicio = removido->proximo;
        if (removido->proximo != NULL)
            removido->proximo->anterior = NULL;
        delete removido;
        removido = NULL;
        return true;
    }
    else {
        TElementoDupla<T> *nav = navegadorDupla(l, pos);
        if (nav == nullptr)
            return false;
        else {
            TElementoDupla<T> *removido = nav->proximo;
            if (removido != NULL) {
                nav->proximo = removido->proximo;
                if (removido->proximo != NULL)
                    removido->proximo->anterior = nav;
                else
                    l.fim = removido->anterior;

                delete removido;
                removido = NULL;
                return true;
            }
        }
        return false;
    }
}

template<typename T>
TElementoDupla<T>* obtemDadoListaDupla(TListaDupla<T> l, int pos) {
    TElementoDupla<T> *nav = l.inicio;
    for (int i = 0; i <= quantidadeElementosListaDupla(l); i++) {
        if (i == pos)
            return nav;
        nav = nav->proximo;
    }
    return nav;
}

template<typename T>
void ImprimirListaDupla(TListaDupla<T> l) {
    for (TElementoDupla<T>* nav = l.inicio; nav != NULL; nav = nav->proximo)
        ImprimirElementoDupla(nav->dado);
}

template<typename T>
void ImprimirElementoDupla(T dado) {
    ImprimirElementoDupla(dado);
}

template<typename T>
void verificaExisteDupla(TListaDupla<T> l, T dado) {
    verificaExisteDupla(l, dado);
}

template<typename T>
void depurarListaDupla(TListaDupla<T> l) {
    cout << "Inicio: " << l.inicio << " - Fim: " << l.fim << endl;
    int i = 0;
    for (TElementoDupla<T>* nav = l.inicio; nav != NULL; nav = nav->proximo, i++) {
        cout << "Elemento[" << i << "]: " << nav << " - anterior: " << nav->anterior << " - prox: " << nav->proximo << endl;
    }
}

#include "vsf.h"

template<typename T>
void trocaEncadeadaDuplaDado(TElementoDupla<T>* elemento1, TElementoDupla<T>* elemento2) {
    trocaEncadeadaDado(elemento1, elemento2);
}

void trocaEncadeadaDuplaDado(TElementoDupla<VSF>* elemento1, TElementoDupla<VSF>* elemento2) {
    TElementoDupla<VSF> aux;
    aux.dado = elemento1->dado;
    elemento1->dado = elemento2->proximo->dado;
    elemento2->proximo->dado = aux.dado;
}

void BubbleSortEncadeadaDupla(TListaDupla<VSF> &l) {
    int quantidade = quantidadeElementosListaDupla(l);
    for (int i = 0; i < quantidade; i++) {
        for (TElementoDupla<VSF>* nav = l.inicio; nav != nullptr && nav->proximo != nullptr; nav = nav->proximo) {
            if (nav->dado.id > nav->proximo->dado.id) {
                TElementoDupla<VSF> aux;
                aux.dado = nav->dado;
                nav->dado = nav->proximo->dado;
                nav->proximo->dado = aux.dado;
            }
        }
    }
}

#endif // LISTA_ENCADEADA_DUPLA
