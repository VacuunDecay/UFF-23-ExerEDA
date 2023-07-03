#include "TH.h"

int main(void){
  int m;
  printf("Digite o tamanho da hash... ");
  scanf("%d", &m);

  if(m <= 1) return 0;

  char nome_dados[31], nome_hash[31];
  printf("Digite nome do arquivo de dados... ");
  scanf("%s", nome_dados);
  printf("Digite nome do arquivo de hash... ");
  scanf("%s", nome_hash);

  TH_inicializa(nome_hash, nome_dados, m);

  int mat;
  float cr;
  do{
    printf("Digite a matricula e o cr...\n");
    scanf("%d", &mat);
    scanf("%f", &cr);
    if(mat <= 0) break;
    TH_insere(nome_hash, nome_dados, m, mat, cr);
  }while(1);
  TH_imprime(nome_hash, nome_dados, m);

  char resp;
  do{
    printf("Digite a matricula a ser removida... ");
    scanf("%d", &mat);
    cr = TH_retira(nome_hash, nome_dados, m, mat);
    if(cr != -1) printf("%d %f saiu\n", mat, cr);
    printf("Quer continuar? ");
    scanf(" %c", &resp);
  }while((resp != 'N') && (resp != 'n'));
  TH_imprime(nome_hash, nome_dados, m);

  return 0;
}
