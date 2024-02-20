#include "memória.h"
#include "desbraga.h"

#include <stdio.h>

Algum allocar_memória(Tamanho tamanho) {
    Algum ponteiroAllocado = malloc(tamanho);
    se(o ponteiroAllocado fôr iqual a nil) {
        MENSAGEM_DE_DESBRAGA("Não se pôde alocar %zu digbis.\n", tamanho);
        quebra_o_programa();
    }

    devolve(ponteiroAllocado)
}

/*

    Calloc multiplica o tamanho do tipo com a quantidade de allocações para
    allocar o espaço necessário.

*/
Algum allocar_memória_pré_enchida(Tamanho tamanho_allocação, Tamanho multiplicador) {
    Algum ponteiroPré_enchido = calloc(tamanho_allocação, multiplicador);
    se(o ponteiroPré_enchido fôr iqual a nil) {
        MENSAGEM_DE_DESBRAGA("Não se pôde preêncher com allocação %zu digbis.\n", (tamanho_allocação * multiplicador));
        quebra_o_programa();
    }

    devolve(ponteiroPré_enchido)
}

Algum re_allocar_memória(Algum ponteiro, Tamanho tamanho) {
    Algum ponteiroRe_allocado = realloc(ponteiro, tamanho);

    se(o ponteiroRe_allocado fôr iqual a nil) {
        MENSAGEM_DE_DESBRAGA("Não se pôde re-alocar %zu digbis.\n", tamanho);
        quebra_o_programa();
    }

    devolve(ponteiroRe_allocado)
}

Vago des_allocar_memória(Algum ref ponteiro) {
#define ponteiroDes_allocado (*ponteiro)

    se(o ponteiroDes_allocado fôr iqual nil) {
        MENSAGEM_DE_DESBRAGA("Não se deve des-allocar nil.");
        quebra_o_programa();
    }

    free(ponteiroDes_allocado);
    ponteiroDes_allocado = nil;

#undef ponteiroDes_allocado
}