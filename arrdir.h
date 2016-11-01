#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//DEFINIÇÃO DOS TIPOS.
typedef struct arrdir{
	int tipo; //Tipo Arquivo==1 Tipo Diretorio==0
	struct arrdir *filho, *prox_irmao;
	void *info;
}TAD;

typedef struct dir{
	char[50] nome;
	const time_t criacao = time(NULL);
	int permissoes;
	int num_arq;
}TDIR;

typedef struct arq{
	char[50] nome;
	int tipo; //Texto ou Binario
	int permissoes;
	const time_t criacao = time(NULL);
	time_t ult_att;
};


//METODOS SOBRE A ARVORE. 

//METODOS SOBRE ARQUIVOS E DIRETORIOS.

//METODOS SOBRE DIRETORIO.

//METODOS SOBRE ARQUIVOS.
