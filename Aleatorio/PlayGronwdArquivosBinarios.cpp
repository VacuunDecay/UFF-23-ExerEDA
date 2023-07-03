#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "PlayGronwdArquivosBinarios.h"

const int MAX_INT = 1000000;
const int MIN_INT = -1000000;

#define TRUE = 1
#define FALSE = 0

/*
Little cheat sheet:

- char* strcpy(char* out, char* in);
- char* strcat(char*
*/
//void cls(){
//    system(CLEAR_COMMAND);
//
//}

int* randVetNT(int tam){// a randon vector finished in -1
    timeElapsed();
    if(tam < 0)return NULL;

    int *vet=(int*)malloc(sizeof(int)*tam+1);
    if(!vet) return vet;

    for(int i = 0; i < tam; i++){
        vet[i] = rand()%89+10;
    }
    vet[tam] = -1;
    timeElapsed();
    return vet;
}

double timeElapsed() {
    static time_t lastTime = 0;  // Variable to store the timestamp of the last call
    time_t currentTime = time(NULL);

    if (lastTime == 0) {
        lastTime = currentTime;  // Set the initial timestamp
        return 0.0;  // Return 0 for the first call
    }

    double elapsed = difftime(currentTime, lastTime);
    lastTime = currentTime;  // Update the last call timestamp

    return elapsed;
}

void NewRanbFile(int n, char* name){
    int lem = strlen(name)+5;
    char buffer[lem];
    strcpy(buffer, name);
    strcat(buffer, ".txt");
    FILE* fp = fopen(buffer, "w+");

    srand(time(NULL));
    while(n){
        n--;
        fprintf(fp, "%d ", rand()%89+10);//from 10 to 99=10+89 .: 89=99-19
    }
    fclose(fp);
}
void NewRanbFile(int n, char* name, int nMax, int nMin){
    int lem = strlen(name)+5;
    char buffer[lem];
    strcpy(buffer, name);
    strcat(buffer, ".txt");
    FILE* fp = fopen(buffer, "w");
    if(!fp) exit(1);

    int nCont = nMax-nMin;
    int ofSet = nMin;

    srand(time(NULL));
    while(n){
        n--;
        fprintf(fp, "%d ", rand()%nCont+ofSet);//from 10 to 99=10+89 .: 89=99-19
    }
    fclose(fp);
}

//Vetor terminado em -1
int* bubleSort(int* v){
    int aux;
    int vSize = 0;
    for(int i = 0; v[i] > 0; i++)vSize++;
    //para quando encontra um numero negativo
    for(int j = 1; j < vSize; j++){
        for(int i = 0; i < vSize-j; i++){
            if(v[i+1]<v[i]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                //printVet(v);
                //ln();
            }
        }
    }
    return v;
}
void printVet(int* v){
    for(int i = 0;v[i] > 0; i++) printf("%d ", v[i]);
}
/*void ln(){
    printf("\n");
}
*/
void retRepet(char* fIn, char* fOut){
    FILE* fpIn = fopen(fIn, "r");
    if(!fpIn) exit(1);

    FILE* fpOut = fopen(fOut, "w");
    if(!fpOut) exit(1);

    char w1[101], w2[101];
    fscanf(fpIn, "%s", &w1);
    fprintf(fpOut, "%s ", w1);

    while(fscanf(fpIn, "%s", &w2) != EOF){
        if(strcmp(w1, w2)){
            fprintf(fpOut, "%s ", w2);
            strcpy(w1, w2);
        }
    }
    fclose(fpIn);
    fclose(fpOut);
}

#include "TLSE.h"

typedef struct Aluno{
    char nome[50];
    float n1, n2, med;
}al;

TLSE* TLSE_insereOrd(TLSE* l, int elem) {
  TLSE* novo = (TLSE*) malloc(sizeof(TLSE));
  novo->info = elem;
  novo->prox = NULL;

  al* elinfo = (al*)(elem);

  // Case 1: Inserting as the first element
  if (l == NULL || elinfo->med < ((al*)(l->info))->med) {
    novo->prox = l;
    return novo;
  }

  // Case 2: Inserting in the middle or at the end
  TLSE* atual = l;
  TLSE* anterior = NULL;

  while (atual != NULL && ((al*)(atual->info))->med < elinfo->med) {
    anterior = atual;
    atual = atual->prox;
  }

  anterior->prox = novo;
  novo->prox = atual;

  return l;
}


void media(char* nameIn, char* nameOut){
    FILE* fIn = fopen(nameIn, "r");
    if(!fIn) exit(1);

    FILE* fOut = fopen(nameOut, "w");
    if(!fOut) exit(1);

    TLSE* fal = NULL;
    TLSE* no = NULL;

    while(1){
        al* auxal = (al*)malloc(sizeof(al));
        if(!auxal) return;
        if(fscanf(fIn, "%s\n", auxal->nome)==EOF)break;
        if(fscanf(fIn, "%f\n", &(auxal->n1))==EOF)break;
        if(fscanf(fIn, "%f\n", &(auxal->n2))==EOF)break;

        auxal->med = ((auxal->n1)+(auxal->n2))/2;

        /*To do -> uma função que insere oredenadamente na fila*/
        fal = TLSE_insereOrd(fal, (int)auxal);
    }
    no = fal;
    while(no){
        al* auxal = (al*)(no->info);

        //printf("%s\n", auxal->nome);
        //printf("%0.2f\n", auxal->med);

        fprintf(fOut, "%s\n", auxal->nome);
        fprintf(fOut, "%0.2f\n", auxal->med);
        no = no->prox;
    }
    TLSE_libera(fal);
    fclose(fOut);
    fclose(fIn);
}

#include "Rev2.h"
int* selecSort(int* vet, int tam){
    int curMin = MAX_INT;
    int indexMin = 0;

    int first = 0;
    while(first < tam){
        curMin = vet[first];
        indexMin = first;
        int lookfirst = vet[first];
        for(int i = first+1; i < tam; i++){
            int lookCur = vet[i];
            if(curMin > vet[i]){
                curMin = vet[i];
                indexMin = i;
            }
        }
        int aux = vet[first];
        vet[first] = vet[indexMin];
        vet[indexMin] = aux;
        first++;
        PrintVetI(vet, 10);
        ln();
    }
    return vet;
}
