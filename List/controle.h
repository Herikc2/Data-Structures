#ifndef CONTROLE_H
#define CONTROLE_H
#include <iostream>
#include <chrono>
#include "stdlib.h"
#include "vsf.h"
#include "listaencadeada.h"
#include "listaencadeadadupla.h"
#include "listaestatica.h"

using namespace std;

#define NUM_ELEMENTOS 40000

struct Controle {
    bool run;
    int op;
    int choose;
};

void inicializa(Controle &c) {
    c.op = 0;
    c.run = true;
    c.choose = 0;
}

int exibirMenuPrincipal() {
    int op = 0;
    cout << "Escolha qual das listas abaixo sera executada: " << endl;
    cout << "1 - Lista Estatica" << endl;
    cout << "2 - Lista Encadeada" << endl;
    cout << "3 - Lista Encadeada Dupla" << endl;
    cout << "4 - Todas Listas" << endl;
    cout << "5 - Sair" << endl;
    cout << "Digite: ";
    cin >> op;
    return op;
}

int exibirMenuSecundario() {
    int op = 0;
    cout << "Escolha qual dos algoritmos abaixo executar: " << endl;
    cout << "1 - BubbleSort" << endl;
    cout << "2 - QuickSort" << endl;
    cout << "3 - Voltar" << endl;
    cout << "4 - Sair" << endl;
    cout << "Digite: ";
    cin >> op;
    return op;
}

bool operadorMenu(Controle &controle) {
    if (controle.op >= 1 && controle.op <= 4) {
        return true;
    }
    else if (controle.op == 5) {
        controle.run = false;
        return false;
    }
    else {
        cout << "Opcao invalida!" << endl;
    }
    return false;
}

void executaAlgoritmos(Controle controle, TListaEncadeada<VSF> &vsf, TListaDupla<VSF> &vsfDupla,
    TListaEstatica<VSF, NUM_ELEMENTOS> &vsfEstatica, VSF vsfElemento[NUM_ELEMENTOS]) {

    for (int i = 0; i<NUM_ELEMENTOS; i++)
        vsfElemento[i].id = rand() % 1000000;
    if (controle.op == 1) {
        inicializaEstatica(vsfEstatica);
        int cont = 0;
        for (int i = 0; i<NUM_ELEMENTOS; i++) {
            InsereListaInicioEstatica(vsfEstatica, vsfElemento[i]);
            cont++;
        }
        vsfEstatica.quantidade = cont;
        if (controle.choose == 1) {
            cout << "LISTA ESTATICA DESORNEDADA - BUBBLESORT: " << endl;
            ImprimirListaEstatica(vsfEstatica);
            auto inicio = chrono::steady_clock::now();
            BubbleSortEstatica(vsfEstatica);
            auto fim = chrono::steady_clock::now();
            cout << endl << "LISTA ESTATICA ORDENADA - BUBBLESORT: " << endl;
            ImprimirListaEstatica(vsfEstatica);
            cout << "\nTempo para executar o bubblesort com " << NUM_ELEMENTOS << " elementos: "
                << chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count() << " ns";
        }
        else if (controle.choose == 2) {

        }
    }
    else if (controle.op == 2) {
        inicializaListaEncadeada(vsf);
        for (int i = 0; i<NUM_ELEMENTOS; i++)
            insereListaEncadeada(vsf, vsfElemento[i], 0);

        if (controle.choose == 1) {
            cout << "LISTA DESORDENADA ENCADEADA - BUBBLESORT: " << endl;
            ImprimirListaEncadeada(vsf);
            auto inicio = chrono::steady_clock::now();
            BubbleSortEncadeada(vsf);
            auto fim = chrono::steady_clock::now();
            cout << endl << "LISTA ORDENADA ENCADEADA - BUBBLESORT: " << endl;
            ImprimirListaEncadeada(vsf);
            cout << "\nTempo para executar o bubblesort com " << NUM_ELEMENTOS << " elementos: "
                << chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count() << " ns";
        }
        else if (controle.choose == 2) {

        }
    }
    else if (controle.op == 3) {
        inicializaListaDupla(vsfDupla);
        for (int i = 0; i<NUM_ELEMENTOS; i++)
            insereListaDupla(vsfDupla, vsfElemento[i], 0);
        if (controle.choose == 1) {
            cout << "LISTA DESORDENADA ENCADEADA DUPLA - BUBBLESORT: " << endl;
            ImprimirListaDupla(vsfDupla);
            auto inicio = chrono::steady_clock::now();
            BubbleSortEncadeadaDupla(vsfDupla);
            auto fim = chrono::steady_clock::now();
            cout << endl << "LISTA ORDENADA ENCADEADA DUPLA - BUBBLESORT: " << endl;
            ImprimirListaDupla(vsfDupla);
            cout << "\nTempo para executar o bubblesort com " << NUM_ELEMENTOS << " elementos: "
                << chrono::duration_cast<chrono::nanoseconds>(fim - inicio).count() << " ns";
        }
        else if (controle.choose == 2) {

        }
    }
    else if (controle.op == 4) {
        inicializaEstatica(vsfEstatica);
        inicializaListaEncadeada(vsf);
        inicializaListaDupla(vsfDupla);
        int cont = 0;
        for (int i = 0; i<NUM_ELEMENTOS; i++) {
            InsereListaInicioEstatica(vsfEstatica, vsfElemento[i]);
            cont++;
        }
        vsfEstatica.quantidade = cont;
        for (int i = 0; i<NUM_ELEMENTOS; i++)
            insereListaEncadeada(vsf, vsfElemento[i], 0);
        for (int i = 0; i<NUM_ELEMENTOS; i++)
            insereListaDupla(vsfDupla, vsfElemento[i], 0);

        if (controle.choose == 1) {
            cout << "LISTA ESTATICA DESORNEDADA - BUBBLESORT: " << endl;
            ImprimirListaEstatica(vsfEstatica);
            auto inicioEstatica = chrono::steady_clock::now();
            BubbleSortEstatica(vsfEstatica);
            auto fimEstatica = chrono::steady_clock::now();
            cout << endl << "LISTA ESTATICA ORDENADA - BUBBLESORT: " << endl;
            ImprimirListaEstatica(vsfEstatica);
            cout << endl;

            cout << "LISTA DESORDENADA ENCADEADA - BUBBLESORT: " << endl;
            ImprimirListaEncadeada(vsf);
            auto inicioEncadeada = chrono::steady_clock::now();
            BubbleSortEncadeada(vsf);
            auto fimEncadeada = chrono::steady_clock::now();
            cout << endl << "LISTA ORDENADA ENCADEADA - BUBBLESORT: " << endl;
            ImprimirListaEncadeada(vsf);
            cout << endl;

            cout << "LISTA DESORDENADA ENCADEADA DUPLA - BUBBLESORT: " << endl;
            ImprimirListaDupla(vsfDupla);
            auto inicioDupla = chrono::steady_clock::now();
            BubbleSortEncadeadaDupla(vsfDupla);
            auto fimDupla = chrono::steady_clock::now();
            cout << endl << "LISTA ORDENADA ENCADEADA DUPLA - BUBBLESORT: " << endl;
            ImprimirListaDupla(vsfDupla);
            cout << "\nTempo para executar o bubblesort com " << NUM_ELEMENTOS << " elementos - Lista Estatica: "
                << chrono::duration_cast<chrono::nanoseconds>(fimEstatica - inicioEstatica).count() << " ns" << endl;
            cout << "\nTempo para executar o bubblesort com " << NUM_ELEMENTOS << " elementos - Lista Encadeada: "
                << chrono::duration_cast<chrono::nanoseconds>(fimEncadeada - inicioEncadeada).count() << " ns" << endl;
            cout << "\nTempo para executar o bubblesort com " << NUM_ELEMENTOS << " elementos - Lista Duplamente Encadeada: "
                << chrono::duration_cast<chrono::nanoseconds>(fimDupla - inicioDupla).count() << " ns";
        }
        else if (controle.choose == 2) {

        }
    }
}

bool operadorMenuSecundario(Controle &controle) {
    if (controle.choose == 1 || controle.choose == 2) {
        return true;
    }
    else if (controle.choose == 3) {
        return false;
    }
    else if (controle.choose == 4) {
        controle.run = false;
        return false;
    }
    else {
        cout << "Opcao invalida!" << endl;
    }
    return false;
}

#endif // CONTROLE_H
