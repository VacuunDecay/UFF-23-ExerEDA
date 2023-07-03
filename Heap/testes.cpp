#include "testes.h"


void tHeapMP(){
    int* rvet = randIntVet(99, 10, 15);
    printIntVet(rvet, 15);

    rvet = build_maxheap(rvet, 15);

    heap_print(rvet, 15, 0, 0);

    rvet = heap_sort(rvet, 15);

    printIntVet(rvet, 15);
}
