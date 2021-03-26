#include <iostream>
#include "string"
#include "lista.h"
#include "musica.h"

#define NUM_MUSICAS 3

using namespace std;

int main()
{
    Musica musica[NUM_MUSICAS];
    TLista<Musica> playlist;

    inicializaLista(playlist);

    musica[0].nome="Musica 0";
    musica[1].nome="Musica 1";
    musica[2].nome="Musica 2";

    for(int i=0; i<NUM_MUSICAS;i++){
        insereLista(playlist, musica[i], i);
    }

    cout << "Lista Completa: " << endl;
    TElemento<Musica> * elem = obtemDadoLista(playlist,0);
    if(elem != nullptr) {
        cout << "Primeiro elemento: " << elem->dado.nome <<  endl;
    } else {
        cout << "Ta retornando NULO" << endl;
    }

    elem = obtemDadoLista(playlist,1);
    if(elem != nullptr) {
        cout << "Segundo elemento: " << elem->dado.nome <<  endl;
    } else {
        cout << "Ta retornando NULO" << endl;
    }

    cout << "Terceiro elemento: " << obtemDadoLista(playlist,2)->dado.nome.c_str() <<  endl << endl;

    depurarLista(playlist);
    cout << endl;

    removerLista(playlist,0);

    cout << "Lista Incompleta: " << endl;
    elem = obtemDadoLista(playlist,0);
    if(elem != nullptr) {
        cout << "Primeiro elemento: " << elem->dado.nome <<  endl;
    } else {
        cout << "Ta retornando NULO" << endl;
    }

    elem = obtemDadoLista(playlist,1);
    if(elem != nullptr) {
        cout << "Segundo elemento: " << elem->dado.nome <<  endl;
    } else {
        cout << "Ta retornando NULO" << endl;
    }

    elem = obtemDadoLista(playlist,2);
    if(elem != nullptr) {
        cout << "Terceiro elemento: " << elem->dado.nome <<  endl;
    } else {
        cout << "Ta retornando NULO" << endl;
    }
    cout << endl;
    depurarLista(playlist);
    cout << endl;
    ImprimirLista(playlist);

    cout << endl << verificaExiste(playlist,musica[0]) << endl;
    cout << verificaExiste(playlist,musica[1]) << endl;

    return 0;
}
