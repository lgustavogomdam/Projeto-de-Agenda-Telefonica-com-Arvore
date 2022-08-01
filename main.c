#include "libArvore.h"

void incluirContato(TNo **r){
    
    int status;
    char nomeContato[50];
    char numeroContato[50];
    
    printf("\n======|INCLUIR CONTATO|======");
    printf("\n\n\tInforme o nome da Pessoa a ser incluída na Agenda: ");
    gets(nomeContato);
    gets(nomeContato);

    printf("\n\n\tAgora informe o número da Pessoa a ser incluída na Agenda: ");
    gets(numeroContato);

    status = inserirNaArvore(&(*r), nomeContato, numeroContato);

    if(status == 1)
        printf("\n\tContato inserido com sucesso em sua Agenda!");
    else{
        do{
            
            printf("\n\tPor favor, Digite o nome do novo contato ou 'cancelar' para sair: \n");
            gets(nomeContato);
    
            if(strcmp(nomeContato,"cancelar") == 0)
                status = 0;
            else
                status = inserirNaArvore(&(*r), nomeContato, numeroContato);
        }while(status != 0);
        
    printf("\n\tVocê optou por sair!\n");
    printf("\n\tContato não inserido!\n");
  }
}

void excluirContato(TNo **r){
    
    int status;
    char nomeContato[50];
    
    printf("\n======|EXCLUIR CONTATO|======");
    
    printf("\n\nInforme o nome da pessoa a ser excluída: ");
    gets(nomeContato);
    gets(nomeContato);

    status = removerDaArvore(&(*r), nomeContato);

    if(status == 1)
      printf("\n\tContato removido com sucesso em sua Agenda!");
    else
      printf("\n\tContato não encontrado em sua Agenda!");
      
}

void buscarContatoPeloNome(TNo *r){
    

    char nomeContato[50];
    TNo *aux;
    
    printf("\n======|BUSCAR CONTATO PELO NOME|======");
    
    printf("\n\n\tInforme o nome a ser procurado: ");
    gets(nomeContato);
    gets(nomeContato);

    aux = consultarPorNome(r, nomeContato);
    
    if(aux != NULL){
        printf("\n\n====|Contato encontrado:|====\n\n");
        printf("\n\n====|Nome: %s\n====|Número: %s\n\n", aux->nome, aux->numero);
    }else
        printf("\n\n====|ERRO: Telefone não encontrado!|====\n\n");

  free(aux);
}

void buscarContatoPeloNumero(TNo *r){
    
  char numeroContato[50];
  TNo *aux;
    
  printf("\n======|BUSCAR CONTATO PELO NÚMERO|======");
    
  printf("\n\n\tInforme o nome a ser procurado: ");
  gets(numeroContato);
  gets(numeroContato);

  aux = consultarPorNumero(r, numeroContato);
    
  if(aux != NULL){
      printf("\n\n====|Contato encontrado:|====\n\n");
      printf("\n\n====|Nome: %s\n====|Número: %s\n\n", aux->nome, aux->numero);
  }else
      printf("\n\n====|ERRO: Telefone não encontrado!|====\n\n");

  free(aux);
}

int main(int argc, char *argv[]) {
  
  setlocale(LC_ALL, "Portuguese");

  int indice, stat;
	
	TNo *raiz;
	
	inicializarArvore(&raiz);

  do{
      //MENU INICIAL
    	
    printf("\n\n\n===========================|Bem Vindo à sua Agenda|===========================");
      //OPÇÕES DO MENU
    		
    printf("\n\nServiços disponíveis:\n"
    "1 - Adicionar contato na Agenda\n"
    "2 - Excluir contato da Agenda\n"
    "3 - Buscar pessoa pelo nome na Agenda\n"
    "4 - Buscar pessoa na Agenda pelo número de telefone\n"
    "5 - Exibir agenda\n"
    "0 - Sair do programa\n");
    				
    printf("\n\nPor favor, digite o serviço que necessita: ");			
    scanf("%d", &indice);
    		
    if(indice < 0 || indice > 7){
    		
    	do{
    		//Verifica a integridade do scanf dentro dos padrões apresentados
        
    	  printf("\n\nERRO: número inválido!\n"
    		"Por favor, digite o serviço que necessita baseado no menu apresentado: ");
    		scanf("%d", &indice);
    				
    	}while(indice < 0 || indice > 5);
    			
    }
    
    switch(indice){
    
      case 1:
        incluirContato(&raiz);
      break;

      case 2:
        excluirContato(&raiz);
      break;

      case 3:
        buscarContatoPeloNome(raiz);
      break;

      case 4:
        buscarContatoPeloNumero(raiz);
      break;

      case 5:
        exibirArvore(raiz);
      break;
             
      default:
        printf("\n\n====|Você optou por sair do programa|====\n");
    }
        
  }while(indice != 0);
    
	return 0;

}
