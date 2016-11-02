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
		const time_t criacao ;
		int perm;
		int num_arq;
	}TDIR;

	typedef struct arq{
		char * nome; // = (char *) malloc (sizeof (char * 25)
		int tipo; //Texto ou Binario
		int perm;
		const time_t criacao ;
		char * ult_att;
	}TARQ;


//METODOS SOBRE A ARVORE.

	//TODO
	TAD * aloca_no (char* nome ,int tipo, int permissao){
		TAD * novo = (TAD *) malloc (sizeof (TAD) );
		novo->tipo = tipo;
		novo->filho = novo->prox_irmao = NULL;
		//Refenciar a info
		return novo;
	}
	
	void insere( TAD * pai, TAD * filho){
		filho-> prox_irmao = pai->filho;
		pai-> filho = filho;
	}
	
	void libera(TAD * a){
		if(a->prox_irmao) libera(a->prox_irmao);
		if(a->filho) libera(a->filho);
		//Libera primeiro a referencia para os tipos arquivo ou diretorio.
		free(a->info);
		free(a);
	}
	
	
//METODOS SOBRE ARQUIVOS E DIRETORIOS.

//METODOS SOBRE DIRETORIO.

	/*
	TDIR * aloca_dir(char* nome, int permissao){
		TDIR * novo = (TDIR *)malloc (sizeof(TDIR));
		novo->nome = nome;
		novo->perm = permissao;
	}
	*/
	
//METODOS SOBRE ARQUIVOS.

	/*
	TARQ * aloca_arq(char* nome, int permissao){
		TARQ * novo = (TARQ *) malloc (sizeof(TARQ));
		novo->nome = nome;
		novo->perm = permissao;
		
		return novo;
	}
	*/
