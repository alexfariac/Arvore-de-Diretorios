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
		char * nome; 
		const time_t criacao = time(NULL);
		int perm;
		int num_arq = 0;
	}TDIR;

	typedef struct arq{
		char * nome; // = (char *) malloc (sizeof (char * 25)
		int tipo; //Texto ou Binario
		int perm;
		const time_t criacao = time(NULL);
		char * ult_att;
	}TARQ;


//METODOS SOBRE A ARVORE.

	TAD * aloca_no (char* nome ,int tipo, int permissao){
		TAD * novo = (TAD *) malloc (sizeof (TAD) );
		novo->tipo = tipo;
		novo->filho = novo->prox_irmao = NULL;
		//Refenciar a info
		return novo;
	}
	
//METODOS SOBRE ARQUIVOS E DIRETORIOS.

//METODOS SOBRE DIRETORIO.
	TDIR * aloca_dir(char* nome, int permissao){
		TDIR * novo = (TDIR *)malloc (sizeof(TDIR));
		novo->nome = nome;
		novo->perm = permissao;
	}
//METODOS SOBRE ARQUIVOS.
	TARQ * aloca_arq(char* nome, int permissao){
		TARQ * novo = (TARQ *) malloc (sizeof(TARQ));
		novo->nome = nome;
		novo->perm = permissao;
		
		return novo;
	}
