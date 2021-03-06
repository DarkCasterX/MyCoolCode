#include <stdio.h>
#include <stdlib.h>
#define nullptr 0

typedef struct List
{
    int data;
    struct List* rest;
}List;

List* CreateList(int val, List* list);

List* ListBuilder(int val, int start, int size);

List* ListConstruct(int val, int size);

void ListDestroy(List** list);

List* EmptyList();

int isEmpty(List* empty);

int length(List* list, int startPos);

int list_length(List* list);

List* getPosition(List* list, int start, int pos);

List* searchPos(List* list, int pos);

List* last(List* list);

void insert(List* list, int val, int pos);

List* join_head(List* list, int val);

void join_list(List* first, List* second);

void append_list(List* list, int val);

void replace(List* list, int pos, int val);

int DisplayList(List* display);
