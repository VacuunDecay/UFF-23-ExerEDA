#include "TARVB.h"
#include "TH.h"
#include "MyUtil.h"
#include <string.h>

#define INPFILE "inputfile.txt"
#define MAXINPSIZE 17
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
    int i = 0, find;
    while(i < a->nchaves){
        if(a->chave[i] == elem) break;

        if(a->chave[i] > elem){
            find = suc(a->filho[i], elem);
            if(find == 0 && i < (a->nchaves)-1) 
                return a->chave[i+1];
            return elem;
        }

        i++;
    }

    if(find != a->chave[i] && i < a->nchaves)
        return suc(a->filho[i+1], elem);

    if(!a->folha)
        return a->filho[i+1]->chave[0];
    
    if(i<a->nchaves-1)
        return a->chave[i+1];

    return 0;
    
}

int main(void){
    TARVB* tree = TARVB_Cria(T);
    TARVB* tree2 = TARVB_Cria(T);

    int i = 0;
    int *inp = (int*)malloc(sizeof(int)*MAXINPSIZE);

    //fillFileWithRandomIntegers(INPFILE, 10, 99, 80);
    inp = loadIntegersFromFile(INPFILE, &i, MAXINPSIZE);

    for(int j = 0; j < i; j++){
        tree = TARVB_Insere(tree, inp[j], T);
    }

    tree2 = copia(tree);
    TARVB_Imprime(tree);

    ln();ln();
    TARVB_Imprime(tree2);
    ln();
    printf("suc de 44:%d\n", suc(tree, 44));
    printf("suc de 45:%d\n", suc(tree, 45));
    printf("suc de 50:%d\n", suc(tree, 50));
    printf("suc de 98:%d\n", suc(tree, 98));


    printIntVet(inp, i);


    free(inp);
    return 0;
}

