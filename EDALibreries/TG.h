#include <stdlib.h>
#include <stdio.h>

typedef struct viz {
	int id_viz;
	struct viz *prox_viz;
}TVIZ;

typedef struct grafo{
	int id_no;
	TVIZ *prim_viz;
	struct grafo *prox_no;
}TG;


TG* TG_inicializa();
void TG_imprime(TG *g);
void TG_libera(TG *g);
TG* TG_busca_no(TG* g, int x);
TVIZ* TG_busca_aresta(TG *g, int no1, int no2);
TG* TG_ins_no(TG *g, int x);
void TG_ins_aresta(TG *g, int no1, int no2);
void TG_retira_aresta(TG *g ,int no1, int no2);
TG* TG_retira_no(TG *g, int no);


////////////////////////////////////
int haveKOrd(TG* g, int k);

/*To do*/

/*1. Descubra a quantidade de nos*/
int nn(TG *g);

/*2. Descrubra a quantidade de arestas*/
int na(TG *g);

/*3. verifique se os vizenhos tem a mesma cor que o no*/
int nao_tem_mesma_cor(TG*g);

/*4. verifique se g tem todos os nos com gral = k*/
int testel(TG *g, int k);

/*5. Testar se 2 grafos sao iguais*/
int ig(TG *g1, TG* g2);

