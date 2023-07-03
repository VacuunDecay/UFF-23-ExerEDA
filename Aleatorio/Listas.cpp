#include "Listas.h"

void inverte (TLSE** l){
    TLSE* ant = NULL;
    TLSE* no = *l;
    TLSE* next = NULL;

    if(!no) return;
    if(no->prox)
        next = no->prox;

    while(no){
        int noel = no->info;
        no->prox = ant;
        ant = no;
        no = next;

        if(next)
            next = next->prox;
    }

    *l = ant;

}

TLSE* inverteRet(TLSE* l){
    TLSE* ant = NULL;
    TLSE* no = l;
    TLSE* next = NULL;

    if(!no) return NULL;
    if(no->prox)
        next = no->prox;

    while(no){
        int noel = no->info;
        no->prox = ant;
        ant = no;
        no = next;

        if(next)
            next = next->prox;
    }

    return ant;
}

TLSE *copia (TLSE *l){
    TLSE* list2 = NULL;
    TLSE* no = l;

    if(!no) return NULL;

    while(no){
        list2 = TLSE_insere(list2, no->info);
        no = no->prox;
    }

    list2 = inverteRet(list2);

    return list2;
}

TLSE* copiaRec(TLSE* l){
    TLSE* list2 = NULL;
    if(!l) return NULL;
    list2 = copiaRec(l->prox);
    list2 = TLSE_insere(list2, l->info);
    return list2;
}

TLSE* rto (TLSE* l, int elem){
    TLSE* no = l;
    if(!l) return NULL;

    while(no){
        if(no->info == elem){
            l = TLSE_retira(l, elem);

        }
        if(!no) no = l;
        else no = no->prox;
    }
    return l;
}

TLSE* i_p (TLSE *l){
    TLSE* imp = NULL;
    TLSE* par = NULL;
    TLSE* no = l;

    while(no){
        if((no->info)%2 == 0) par = TLSE_insere(par, no->info);
        else imp = TLSE_insere(imp, no->info);
        no = no->prox;
    }
    imp = inverteRet(imp);
    par = inverteRet(par);

    no = imp;
    while(no->prox){
        no = no->prox;
    }

    no->prox = par;

    return imp;
}

void i_pV(TLSE* l) {
    TLSE* impH = NULL;
    TLSE* parT = NULL;
    TLSE* parH = NULL;
    TLSE* impT = NULL;

    TLSE* no = l;

    while(no){
        if(no->info%2 == 1){
            if(impT){
                impT->prox = no;
                impT = no;
            }else{
                impH = no;
                impT = no;
            }
        }else{
            if(parT){
                parT->prox = no;
                parT = no;
            }else{
                parH = no;
                parT = no;
            }
        }
        no = no->prox;
    }
    impT->prox = parH;
    parT->prox = NULL;

    l = impH;
}

int igual(TLSE *l1, TLSE *l2){
    TLSE* no1 = l1;
    TLSE* no2 = l2;

    while(no1 && no2 && no1->info == no2->info){
        no1 = no1->prox;
        no2 = no2->prox;
    }

    if(!no1 && !no2) return 1;

    return 0;
}


TLSE* junta_listas (TLSE*l1, TLSE* l2){
    TLSE* no1 = l1, *no2 = l2;

    while(no1->prox){
        no1 = no1->prox;
    }

    no1->prox = no2;

    return no1;
}


int Contrario (TLSE *l1, TLSE *l2){

    /*to do*/
}
