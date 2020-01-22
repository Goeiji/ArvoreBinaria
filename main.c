#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*[Typedefs(Início)]*/
typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux{
	TIPOCHAVE chave;
	struct aux *esq, *dir;
}NO;

typedef NO *PONT;
/*[Typedefs(Fim)]*/

/*[Funções(início)]*/
/*Inicializando a árvore*/
PONT inicializa(){
	return(NULL);
}

/*Criar novo no*/
PONT criarNovoNo(TIPOCHAVE chave){
	PONT novoNo = (PONT)malloc(sizeof(NO));
	novoNo->chave = chave;
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	return(novoNo);
}

/*Adicionando um novo nó*/
PONT adicionar(PONT raiz, PONT no){
	if(raiz == NULL) return (no);
	if(no->chave < raiz->chave){
		raiz->esq = adicionar(raiz->esq, no);
	}else if(no->chave > raiz->chave){
		raiz->dir = adicionar(raiz->dir, no);
	} 
	
}
/*Mostrar a árvore:*/
void mostrar(){
}
/*[Funções(Fim)]*/

int main(int argc, char *argv[]) {
	PONT r;
	PONT no;
	int num;
	int opcao;
	int ok;
	int cont=0;
	
	/*Menu*/
	menu:
	system("cls");
	printf("<-ARVORE BINARIA->");
	printf("\n\n<MENU>\n");
	printf("Digite <1> para inicializar a arvore:\n");
	printf("Digite <2> para inserir um no na arvore:\n");
	printf("Digite <3> para buscar um elemento na arvore:\n");
	scanf("%d", &opcao);
	
	/*Acesso às funções*/
	if(opcao == 1){
		r = inicializa();
		printf("Arvore inicializada...\n");
		
		printf("\nDigite <(1)> para continuar ou <(QUALQUER COISA)> para encerrar o programa.\n");
		scanf("%d", &ok);
		if (ok == 1){
			goto menu;
		}else{
			printf("\nEncerrando o programa...");
		}
	}
		
	if(opcao == 2){
		printf("Digite o no que deseja inserir:");
		scanf("%d", &num);
		no = criarNovoNo(num);
		r = adicionar(r, no);
		printf("A chave eh:%d\n", no->chave);
		cont++;

		printf("Situacao da arvore:\n");
		mostrar(r, no, cont);
		
		printf("\nDigite <(1)> para continuar ou <(QUALQUER COISA)> para encerrar o programa.\n");
		scanf("%d", &ok);
		if (ok == 1){
			goto menu;
		}else{
			printf("\nEncerrando o programa...");
		}
	}
	return 0;
}
