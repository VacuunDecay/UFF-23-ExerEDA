#include <stdio.h>
#include <stdlib.h>

struct arvbinbusca{
  int info;
  struct arvbinbusca *esq, *dir;
};

typedef struct arvbinbusca TABB;

TABB *TABB_inicializa(void);
TABB *TABB_cria(int raiz, TABB *esq, TABB *dir);

void TABB_imp_pre(TABB *a);
void TABB_imp_pos(TABB *a);
void TABB_imp_sim(TABB *a);
void TABB_imp_ident(TABB *a);

void TABB_libera(TABB *a);

TABB *TABB_busca(TABB *a, int elem);

TABB *TABB_insere(TABB *a, int elem);
TABB *TABB_retira(TABB *a, int info);


TABB* maior(TABB *a);
TABB* menor(TABB* a);
TABB* retira_inpares(TABB* a);

/*retornar todos os numeros menores que
n sob a forma de um vetor*/
/*to do*/
int contSmaller(TABB* a, int cont, int n);

int* mN(TABB *a, int n);

/*Implemente uma ABB heterogenea
essa arvore pode conter informaçes para
triangulos retangolos circulos e trapesios
use a area dessas formas geomentricas para
ordena-las*/
