#include "TARVB.h"
#include "TLSEINT.h"
#include "MyUtil.h"


int* mN(TARVB*a, int N, int *tam);

int main(){
    TARVB* tree = TARVB_Cria(2);
    
    char onp = 1;
    while(1){
        scanf("%d", &onp);
        if(onp == 0) break;
        printf("Inserindo: %d\n", onp);
        tree = TARVB_Insere(tree, onp, 2);
        TARVB_Imprime(tree);
    }

    while(1){
        scanf("%d", &onp);
        if(onp == 0) break;
        printf("Removendo: %d\n", onp);
        tree = TARVB_Retira(tree, onp, 2);
        TARVB_Imprime(tree);
    }





    int tam = 0;
    int* vet;
    //vet = mN(tree, 50, &tam);

    //printIntVet(vet, tam);
    //scanf("%d", &tam);
    return 0;
}


