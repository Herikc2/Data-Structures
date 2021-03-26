#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#include <iostream>
#include "stdlib.h"
#include "string"
#include "vsf.h"

using namespace std;

template<typename T>
struct TElementoEncadeada {
    T dado;
    TElementoEncadeada *prox;
};

template<typename T>
struct TListaEncadeada {
    TElementoEncadeada<T> *inicio;
};

template<typename T>
void verificaExisteEncadeada(TListaEncadeada<T> l, T* dado);
template<typename T>
TElementoEncadeada<T>* navegadorEncadeadaAnterior(TListaEncadeada<T> l, int pos);
template<typename T>
int descobreIndiceEncadeada(TListaEncadeada<T> l, TElementoEncadeada<T> e);
template<typename T>
bool insereListaEncadeada(TListaEncadeada<T> &l, T dado, int pos);
template<typename T>
void BubbleSortEncadeada(TListaEncadeada<T> &l);

template<typename T>
TElementoEncadeada<T>* criarNovoElementoEncadeada(T dado) {
    TElementoEncadeada<T> *N = new TElementoEncadeada<T>();
    N->prox = nullptr;
    N->dado = dado;
    return N;
}

template<typename T>
int quantidadeElementosListaEncadeada(TListaEncadeada<T> l) {
    int cont = 0;
    TElementoEncadeada<T> *nav = l.inicio;
    while (true) {
        if (nav == nullptr)
            return cont;
        nav = nav->prox;
        cont++;
    }
}

template<typename T>
TElementoEncadeada<T>* navegadorEncadeadaAnterior(TListaEncadeada<T> l, int pos) {
    if (pos >= 0) {
        TElementoEncadeada<T> *nav = l.inicio;
        int i = 0;
        while (nav != nullptr && i < pos - 1) {
            nav = nav->prox;
            i++;
        }
        return nav;
    }
    return NULL;
}

template<typename T>
TElementoEncadeada<T>* navegadorEncadeadaAtual(TListaEncadeada<T> l, int pos) {
    if (pos >= 0) {
        TElementoEncadeada<T> *nav = l.inicio;
        for (int i = 0; i < pos && i <quantidadeElementosListaEncadeada(l); i++) {
            nav = nav->prox;
        }
        return nav;
    }
    return NULL;
}

template<typename T>
void inicializaListaEncadeada(TListaEncadeada<T> &l) {
    l.inicio = nullptr;
}

template<typename T>
bool insereListaEncadeada(TListaEncadeada<T> &l, T dado, int pos) {
    if (pos == 0) {
        TElementoEncadeada<T> *novo = criarNovoElementoEncadeada(dado);
        novo->prox = l.inicio;
        l.inicio = novo;
        return true;
    }
    else {
        TElementoEncadeada<T> *nav = l.inicio;
        int i = 0;
        while (nav != nullptr && i < pos - 1) {
            nav = nav->prox;
            i++;
        }
        if (nav == nullptr) {
            return false;
        }
        else {
            TElementoEncadeada<T> *novo = criarNovoElementoEncadeada(dado);
            novo->prox = nav->prox;
            nav->prox = novo;
            return true;
        }
    }
}

template<typename T>
bool removeListaEncadeada(TListaEncadeada<T> &l, T dado, int pos) {
    if (pos == 0)
    {
        TElementoEncadeada<T> *removido = l.inicio;
        l.inicio = removido->prox;
        delete removido;
        removido = nullptr;
    }
    else
    {
        TElementoEncadeada<T> *nav = navegadorEncadeadaAnterior(l, pos);
        if (nav == nullptr)
            return false;
        else {
            TElementoEncadeada<T> *removido = nav->prox;
            nav->prox = removido->prox;
            delete removido;
            removido = nullptr;
        }
    }
}

template<typename T>
TElementoEncadeada<T>* obtemDadoListaEncadeada(TListaEncadeada<T> l, int pos) {
    TElementoEncadeada<T> *nav = l.inicio;
    for (int i = 0; i < quantidadeElementosListaEncadeada(l); i++) {
        if (i == pos)
            return nav;
        nav = nav->prox;
    }
    return nav;
}

template<typename T>
void ImprimirElementoEncadeada(T dado) {
    ImprimirElementoEncadeada(dado);
}

template<typename T>
void ImprimirListaEncadeada(TListaEncadeada<T> l) {
    for (TElementoEncadeada<T>* nav = l.inicio; nav != nullptr; nav = nav->prox)
        ImprimirElementoEncadeada(nav->dado);
}

template<typename T>
void verificaExisteEncadeada(TListaEncadeada<T> l, T dado) {
    verificaExisteEncadeada(l, dado);
}

template<typename T>
int descobreIndiceEncadeada(TListaEncadeada<T> l, TElementoEncadeada<T> e) {
    int i = 0;
    for (TElementoEncadeada<T>* nav = l.inicio; nav != nullptr; nav = nav->prox, i++)
        if (verificaExisteEncadeada(*nav, e))
            return i;
    return -1;
}

template<typename T>
void trocaEncadeadaEndereco(TListaEncadeada<T> &l, TElementoEncadeada<T>* elemento1, TElementoEncadeada<T>* elemento2, int pos1, int pos2) {
    if (pos1 == 0) {
        TElementoEncadeada<T>* navA = navegadorEncadeadaAnterior(l, pos1);
        TElementoEncadeada<T>* navB = navegadorEncadeadaAnterior(l, pos2);
        TElementoEncadeada<T>* indexA = elemento1;
        TElementoEncadeada<T>* indexB = elemento2;

        TElementoEncadeada<T>* navX = indexB->prox;
        cout << "Endereco navX: " << endl << navX << endl;
        navA->prox = indexB;
        cout << "Endereco navA->prox: " << endl << navA->prox << endl;
        cout << "Endereco indexA->prox: " << endl << indexA->prox << endl;
        indexB->prox = indexA->prox;
        cout << "Endereco indexB->prox: " << endl << indexB->prox << endl;
        l.inicio = elemento2;
        cout << "Endereco l.inicio: " << endl << l.inicio << endl;

        navB->prox = indexA;
        cout << "Endereco navB->prox: " << endl << navB->prox << endl;
        indexA->prox = navX;
        cout << "Endereco indexA->prox: " << endl << indexA->prox << endl;
    }
    else {
        TElementoEncadeada<T>* navA = navegadorEncadeadaAnterior(l, pos1);
        TElementoEncadeada<T>* navB = navegadorEncadeadaAnterior(l, pos2);
        TElementoEncadeada<T>* indexA = navA->prox;
        TElementoEncadeada<T>* indexB = navB->prox;

        TElementoEncadeada<T>* navX = indexB->prox;
        navA->prox = indexB;
        indexB->prox = indexA->prox;

        navB->prox = indexA;
        indexA->prox = navX;
    }
}

template<typename T>
void trocaEncadeadaDado(TElementoEncadeada<T>* elemento1, TElementoEncadeada<T>* elemento2) {
    trocaEncadeadaDado(elemento1, elemento2);
}

void BubbleSortEncadeada(TListaEncadeada<VSF> &l) {
    int quantidade = quantidadeElementosListaEncadeada(l);
    for (int i = 0; i < quantidade - 1; i++) {
        for (TElementoEncadeada<VSF>* nav = l.inicio; nav != nullptr && nav->prox != nullptr; nav = nav->prox) {
            if (nav->dado.id > nav->prox->dado.id) {
                TElementoEncadeada<VSF> aux;
                aux.dado = nav->dado;
                nav->dado = nav->prox->dado;
                nav->prox->dado = aux.dado;
            }
        }
    }
}

#endif // LISTA_ENCADEADA
