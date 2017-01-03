#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//DEFINIÇÃO DOS TIPOS.
	typedef struct arrdir{
        struct arrdir *filho, *prox_irmao;
        char *nome; // = (char *) malloc (sizeof (char * 25)
		int eh_diretorio; //Tipo Arquivo==0 Tipo Diretorio==1
		time_t criacao;
		time_t ult_mod; //ultima modificacao
        char *perm; //permissoes em sistema linux (rwxrwxrwx)
		void *info;
	}TAD;

	typedef struct dir{
		int num_arq; //numero de arquivos/diretorios abaixo dele
	}TDIR;

	typedef struct arq{
		int eh_binario; //binario == 1; textual == 0;
		int tam; //tamanho
	}TARQ;


//METODOS SOBRE A ARVORE.

	//TODO
	TAD * cria_no (char *nome ,int eh_dir, char *perm, void *info){
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

	void insere_filho(TAD * pai, TAD * filho){ // insere o filho embaixo do pai
		if(pai->eh_diretorio){
            filho->prox_irmao = pai->filho;
            pai->filho = filho;
            TDIR *dir = (TDIR *)pai->info;
            dir->num_arq++;
        }
	}

    TAD * busca_nome(TAD *a, char *nome){
      if(!strcmp(a->nome, nome)) return a;
      TAD *p;
      for(p = a->filho; p; p=p->prox_irmao){
        TAD *resp = busca_nome(p, nome);
        if(resp) return resp;
      }
      return NULL;
    }

//METODOS SOBRE ARQUIVOS E DIRETORIOS.

//METODOS SOBRE DIRETORIO.

	TDIR * cria_dir(){
		TDIR *novo = (TDIR *)malloc (sizeof(TDIR));
		novo->num_arq = 0;
		return novo;
	}

//METODOS SOBRE ARQUIVOS.

	TARQ * cria_arq(int eh_bin, int tam){
		TARQ * novo = (TARQ *) malloc (sizeof(TARQ));
        novo->eh_binario = eh_bin;
        novo->tam = tam;
		return novo;
	}


// METODOS GERAIS
void libera(TAD * a){
    if(a->prox_irmao) libera(a->prox_irmao);
    if(a->filho) libera(a->filho);
    //Libera primeiro a referencia para os tipos arquivo ou diretorio.
    free(a->info);
    free(a);
}

void renomear(TAD *a, char* nome){
    a->nome = nome;
    printf("Nome alterado com sucesso. \n");
}

void excluir(TAD *raiz, TAD *e){
    if(e != raiz){
        libera(e);
        printf("Arquivo/Diretório excluído com sucesso. \n");
    }
    else printf("Erro: Impossível apagar a raíz. \n");
}

void cria_geral(TAD *pai, int eh_dir){
    char *nome_ph; //placeholder de nome para usar mais na frente
    void *info;
    if(eh_dir){
        info = cria_dir();
        nome_ph = "Diretório";
    }
    else{
        printf("Prezado usuário, deseja criar um Arquivo binário ou textual? \n");
        printf("1 - Binário \n");
        printf("0 - Textual \n");
        int eh_bin;
        scanf(" %d", &eh_bin);
        printf("Qual o tamanho do Arquivo que deseja criar? \n");
        int tam;
        getchar();
        scanf(" %d", &tam);
        getchar();
        info = cria_arq(eh_bin, tam);
        nome_ph = "Arquivo";
    }

    printf("Qual o nome que gostaria de dar para o seu %s?\n", nome_ph);
    char nome [255];
    fgets(nome, 255, stdin);

    printf("Quais as permissões que gostaria dar ao seu %s?\nUse o sistema de permissões do linux.\n", nome_ph);
    char perm[255];
    getchar();
    fgets(perm, 255, stdin);

    TAD *novo = cria_no(nome, eh_dir, perm, info);
    insere_filho(pai, novo);

    printf("%s criado com sucesso! \n\n", nome_ph);
}

void transforma(TAD *raiz, TAD *a){
    if(a != raiz){
        if(a->eh_diretorio){
            printf("Prezado usuário, deseja transformar seu Diretório em um Arquivo binário ou textual?\n");
            printf("1 - Binário \n");
            printf("0 - Textual \n");
            int eh_bin;
            scanf(" %d", &eh_bin);
            printf("Qual o tamanho do Arquivo que deseja criar? \n");
            int tam;
            scanf(" %d", &tam);
            TARQ *info = cria_arq(eh_bin, tam);
            libera(a->filho);
            a->filho = NULL;
            a->info = info;
            a->eh_diretorio = 0;
            a->ult_mod = time(NULL);
            printf("Diretório transformado em Arquivo com sucesso. \n");
            return;
        }
        else {
            TDIR *info = cria_dir();
            a->info = info;
            a->eh_diretorio = 1;
            a->ult_mod = time(NULL);
            printf("Arquivo transformado em Diretório com sucesso. \n");
            return;
        }
    }
    else printf("Erro: Impossível transformar raíz em arquivo. \n");
}
/*
void imprime(TAD *a, char *divisor){ // divisor eh um - para demonstar a diferenca entre um pai e um filho
    if(!a) return;
    TAD *p = a;
    while(p){
        printf("%s %s \n", divisor, p->nome);
        TAD *q = p->filho;
        char *aux = divisor;
        strcat(divisor, "-");
        imprime(q, divisor);
        divisor = aux;
        p = p->prox_irmao;
    }
}*/

void imprime(TAD *a){
  printf("- %s\n", a->nome);
  TAD *q = a->filho;
  for(;q;q=q->prox_irmao) imprime(q);
}
