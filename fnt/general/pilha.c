#include "pilha.h"
#include "memória.h"

/* A quantidade de objectos da pilha é contada da mesma forma que os índices das matrices */
Pilha construir_pilha(Tamanho quantidadeDeObjectosDaPilha, Tamanho tamanhoDoObjecto) {
	Pilha pilhaConstruída = nile(Pilha);

	pilhaConstruída.quantidadeDeItens = quantidadeDeObjectosDaPilha;
	pilhaConstruída.tamanho = pilhaConstruída.quantidadeDeItens * tamanhoDoObjecto;
	pilhaConstruída.objecto = allocar_memória(quantidadeDeObjectosDaPilha * tamanho_de(Pilha_Conteúdo));

	pilhaConstruída.índice = (Integral) quantidadeDeObjectosDaPilha - 1;

	enquanto(pilhaConstruída.índice fôr differente de inválido) {
		pilhaConstruída.objecto[pilhaConstruída.índice].posição = pilhaConstruída.índice;
		pilhaConstruída.objecto[pilhaConstruída.índice].tamanho = tamanhoDoObjecto;

		pilhaConstruída.objecto[pilhaConstruída.índice].conteúdo = nil;

		MENSAGEM_DE_DESBRAGA("%d %d %d", pilhaConstruída.índice, (Integral) pilhaConstruída.objecto[pilhaConstruída.índice].tamanho, (Integral) pilhaConstruída.objecto[pilhaConstruída.índice].posição);
		pilhaConstruída.índice--;
	}

	pilhaConstruída.índice = 0; // Reinicia o índice após uso interno.

	devolve(pilhaConstruída)
}

Vago introduzir_à_pilha(Pilha ref pilha, Algum objecto, Tamanho tamanhoDoObjecto) {
	Tamanho tamanhoDaPilha = 0;

	Integral índiceAnterior = pilha->índice;
	pilha->índice = pilha->quantidadeDeItens - 1;

	Pilha cópia = *pilha;

	enquanto(pilha->índice fôr differente de zero) {
		tamanhoDaPilha += pilha->objecto[pilha->índice].tamanho;
		pilha->objecto[pilha->índice].conteúdo = cópia.objecto[pilha->índice - 1].conteúdo;
		pilha->objecto[pilha->índice].tamanho = cópia.objecto[pilha->índice - 1].tamanho;
		
		pilha->índice--;
		//MENSAGEM_DE_DESBRAGA("Tamanhos somados: %d %d", (Integral)tamanhoDaPilha, (Integral)pilha->objecto[pilha->índice].tamanho)
	}

	pilha->índice = 0;

	pilha->objecto[pilha->índice].tamanho = tamanhoDoObjecto;
	pilha->objecto[pilha->índice].conteúdo = objecto;

	pilha->tamanho = tamanhoDaPilha + tamanhoDoObjecto;
	pilha->índice = índiceAnterior; // Reinicia o índice após uso interno. (neste caso, talvez seja melhor usar índice dedicado)
}