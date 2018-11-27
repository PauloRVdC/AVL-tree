#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "fila.h"

void enqueue(int x, list *l)
{
    if (is_null(l) || is_full(l))
        return;
    insert_last(x, l);
}

int dequeue(list *l) {
	if (is_null(l))
        return -1;
    return remove_at(l->first, l);
}

int remove_at(int i, list *l)
{
    if (is_null(l) ||
        is_empty(l) ||
        (i < 0 || i > l->last))
        return -1;
    int x = l->items[i];
    int j;
    for (j = i; j < l->last; j++)
    {
        l->items[j] = l->items[j + 1];
    }
    l->last--;
    l->count--;
    if (is_empty(l))
    {
        l->first = -1;
    }
    return x;
}

void insert_last(int x, list *l)
{
    if (is_null(l) || is_full(l))
        return;
    if (is_empty(l))
        insert_at(x, 0, l);
    else if (l->last == l->max-1 && l->first != 0){
        l->last = 0;
        l->items[l->last] = x;
        l->count++;
    }
        else if (l->last == 0){
            l->last++;
            l->items[l->last] = x;
            l->count++;
        } else
        insert_at(x, l->last, l);
}

void insert_at(int x, int i, list *l)
{
    //se a lista for nula ou estiver cheia nao é possivel inserir
    if (is_null(l) ||
        is_full(l))
        return;
    int j;
    //condicao especial quando a lista é vazia
    if (is_empty(l))
    {
        if (i != 0)
            return;
        l->items[0] = x;
        l->first = 0;
        l->last = 0;
        l->count = 1;
        return;
    }

    //se a lista nao estiver vazia,
    //nao eh possivel inserir fora do intervalo da lista
    //caso i == l->count o item sera inserido em l->count
    if (i < 0 || (i != l->count && i > l->last))
    {
        return;
    }

    if (i == l->last)
    {
        l->last++;
        l->items[l->last] = x;
    }
    else
    {
        for (j = l->last; j >= i; j--)
        {
            l->items[j + 1] = l->items[j];
        }
        l->last++;
        l->items[i] = x;
    }
    l->count++;
}

int peek(list *l) {
	return l->items[l->first];
}

int countf(list *l) {
	return l->count;
}

int max(list *l) {
	return l->max;
}

int is_null(list *l)
{
    return l == NULL;
}

int is_empty(list *l)
{
    return is_null(l) || l->count == 0;
}

int is_full(list *l)
{
    return l->count == l->max;
}

void destroy_list(list **l)
{
    free((*l)->items);
    free(*l);
    *l = NULL;
}

list *new_queue(int size)
{
    list *l = (list *)malloc(sizeof(list));
    l->items = (int *)malloc(size * sizeof(int));
    l->count = 0;
    l->first = -1;
    l->last = -1;
    l->max = size;
    return l;
}

int search(int x, list *l)
{
    if (is_null(l) || is_empty(l))
        return -1;
    int i;
    for (i = l->first; i < l->last; i++)
    {
        if (x == l->items[i])
            return i;
    }
    return -1;
}