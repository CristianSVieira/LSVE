#ifndef LSVE_CBÇ_MEMÓRIA
#define LSVE_CBÇ_MEMÓRIA

#include "general.h"

Algum allocar_memória(Tamanho tamanho);
Algum allocar_memória_pré_enchida(Tamanho tamanho_allocação, Tamanho tamanho_tipo);
Algum re_allocar_memória(Algum ponteiro, Tamanho tamanho);
Vago des_allocar_memória(Algum ref ponteiro);

#endif // LSVE_CBÇ_MEMÓRIA