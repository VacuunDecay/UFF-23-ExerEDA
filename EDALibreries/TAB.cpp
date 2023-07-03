#include "TAB.h"

TAB *TAB_inicializa(void){
  return NULL;
}

TAB *TAB_cria(int raiz, TAB *esq, TAB *dir){
  TAB *novo = (TAB *) malloc(sizeof(TAB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  return novo;
}

TAB *TAB_busca(TAB *a, int elem){
  if((!a) || (a->info == elem)) return a;
  TAB *resp = TAB_busca(a->esq, elem);
  if(resp) return resp;
  return TAB_busca(a->dir, elem);
}

void TAB_imp_pre(TAB *a){
  if(a){
    printf("%d ", a->info);
    TAB_imp_pre(a->esq);
    TAB_imp_pre(a->dir);
  }
}

void TAB_imp_pos(TAB *a){
  if(a){
    TAB_imp_pos(a->esq);
    TAB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

void TAB_imp_sim(TAB *a){
  if(a){
    TAB_imp_sim(a->esq);
    printf("%d ", a->info);
    TAB_imp_sim(a->dir);
  }
}

void imp_aux(TAB *a, int andar){
  int j;
  if(a){
    imp_aux(a->esq, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t"); //printf("   ");
    printf("%d\n", a->info);
    imp_aux(a->dir, andar + 1);
  }
  else{
   for(j = 0; j <= andar; j++) printf("\t");
   printf("N\n");
  }
}

void TAB_imp_ident(TAB *a){
  imp_aux(a, 0);
}

void TAB_libera(TAB *a){
  if(a){
    TAB_libera(a->esq);
    TAB_libera(a->dir);
    free(a);
  }
}

/*****************************/

TAB* copia(TAB *a){
  TAB* no = (TAB*)malloc(sizeof(TAB));
  if(!a) return a;
  no = TAB_cria(a->info, copia(a->esq), copia(a->dir));
  return no;
}

TAB* espelho(TAB *a){
  TAB* no = (TAB*)malloc(sizeof(TAB));
  if(!a) return a;
  no = TAB_cria(a->info, espelho(a->dir), espelho(a->esq));
  return no;
}

TAB* maior(TAB *a){
    if(!a) return a;
    //printf("%d \n",a->info);
    TAB* noEsq = maior(a->esq);
    TAB* noDir = maior(a->dir);

    if(!noEsq && !noDir) return a;
    if(!noEsq) return noDir;
    if(!noDir) return noEsq;

    if(a->info >= noDir->info && a->info >=noEsq->info) return a;

    if(noEsq->info >= noDir->info){
        return noEsq;
    }else {
        return noDir;
    }
}

TAB* menor(TAB *a){
    if(!a) return a;
    //printf("%d \n",a->info);
    TAB* noEsq = menor(a->esq);
    TAB* noDir = menor(a->dir);

    if(!noEsq && !noDir) return a;
    if(!noEsq) return noDir;
    if(!noDir) return noEsq;

    if(a->info <= noDir->info && a->info >=noEsq->info) return a;

    if(noEsq->info <= noDir->info){
        return noEsq;
    }else {
        return noDir;
    }
}

int igual(TAB* a1, TAB* a2){
    if(!a1 && !a2) return 1;
    if(!a1) return 0;
    if(!a2) return 0;

    if(a1->info != a2->info) return 0;

    if(!igual(a1->esq, a2->esq)) return 0;
    if(!igual(a1->dir, a2->dir)) return 0;

    return 1;
}

TAB* retira_pares (TAB* arv){

};
/*
int cor
colorir uma arvore balanceada de forma que o pai
nunca tenha a mesma cor que o filho
0 -> sem cor
1 -> vermelho
2 -> laranja
*/
TAB* colore (TAB* a){
    if(!a) return a;

    colore(a->esq);
    colore(a->dir);
    if(!(a->esq)){
        a->cor = 1;
        return a;
    }
    if(a->esq->cor == 1){
        a->cor = 2;
    }
    if(a->esq->cor == 2){
        a->cor = 1;
    }
    return a;
};

void imp_aux_cor(TAB *a, int andar){
  int j;
  if(a){
    imp_aux_cor(a->esq, andar + 1);
    for(j = 0; j <= andar; j++) printf("\t"); //printf("   ");
    printf("%d\n", a->cor);
    imp_aux_cor(a->dir, andar + 1);
  }
  else{
   for(j = 0; j <= andar; j++) printf("\t");
   printf("N\n");
  }
}

void TAB_imp_ident_cor(TAB *a){
  imp_aux_cor(a, 0);
}
/*quantos nois tem a arvore*/
int ni(TAB *a){
    if(!a) return 0;

    int cont = 0;
    cont += ni(a->esq);
    cont += ni(a->dir);

    if(a->esq || a->dir)
        return cont+1;
    return 0;
};

/*quantas folhas tem a arvore*/
int nf (TAB *a){
    if(!a) return 0;

    int cont = 0;
    cont += nf(a->esq);
    cont += nf(a->dir);

    if(!(a->esq || a->dir))
        return cont+1;
    return cont;


};


















