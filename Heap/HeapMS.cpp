#include "HeapMP.h"

#define I sizeof(int)

int heapms_pai(int n) {
    n = n/I;
    if (n == 0)
        return 2000000000;
    return I*((n / 2) - 1);
}

int heap_esq(int n) {
    return n * 2 + I;
}

int heap_dir(int n) {
    return (n * 2) + (2*I);
}

int* max_heapfy(char* narq, int end) {
    int iend = end*I;
    int eind = heap_esq(iend);
    int dind = heap_dir(iend);
    int maind = iend;

    FILE* fp = fopen(narq, "rb+");

    if(!fp) return NULL;

    int ve, vd, vm, vi;
    int fe, fd, fm;

    fe = fread(&ve, eind, 1, fp);
    fd = fread(&vd, dind, 1, fp);
    fm = fread(&vm, maind, 1, fp);
    vi = vm;
    if(!fe && ve > vm) {
        maind = eind;
        vm = ve;    
    }

    if(!fd && vd > vm) {
        maind = dind;
        vm = vd;    
    }

    if(maind != iend){
        fwrite(&vm, iend, 1, fp);
        fwrite(&vi, maind, 1, fp);

        fclose(fp);
        max_heapfy(narq, maind/I);
    }

    if(fp) fclose(fp);
}

void build_maxheap(char* narq) {
    FILE* fp = fopen(narq, "r");

    if(!fp) return;

    int ult_elend;
    fseek(&ult_elend, -I, SEEK_END);

    fclose(fp);

    int ult_pai = heapms_pai(ult_elend);

    for (int i = ult_pai/I; i >= 0; i--) {
        max_heapfy(narq, i/I);
    }
}

int* build_minheap(int *vet, int n) {

    
    int ult_pai = heapms_pai(n - 1);

    for (int i = ult_pai; i >= 0; i--) {
        min_heapfy(vet, n, i);
    }

    return vet;
}

int* copIntVet(int *vet, int n){
    int* exit = (int*)malloc(n * sizeof(int));

    //copieng vet to exit
    for(int i = 0; i < n; i++) {
        exit[i] = vet[i];
    }

    return exit;
}

int* heap_sort(int *vet, int n) {
    int* exit = NULL;

    exit = copIntVet(vet, n);

    int ult_val = n-1;
    for(int i = ult_val; i >= 0; i--) {
        //trocando a raiz com o ultimo elemento da arvore
        int aux = exit[0];
        exit[0] = exit[i];
        exit[i] = aux;

        max_heapfy(exit, i, 0);
    }
    return exit;
}

void heap_print(int *vet, int n, int pos, int indent) {
    if (pos >= n) return;

    heap_print(vet, n, heap_dir(pos), indent + 1);

    for (int i = 0; i < indent; i++)
        printf("\t");
    printf("%d\n", vet[pos]);

    heap_print(vet, n, heap_esq(pos), indent + 1);
}
