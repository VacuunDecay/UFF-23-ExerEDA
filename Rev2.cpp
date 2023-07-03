#include "Rev2.h"
#include <stdio.h>
#include <stdlib.h>

void PrintVetI(int *vet, int maxSize) {
    int i = 0;
    while (i < maxSize && vet[i] >= 0) {
        printf("%d ", vet[i]);
        i++;
    }
    printf("\n");
}

void PrintVetI(int *vet) {
    int i = 0;
    while (vet[i] >= 0) {
        printf("%d ", vet[i]);
        i++;
    }
    printf("\n");
}

int* IntToVet(int num, int iter){
    if(num >= 10 && num <= 99){
        int* vet = (int*)malloc(num * sizeof(int)*iter+1);
        vet[iter-1] = num/10;
        vet[iter-2] = num%10;
        vet[iter] = -1;
        return vet;
    }
    int* vet = IntToVet(num/10, iter+1);

    vet[iter-2] = num%10;

    return vet;

}

int* ContOcorrencia(int* vet, int maxSize){
    int* oco = (int*)malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; i++)
        oco[i] = 0;

    for(int i = 0; vet[i] >= 0 && i < maxSize; i++)
        oco[vet[i]] ++;

    return oco;
}

int* ContOcorrencia(int* vet){
    int* oco = (int*)malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; i++)
        oco[i] = 0;

    for(int i = 0; vet[i] >= 0; i++)
        oco[vet[i]] ++;

    return oco;
}

int IsVetIqual(int* vet1, int* vet2, int maxSize){
    for(int i = 0; i < maxSize; i++){
        if(vet1[i] != vet2[i])return 0;
    }
    return 1;
}

int IsPermut(int num1, int num2){
    int* vNum1 = IntToVet(num1, 2);
    int* vNum2 = IntToVet(num2, 2);

    int* oc1 = ContOcorrencia(vNum1);
    int* oc2 = ContOcorrencia(vNum2);

    int temp = IsVetIqual(oc1, oc2, 10);

    free(vNum1);
    free(vNum2);
    free(oc1);
    free(oc2);

    return temp;
};

int IsCharPalindrodo(char* palavra){
    int sizePalavra = 0;

    for(int i = 0; palavra[i] != '\0'; i++){
        sizePalavra++;
    }
    int i = 0, j = sizePalavra;
    while(i < sizePalavra/2){
        if(palavra[i] != palavra[j-1]){
            return 0;
        }
        j--;
        i++;
    }

    return 1;
}

int* IntDecToBim(int num){
    int* bim = (int*)malloc(sizeof(int)* 100);
    int sizBim = 0;
    int i = 0;
    if(num == 0){
        realloc(bim, sizeof(int)* 2);
        bim[0] = 0;
        bim[1] = -1;
        return bim;
    }

    while(num >= 1){
        bim[i] = num%2;
        num /= 2;
        i++;
        sizBim++;
    }

    realloc(bim, sizeof(int)* sizBim+1);
    bim[sizBim] = -1;
    return bim;
}

//-------------------------------------------------------------//
//-------------------Exemplo pros exercicios-------------------//
//-------------------------------------------------------------//


void Rev2Exercicio3(){
    //int vet[9] = {1, 2, 3, 4, 5, 6, 7, 8, -1};
    int num1 = 574301;
    int num2 = 543510;

    if(IsPermut(num1, num2)){
        printf("%d e %d sao permutacos\n", num1, num2);
    }else{
        printf("%d e %d nao sao permutacos\n", num1, num2);
    }
}

void Rev2Exercicio4(){
    char* pav1 = "ftnhhtf";

    if(IsCharPalindrodo(pav1)){
        printf("%s e palimbrodo\n", pav1);
    }else{
        printf("%s nao e palimbrodo\n", pav1);
    }
}

void Rev2Exercicio5(){
    int num = 0;

    while(num >= 0){
        printf("Digite o numero para converter pra binario: ");
        scanf("%d", &num);
        PrintVetI(IntDecToBim(num));


    }
}

void Rev2Exercicio6(){
    int m = 1, n = 2;
    int* t = NULL;
    int cont = 0;

    while(m != 0 && n != 0){
        scanf("%d %d", &n, &m);

        if (m == 0 || n == 0){
            break;
        }

        t = (int*)malloc(sizeof(int)*m);

        for(int i = 0; i < m; i++)
            scanf("%d", &t[i]);

        for(int i = 0; i <= n; i++){
            int rep = 0;
            for(int j = 0; j < m; j++){
                if(t[j] == i && rep != 0){
                    rep = 0;
                    cont ++;
                }else if(t[j] == i && rep == 0){
                    rep = 1;
                }
            }
        }

        printf("%d\n", cont);
        cont = 0;
        free(t);
    }
}
