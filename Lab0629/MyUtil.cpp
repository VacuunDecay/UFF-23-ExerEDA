#include "MyUtil.h"


void printIntVet(int *vet, int n){
    for(int i = 0; i<n; i++){
        printf("%d ", vet[i]);
    }
    ln();
}

void cls(int time) {
    //sleep(time);
    #ifdef _WIN32  // For Windows
        system("cls");
    #else  // For UNIX-like systems (Linux, macOS, etc.)
        system("clear");
    #endif
}

void ln() {
    printf("\n");
}


int randRange(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int* randIntVet(int max, int min, int n){
    int *vet = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        vet[i] = randRange(min, max);
    }

    return vet;
}

int ask2op(const char* question) {
    printf("%s (y/n): ", question);

    char response;
    do {
        scanf(" %c", &response);
        if (response == 'y' || response == 'Y') {
            return 1;  // Yes
        } else if (response == 'n' || response == 'N') {
            return 0;  // No
        } else {
            printf("Invalid input. Please enter 'y' for Yes or 'n' for No: ");
        }
    } while (1);  // Keep asking until a valid response is entered
}

/**!Pace o str como referencia ou seja, passe o seu indereço Ex.: &minhaStr*/
void capStr(char** str) {
    if (str == NULL || *str == NULL) {
        return;  // Handle NULL string pointer or empty string
    }

    for (int i = 0; (*str)[i] != '\0'; i++) {
        (*str)[i] = toupper((*str)[i]);
    }
}

void fillFileWithRandomIntegers(const char* filename, int min, int max, int size) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open the file.\n");
        return;
    }

    int* vector = randIntVet(max, min, size);
    if (!vector) {
        fclose(file);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", vector[i]); // Write the integer to the file
    }

    fclose(file);
    free(vector);
}

int* loadIntegersFromFile(const char* filename, int* size, int maxSize){
    FILE* fp = fopen(filename, "r");
    if(!fp) exit(0);

    int *inp = (int*)malloc(sizeof(int)*maxSize);
    int num, i = 0;
    while(fscanf(fp, "%d ", &num) == 1){
        if(i >= maxSize) break;
        inp[i++] = num;
    }
    
    
    fclose(fp);
    *size = i;

    return inp;
}