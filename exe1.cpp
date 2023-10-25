#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *proximo;
};

struct no *cabeca = NULL;

void inserir(int numero) {
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL){
		cabeca = novoNo;
	}else {
		struct no *ponteiro = cabeca;
		while (ponteiro -> proximo != NULL) {
			ponteiro = ponteiro -> proximo;
		}
		ponteiro -> proximo = novoNo;
	}
}

void imprimir() {
	printf("==============================\n");
	struct no *ponteiro = cabeca;
	while (ponteiro != NULL){
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

void remover(int numero) {
	if (cabeca != NULL){
		if (cabeca -> numero == numero){
			struct no *ponterioExcluir = cabeca;
			cabeca = cabeca -> proximo;
			free (ponterioExcluir);
		}else {
			struct no *ponteiroAnterior = cabeca;
			
			while ((ponteiroAnterior -> proximo != NULL) && (ponteiroAnterior -> proximo -> numero != numero)) {
				ponteiroAnterior = ponteiroAnterior -> proximo;
			}
			
			if (ponteiroAnterior -> proximo != NULL){
				struct no *ponteiroExcluir = ponteiroAnterior -> proximo;
				ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
				free(ponteiroExcluir);
			}
			
		}
	}
}

int main (int argc, char *argv[]){
	int opcao = 0;
	int numero = 0;
	
	while (opcao != 4) {
		printf("+----------------+\n");
		printf("| Menu de opcoes |\n");
		printf("+----------------+\n");
		printf("|  1- Inserir    |\n");
		printf("|  2- Remocer    |\n");
		printf("|  3- Imprimir   |\n");
		printf("|  4- Sair       |\n");
		printf("+----------------+\n");
		printf("Digite a opcao: ");
		scanf("%d", &opcao);
		
		switch (opcao) {
			case 1: 
				printf("Digite o numero: ");
				scanf("%d", &numero);
				inserir(numero);
				break;
			case 2:
				printf("Digite o numero: ");
				scanf("%d", &numero);
				remover(numero);
				break;
			case 3:
				imprimir();
				break;
		}
	}
}
