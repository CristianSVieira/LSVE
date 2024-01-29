#ifndef LSVE_CBÇ_FICHEIRO
#define LSVE_CBÇ_FICHEIRO

#define _CRT_SECURE_NO_WARNINGS

#include "general.h"

/* MODOS DE LEICTURAS */
/* Na funcção 'fopen', indica-se como se deve abrir o ficheiro, com quais intenções de modificação */
#define ficheiro_modo_leitura "r"
#define ficheiro_modo_leitura_binária "rb"

#define fim_do_ficheiro inválido

#pragma region ficheiro_ler_linhas
Linha* ficheiro_ler_linhas(Linha caminho);
Vago ficheiro_ler_linhas__processar_charactére_lido();
Vago ficheiro_ler_linhas__processar_salta_linha();
Vago ficheiro_ler_linhas__processar_charactére_qualquer();
Vago ficheiro_ler_linhas__limpar();
#pragma endregion // ficheiro_ler_linhas

#endif // LSVE_CBÇ_FICHEIRO