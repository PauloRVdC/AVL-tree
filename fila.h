#ifndef FILA_H 
#define FILA_H

#include "list.h"

void enqueue(int x, list *l);
int dequeue(list *l);
int peek(list *l);
int countf(list *l);
int max(list *l);
list *new_queue(int size);

#endif