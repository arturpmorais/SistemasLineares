#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

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

