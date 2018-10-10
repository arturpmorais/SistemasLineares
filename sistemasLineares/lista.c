#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista/*<int>*/ lis;

char/*boolean*/ insira (Lista* lis, void* inf)
{
    if (lis->inicio==NULL)
    {
        lis->inicio       = (No*)malloc(sizeof(No));
        lis->inicio->info = inf;
        lis->inicio->prox = NULL;
        return 1/*true*/;
    }

    int comp = lis->compareTo(inf,lis->inicio->info);

    if (comp<0)
    {
        No* novo     = (No*)malloc(sizeof(No));
        novo->info   = inf;
        novo->prox   = lis->inicio;
        lis ->inicio = novo;
        return 1/*true*/;
    }

    if (comp==0)
        return 0/*false*/; //Informacao repetida!

    No* atual = lis->inicio;

    for(;;) // parar ao achar onde inserir
    {
        if (atual->prox==NULL)
            break;

        comp=(*(lis->compareTo))(inf,atual->prox->info); ////////////////////////////////////

        if (comp==0)
            return 0/*false*/;

        if (comp<0)
            break;

        if (comp>0)
            atual=atual->prox;
    }

    No* novo    = (No*)malloc(sizeof(No));
    novo ->info = inf;
    novo ->prox = atual->prox;
    atual->prox = novo;
}

char/*boolean*/ remova (Lista* lis, void* inf)
{
    if (lis->inicio==NULL)
        return 0/*false*/; //Lista vazia!
    No* atual = lis->inicio;


    return 0/*false*/; //Informacao nao encontrada!
}

void imprima (Lista* lis)
{
    if (lis->inicio==NULL)
    {
        printf("A lista esta vazia!\n\n");
        return;
    }

    // Caso a lista nao esteja vazia
    No* atual = lis->inicio;

    for (;;)
    {
        if (atual == NULL)
            break;

        //printf("Info = %d\n", atual->info);
        intPrint(atual->info);
        printf("\n");
        atual = atual->prox;
    }

    printf("--- fim da lista ---\n\n");
}

int intCompareTo (void* a, void* b)
{
    int numero1 = *(int*)a;
    int numero2 = *(int*)b;

    if (numero1<numero2)
        return -1;

    if (numero1==numero2)
        return 0;

    if (numero1>numero2)
        return 1;
}

void intPrint (void* i)
{
    int imprimir = *(int*)i;
    printf ("%d", imprimir);
}

void insercao ()
{
    int* i=(int*)malloc(sizeof(int));
    printf ("Entre com o inteiro a inserir: ");
    scanf ("%d",i);
    char deuCerto = insira (&lis,(void*)i);
    if (!deuCerto)
        fprintf (stderr,"Valor repetido\n\n");
}

void remocao ()
{
    int* i=(int*)malloc(sizeof(int));
    printf ("Entre com o inteiro a remover: ");
    scanf ("%d",i);
    char deuCerto = remova (&lis,(void*)i);
    if (!deuCerto)
        fprintf (stderr,"Valor inexistente\n\n");
}

int main ()
{
    static void (*funcao[4]) () =
    {&insercao, &remocao, &impressao, &termino};

    lis.inicio    = NULL;
    lis.compareTo = (int  (*) (void*,void*))&intCompareTo;
    lis.print     = (void (*) (void*))      &intPrint;

    for(;;)
    {
        unsigned int opcao;
        printf ("\nOpcao (0=insercao/1=remocao/2=impressao/3=termino): ");
        scanf  ("%d", &opcao);
        (*funcao[opcao]) ();
    }

    return 0;
}
