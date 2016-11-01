# Arvore-de-Diretorios
Repositório para controle de versionamento do trabalho computacional de estruturas de dados I da universidade federal fluminense. Aula ministrada pela professora Isabel Rosseti.

Simulação de uma arvore de diretorios. Usar arvore n-arias e ponteiros para void. 

typedef struct arrdir{
  int tipo;
  struct arrdir *filho, *prox_irmao;
  void * info;
}

//Tipo == 0 (diretorio) Tipo == 1 (arquivo)

Operações para diretorios e arquivos.
  -MOVER
  -Renomear
  -Destruir (Não pode destruir a raiz)
  -Criar
  -Liberar (memoria) 
  

