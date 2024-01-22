#include "ficheiro.h"
#include "pilha.h"
#include "desbraga.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#include "memória.h"

Ficheiro* ficheiro;
Linha ficheiro_caminho;

Pilha pilha;

Charactére charactéreLido;

Linha* linhas; Integral i_linhas;
Linha linhaProcessada; Integral i_linhaProcessada;

#pragma region ficheiro_ler_linhas
Linha* ficheiro_ler_linhas(Linha caminho)
{
    ficheiro_caminho = caminho;
    TÓPICO_DE_DESBRAGA("Ficheiro a ser lido %s", ficheiro_caminho);
    ficheiro = fopen(ficheiro_caminho, ficheiro_modo_leitura);

    se(o ficheiro é iqual a nil) { TÓPICO_DE_DESBRAGA("O ficheiro %s não foi encontrado, ou está ocupado.", ficheiro_caminho); quebra_o_programa(); }

    pilha = construir_pilha(3, tamanho_de(Charactére));
    linhas = allocar_memória(tamanho_de(Linha));
    i_linhas é igual a zero;

    linhaProcessada = allocar_memória(tamanho_de(Charactére) * 4);
    i_linhaProcessada é igual a zero;

    quando(1) {
        introduzir_à_pilha(&pilha, (Charactére)fgetc(ficheiro), tamanho_de(Charactére));
        charactéreLido = (Charactére)pilha.objecto[pilha.índice].conteúdo;

        ficheiro_ler_linhas__processar_charactére_lido();
    }

fim:
    ficheiro_ler_linhas__limpa();
    devolve(nil)
}

// Funcções reductivas, só para organizar e deixar o código mais legível
Vago ficheiro_ler_linhas__processar_charactére_lido() {
    desvio(charactéreLido) {
        orienta salta_linha : {
            ficheiro_ler_linhas__processar_salta_linha();
            quebra
        }
        orienta ao fim_do_ficheiro : {
            TÓPICO_DE_DESBRAGA("%s lido! :)", ficheiro_caminho);
            quebra
        }
    norma: {
        ficheiro_ler_linhas__processar_charactére_qualquer();
        quebra
        }
    }
}

Vago ficheiro_ler_linhas__processar_salta_linha() {
    linhas[i_linhas] = allocar_memória((i_linhaProcessada * tamanho_de(Charactére)) + 1); i_linhaProcessada++;
    linhas[i_linhas][i_linhaProcessada] = nil_linha;

    incrementa(i_linhas);
    i_linhaProcessada é igual a zero;

    linhas = re_allocar_memória(linhas, i_linhas * tamanho_de(Linha));
}

Vago ficheiro_ler_linhas__processar_charactére_qualquer() {
    linhaProcessada[i_linhaProcessada] = charactéreLido;

    i_linhaProcessada++;
    linhaProcessada = re_allocar_memória(linhaProcessada, i_linhaProcessada * tamanho_de(Charactére));
    MENSAGEM_DE_DESBRAGA("%d %d %c, %c, %c", pilha.índice, pilha.objecto[pilha.índice].posição, charactéreLido, (Charactére)pilha.objecto[1].conteúdo, (Charactére)pilha.objecto[2].conteúdo);
}
#pragma endregion // ficheiro_ler_linhas



