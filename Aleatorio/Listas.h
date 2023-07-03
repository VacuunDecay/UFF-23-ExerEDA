#ifndef LISTAS_H
#define LISTAS_H

#include "TLSE.h"
#include <stdio.h>
#include <stdlib.h>

void inverte (TLSE** l);//?
TLSE* inverteRet (TLSE* l);

TLSE *copia (TLSE *l);
TLSE *copiaRec (TLSE *l);

//Exerercico 5
TLSE* rto (TLSE* l, int elem);//Slow as hell :P

//Exercicio 6
TLSE* i_p (TLSE *l);

//Exercico 7
void i_pV(TLSE *l);

//Exercicio 8
int igual(TLSE *l1, TLSE *l2);

//Exercicio 9
TLSE* junta_listas (TLSE*l1, TLSE* l2);

//Exercicio 10
int Contrario (TLSE *l1, TLSE *l2);/*to do*/

#endif // LISTAS_H
