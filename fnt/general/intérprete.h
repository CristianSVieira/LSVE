#ifndef LSVE_CBÇ_INTÉRPRETE
#define LSVE_CBÇ_INTÉRPRETE

#include "general.h"

#include <stddef.h>

typedef enum {
	rastilho__carece_concedido,
	rastilho__carece_concessão,
	rastilho__carece_concessão_válida,
	rastilho__carece_ficha_válida,
	rastilho__carece_valôr,
	// Quando se tem elementos mais do que esperados.
	rastilho__expressão_excedente,
	// Quando se encontra quebra-de-ficheiro na linha.
	rastilho__encerro_forçado,
	// Linha comentada.
	rastilho__comentário,
	rastilho__nil,
} Tipo_Rastilho;

typedef struct {
	Integral índice;

	Tipo_Rastilho tipo;
	Linha linha;
} Rastilho;


/*
	O quê foi lido?

	Um concedido (variável)?
	Uma concessão direta? Onde se concede o valôr bruto?
*/

typedef enum {
	operação__concedido,				// Clave. 
	operação__concessão_directa,		// O valôr da clave é literalmente o que seguir.
	operação__concessão_passiva,		// O valôr da clave é são as claves de outro ficheiro.
	operação__concessão_objectiva,		// Indica-se o nome da clave e é buscado em outro ficheiro.
	operação__concessão_selectiva,		// O valôr da clave é o que o utilizador seleccionar.
	operação__concessão_corredora,		// Corre-se o commando que segue a clave.
	operação__valôr,					// Valôr da clave.
	operação__nil						// Nada. Terminação das operações
} Tipo_Operação;

/*
	O quê se espera que venha a seguir?
*/
typedef enum {
	expectação__concedido,
	expectação__concessão,
	expectação__valôr,
	expectação__ficha_abre,
	expectação__ficha_fecha,

	expectação__nil // Nada a aguardar/desconhece-se o quê aguardar.
} Expectação;

typedef struct {
	Integral índice;

	Tipo_Operação tipo;
	Expectação expectação;
	Linha linha;
} Operação;

typedef struct {
	Integral índice;

	Operação* operação;
	Linha linha;
} Expressão;

typedef struct {
	Expressão* expressão;
	Rastilho* rastilho;
} Intérprete;

Linha rastilho_têr_linha_por_tipo(Tipo_Rastilho tipo);

void operação_re_definir(Integral operação_n, Expressão ref expressão, Expectação expectação, Tipo_Operação operação_tipo, size_t linha_t);
Operação operação_falha();

Expressão* expressão_têr_por_ficha(Expressão* expressões, Linha ficha);
Expressão expressão_operação_têr_por_ficha(Expressão* expressão, Linha ficha);
Expressão expressão_operação_têr_por_tipo(Expressão* expressão, Tipo_Operação tipo);
Expressão expressão_falha();

void intérprete_agregar(Intérprete ref intérprete, Expressão* expressões, Integral posição);
Integral intérprete_expressões_contar(const Intérprete* intérprete);
void interpretar_linha(Integral ref expressão_n, Linha ref linha, Intérprete ref intérprete);
void interpretar(Linha* ref linhas, Intérprete* intérprete);

#endif // !LSVE_CBÇ_INTÉRPRETE