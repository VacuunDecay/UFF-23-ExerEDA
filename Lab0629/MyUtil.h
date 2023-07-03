#ifndef MYUTIL_H
#define MYUTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

void printIntVet(int *vet, int n);

void cls(int time);

void ln();

int randRange(int min, int max);

int* randIntVet(int max, int min, int n);

int ask2op(const char* question);

void capStr(char** str);

void fillFileWithRandomIntegers(const char* filename, int min, int max, int size);

int* loadIntegersFromFile(const char* filename, int* size, int maxSize);

#endif // MYUTIL_H