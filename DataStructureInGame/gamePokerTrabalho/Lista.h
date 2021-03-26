#ifndef LISTA_ESTATICA
#define LISTA_ESTATICA

#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include "string"
using namespace std;

template<typename TIPO>
struct TElemento {
	TIPO dado;
};

template<typename T, int MAX>
struct TLista {
	TElemento<T> elementos[MAX];
	int quantidade;
};


template<typename TIPO, int MAX>
void inicializa(TLista<TIPO, MAX> &l) {
	l.quantidade = 0;
}

template<typename TIPO, int MAX>
void InsereLista(TLista<TIPO, MAX> &l, TIPO dado) {
	system("cls");
	int op;

	// INICIO TESTE
	cout << "\n Digite o numero da carta: ";
	cin >> dado.valor;
	cout << "\n Digite o naipe da carta: ";
	cin >> dado.naipe;
	cout << "\n Digite 0 para inserir no inicio, 1 para inserir no fim e 2 para posição especifica: ";
	cin >> op;
	// FIM TESTE

	if (op == 0) {
		InsereListaInicio(l, dado);
	}
	else if (op == 1)
		InsereListaFim(l, dado);
	else {
		cout << "\n Digite a posição: ";
		cin >> op;
		if (op <= 51 && op >= 0)
			InsereListaPos(l, dado, op);
	}
	op = 99;
}
template<typename TIPO, int MAX>
void InsereListaInicio(TLista<TIPO, MAX> &l, TIPO dado) {
	TElemento<TIPO> elemento;
	elemento.dado = dado;

	for (int i = l.quantidade; i >= 0; i--)
		if (i == 52)
			break;
		else
			l.elementos[i + 1] = l.elementos[i];
	l.elementos[0] = elemento;
	l.quantidade++;
}
template<typename TIPO, int MAX>
void InsereListaFim(TLista<TIPO, MAX> &l, TIPO dado) {

    if(l.quantidade > MAX) {
        throw "Lista cheia - nao pode inserir";
    }
	TElemento<TIPO> elemento;
	elemento.dado = dado;
	
	l.elementos[l.quantidade] = elemento;
	l.quantidade++;
}
template<typename TIPO, int MAX>
void InsereListaPos(TLista<TIPO, MAX> &l, TIPO dado, int pos) {

    if(l.quantidade > MAX) {
        throw "Lista cheia - nao pode inserir";
    }
    TElemento<TIPO> elemento;
	elemento.dado = dado;
	for (int i = l.quantidade; i >= pos; i--)
		if (i == 52)
			break;
		else
			l.elementos[i + 1] = l.elementos[i];

    l.elementos[pos] = elemento;
	l.quantidade++;
}

template<typename TIPO, int MAX>
void RemoveLista(TLista<TIPO, MAX> &l) {
	int op;
	system("cls");
	// INICIO TESTE
	cout << "\n Digite 0 para remover no inicio, 1 no fim e 2 posicição especifica: ";
	cin >> op;
	// FIM TESTE

	if (op == 0)
		RemoveListaInicio(l);
	else if (op == 1)
		RemoveListaFim(l);
	else if (op == 2) {
		cout << "\n Digite a posição: ";
		cin >> op;
		if (op <= 51 && op >= 0)
			RemoveListaPos(l, op);
	}

}
template<typename TIPO, int MAX>
void RemoveListaInicio(TLista<TIPO, MAX> &l) {
	for (int i = 1; i <= l.quantidade; i++)
		l.elementos[i - 1] = l.elementos[i];
	l.quantidade--;
}
template<typename TIPO, int MAX>
void RemoveListaFim(TLista<TIPO, MAX> &l) {
	l.quantidade--;
}
template<typename TIPO, int MAX>
void RemoveListaPos(TLista<TIPO, MAX> &l, int pos) {
    if(l.quantidade == 0) {
        throw "Lista vazia";
    }
	for (int i = pos + 1; i <= l.quantidade; i++)
		l.elementos[i - 1] = l.elementos[i];
	l.quantidade--;
}

template<typename TIPO, int MAX>
bool PertenceLista(TLista<TIPO, MAX> &l, TIPO dado) {
	// INICIO TESTE
	cout << "\nDigite o numero da carta: ";
	cin >> dado.valor;
	cout << "\nDigite o naipe da carta: ";
	cin >> dado.naipe;
	// FIM TESTE

	for (int i = 0; i <= l.quantidade; i++)
		if (VerificaIgual(l.elementos[i].dado, dado)) 
			return true;

	return false;
}

template<typename TIPO>
bool VerificaIgual(TIPO dado1, TIPO dado2) {
    return VerificaIgual(dado1, dado2);
}

template<typename TIPO, int MAX>
TElemento<TIPO> ObtemLista(TLista<TIPO, MAX> l, int pos) {
	return l.elementos[pos];
}

template<typename TIPO, int MAX>
int DescobrirIndice(TLista<TIPO, MAX> l, TIPO dado) {
	for (int i = 0; i <= l.quantidade; i++)
		if (VerificaIgual(l.elementos[i].dado, dado))
			return i;
	return -1;
}

#include <iostream>
template<typename TIPO, int MAX>
void ImprimirLista(TLista<TIPO, MAX> l) {
    std::cout << "\Quantidade: " << l.quantidade << std::endl;
	for (int i = 0; i < l.quantidade; i++) 
		ImprimirElemento(l.elementos[i].dado);
}

template<typename TIPO>
void ImprimirElemento(TIPO dado) {
    ImprimirElemento(dado);
}

#endif
