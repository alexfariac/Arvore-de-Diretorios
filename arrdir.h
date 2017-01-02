#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//DEFINIÇÃO DOS TIPOS.
	typedef struct arrdir{
        struct arrdir *filho, *prox_irmao;
        char * nome; // = (char *) malloc (sizeof (char * 25)
		int eh_diretorio; //Tipo Arquivo==1 Tipo Diretorio==0
		time_t criacao;
		time_t ult_mod;
        int perm;
		void *info;
	}TAD;

	typedef struct dir{
		int num_arq; //numero de arquivos/diretorios abaixo dele
	}TDIR;

	typedef struct arq{
		int eh_binario;
	}TARQ;


//METODOS SOBRE A ARVORE.

	//TODO
	TAD * cria_no (char* nome ,int eh_dir, int perm, void *info){
		TAD * novo = (TAD *) malloc (sizeof (TAD));
		novo->prox_irmao = NULL;
		novo->filho = NULL;
		novo->nome = nome;
		novo->eh_diretorio = eh_dir;
		novo->criacao = time(NULL);
		novo->ult_mod = novo->criacao;
		novo->perm = perm;
		novo->info = info;
		//Refenciar a info
		return novo;
	}

	void insere(TAD * pai, TAD * filho){ // insere o filho embaixo do pai
		if(pai->eh_diretorio){
            filho->prox_irmao = pai->filho;
            pai->filho = filho;
        }
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

	TDIR * cria_dir(){
		TDIR *novo = (TDIR *)malloc (sizeof(TDIR));
		novo->num_arq = 0;
		return novo;
	}

//METODOS SOBRE ARQUIVOS.

	TARQ * cria_arq(int eh_bin){
		TARQ * novo = (TARQ *) malloc (sizeof(TARQ));
        novo->eh_binario = eh_bin;
		return novo;
	}
