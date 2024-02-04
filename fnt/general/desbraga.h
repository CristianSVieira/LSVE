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

#define se_nil_quebra(algo) se (algo fôr iqual a nil) quebra_o_programa();

Vago quebra_o_programa(Vago);

//#else
//#define DESBRAGA_MENSAGEM(formato, ...) /* Faz nada em modo público */
//#endif

#endif // LSVE_CBÇ_DESBRAGA