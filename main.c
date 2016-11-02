/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <time.h>
#include "arrdir.h"

int main(int argc, char *argv[]) {
	//Teste da função de imprimir a hora do sistema.
	const time_t timer = time(NULL);
	printf("%s\n", ctime(&timer));	
	
	int comando;
	do{
		//Receber o comando do usuario pelo menos uma vez
		printf("Digite um dos comandos listados: \n");
		printf("0 - Sair \n");
		
		scanf("%d", &comando);
		
		switch(comando){
			case 0:
				break;
			case 1:
				//Comando 1
				break;
			case 2:
				//Comando 2	
				break;
			default:
				printf("Comando inválido, por favor entre com um comando númerico existente.");
				break;
		}
		
		
	}while(comando != 0);
	//Liberar memoria da arvore. Inclusive Raiz.
	return 0;
}
