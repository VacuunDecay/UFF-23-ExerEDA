#ifndef PLAYGRONWDARQUIVOSBINARIOS_H_INCLUDED
#define PLAYGRONWDARQUIVOSBINARIOS_H_INCLUDED

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif // _WIN32

//Eniac's std
void ln();
void printVet(int* v);
void cls();
void NewRanbFile(int n, char* name);
void NewRanbFile(int n, char* name, int nMax, int nMin);

// Play with files
int* bubleSort(int* v);
int* randVetNT(int tam);
double timeElapsed();


//Lista de arquivos texto
void retRepet(char* fIn, char* fOut);
void media(char* nameIn, char* nameOut);

int* selecSort(int* vet, int tam);
#endif // PLAYGRONWDARQUIVOSBINARIOS_H_INCLUDED
