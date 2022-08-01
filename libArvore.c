#include "libArvore.h"

void inicializarArvore(TNo **r){

  //inicia a raiz da arvore como null
	*r= NULL; 
}

TNo *consultarPorNome(TNo *r, char nome[]){

  //se raiz for null ira retornar null
	if (r == NULL)
		return NULL;
    
  //se na comaparação achar um valor igual ao procurado, ira retornar a raiz
	else if (strcmp(r->nome, nome) == 0)
		return r;

  // se o nome for maior que o procurado, ira passar para a raiz da direita
	else if (strcmp(nome, r->nome) > 0)
		return consultarPorNome(r->dir, nome);

  //se for menor ira para a raiz da esquerda
	else
		return consultarPorNome(r->esq, nome);
}

void inserirNo(TNo **r, TNo *novo){

  //se raiz estiver vzia, ira inserir um novo
	if(*r == NULL){
		*r = novo;	
    
  // se n estiver vazia
	}else{
    
		if (strcmp(novo->nome,(*r)->nome) > 0){
      
			// se a raiz n tiver filho a direita, o novo elemento sera o seu filho
			if((*r)->dir == NULL)
				(*r)->dir = novo;
        
      // se tiver filho a direita, ira chamar a funcao inserirNo recursivamente
			else
				inserirNo(&(*r)->dir, novo);

    // se for menor do que a raiz
		}else{

      // se n tiver filho a esquerda, o novo elemento sera o seu filho
			if((*r)->esq == NULL)
				(*r)->esq = novo;

      // se tiver filho a esquerda, ira chamar a funcao inserirNo recursivamente
			else
				inserirNo(&(*r)->esq, novo);
		}
	}
}

int inserirNaArvore(TNo **r, char nome[], char num[]){

  //se n exitir o nome procurado,ira criar um novo no, chamando a funcao e ira inserir o valores passados pelo usuario
	if(consultarPorNome(*r, nome) ==  NULL){
	
		TNo *novo = (TNo *) malloc (sizeof(TNo));
		strcpy(novo->nome, nome);
		strcpy(novo->numero, num);
		novo->dir = NULL;
		novo->esq = NULL;
    
		inserirNo(r, novo);
		
		return 1;

  // se exitir o nome procurado ira retornar 0
	}else
		return 0;
	
}

TNo *encontrarMaior(TNo *r){

  // se n ouver filho a direitam significa que ele sera o maior
	if(r->dir == NULL){
		TNo *maior;
		maior = r;
		r = r->esq;
		return maior;

  //se houver filho a direita ira chamar a funcao recursivamente para localizar o maior
	}else
		return encontrarMaior(r->dir);
}

int removerDaArvore(TNo **r, char nome[]){
	
	TNo *excluido;
  excluido = *r;
  
  int status;
  
  //verifica se a raiz eh diferente de null
	if(*r != NULL){

    // compara a chave com o primeiro elemnto, se for igual, guarda o valor
		if(strcmp((*r)->nome, nome) == 0){

      // se n houver filho ha esquerda, o filho da direita passara a ser o da esquerda
			if((*r)->esq == NULL){
				*r = (*r)->dir;
        status = 1;
      //se n houver filho ha direita, o filho da esquerda passara a ser o da esquerda
      }else if((*r)->dir == NULL){
				*r = (*r)->esq;
        status = 1;
      //se tiver os dois filhos, ira achar o valor do maior elemento da subarvore da esquerda e ira copiar o valor dele para o  elemento que vai
      }else{
			  
				excluido = encontrarMaior((*r)->esq);
				strcpy((*r)->nome, excluido->nome);
        strcpy((*r)->numero, excluido->numero);
      }
      free(excluido);
			status = 1;

    // o nome procurado for menor que o da raiz, ira chamar recursivamenta a funcao de remover com a raiz da esquerda
    }else if(strcmp(nome,(*r)->nome)< 0)
			return removerDaArvore(&(*r)->esq, nome);

    //se for mairo ira chamar recursivamenta a funcao de remover com a raiz da direita
		else
			return removerDaArvore(&(*r)->dir, nome);
    
  }else
		  status = 0;

  return status;
}

void percorrerEmOrdem(TNo *r){

  //se a raiz for diferente de null, ira passar por cada no, do menor pro maior, printando o nome e numero
	if(r != NULL){
		percorrerEmOrdem(r->esq);
		printf("%s - %s\n", r->nome, r->numero);
		percorrerEmOrdem(r->dir);
	}
}

TNo *consultarPorNumero(TNo *r, char num[]){
	
	if(r != NULL){
		
		if(strcmp(num, r->numero) == 0)
			return r;
    else if(r->esq != NULL)
      consultarPorNumero(r->esq, num);
    else
      consultarPorNumero(r->dir, num);
    
	}else
		return NULL;
	
}

void exibirArvore(TNo *r){

  // se a raiz for diferente de null, ira chamar a funcao em ordem para imprimir a arvore
	if(r != NULL)
		percorrerEmOrdem(r);

  //se estiver null, ira printar que agenda esta vazia
	else
		printf("Agenda vazia!\n");
	
}

