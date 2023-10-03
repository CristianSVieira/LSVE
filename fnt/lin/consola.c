#include "consola.h"
#include "teclado/ASCII.h"
#include "linha.h"

#include <stdio.h>
#include <stdlib.h>

void
consola_limpar()
{
    system("cls");
}

void
consola_opção_destacar(Linha opções, int opçãoSeleccionada) {
	consola_limpar();

	for (int i = 0; opções[i] differente linha_nil; i++)
	{
		se (opçãoSeleccionada differente i) { printf("%s\n", opções[i]); }
		se_não {
			printf("\x1b[34;46m%s\n", opções[i]);
			printf("\x1b[39m");
			printf("\x1b[49m");
		}
	}
}

int
consola_construir_menu_de_opções(Linha opções) {
	int opção = 0;

	consola_opção_destacar(opções, opção);

	Linha opçãoSeleccionada = "";
	int c = -1;
	while (c) {
		c = getc(stdin);

		switch (c) {
		case clave__ponta_cima: { printf("CIMA"); opção--; consola_opção_destacar(opções, opção); printf("%d ", opção); break; }
		case clave__ponta_baixo: { printf("BAIXO"); opção++; consola_opção_destacar(opções, opção); printf("%d ", opção); break; }
		case clave__ponta_esquerda: { printf("ESQUERDA"); opção--; consola_opção_destacar(opções, opção); printf("%d ", opção); break; }
			   //case 77: { printf("DIREITA"); opção++; consola_opção_destacar(opção, opções); break; }
		case clave__ponta_direita: {
			consola_opção_destacar(opções, opção);
			printf("ENTRA - %s\n", opções[opção]);
			goto ciclo_quebrar;
		}
		case clave__entra: {
			consola_opção_destacar(opções, opção);
			printf("ENTRA - %s\n", opções[opção]);
			goto ciclo_quebrar;
		}
        case clave__escape: { printf("ESCAPE"); return -1; }
		default: { break; }
		}
	}

ciclo_quebrar:
	return opção;
}
