#ifndef LISTA
#define LISTA

template<typename T>
struct TElemento {
    T dado;
    TElemento *prox;
};

template<typename T>
struct TLista{
    TElemento<T> *inicio;
};

template<typename T>
TElemento<T>* criarNovoElemento(T dado){
    TElemento<T> *N = new TElemento<T>();
    N->prox = nullptr;
    N->dado = dado;
    return N;
}

template<typename T>
int quantidadeElementosLista(TLista<T> l){
    int cont=0;
    TElemento<T> *nav = l.inicio;
    while(true){
        if(nav==nullptr)
            return cont;
        nav=nav->prox;
        cont++;
    }
}

template<typename T>
void inicializaLista(TLista<T> &l){
    l.inicio=nullptr;
}

template<typename T>
bool insereLista (TLista<T> &l, T dado, int pos){
    if(pos == 0){
        TElemento<T> *novo = criarNovoElemento(dado);
        novo->prox=l.inicio;
        l.inicio=novo;
    }else{
        TElemento<T> *nav = l.inicio;
        int i=0;
        while(nav != nullptr && i < pos - 1){
            nav=nav->prox;
            i++;
        }
        if(nav==nullptr){
             return false;
         }
        else{
            TElemento<T> *novo = criarNovoElemento(dado);
            novo->prox=nav->prox;
            nav->prox=novo;
            return true;
        }
    }
}

template<typename T>
bool removeLista (TLista<T> &l, T dado, int pos){
    if(pos == 0)
    {
        TElemento<T> *removido = l.inicio;
        l.inicio = removido->prox;
        delete removido;
        removido = nullptr;
    }
    else
    {
        TElemento<T> *nav = l.inicio;
        int i=0;
        while(nav != nullptr && i < pos - 1){
            nav=nav->prox;
            i++;
        }
        if(nav==nullptr)
            return false;
        else{
             TElemento<T> *removido = nav->prox;
             nav->prox=removido->prox;
             delete removido;
             removido = nullptr;
        }
    }
}

template<typename T>
TElemento<T>* obtemDadoLista (TLista<T> l, int pos){
    TElemento<T> *nav = l.inicio;
    for(int i = 0; i < quantidadeElementosLista(l); i++){
        if(i == pos)
            return nav;
        nav=nav->prox;
    }
    return nav;
}

template<typename T>
void ImprimirLista(TLista<T> l) {
    for(TElemento<T>* nav = l.inicio; nav != nullptr; nav = nav->proximo)
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

#endif LISTA
