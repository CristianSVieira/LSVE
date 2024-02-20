#ifndef LSVE_CBÇ_PILHA
#define LSVE_CBÇ_PILHA

#include "general.h"
#include "teclado/ASCII.h"

#include "desbraga.h"

typedef struct Pilha_Conteúdo {
    Integral posição;

    Tamanho tamanho;
    Algum conteúdo;
} Pilha_Conteúdo;

/* Estructura para PEQUENA dados em cascata. */
typedef struct Pilha {
    Integral índice; // Para manipulação do conteúdo, evita a criação de múltiplos índices avulsos, variáveis soltas. 

    Tamanho tamanho; // Peso da estructura, é differente de quantos objectos ela possui.
    Integral quantidadeDeItens; // Agora sim, a quantidade de objectos presentes.
    Pilha_Conteúdo* objecto;
} Pilha;

Pilha construir_pilha(Tamanho tamanhoDaPilha, Tamanho tamanhoDoObjecto);
Vago introduzir_à_pilha(Pilha ref pilha, Algum objecto, Tamanho tamanhoDoObjecto);

#endif //LSVE_CBÇ_PILHA
