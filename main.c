#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main () {
	no *T = NULL, *p = NULL;
	int menu = 0,valor = 0;
	printf("Arvore T:\n1-Realizar insercao na arvore T\n2-Pesquisar valor na arvore T\n"
			"3-Percurso preOrdem\n4-Percurso emOrdem\n5-Percuros posOrdem\n6-Folhas arvore\n"
			"7-Liberar arvore\n8-Contador de nos\n9-Menor no\n10-Maior no\n11-Nivel no\n"
			"12-Altura da arvore\n13-Remover no\n14-Percurso largura\n\n"
		   "0-Sair da interface de acesso\n\n");
	do {
		//scan
		printf("\nMenu: ");
		scanf("%d",&menu);
		//insert
		if (menu == 1) {
			printf("Valor a ser inserido: ");
			scanf("%d",&valor);
			T = insert(&T,valor);
			printf("Fim\n");
		}
		//search
		else if (menu == 2) {
			printf("No a ser pesquisado: ");
			scanf("%d",&valor);
			p = pesq_AB(&T,valor);
			if (p != NULL) 
				printf("Valor: %d\n\n", p->info);
			else 
				printf("No nao se encontra na arvore\n\n");
		}
		//percursos
		else if (menu == 3) 
			preOrdem_AB(&T);
		else if (menu == 4)
			emOrdem_AB(&T);
		else if (menu == 5)
			posOrdem_AB(&T);
		//folhas arvore
		else if (menu == 6)
			folha(&T);
		//liberar
		else if (menu == 7) {
			if (liberar(&T) == 1)
				printf("Arvore liberada!\n");
			else
				printf("Liberacao falhou!\n");
		}
		//contador de nos
		else if (menu == 8) {
			printf("Existem %d nos na arvore.\n", count(&T)); 
		}
		//menor no
		else if (menu == 9) {
			no *aux;
			aux = menor(&T);
			printf("Valor menor no: %d\n", aux->info);
		}
		//maior no
		else if (menu == 10) {
			no *aux;
			aux = maior(&T);
			printf("Valor maior no: %d\n", aux->info);
		}
		//nivel no
		else if (menu == 11) {
			printf("No a conhecer o nivel: ");
			scanf("%d",&valor);
			p = pesq_AB(&T,valor);
			if (p != NULL) {
				printf("Nivel do no = %d\n", nivel(&T,valor));
			}
			else 
				printf("No nao se encontra na arvore\n\n");
			 
		}
		//altura arvore
		else if (menu == 12) {
			printf("Altura da arvore = %d\n", altura(&T));
		}
		//remover no
		else if (menu == 13) {
			printf("No a ser o removido: ");
			scanf("%d",&valor);
			if (remove_AB(&T,valor) == 1)
				printf("Valor removido com sucesso!\n");
			else 
				printf("Remocao falhou!\n");
		}
		//percurso largura
		else if (menu == 14) {
			largura(&T);
		}
		//tramento de entrada
		else if (menu > 14 || menu < 0)
			printf("Acao invalida\n");
	} while (menu != 0);
	if (liberar(&T) == 1)
		printf("Arvore liberada!\n");
	else
		printf("Liberacao falhou!\n");
	return 0;
}
