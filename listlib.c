#include "LinkedList.h"

//Constructor to create a list
List* CreateList(int val, List* list)
{
    List* newlist = malloc(sizeof(List));
    newlist->data = val;
    newlist->rest = list;
    return newlist;
}

//Recursive function used to implement ListConstruct
List* ListBuilder(int val, int start, int size)
{
    if(start < size - 1)
    {
        return CreateList(val, ListBuilder(val, start + 1, size));
    }
    else if( start >= size - 1)
    {
        return CreateList(val, EmptyList());
    }
}


//Creates a list of a specified size filled with the 'val' argument
List* ListConstruct(int val, int size)
{
    ListBuilder(val, 0, size);
}

//Frees a list from memory and sets its pointer to zero
void ListDestroy(List** list)
{
    if(!isEmpty(*list))
    {
        while (!isEmpty(*list))
        {
            List* temp = (*list);
            (*list) = (*list)->rest;
            free(temp);
            DisplayList(*list);
        }
        *list = nullptr;
        printf("Deleted list from memory.\n");
    }

}

//Useful function to create an empty list
List* EmptyList()
{
    return nullptr;
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

//Recursive function used to implement list_length
int length(List* list, int startPos)
{
    if(isEmpty(list))
    {
        return startPos;
    }
    length(list->rest, startPos + 1);
}

//Returns the amount of elements on a list
int list_length(List* list)
{
    length(list, 0);
}

//Recursive Function used to implement searchPos
List* getPosition(List* list, int start, int pos)
{
    if(start == pos)
    {
        return list;
    }
    getPosition(list->rest, start + 1, pos);
}

//Searches for the element in the specified position, set start to zero unless
//You otherwise need to
List* searchPos(List* list, int pos)
{
    return getPosition(list, 0, pos);
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
void insert(List* list, int val, int ind)
{
    if(ind <= 0)
    {
        printf("Use the (join_head) function to insert at the start.\n");
        return;
    }
    List* prev = searchPos(list, ind - 1);
    List* next = prev->rest;
    prev->rest = CreateList(val, next);
    printf("Inserted element into list at position %d\n", ind);
    prev = nullptr;
    next = nullptr;
}

//Returns a new list with the specified value at the start
List* join_head(List* list, int val)
{
    return CreateList(val, list);
}

//Add the elements of the second list to the first
void join_list(List* first, List* second)
{
    if(!isEmpty(first->rest))
    {
        List* connect = last(first);
        connect->rest = second;
        connect = nullptr;
    }
    else if(isEmpty(first->rest))
    {
        first->rest = second;
    }
}

//Adds an element to the end of the list
void append_list(List* list, int val)
{
    List* last_element = last(list);
    last_element->rest = CreateList(val, EmptyList());

    //Set pointers to null before returning
    last_element = nullptr;
}

//Replaces an element with the value of your choice
void replace(List* list, int ind, int val)
{
    searchPos(list, ind)->data = val;
}

//Recursively displays all the elements of a list in a way that is easy to visualize
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
