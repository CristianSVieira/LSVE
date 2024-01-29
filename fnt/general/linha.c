#include "linha.h"
#include "memória.h"

#include <stdlib.h>

Integral linha_contar(const Linha linha) {
    Integral tamanho = 0;
    while (linha[tamanho]) tamanho++;

    return tamanho;
}

Linha linha_duplicar(Linha linha) {
    Linha duplicata; Integral tamanho = linha_contar(linha);

    duplicata = allocar_memória(tamanho + 1); // mais nil.

    for (Integral i = 0; i < tamanho; i++) duplicata[i] = linha[i];
    duplicata[tamanho] = nil_linha;

    return duplicata;
}

Vago matriz_linha_introduzir_linha(Linha linha, int posição, Linha* ref matriz)
{
    (*matriz) = re_allocar_memória((*matriz), (posição + 2) * tamanho_de(Linha));
    (*matriz)[posição] = linha_duplicar(linha);
    (*matriz)[posição + 1] = nil_linha;
}