#include <iostream>
#include "stdio.h"
#include <stdlib.h>
#include "string"
#include "Lista.h"
#include "Cartas.h"

#define NUMBER_PLAYERS 4
#define LETTERS_HAND 2	

using namespace std;

int menu(int op) {
	cout << "Escolha uma opção: \n0 - Inserir na Lista\n1 - Remover da Lista\n2 - Verifica se pertence a lista\n";
	cout << "3 - Obtem elemento da lista\n4 - Imprimir Lista\n5 - Sair";
	cout << "\nOpção: ";
	cin >> op;
	return op;
}

int main()
{
	// ADD-ONS
	setlocale(LC_ALL, "Portuguese");
	//-----------------------------------------------------------------

	// DECLARAÇÃO DE VARIAVEIS
//	int op = 0;
	TLista<TCarta, 52> crupie;
	TLista<TCarta, 5> mesa;
    TLista<TCarta, LETTERS_HAND> players[NUMBER_PLAYERS];
	//-----------------------------------------------------------------

	// INICIALIZAÇÃO 
	inicializa(crupie);
	PreencherBaralho(crupie);
	Embaralhar(crupie);
	inicializa(mesa);
	for (int i = 0; i < NUMBER_PLAYERS; i++)
		inicializa(players[i]);
	//-----------------------------------------------------------------

    // SET UP INICIAL
    for (int x = 0; x < LETTERS_HAND; ++x)
        for (int i = 0; i < NUMBER_PLAYERS; i++)
            DistribuirCarta(crupie, players[i]);

	for (int i = 0; i < 3; i++)
		DistribuirCarta(crupie, mesa);
	//-----------------------------------------------------------------

	// EXECUÇÃO PRINCIPAL
    cout << "IMPRIMIR MESA:" << endl;
	ImprimirLista(mesa);
    cout << "----------------------------------------------------------" << endl;
    for (int i = 0; i < 4; i++){
        cout << "IMPRIMIR JOGADOR " << i << ":" << endl;
        ImprimirLista(players[i]);
        cout << "----------------------------------------------------------" << endl;
    }
    cout << "IMPRIMIR CRUPIE:" << endl;
	ImprimirLista(crupie);
    cout << "----------------------------------------------------------" << endl;
	//-----------------------------------------------------------------

	return 0;
}
