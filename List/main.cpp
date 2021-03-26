#include <iostream>
#include <chrono>
#include "stdlib.h"
#include "vsf.h"
#include "listaencadeada.h"
#include "listaencadeadadupla.h"
#include "listaestatica.h"
#include "controle.h"

#define NUM_ELEMENTOS 40000

using namespace std;

bool verificaExisteEncadeada(TElementoEncadeada<VSF> e1, TElementoEncadeada<VSF> e2) {
    if (e1.dado.id == e2.dado.id)
        return true;
    else
        return false;
}

int main()
{
    // DECLARAÇÃO E INSTALAÇÃO DE ADD-ONS
    srand(0);
    // --------------------------------------------------------------

    // DECLARAÇÃO DE VARIAVEIS
    Controle controle;
    VSF vsfElemento[NUM_ELEMENTOS];
    TListaEncadeada<VSF> vsf;
    TListaDupla<VSF> vsfDupla;
    TListaEstatica<VSF, NUM_ELEMENTOS> vsfEstatica;
    // --------------------------------------------------------------

    // INICIALIZAÇÃO PRIMÁRIA
    inicializaListaEncadeada(vsf);
    inicializaListaDupla(vsfDupla);
    inicializaEstatica(vsfEstatica);
    inicializa(controle);
    // --------------------------------------------------------------

    // OPERAÇÕES PRIMARIAS

    // --------------------------------------------------------------

    // LOOPING PRINCIPAL DE EXECUÇÃO
    while (controle.run) {
        controle.op = exibirMenuPrincipal();
        bool operation = operadorMenu(controle);
        if (operation) {
            system("cls");
            controle.choose = exibirMenuSecundario();
            operation = operadorMenuSecundario(controle);
            if (operation) {
                system("cls");
                executaAlgoritmos(controle, vsf, vsfDupla, vsfEstatica, vsfElemento);
                cout << endl << endl;
            }

        }
    }
    // --------------------------------------------------------------

    return 0;
}
