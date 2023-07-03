#ifndef TAB_H
#define TAB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arvbin{
  int info;
  int cor;
  struct arvbin *esq, *dir;
}TAB;

TAB *TAB_inicializa(void);
TAB *TAB_cria(int raiz, TAB *esq, TAB *dir);

void TAB_imp_pre(TAB *a);
void TAB_imp_pos(TAB *a);
void TAB_imp_sim(TAB *a);
void TAB_imp_ident(TAB *a);

void TAB_libera(TAB *a);

TAB *TAB_busca(TAB *a, int elem);




TAB* copia(TAB *a); //Done
TAB* espelho(TAB *a);//Done
TAB* maior(TAB *a); //Done
TAB* menor(TAB *a);//Done
int igual(TAB* a1, TAB* a2); //done

TAB* retira_pares (TAB* arv);
/*
int cor
colorir uma arvore balanceada de forma que o pai
nunca tenha a mesma cor que o filho
0 -> sem cor
1 -> vermelho
2 -> laranja
*/
TAB* colore (TAB* arv);

/*quantos nois tem a arvore*/
int ni(TAB *a);

/*quantas folhas tem a arvore*/
int nf (TAB *a);



#endif // TAB_H
