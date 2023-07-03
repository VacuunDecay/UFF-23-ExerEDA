#include "TABB.h"



TABB *TABB_inicializa(void){
  return NULL;
}

TABB *TABB_cria(int raiz, TABB *esq, TABB *dir){
  TABB *novo = (TABB *) malloc(sizeof(TABB));
  novo->info = raiz;
  novo->esq = esq;
  novo->dir = dir;
  return novo;
}

void TABB_imp_pre(TABB *a){
  if(a){
    printf("%d ", a->info);
    TABB_imp_pre(a->esq);
    TABB_imp_pre(a->dir);
  }
}

void TABB_imp_pos(TABB *a){
  if(a){
    TABB_imp_pos(a->esq);
    TABB_imp_pos(a->dir);
    printf("%d ", a->info);
  }
}

void TABB_imp_sim(TABB *a){
  if(a){
    TABB_imp_sim(a->esq);
    printf("%d ", a->info);
    TABB_imp_sim(a->dir);
  }
}

void imp_aux(TABB *a, int andar){
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

void TABB_imp_ident(TABB *a){
  imp_aux(a, 0);
}

void TABB_libera(TABB *a){
  if(a){
    TABB_libera(a->esq);
    TABB_libera(a->dir);
    free(a);
  }
}

TABB *TABB_busca(TABB *a, int elem){
  if((!a) || (a->info == elem)) return a;
  if(a->info > elem) return TABB_busca(a->esq, elem);
  return TABB_busca(a->dir, elem);
}

TABB *TABB_insere(TABB *a, int elem){
  if(!a) return TABB_cria(elem, NULL, NULL);
  if(a->info > elem) a->esq = TABB_insere(a->esq, elem);
  else if (a->info < elem) a->dir = TABB_insere(a->dir, elem);
  return a;
}

TABB *TABB_retira(TABB *a, int info){
  if(!a) return a;
  if(info < a->info)
    a->esq = TABB_retira(a->esq, info);
  else if(info > a->info)
    a->dir = TABB_retira(a->dir, info);
  else{ //info encontrada
    if((!a->esq) && (!a->dir)){ //CASO (1)
      free(a);
      a = NULL;
    }
    else if((!a->esq) || (!a->dir)){ //CASO (2)
      TABB *temp = a;
      if(!a->esq) a = a->dir;
      else a = a->esq;
      free(temp);
    }
    else{ //CASO (3)
      TABB *filho = a->esq;
      while(filho->dir) filho = filho->dir;
      a->info = filho->info;
      filho->info = info;
      a->esq = TABB_retira(a->esq, info);
    }
  }
  return a;
}



///////////////////////////////////////////////////


TABB* maior(TABB *a){
    if(!a) return a;
    if(!a->dir) return a;

    return maior(a->dir);
}

TABB* menor(TABB* a){
    if(!a) return a;
    if(!a->esq) return a;

    return menor(a->esq);
}

TABB* retira_inpares(TABB* a){
    if(!a) return a;
    TABB* arv = a;
    int info = arv->info;
    if((a->info)%2 == 1){
        a = TABB_retira(a, a->info);
    }
    if(a){
        a->esq = retira_inpares(a->esq);
        a->dir = retira_inpares(a->dir);
        TABB_imp_sim(a);
        printf("\n");
    }

    return a;
}

/*retornar todos os numeros menores que
n sob a forma de um vetor*//*ToDo*/
int contSmaller(TABB* a, int cont, int n){
    if(!a) return 0;
    int i = a->info;

    if(a->info >= n)
        cont += contSmaller(a->esq, cont, n);

    cont += contSmaller(a->dir, cont, n);
    cont++;

    return cont;
}
int* pmN(TABB* a){/*WiP*/
    int* vet = (int*)malloc(sizeof(int));
    int* vet2 = (int*)malloc(sizeof(int));
    if(!a){
        vet = (int*)malloc(sizeof(int));
        vet[0] = 1;
        return vet;
    }
    vet = pmN(a->esq);
    realloc(vet, sizeof(int)*(vet[0]+1));
    vet[vet[0]] = a->info;
    vet[0]++;
    vet2 = pmN(a->dir);
    if(vet2[0] != 1){
        realloc(vet, sizeof(int)*(vet2[0]-1));
        vet[0] += vet2[0]-1;
        for(int i = 0; i < vet2[0]-1; i++){
            vet[i+vet2[0]] = vet2[i+1];
        }
    }
    return vet;
}
TABB* acha_menor(TABB* a, int n){
    if(!a) return a;
    if(a->info > n){
        return acha_menor(a->esq, n);
    }
    if(a->info <= n && a->dir->info > n)
        return a;

}
int* mN(TABB *a, int n){
    if(!a) return NULL;
    a = acha_menor(a, n);
    int* vet = pmN(a);
    int tam = vet[0];
    for(int i = 0; i < tam-2; i++){
        vet[i] = vet[i+1];
    }
    realloc(vet, sizeof(int)*(tam-1));
    return vet;
}
