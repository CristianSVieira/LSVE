#ifndef LSVE_CBÇ_FICHEIRO
#define LSVE_CBÇ_FICHEIRO

#define _CRT_SECURE_NO_WARNINGS

#include "general.h"

/* MODOS DE LEICTURAS */
/* Na funcção 'fopen', indica-se como se deve abrir o ficheiro, com quais intenções de modificação */
#define ficheiro_modo_leitura "r"
#define ficheiro_modo_leitura_binária "rb"

#define fim_do_ficheiro inválido

Linha* ficheiro_ler_linhas(Linha caminho);

#endif // LSVE_CBÇ_FICHEIRO