#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _pudim   pudim;
typedef struct _hash    hash_table;

//Valor da key na Hash
int hash_key(int key, int size);
//Cria a hash
hash_table* creat_hash_table(int size, int elements);
//Adiciona pudins na hash
void add_pudim(int key, hash_table *nyan);
//Deleta pudins
void delete_pudim(int key, hash_table *nyan);
//Verifica se os pudins existem
void search_hash(int key, hash_table *nyan);
//Informacoes dos pudins
void prt_rash(hash_table *nyan);
//atualizando a capacidade
int update(hash_table *nyan);
//Redimensiona a table, casta uma fireball, e invoca um dragao
hash_table* resize(hash_table *nyan);

int main()
{

    return 0;
}
struct _pudim
{
    int key;
    pudim *next;
};
struct _hash
{
  pudim **table;
  int size;
  int elements;
  double load;
};

int hash_key(int key, int size)
{
    return key%size;
}
pudim* creat_pudim(int key)
{
    pudim *new_pudim = (pudim*) malloc(sizeof(pudim));
    new_pudim->key = key;
    new_pudim->next = NULL;
    return new_pudim;
}
hash_table* creat_hash_table(int size, int elements)
{
    int k;
    pudim **aux;
    hash_table *a;
    a = (hash_table*) malloc(sizeof(hash_table));
    a->table = (pudim**) malloc(sizeof(pudim*)*size);
    a->size = size;
    a->elements = elements;
    a->load = (double)elements/(double)size;
    aux = a->table;

    for(k = 0; k < size; k++)
        *(aux+k) = NULL;

    return a;
}
void add_pudim(int key, hash_table *nyan)
{
    pudim **aux_t, *aux;
    int a, comp = 0, p = hash_key(key, nyan->size);
    aux_t = nyan->table;

    aux = *(aux_t+p);
    if(aux == NULL)
    {
        aux = creat_pudim(key);
        aux->next = *(aux_t+p);
        *(aux_t+p) = aux;
        (nyan->elements)++;
        printf(" 1 0");
        return ;
    }

    while(aux != NULL)
    {
        comp++;
        if(aux->key == key)
        {
            printf(" 0 %d", comp);
            return ;
        }
        aux = aux->next;
    }
    aux = creat_pudim(key);
    aux->next = *(aux_t+p);
    *(aux_t+p) = aux;
    (nyan->elements)++;

    printf(" 1 %d", comp);
    return ;
}
void delete_pudim(int key, hash_table *nyan)
{
    pudim **aux_t, *aux, *aux1 = NULL;
    int a, comp = 0, p = hash_key(key, nyan->size);
    aux_t = nyan->table;
    aux = *(aux_t+p);

    if(aux == NULL)
    {
        printf(" 0 0");
        return;
    }
    if(aux->key == key)
    {
        printf(" 1 1");
        (nyan->elements)--;
        *(aux_t+p) = aux->next;
        free(aux);
        return ;
    }
    while(aux != NULL)
    {
        comp++;
        if(aux->key == key)
            break;
        aux = aux->next;
    }
    if(aux == NULL)
    {
        printf(" 0 %d", comp);
        return ;
    }
    if(aux->key == key)
    {
        aux = *(aux_t+p);
        while(aux->next->key != key)
            aux = aux->next;
        aux1 = aux->next;
        aux->next = aux->next->next;
        free(aux1);
        (nyan->elements)--;
        printf(" 1 %d", comp);
        return ;
    }
}
void search_hash(int key, hash_table *nyan)
{
    pudim **aux_t, *aux;
    int a, comp = 0, p = hash_key(key, nyan->size);
    aux_t = nyan->table;
    aux = *(aux_t+p);

    while(aux != NULL)
    {
        comp++;
        if(aux->key == key)
        {
            break;
        }
        aux = aux->next;
    }
    if(aux == NULL)
    {
        printf(" 0 %d", comp);
        return ;
    }
    printf(" 1 %d", comp);
}
void prt_rash(hash_table *nyan)
{
    int a, g_list, b_lis_def = 0;
    pudim **aux_t = nyan->table, *aux;

    for(a = 0; a < nyan->size; a++)
    {
        g_list = 0;
        aux = *(aux_t+a);
        while(aux != NULL)
        {
            g_list++;
            aux = aux->next;
        }
        if(g_list > b_lis_def)
            b_lis_def = g_list;
    }
    printf(" %d %d %d", nyan->size, nyan->elements, b_lis_def);
}
int update(hash_table *nyan)
{
    nyan->load = (double)nyan->elements/(double)nyan->size;
    if(nyan->load >= 0.75)
        return 1;
    return 0;
}
void add_pudim_re(int key, hash_table *nyan)
{
    pudim *aux, **aux_t;
    int p = hash_key(key, nyan->size);
    aux_t = nyan->table;

    aux = creat_pudim(key);
    aux->next = *(aux_t+p);
    *(aux_t+p) = aux;

    return ;
}
hash_table* resize(hash_table *nyan)
{
    int a, b, c;
    pudim **aux_t_1, *aux, *aux1;
    hash_table *new_hash = creat_hash_table((((nyan->size)*2)-1), nyan->elements);
    aux_t_1 = nyan->table;

    for(a = 0; a < nyan->size; a++)
    {
        aux = *(aux_t_1+a);
        while(aux != NULL)
        {
            add_pudim_re(aux->key, new_hash);
            aux1 = aux;
            aux = aux->next;
            free(aux1);
        }
    }

    return new_hash;
}
