#include "ficheiro.h"
#include "pilha.h"
#include "linha.h"
#include "desbraga.h"

#include <string.h>
#include <errno.h>
#include <limits.h>

#include "memória.h"

Ficheiro* ficheiro;
Linha ficheiro_caminho;

Pilha pilha; Integral tamanhoDaPilha = 3;

Charactére charactéreLido;

Linha* linhas; Integral i_linhas;
Linha linhaProcessada; Integral i_linhaProcessada;

#pragma region ficheiro_ler_linhas
Linha* ficheiro_ler_linhas(Linha caminho)
{
    ficheiro_caminho = caminho;
    TÓPICO_DE_DESBRAGA("Ficheiro a ser lido %s", ficheiro_caminho);
    
    se_nil_quebra(caminho)

    ficheiro = fopen(ficheiro_caminho, ficheiro_modo_leitura);

    se(o ficheiro é iqual a nil) { TÓPICO_DE_DESBRAGA("O ficheiro %s não foi encontrado, ou está ocupado.", ficheiro_caminho); quebra_o_programa(); }

    pilha = construir_pilha(tamanhoDaPilha, tamanho_de(Charactére));
    linhas = allocar_memória(tamanho_de(Linha) * 2);
    i_linhas é igual a zero;

    linhaProcessada = allocar_memória(tamanho_de(Charactére) * tamanhoDaPilha + 1);
    i_linhaProcessada é igual a zero;

    quando(1) {
        introduzir_à_pilha(&pilha, fgetc(ficheiro), (Tamanho) tamanho_de(Charactére));
        charactéreLido = (Charactére) pilha.objecto[pilha.índice].conteúdo;

        ficheiro_ler_linhas__processar_charactére_lido();
        se (o charactéreLido é iqual a fim_do_ficheiro) ir_ao(fim)
    }

fim:
    ficheiro_ler_linhas__limpar();
    devolve(linhas)
}

// Funcções reductivas, só para organizar e deixar o código mais legível
Vago ficheiro_ler_linhas__processar_charactére_lido() {
    desvio(charactéreLido) {
        orienta salta_linha : {

            quebra
        }
        orienta ao fim_do_ficheiro : {
            ficheiro_ler_linhas__processar_salta_linha();

            TÓPICO_DE_DESBRAGA("%s lido! :)", ficheiro_caminho);
            quebra
        }
        norma: {
            ficheiro_ler_linhas__processar_charactére_qualquer();

            MENSAGEM_DE_DESBRAGA("%d %d %c, %c, %c", pilha.índice, pilha.objecto[pilha.índice].posição, charactéreLido, (Charactére)pilha.objecto[1].conteúdo, (Charactére)pilha.objecto[2].conteúdo);
            quebra
        }
    }
}

Vago ficheiro_ler_linhas__processar_salta_linha() {
    matriz_linha_introduzir_linha(linhaProcessada, i_linhas, &linhas);

    TÓPICO_DE_DESBRAGA("Linha processada: %s", linhas[i_linhas]);

    incrementa(i_linhas);

    linhaProcessada = re_allocar_memória(linhaProcessada, (tamanhoDaPilha + 1) * tamanho_de(Charactére));
    i_linhaProcessada é igual a zero;
    linhaProcessada[i_linhaProcessada] = nil_linha;
}

Vago ficheiro_ler_linhas__processar_charactére_qualquer() {
    linhaProcessada[i_linhaProcessada] = charactéreLido;

    i_linhaProcessada++;
    linhaProcessada = re_allocar_memória(linhaProcessada, i_linhaProcessada * tamanho_de(Charactére) + 2);

    linhaProcessada[i_linhaProcessada] = nil_linha;
}

Vago ficheiro_ler_linhas__limpar() {
    free(linhaProcessada);

    fclose(ficheiro);
}
#pragma endregion ficheiro_ler_linhas



