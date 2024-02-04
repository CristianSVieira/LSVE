#ifndef LSVE_CBÇ_GENERAL
#define LSVE_CBÇ_GENERAL

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define numero_da_sorte 20231210
#define numero_do_azar 20191201

#define origem main
#define matrice(matrice, índice) matrice[índice]

#define tamanho_de(tipo) sizeof(tipo)

/* DEFINIÇÕES FUNCCIONAIS */
#define juntar(a, b) a##b
#define juntar_(a, b) juntar(a, b) // O acolhido de cima. Útil quando os parâmetros outras definições.


/* DEFINIÇÕES DE VISIBILIDADE */
#define privado static
#define exclusivo privado
#define público 

/* DEFINIÇÕES DE SUPORTE LINGÜÍSTICO */
#define a
#define à
#define ao
#define o
#define é
#define fôr
#define de

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

/* DEFINIÇÕES CONDICIONAIS */
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

#define norma default

#define ref *

#define nil 0 // Nil para ponteiros.
#define inválido (-1) // Posição inválida para matriz.

#define nile(tipo) (tipo) { 0 } // Nil para estructuras, sem ponteiros.

#define retorna(algo) return algo;
#define devolve(algo) retorna(algo)

/* CONSTANTES LINHAIS */
#define nil_linha '\0'
#define salta_linha '\n'
#define linha_tabulação '\t'

/* Tipos customizados */
typedef void Vago;
typedef void* Algum;

typedef char Charactére;
typedef char* Linha;
typedef int Integral;

typedef FILE Ficheiro;
typedef size_t Tamanho;

typedef enum { fal, vero } Dico; // Tipo dicotômico, sim ou não, verdadeiro ou falso.

/*
    Em alguns métodos, faz-se uso deste que enumera estructuras
    marcadas por índices.

    Ao invés de indicar um específico, pode-se ordenar
    uma destas opções quando calhar, que, o método que o
    especificar como parâmetro pode lidar a têr o objecto
    da lista.

    Métodos sem tratamento especial deve usar inteiro, somente.
*/
typedef enum {
    índice__primeiro = -1,
    índice__último = -2,
    /*
        "Qualquer" que for encontrado, geralmente usado quando
        em conjunto a outros condicionais, em caso de
        identificações repetidas.
    */
    índice__qualquer = -3,
} Índice;


#endif // LSVE_CBÇ_GENERAL