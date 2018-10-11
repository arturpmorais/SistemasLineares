#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef
    struct No
    {
        void*      info;
        struct No* prox;
    }
    No;
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
char insira (Lista* lis, void* inf);
char remova (Lista* lis, void* inf);

#endif // LISTA_H_INCLUDED
