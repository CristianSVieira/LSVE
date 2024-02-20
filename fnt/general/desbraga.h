#ifndef LSVE_CBÇ_DESBRAGA
#define LSVE_CBÇ_DESBRAGA

#include "general.h"
#include <stdlib.h>

//#if defined(DESBRAGA) && DESBRAGA > 0

#define LINHA_SALTAR() printf("%c", salta_linha) \

#define MENSAGEM_DE_DESBRAGA(formato, ...) \
printf("DESBRAGA ― %s:%d:%s: " formato, \
__FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
LINHA_SALTAR();

#define TÓPICO_DE_DESBRAGA(formato, ...) \
LINHA_SALTAR(); \
printf("DESBRAGA ― %s:%d:%s: " formato, \
__FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); \
LINHA_SALTAR(); \
LINHA_SALTAR()

/// <summary>
/// Quebra o programa se estiver nilo
/// </summary>
/// <param name="">Qualquer coisa que pode ser nilada</param>
#define se_nil_quebra(algo) se (algo fôr iqual a nil) quebra_o_programa();

/// <summary>
/// Quebra tudo com e carimba o número do azar
/// </summary>
/// <param name=""></param>
/// <returns></returns>
Vago quebra_o_programa(Vago);

//#else
//#define DESBRAGA_MENSAGEM(formato, ...) /* Faz nada em modo público */
//#endif

#endif // LSVE_CBÇ_DESBRAGA