#include "HeapMP.h"

int heapms_pai(int n) {
    if (n == 0)
        return 2000000000;
    return (n / 2) - 1;
}

int heap_esq(int n) {
    return n * 2 + 1;
}

int heap_dir(int n) {
    return n * 2 + 2;
}

int* max_heapfy(int *vet, int n, int pos) {
    int maior = pos;
    int e = heap_esq(pos);
    int d = heap_dir(pos);

    if ((n > e) && (vet[e] > vet[maior]))
        maior = e;
    if ((n > d) && (vet[d] > vet[maior]))
        maior = d;

    if (maior != pos) {
        int aux = vet[pos];
        vet[pos] = vet[maior];
        vet[maior] = aux;
        max_heapfy(vet, n, maior);
    }

    return vet;
}

void min_heapfy(int *vet, int n, int pos) {
    int menor = pos;
    int e = heap_esq(pos);
    int d = heap_dir(pos);

    if ((n > e) && (vet[e] < vet[menor]))
        menor = e;
    if ((n > d) && (vet[d] < vet[menor]))
        menor = d;

    if (menor != pos) {
        int aux = vet[pos];
        vet[pos] = vet[menor];
        vet[menor] = aux;
        min_heapfy(vet, n, menor);
    }
}

int* build_maxheap(int *vet, int n) {
    int ult_pai = heapms_pai(n - 1);

    for (int i = ult_pai; i >= 0; i--) {
        max_heapfy(vet, n, i);
    }

    return vet;
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
