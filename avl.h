#ifndef EMORDEM_AB_H
#define EMORDEM_AB_H

#include "list.h"

typedef struct Treeno {
	int info;
	struct Treeno *Llink;
	struct Treeno *Rlink;
} no;

void emOrdem_AB (no **T);
void preOrdem_AB (no **T);
void posOrdem_AB (no **T);
void folha(no **T);
int liberar(no **T);
int count(no **T);
no *menor(no **T);
no *maior(no **T);
int nivel(no **T, int x);
int altura (no **T); 
no *insert (no **T, int x);
no *new_no (int x);
no *pesq_AB (no **T, int x);
int remove_AB(no **T, int x);
void largura(no **T);
int fb(no **T);
no *rotacao_direita(no **T);
no *rotacao_esquerda(no **T);
no *balance(no **T);

#endif