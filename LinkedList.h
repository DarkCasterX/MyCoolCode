#include <stdio.h>
#include <stdlib.h>
#define nullptr 0

typedef struct List
{
    int data;
    struct List* rest;
}List;

List* CreateList(int val, List* list);

List* EmptyList();

int isEmpty(List* empty);

int length(List* list, int startPos);

List* searchPos(List* list, int start, int pos);

List* last(List* list);

void insert(List* list, int val, int pos);

List* join_head(List* list, int val);

void join_list(List* first, List* second);

int DisplayList(List* display);
