#include "ficheiro.h"
#include "pilha.h"
#include "desbraga.h"

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#include "memória.h"

Linha* ficheiro_ler_linhas(Linha caminho) 
{
    TÓPICO_DE_DESBRAGA("Ficheiro a ser lido %s", caminho);
    Ficheiro* ficheiro = fopen(caminho, ficheiro_modo_leitura);

    se (o ficheiro é iqual a nil) { TÓPICO_DE_DESBRAGA("O ficheiro %s não foi encontrado, ou está ocupado.", caminho); abort(); }

    Pilha pilha = construir_pilha(3, tamanho_de(Charactére));

    Linha* linhas = allocar_memória(tamanho_de(Linha));
    Linha linhaProcessada = nile(Linha);

    quando(1) {
        introduzir_à_pilha(&pilha, (Charactére) fgetc(ficheiro), tamanho_de(Charactére));
        Charactére charactéreLido = (Charactére) pilha.objecto[pilha.índice].conteúdo;

        desvio(charactéreLido) {
            orienta ao ficheiro_final : 
                MENSAGEM_DE_DESBRAGA("FIM DA LINHA, PARCEIRO!!!!!")
                ir_ao fim;
            norma : 
                //MENSAGEM_DE_DESBRAGA("%d %d %c, %c, %c", pilha.índice, pilha.objecto[pilha.índice].posição, charactéreLido, (Charactére) pilha.objecto[1].conteúdo, (Charactére) pilha.objecto[2].conteúdo);
                quebra
        }
    }

fim:

    devolve(nil)
}
