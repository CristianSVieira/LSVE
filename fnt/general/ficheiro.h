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
/// <summary>
/// Lê todas as linhas de um ficheiro dado.
/// </summary>
/// <param name="caminho"></param>
/// <returns>Motrice de linhas</returns>
Linha* ficheiro_ler_linhas(Linha caminho);
/// <summary>
/// Processa o charactére lido.
/// Avalia o charactére e decide quais outras funcções utilizar 
/// para manipular os recursos internos para a leitura do ficheiro.
///
/// </summary>
/// <returns></returns>
Vago ficheiro_ler_linhas__processar_charactére_lido();
/// <summary>
/// Processamento do charactére-salta-linhas.
/// </summary>
/// <returns></returns>
Vago ficheiro_ler_linhas__processar_salta_linha();
/// <summary>
/// Processamento de um charactére qualquer. Texto, em geral.
/// </summary>
/// <returns></returns>
Vago ficheiro_ler_linhas__processar_charactére_qualquer();
/// <summary>
/// Limpa os recursos usados para a leitura do ficheiro
/// para a próxima leitura. 
/// </summary>
/// <returns></returns>
Vago ficheiro_ler_linhas__limpar();
#pragma endregion // ficheiro_ler_linhas

#endif // LSVE_CBÇ_FICHEIRO