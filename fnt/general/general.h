#ifndef LSVE_CBÇ_GENERAL
#define LSVE_CBÇ_GENERAL

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/* Funcções d'usos generais applicadas a qualquer programa. */
#pragma region /* DEFINIÇÕES */

#pragma region /* VILANTINAS */

// Não têm funcionalidades quaisquer, são só pessoalidades que me gosto pôr no meio do código.
// Meu programa, minhas brincadeirinhas, tá bem? :)

#define numero_da_origem        20180917    // Data dos arredores (não lembro ao certo) da origem! :+)
#define numero_do_azar         -20191101    // Data dos arredores (também não me lembro) do fim...:+/
#define numero_da_sorte         20231210    // Dia do reinício. :+D Data seguinte de fim inexistente.

#pragma endregion
#pragma region /* PORTUGUESAÇÕES */

// Obrigatoriedades inalteráveis da linguagem, adaptadas ao português.

// Main, por exemplo, é obrigatório. É o nome que se exige à funcção principal. 
// Com a definição, pode-se alterar.
#define origem main
#define matrice(matrice, índice) matrice[índice]
#define tamanho_de(tipo) sizeof(tipo)
#define retorna(algo) return algo;
#define devolve(algo) retorna(algo)

#define ref *

#define nil zero // Nil para ponteiros.
#define inválido (-1) // Posição inválida para matriz.

#define nile(tipo) (tipo) { 0 } // Nil para estructuras, sem ponteiros.

/* CONSTANTES LINHAIS */
#define nil_linha '\0'
#define salta_linha '\n'
#define linha_tabulação '\t'

#pragma region /* SUPORTE LINGÜÍSTICO */

#define a
#define à
#define ao
#define o
#define é
#define fôr
#define de

#pragma endregion /* SUPORTE LINGÜÍSTICO */

#pragma endregion
#pragma region /* FUNCCIONAIS */

// Estas têm alguma funccionalidade a outras definições, utilidades a elas, geralmente. 
#define juntar(a, b) a##b
#define juntar_(a, b) juntar(a, b) // O acolhido de cima. Útil quando os parâmetros são outras definições.

#pragma endregion
#pragma region /* VISIBILIDADE */

#define privado static
#define exclusivo privado
#define público 

#pragma endregion
#pragma region /* EXPRESSÕES NUMÉRICAS */

#define igual =
#define iqual juntar_(igual, igual)
#define equal igual

#define não !
#define differente juntar_(não, igual)
#define differe differente

#define incrementa(valôr) valôr++;
#define decrementa(valôr) valôr--;

#define incrementa_por(valôr, incremento) valôr += incremento;
#define decrementa_por(valôr, incremento) valôr -= incremento;

#define zero 0

#pragma endregion
#pragma region /* CONDICIONAIS */

#define ir_ao(onde) goto onde;

#define se(condição) if(condição)
#define ou_se(condição) else se(condição)
#define senão else(condição)

#define desvio(condição) switch(condição)

#define orienta case
#define quebra break;

#define cada(condição) for(condição)

#define enquanto(condição) while(condição)
#define quando enquanto
#define sísifo quando(1)

#define norma default

#pragma endregion
#pragma region /* TIPOS */

typedef void Vago; // Vazío, nada, vago...
typedef void* Algum; // Alguma coisa, um objecto qualquer...

typedef char Charactére;
typedef char* Linha;
typedef int Integral; // Inteiro, Integral...

typedef FILE Ficheiro;
typedef size_t Tamanho;

typedef enum { fal, vero } Dico; // Dicotômico, sim ou não, verdadeiro ou falso.

/*
    Em alguns métodos, faz-se uso deste que enumera estructuras
    marcadas por índices.

    Ao invés de indicar um específico, pode-se ordenar
    uma destas opções quando calhar, que, o método que o
    especificar como parâmetro pode lidar a têr o objecto
    da lista.

    Funcções sem tratamento especial deve usar inteiro, somente.
*/
typedef enum {
    índice__primeiro = -1,
    índice__último = -2,
    // Índice qualquer, supõe-se que a funcção devolva
    // o primeiro encontrado à frente. 
    índice__qualquer = -3,
} Índice;

#pragma endregion

#pragma endregion /* DEFINIÇÕES */

#endif // LSVE_CBÇ_GENERAL