/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include <time.h>
#include "arrdir.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	//Teste da função de imprimir a hora do sistema.
	const time_t timer = time(NULL);
	printf("%s\n", ctime(&timer));
    char *divisor;


    TDIR *info_raiz = cria_dir();
    TDIR *info_filho = cria_dir();
    TARQ *info_filho2 = cria_arq(0, 128);
    TDIR *info_filho3 = cria_dir();
    TAD *raiz = cria_no("Raiz", 1, "rwx------", info_raiz);
    TAD *filho = cria_no("Filho", 1, "rwx------", info_filho);
    TAD *filho2 = cria_no("Filho2", 0, "rwx------", info_filho2);
    TAD *filho3 = cria_no("Filho3", 1, "---rwx---", info_filho3);
    insere_filho(raiz, filho);
    insere_filho(filho, filho2);
    insere_filho(raiz, filho3);
    //cria_geral(raiz, 1);
    //cria_geral(raiz, 0);
    imprime(raiz);

    /*strcpy(divisor, "-");
    imprime(raiz);

    printf("Raiz: %s\n", raiz->nome);
    printf("Filho 1: %s\n", raiz->filho->eh_diretorio);
    printf("Filho 2: %s\n", raiz->filho->prox_irmao->eh_diretorio);*/

    //strcpy(divisor, "-");
    //imprime(raiz, divisor);

    //strcpy(divisor, "-");
    //imprime(raiz);

    /*printf("%s %s", divisor, raiz->nome);
    strcat(divisor, "-");
    printf("%s", divisor);*/


	/*int comando;
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
	//Liberar memoria da arvore. Inclusive Raiz.*/
	return 0;
}
