#include "LinkedList.h"

//Constructor to create a list
List* CreateList(int val, List* list)
{
    List* newlist = malloc(sizeof(List));
    newlist->data = val;
    newlist->rest = list;
    return newlist;
}

//Useful function to create an empty list
List* EmptyList()
{
    return 0;
}

//Checks if the element points to 0
int isEmpty(List* empty)
{
    if(empty == nullptr)
    {
        return 1;
    }
    return 0;
}

//Returns the amount of elements on a list
int length(List* list, int startPos)
{
    if(isEmpty(list))
    {
        return startPos;
    }
    length(list->rest, startPos + 1);
}

//Searches for the element in the specified position, set start to zero unless
//You otherwise need to
List* searchPos(List* list, int start, int pos)
{
    if(start == pos)
    {
        return list;
    }
    searchPos(list->rest, start + 1, pos);
}

//Grabs the last element of a list
List* last(List* list)
{
    if(isEmpty(list->rest))
    {
        return list;
    }
    last(list->rest);
}

//Inserts a value at a zero-indexed position in the list
void insert(List* list, int val, int pos)
{
    if(pos <= 0)
    {
        printf("Use the (join_head) function to insert at the start.\n");
        return;
    }
    List* prev = searchPos(list, 0, pos - 1);
    List* next = prev->rest;
    prev->rest = CreateList(val, next);
    printf("Inserted element into list.\n");
    prev = nullptr;
    next = nullptr;
}

//Returns a new list with the sspecified value at the start
List* join_head(List* list, int val)
{
    return CreateList(val, list);
}

//Add the elements of the second list to the first
void join_list(List* first, List* second)
{
    List* connect = last(first);
    connect->rest = second;
    connect = nullptr;
}

//Adds an element to the end of the list
void append_list(List* list, int val)
{
    List* last_element = last(list);
    last_element->rest = CreateList(val, EmptyList());
    last_element = nullptr;
}

//Displays all the elements of a list in a way that is easy to visualize
int DisplayList(List* display)
{
    if(isEmpty(display))
    {
        printf("End of list.\n");
        return 0;
    }
    printf("%d", display->data);
    printf("->");
    DisplayList(display->rest);
}

int main()
{
    List* my_list = CreateList(4, CreateList(1, CreateList(2, CreateList(3, EmptyList()))));
    DisplayList(my_list);
    return 0;
}   
