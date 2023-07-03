#include "TLSE.h"
#include "TAB.h"
#include "TABB.h"
#include "TAVL.h"
#include "TG.h"

#include "Rev2.h"
#include "Listas.h"
#include "PlayGronwdArquivosBinarios.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testeListas(){
TLSE* lista = NULL;
    TLSE* lista2 = NULL;

    lista = TLSE_insere(lista, 1);
    lista = TLSE_insere(lista, 2);
    lista = TLSE_insere(lista, 3);
    lista = TLSE_insere(lista, 4);
    lista = TLSE_insere(lista, 5);

    //TLSE_imprime(lista);

    lista2 = copiaRec(lista);
    lista = inverteRet(lista);

    lista = TLSE_insere(lista, 5);
    lista = TLSE_insere(lista, 2);
    lista = TLSE_insere(lista, 3);
    TLSE_imprime(lista);
    lista2 = copia(lista);
    TLSE_imprime(lista2);
    lista = TLSE_insere(lista, 10);
    TLSE_imprime(lista);
    if(igual(lista, lista2)){
        printf("igual\n");
    }else printf("diferente\n");

    junta_listas(lista, lista2);

    TLSE_imprime(lista);

    TLSE_libera(lista);
    //TLSE_libera(lista2);

}
void testesABBeAB(){
    srand(3);

    TAB *no1 = TAB_cria(1, NULL, NULL);
    TAB *no2 = TAB_cria(2, NULL, NULL);
    TAB *no3 = TAB_cria(3, NULL, NULL);
    TAB *no4 = TAB_cria(4, NULL, NULL);
    TAB *no5 = TAB_cria(5, no1, no2);
    TAB *no6 = TAB_cria(6, no3, no4);
    TAB *tree1 = TAB_cria(7, no5, no6);


    TAB *ne1 = TAB_cria(rand()%89+10, NULL, NULL);
    TAB *ne2 = TAB_cria(rand()%89+10, NULL, NULL);
    TAB *ne3 = TAB_cria(rand()%89+10, NULL, NULL);
    TAB *ne4 = TAB_cria(rand()%89+10, ne1, ne2);
    TAB *ne5 = TAB_cria(rand()%89+10, NULL, ne3);
    TAB *ne6 = TAB_cria(rand()%89+10, ne4, NULL);
    TAB *ne7 = TAB_cria(rand()%89+10, NULL, ne5);
    TAB *tree2 = TAB_cria(rand()%89+10, ne6, ne7);

    TABB *tree3 = TABB_cria(rand()%89+10, NULL, NULL);
    TABB *nu1 = TABB_insere(tree3, rand()%89+10);
    TABB *nu2 = TABB_insere(tree3, rand()%89+10);
    TABB *nu3 = TABB_insere(tree3, rand()%89+10);
    TABB *nu4 = TABB_insere(tree3, rand()%89+10);
    TABB *nu5 = TABB_insere(tree3, rand()%89+10);
    TABB *nu6 = TABB_insere(tree3, rand()%89+10);

    TAB* cop = copia(tree1);
    TAB* esp = espelho(tree1);

    ///////////////////////////////////////
    TAB_imp_ident(tree2);
    ln();
    PrintVetI(mN(tree3, 50), 8);
    //TABB_imp_sim(retira_inpares(tree3));
//    printf("%d\n", a);
    ln();
    //printf("%d\n", contSmaller(tree3, 0, 50));


/*
    ln();
    if(igual(cop, tree1)) printf("Iguais");
    else printf("Diferentes");
    ln();
    TAB_imp_pos(tree2);
    ln();
    printf("%d", maior(tree2)->info);
    ln();
    printf("%d", menor(tree2)->info);
    */
/*
    TAB_imp_pos(tree1);
    ln();
    TAB_imp_pos(cop);
    ln();
    TAB_imp_pos(esp);
*/
    TAB_libera(tree1);
    TAB_libera(tree2);
    TABB_libera(tree3);
}
void testeAVL(){

    TAVL* avl1 = NULL;

    avl1 = TAVL_insere(64, avl1);

    int inp[] = {01, 64, 12, 18, 66, 38, 95, 58, 59, 70, 68, 39, 62, 07, 60, 43, 16, 67, 34, 35};
    int rem[] = {50};//, 95, 70, 60, 35};
    int num = 0;
    printf("digite n\n -se n > 0 -> adiciona um valor a arvore\n-se n < 0 -> remove um valor da arvore\n-se n = 0 -> finaliza o programa");
    do{
        scanf("%d", &num);

        if(num > 0)
            avl1 = TAVL_insere(num, avl1);
        else if(num < 0)
            avl1 = TAVL_retira((-1*num), avl1);

        TAVL_imprime(avl1);
    }while(num != 0);
    /*
    for(int i = 0; i < 17; i++){
        avl1 = TAVL_insere(inp[i], avl1);
    }

    cls();
    TAVL_imprime(avl1);
    for(int i = 0; i < 5; i++){
        avl1 = TAVL_retira(rem[i], avl1);
    }
*/
}
void bimplay(){
    int* vet = randVetNT(100);

    printVet(vet);
    ln();
    vet = bubleSort(vet);
    printVet(vet);
}
void graphsTest(){
    srand(2);

    TG* gr = TG_inicializa();


    gr = TG_ins_no(gr, 6);
    gr = TG_ins_no(gr, 5);
    gr = TG_ins_no(gr, 4);
    gr = TG_ins_no(gr, 3);
    gr = TG_ins_no(gr, 2);
    gr = TG_ins_no(gr, 1);

    TG_ins_aresta(gr, 1, 2);
    TG_ins_aresta(gr, 1, 3);
    TG_ins_aresta(gr, 1, 4);

    TG_ins_aresta(gr, 3, 4);
    TG_ins_aresta(gr, 5, 6);
    TG_ins_aresta(gr, 6, 4);


    //printf("%d", nn(gr));
    TG_imprime(gr);
    ln();
    haveKOrd(gr, 3)?printf("sim"):printf("nao");
    //printf("%d", na(gr));



}
void randFileGentText1(){
    NewRanbFile(10, "text", 99, 10);
    FILE* fp = fopen("text.txt", "r");
    if(!fp)exit(1);

    char num[100];
    while(fscanf(fp, "%s", &num) == 1){
        printf("%s ", num);
    }
    fclose(fp);
}
void testRetRepet(){
    retRepet("in-1.txt", "out-1.txt");
    retRepet("in-2.txt", "out-2.txt");
    retRepet("in-3.txt", "out-3.txt");
    retRepet("in-4.txt", "out-4.txt");

}
void testeMedia(){
    media("Min-1.txt", "Mout-1.txt");

}


#include "TARVB.h"
#include "TARVBM.h"
#include "MyUtil.h"

#define INPFILE "inputfile.txt"
#define MAXINPSIZE 23
#define T 2

//ToDo
TARVB* copia(TARVB *a){
    TARVB* tree= TARVB_Cria(T);
    if(!a) return tree;

    tree->folha = a->folha;
    tree->nchaves = a->nchaves;
    for(int i = 0; i < a->nchaves; i++){
        tree->chave[i] = a->chave[i];
    }

    if(a->folha) return tree;
    for(int i = 0; i <= a->nchaves; i++){
        tree->filho[i] = copia(a->filho[i]);
        printf("cha:%d fi:%d\n", a->chave[i], i);
    }
    return tree;
}

int suc(TARVB* a, int elem){
    int i = 0, find = 2000000, fo;
    while(i <= a->nchaves){
        fo = a->chave[i];
        if(a->chave[i] == elem) break;

        if(a->chave[i] > elem){
            find = suc(a->filho[i], elem);
            if(find == 2000000 && i < a->nchaves)
                return a->chave[i];
            return find;
        }

        i++;
    }

    if(elem != a->chave[i] && i < a->nchaves)
        return suc(a->filho[i+1], elem);

    if(!a->folha && elem == a->chave[i])
        return a->filho[i+1]->chave[0];

    if(i<a->nchaves-1)
        return a->chave[i+1];

    return 2000000;
}

int* mN_aux(TARVB* a,int N, int* tam){
    if(!a) return NULL;
    int info = a->chave[0], tinfo = *tam;
    int i, j;
    if(a->folha){
        int ta = a->nchaves;
        int* vet = (int*)malloc(sizeof(int)* (ta+1));
        ta = 0;
        for(i = 0; i < a->nchaves; i++){
            if(a->chave[i] > N){
                vet[i+1] = a->chave[i];
                ta++;
            }
        }
        *tam += ta;
        vet[0] = ta;
        return vet;
    }


    int** vet = (int**)malloc(sizeof(int*)* (a->nchaves+1));

    for(i = 0; i < a->nchaves; i++){

        vet[i] = mN_aux(a->filho[i], N, tam);
    }
    vet[i] = mN_aux(a->filho[i], N, tam);

    int lta = 0; tinfo = *tam;
    int* rvet =(int*)malloc(sizeof(int)*(a->nchaves+1+(*tam)));

    for(i = 0; i < a->nchaves; i++){
        for(j = 0; j < vet[i][0]; j++){
            rvet[j+lta+1] = vet[i][j+1]; //possição 0 usada para guardar o tamanho do vetor
        }
        if(a->chave[i] > N){
            rvet[j+lta+1] = a->chave[i];
            lta += j+1;
        }
    }
    for(j = 0; j < vet[i][0]; j++){
        rvet[j+lta+1] = vet[i][j+1]; //possição 0 usada para guardar o tamanho do vetor
    }
    lta += j;
    rvet[0] = lta;
    *tam = lta;

    for(j = 0; j < a->nchaves+1; j++){
        free(vet[i]);
    }
    free(vet);
    return rvet;
}

int* mN(TARVB* a,int N, int* tam){
    int* vet = mN_aux(a, N, tam);
    int* rvet =(int*)malloc(sizeof(int)* vet[0]);
    for(int i = 0; i < vet[0]; i++){
        rvet[i] = vet[i+1];
    }
    vet[0] = 0;
    free(vet);
    return rvet;
}

TARVB* maior(TARVB* a){
    if(!a)return NULL;
    if(a->folha) return a;
    return maior(a->filho[a->nchaves]);
}


TARVB* menor(TARVB* a){
    if(!a)return NULL;
    if(a->folha) return a;
    return menor(a->filho[0]);
}

int igual(TARVB* a, TARVB* b){
    if(!a && !b) return 1;

    if(!a||!b) return 0;

    if(a->folha != b->folha) return 0;

    if(a->nchaves != b->nchaves) return 0;

    for(int i = 0; i < a->nchaves; i++){
        if(a->chave[i] != b->chave[i]) return 0;
    }

    if(!a->folha){
        int i;
        for(i = 0; i < a->nchaves; i++){
            if(!igual(a->filho[i], b->filho[i])) return 0;
        }
        if(!igual(a->filho[i], b->filho[i])) return 0;
    }
    return 1;
}

int ni(TARVB* a){
    if(!a) return 0;

    if(a->folha) return 0;

    int i, tam = 1;

    for(i = 0; i < a->nchaves; i++){
        tam += ni(a->filho[i]);
    }
    tam += ni(a->filho[i]);

    return tam;
}

int nf(TARVB* a){
    if(!a) return 0;

    if(a->folha) return 1;

    int i, tam = 0;

    for(i = 0; i < a->nchaves; i++){
        tam += nf(a->filho[i]);
    }
    tam += nf(a->filho[i]);

    return tam;
}

TARVBM* copia(TARVBM* a){
    if(!a) return a;

    TARVBM* novo = TARVBM_cria(T);

    novo->folha = a->folha;
    novo->nchaves = a->nchaves;

    int i;
    for(i = 0; i < a->nchaves; i++){
        novo->chave[i] = a->chave[i];
    }

    if(a->folha) return novo;

    for(i = 0; i < a->nchaves; i++)
        novo->filho[i] = copia(a->filho[i]);
    novo->filho[i] = copia(a->filho[i]);

    for(i = 0; i < a->nchaves; i++)
        novo->filho[i]->prox = novo->filho[i+1];

    return novo;
}

TARVBM* nao_par(TARVBM* a){
    if(!a) return a;

    TARVBM* no = a;
    int i;

    while(!no->folha)
        no = no->filho[0];

    while(no){
        for(i = 0; i < no->nchaves; i++){
            if(no->chave[i]%2 == 0) a = TARVBM_retira(a, no->chave[i], T);
        }
        no = no->prox;
    }

    return a;
}

void testeTARVBM();
void testeTARVB();
int main(void){

    testeTARVBM();

    return 0;
}
void testeTARVB(){
    TARVB* tree = TARVB_Cria(T);
    TARVB* tree2 = TARVB_Cria(T);

    int i = 0;
    int *inp = (int*)malloc(sizeof(int)*MAXINPSIZE);

    //fillFileWithRandomIntegers(INPFILE, 10, 99, 80);
    inp = loadIntegersFromFile(INPFILE, &i, MAXINPSIZE);

    for(int j = 0; j < i; j++){
        tree = TARVB_Insere(tree, inp[j], T);
//        TARVB_Imprime(tree);
    }
    char onp = 1;

    TARVB_Imprime(tree);
    int inp2[5] = {50, 95, 70, 60, 35};
    for(int j = 0; j < 5; j++){
        tree = TARVB_Insere(tree, inp2[j], T);
//        TARVB_Imprime(tree);
    }
    /*
    while(1){
        scanf("%d", &onp);
        if(onp == 0) break;
        printf("Removendo: %d\n", onp);
        tree = TARVB_Retira(tree, onp, 2);
        TARVB_Imprime(tree);
    }
*/
    tree2 = copia(tree);

    ln();ln();
    TARVB_Imprime(tree2);
    ln();
    for(int j = 0; j < i; j++)
        printf("suc de %d:%d\n", inp[j], suc(tree, inp[j]));

    int tam = 0;
    int* vet = mN(tree ,50, &tam);
    TARVB_Imprime(tree2);

    printIntVet(vet, tam);
    printIntVet(inp, i);

    TARVB* maior1 = maior(tree);
    TARVB* menor1 = menor(tree);

    printf("maior: %d, menor: %d\n", maior1->chave[(maior1->nchaves)-1], menor1->chave[0]);

    TARVB* tree3 = TARVB_Retira(tree, 99, T);
    if(igual(tree, tree2)){
        printf("siiiii\n");
    }
    else{
        printf("noooooo\n");
    }
    if(igual(tree, tree3)){
        printf("siiiii\n");
    }
    else{
        printf("noooooo\n");
    }

    printf("INternos: %d\nEXternos: %d", ni(tree), nf(tree));
    free(inp);

}


void testeTARVBM(){
    TARVBM* tree = TARVBM_cria(T);
    TARVBM* tree2 = TARVBM_cria(T);

    int onp = 1;
    while(1){
        scanf("%d", &onp);
        if(onp == 0) break;
        if(onp > 0){
            printf("Incerindo: %d\n", onp);
            tree = TARVBM_insere(tree, onp, 2);
            TARVBM_imprime(tree);
        }
        if(onp < 0){
            printf("Removendo: %d\n", onp);
            tree = TARVBM_retira(tree, -1*onp, 2);
            TARVBM_imprime(tree);
        }

    }

    tree2 = copia(tree);

    tree = nao_par(tree);

    TARVBM_imprime(tree);
    TARVBM_imprime(tree2);

}

