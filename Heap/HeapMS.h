#ifndef HEAPMS_H
#define HEAPMS_H

#include <stdio.h>
#include <stdlib.h>


int heapms_pai(int n);
int heap_esq(int n);
int heap_dir(int n);
int* max_heapfy(int *vet, int n, int pos);
int* build_maxheap(int *vet, int n);
int* heap_sort(int *vet, int n);
void heap_print(int *vet, int n, int pos, int indent);

#endif // HEAPMP_H
