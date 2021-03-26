#ifndef CARTAS
#define CARTAS

#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include "string"
#include "Lista.h"

#define LIMITE_BARALHO 52

using namespace std;

enum { COPAS, ESPADAS, OURO, PAUS};

struct TCarta {
	int valor;
	int naipe;
};

bool VerificaIgual(TCarta c1, TCarta c2) {
	if (c1.naipe == c2.naipe && c1.valor == c2.valor) {
		return true;
	}
	return false;
}

void ImprimirElemento(TCarta c1) {
    string naipeString[4] = {"COPAS","ESPADAS","OURO","PAUS"};
	cout << "Valor: " << c1.valor << endl;
    cout << "Naipe: " << naipeString[c1.naipe] << endl;
}

int InicializarCarta(int i, bool op) {
	if (op)
		return (i / 4) + 1;
	else 
		switch (i % 4) {
		case COPAS:
			return COPAS; // COPAS == 0
			break;
		case ESPADAS:
			return ESPADAS;; // ESPADAS == 1
			break;
		case OURO:
			return OURO; // OURO == 2
			break;
		case PAUS:
			return PAUS; // PAUS == 3
			break;
		}

    return -1;
}

void PreencherBaralho(TLista<TCarta, LIMITE_BARALHO> &lista) {
	for (int i = 0; i < LIMITE_BARALHO; i++) {
		TCarta aux;
        aux.valor = InicializarCarta(i, true);
        aux.naipe = InicializarCarta(i, false);
		InsereListaFim(lista, aux);
	}
}

void Embaralhar(TLista<TCarta, LIMITE_BARALHO> &lista) {
	for (int i = 0; i < 52; i++) {
		int rand_numb = rand() % 52;
		TElemento<TCarta> aux = lista.elementos[i];

        lista.elementos[i] = lista.elementos[rand_numb];
		lista.elementos[rand_numb] = aux;
	}
}

template <int MAX1, int MAX2>
void DistribuirCarta(TLista<TCarta, MAX1> &fonte, TLista<TCarta, MAX2> &destino) {
	TElemento<TCarta> aux = ObtemLista(fonte, 0);
	RemoveListaPos(fonte, 0);
    InsereListaFim(destino, aux.dado);
}
#endif
