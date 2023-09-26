#include <stdio.h>
#include <stdlib.h>

struct TNo
{
    int chave;
    struct TNo *anterior;
    struct TNo *proximo;
};
typedef struct TNo TNo;

void criaFila(TNo **primeiro, TNo **ultimo)
{
    *primeiro = NULL;
    *ultimo = NULL;
}

TNo *aloca(int k)
{
    TNo *novoNo = (TNo *)malloc(sizeof(TNo));
    novoNo->chave = k;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}

void incluiNaFila(TNo **primeiro, TNo **ultimo, int k)
{
    TNo *novoNo = aloca(k);
    if (*primeiro == NULL)
    {
        *primeiro = novoNo;
        *ultimo = novoNo;
    }
    else
    {
        novoNo->anterior = *ultimo;
        (*ultimo)->proximo = novoNo;
        *ultimo = novoNo;
    }
    printf("Elemento enfileirado\n");
}

void removePrimeiro(TNo **primeiro)
{
    if (*primeiro == NULL)
    {
        printf("Fila vazia! Impossível remover primeiro nó.\n");
        return;
    }

    TNo *noAtual = *primeiro;
    *primeiro = noAtual->proximo;

    if (*primeiro != NULL)
    {
        (*primeiro)->anterior = NULL;
    }

    free(noAtual);
    printf("Elemento desenfileirado\n");
}

void imprimeFila(TNo *primeiro)
{
    if (primeiro == NULL)
    {
        printf("Fila vazia!\n");
        return;
    }

    printf("-----------------------\n");
    printf("PRIMEIRO ELEMENTO DA FILA\n");
    while (primeiro)
    {
        printf("%d\n", primeiro->chave);
        primeiro = primeiro->proximo;
    }
    printf("ULTIMO ELEMENTO DA FILA\n");
    printf("-----------------------\n");
}

void menu()
{
    int opcao;
    int valor;
    TNo *primeiro = NULL;
    TNo *ultimo = NULL;

    opcao = 0;

    do
    {
        printf("Digite a opcao desejada:\n");
        printf("\t1 - Criar fila\n");
        printf("\t2 - Inserir elemento na fila\n");
        printf("\t3 - Remover elemento da fila\n");
        printf("\t4 - Imprimir fila\n");
        printf("\t0 - Sair do programa\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            criaFila(&primeiro, &ultimo);
            break;
        case 2:
            printf("Digite o valor que deseja inserir na fila:\n");
            scanf("%d", &valor);
            incluiNaFila(&primeiro, &ultimo, valor);
            break;
        case 3:
            removePrimeiro(&primeiro);
            break;
        case 4:
            imprimeFila(primeiro);
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
