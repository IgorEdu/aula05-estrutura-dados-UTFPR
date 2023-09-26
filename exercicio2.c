/*2 - Construir um programa em Linguagem C  que permita criar uma Pilha Simplesmente Encadeada para armazenar uma lista de inteiros.

Deverão ser implementadas as seguintes opções:
[x]Criar uma Pilha,
[x]incluir um elemento na Pilha,
[x]Excluir um elemento na Pilha,
[x]Consultar todos os elementos da Pilha a partir do Último.*/

#include <stdlib.h>
#include <stdio.h>

struct TNo
{
  int chave;
  struct TNo *anterior;
};
typedef struct TNo TNo;

void criaPilha(TNo **topo)
{
  *topo = NULL;
  // tamanho = 0;
}

TNo *aloca(int k)
{
  TNo *novoNo = (TNo *)malloc(sizeof(TNo));
  novoNo->chave = k;
  novoNo->anterior = NULL;
  return novoNo;
}

void incluiNaPilha(TNo **topo,int k)
{
  TNo *novoNo = aloca(k);
  if (*topo == NULL)
  {
    *topo = novoNo;
  }
  else
  {
    TNo *noAtual;
    noAtual = *topo;
    novoNo->anterior = noAtual;
    *topo = novoNo;
  }

  printf("Elemento inserido na pilha\n");
  // tamanho++;
}

void removeDaPilha(TNo **topo)
{
  TNo *noAux = *topo;
  if (*topo == NULL)
  {
    printf("Pilha vazia! Impossivel remover no do topo.\n");
    return;
  }
  *topo = noAux->anterior;
  free(noAux);
  printf("Elemento removido da pilha\n");
  // tamanho--;
}

void imprimePilha(TNo **topo)
{
  TNo *noAtual;
  noAtual = *topo;
  if (noAtual == NULL)
  {
    printf("Pilha vazia!\n");
    return;
  }
  printf("-----------------------\n");
  printf("TOPO DA PILHA\n");
  while (noAtual)
  {
    printf("%d\n", noAtual->chave);
    noAtual = noAtual->anterior;
  }
  printf("BASE DA PILHA\n");
  printf("-----------------------\n");
}


void menu()
{
    int opcao;
    int valor;
    TNo *topo;

    opcao = 0;

    do
    {
        printf("Digite a opcao desejada:\n");
        printf("\t1 - Criar pilha\n");
        printf("\t2 - Inserir elemento na pilha\n");
        printf("\t3 - Remover elemento da pilha\n");
        printf("\t4 - Imprimir pilha\n");
        printf("\t0 - Sair do programa\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            criaPilha(&topo);
            break;
        case 2:
            printf("Digite o valor que deseja inserir na fila:\n");
            scanf("%d", &valor);
            incluiNaPilha(&topo, valor);
            break;
        case 3:
            removeDaPilha(&topo);
            break;
        case 4:
            imprimePilha(&topo);
            break;
        default:
            break;
        }
    } while (opcao != 0);
}

int main()
{
    menu();

    printf("Programa encerrado\n");
    return 0;
}

