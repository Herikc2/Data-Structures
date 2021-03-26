#ifndef LISTA_H
#define LISTA_H

template<typename T>
struct TElemento {
    T dado;
    TElemento<T> * anterior;
    TElemento<T> * proximo;
};

template<typename T>
struct TLista {
    TElemento<T> * inicio;
    TElemento<T> * fim;
};

template<typename T>
void inicializaLista(TLista<T> &l){
    l.inicio=nullptr;
    l.fim=nullptr;
}

template<typename T>
int quantidadeElementosLista(TLista<T> l){
    int cont = 0;
    TElemento<T> *nav = l.inicio;
    while(nav!=nullptr){
        nav=nav->proximo;
        cont++;
    }
    return cont - 1;
}

template<typename T>
TElemento<T>* criarNovoElemento(T dado){
    TElemento<T> *N = new TElemento<T>();
    N->proximo = nullptr;
    N->anterior = nullptr;
    N->dado = dado;
    return N;
}

#include <iostream>
using namespace std;

template<typename T>
TElemento<T>* navegador(TLista<T> l, int pos){
    TElemento<T> *nav = l.inicio;
    int i=0;
    while(nav != nullptr && i < pos - 1){
        nav = nav->proximo;
        i++;
    }
    return nav;
}

template<typename T>
bool insereLista (TLista<T> &l, T dado, int pos){
    if(pos == 0){
        TElemento<T> *novo = criarNovoElemento(dado);
        novo->proximo = l.inicio;
        l.inicio = novo;
        if(quantidadeElementosLista(l) == 0)
            l.fim = novo;
        return true;
    }else{
        TElemento<T> *nav = navegador(l, pos);
        if(nav==nullptr){
             return false;
         }else{
            TElemento<T> *novo = criarNovoElemento(dado);
            novo->proximo=nav->proximo;
            novo->anterior=nav;

            nav->proximo = novo;
            if(novo->proximo != NULL)
                novo->proximo->anterior = novo;
            if(quantidadeElementosLista(l) == pos)
                l.fim = novo;
            return true;
        }
    }
}

template<typename T>
bool removerLista(TLista<T> &l, int pos){
    if(l.inicio==NULL)
        return false;
    if(pos == 0){
        TElemento<T> *removido = l.inicio;
        l.inicio = removido->proximo;
        if(removido->proximo != NULL)
            removido->proximo->anterior = NULL;
        delete removido;
        removido = NULL;
        return true;
    }else{
        TElemento<T> *nav = navegador(l, pos);
        if(nav==nullptr)
            return false;
        else{
            TElemento<T> *removido = nav->proximo;
            if(removido != NULL) {
                nav->proximo = removido->proximo;
                if(removido->proximo != NULL)
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
TElemento<T>* obtemDadoLista (TLista<T> l, int pos){
    TElemento<T> *nav = l.inicio;
    for(int i = 0; i <= quantidadeElementosLista(l); i++){
        if(i == pos)
            return nav;
        nav=nav->proximo;
    }
    return nav;
}

template<typename T>
void ImprimirLista(TLista<T> l) {
    for(TElemento<T>* nav = l.inicio; nav != NULL; nav = nav->proximo)
        ImprimirElemento(nav->dado);
}

template<typename T>
void ImprimirElemento(T dado) {
    ImprimirElemento(dado);
}

template<typename T>
void verificaExiste(TLista<T> l, T dado){
       verificaExiste(l,dado);
}

template<typename T>
void depurarLista(TLista<T> l) {
    cout << "Inicio: " << l.inicio << " - Fim: " << l.fim << endl;
    int i = 0;
    for(TElemento<T>* nav = l.inicio; nav != NULL; nav = nav->proximo, i++) {
        cout << "Elemento[" << i << "]: " << nav << " - anterior: " << nav->anterior << " - prox: " << nav->proximo << endl;
    }
}

#endif // LISTA_H
