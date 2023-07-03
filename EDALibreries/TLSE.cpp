#include "TLSE.h"



TLSE* TLSE_insere(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
}

void TLSE_imprime(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("%d ", p->info);
    p = p->prox;
  }
  printf("\n");
}

void TLSE_libera(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  }
}

TLSE* TLSE_busca(TLSE *l, int elem){
  TLSE *p = l;
  while((p) && (p->info != elem)) p = p->prox;
  return p;
}

TLSE* TLSE_retira(TLSE *l, int elem){
    TLSE* no = l;
    TLSE* ant = NULL;

    if(!no) return NULL;
    if(!(no->prox)){
        free(l);
        return NULL;
    }
    while(no && no->info != elem){
        ant = no;
        no = no->prox;
    }
    if(no){
        if(!ant) l = no->prox;
        else ant->prox = no->prox;
        no = NULL;
        free(no);
    }
    return l;
}
