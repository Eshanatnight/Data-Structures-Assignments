#include <stdio.h>
#include <stdlib.h>


struct Linkedlist
{
    struct Linkedlist *m_nxtPointer;
    int m_data;
};

/* Sudo-Overloaded free function */
void Free(void* _pointer)
{
    free(_pointer);
    _pointer = NULL;
    return;
}

typedef struct Linkedlist Linkedlist;

Linkedlist *Head = NULL;
Linkedlist *Tail = NULL;

/* Length Function (ITERATIVE) */
int length(Linkedlist *headRef)
{
    Linkedlist *temp = headRef;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->m_nxtPointer;
    }
    return count;
}

/* Length Function (RECURSSIVE) */
int Length(Linkedlist* headRef)
{
    if (headRef == NULL)
        return 0;

    return 1 + Length(headRef->m_nxtPointer);
}

/* To Create A new Head node */
Linkedlist* Create(int data)
{
    Linkedlist* headNode = (Linkedlist *)calloc(1, sizeof(Linkedlist));
    Head = headNode;
    headNode->m_data = data;
    return headNode;
}

/* To print */
void print(Linkedlist* _list)
{
    while(_list != NULL)
    {
        printf("Element: %d \n", _list -> m_data);
        _list= _list -> m_nxtPointer;
    }

    printf("\n X-----------------------------------------------------X \n \n");
}

/* To Append */
void push_back(Linkedlist** headRef, int newData)
{
    //* Heap Allocated
    Linkedlist *newNode = (Linkedlist *)malloc(sizeof(Linkedlist));

    Linkedlist *prev = *headRef;

    newNode->m_data = newData;
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    while (prev->m_nxtPointer != NULL)
        prev = prev->m_nxtPointer;

    prev->m_nxtPointer = newNode;
    Tail = newNode;
    return;
}

/* To Insert After */
void insertAfter(Linkedlist* prevNode, int newData)
{
    if (prevNode == NULL)
    {
        printf("the given previous node cannot be NULL \n");
        printf("initialize a new node \n");
        return;
    }

    Linkedlist* newNode =(Linkedlist*) malloc(sizeof(Linkedlist));

    newNode->m_data  = newData;

    newNode->m_nxtPointer = prevNode->m_nxtPointer;

    prevNode->m_nxtPointer = newNode;

    return;
}

void insertAfterKey(Linkedlist** headRef, int keyData, int newData)
{
    Linkedlist *temp = *headRef;

    if (temp == NULL)
    {
        printf("the given previous node cannot be NULL \n");
        printf("initialize a new node \n");
        printf("Linked List Empty\n");
        return;
    }

    while (temp->m_data != keyData)
    {
        temp = temp->m_nxtPointer;
    }

    Linkedlist* newNode =(Linkedlist*) malloc(sizeof(Linkedlist));

    newNode->m_data  = newData;

    newNode->m_nxtPointer = temp->m_nxtPointer;

    temp->m_nxtPointer = newNode;

    return;
}

/* To Push a New Elem in front */
void push_front(Linkedlist** headRef, int newData)
{
    Linkedlist* newNode =(Linkedlist*) malloc(sizeof(Linkedlist));

    newNode->m_data  = newData;

    newNode->m_nxtPointer = (*headRef);

    (*headRef) = newNode;

    return;
}

/* To Delete a node based on data*/
void delete(Linkedlist** headRef, int key)
{
    Linkedlist *temp = *headRef;
    Linkedlist *prev;

    if (temp != NULL && temp -> m_data == key)
    {
        *headRef = temp->m_nxtPointer;
        Free(temp);
        printf("Deleted \n");
        return;
    }

    while (temp != NULL && temp->m_data != key)
    {
        prev = temp;
        temp = temp->m_nxtPointer;
    }

    if(temp == NULL)
        return;

    prev->m_nxtPointer = temp->m_nxtPointer;
    Free(prev);
}

/* To Delete a node at a specific position */
void delete_at_pos(Linkedlist** headRef, int _pos)
{
    if(*headRef == NULL)
    {
        printf("List Empty");
        return;
    }

    Linkedlist* temp = *headRef;  //Temporary

    if (_pos == 0)
    {
        *headRef = temp->m_nxtPointer;
        Free(temp);  //Free Up old head
        Head = *headRef; //! to be tested
        return;
    }

    for (int i = 0; temp != NULL && i < _pos-1; i++)
        temp = temp->m_nxtPointer;

    if (temp == NULL || temp->m_nxtPointer == NULL)
    {
        printf("Position is greater than the number of nodes \n \n");
        return;
    }

    Linkedlist *m_nxtPointerFromDel = temp->m_nxtPointer->m_nxtPointer;
    Free(temp->m_nxtPointer);// Free's the memory
    temp->m_nxtPointer = m_nxtPointerFromDel; // Unlinks here
}

/* To delete an entire list */
void deleteList(Linkedlist** headRef)
{
    Linkedlist *_current = *headRef;
    Linkedlist* _m_nxtPointer = NULL;

    while (_current != NULL)
    {
        _m_nxtPointer = _current->m_nxtPointer;
        Free(_current);
        _current = _m_nxtPointer;
    }

    *headRef = NULL;
    printf("List Was Deleted Successfully \n");
    Head = NULL;
    Tail = NULL;
}

/* Reversing a Linked List */
void reverse(Linkedlist** headRef)
    {
        Linkedlist* current = *headRef;
        Linkedlist *prev = NULL, *m_nxtPointer = NULL;

        while (current != NULL) {
            m_nxtPointer = current->m_nxtPointer;

            current->m_nxtPointer = prev;

            prev = current;
            current = m_nxtPointer;
        }
        *headRef = prev;
    }

int main()
{
    printf(" Head : %d", Head);
    printf(" Tail : %d", Tail);
    printf("\n \n X-----------------------------------------------------X \n \n");
    Linkedlist* firstNode = NULL;
    Linkedlist* secondNode = NULL;
    Linkedlist* thirdNode = NULL;

    firstNode = (Linkedlist *)malloc(sizeof(Linkedlist));  //head Node Constructed
    secondNode = (Linkedlist *)malloc(sizeof(Linkedlist)); //second Node Constructed
    thirdNode = (Linkedlist *)malloc(sizeof(Linkedlist)); //third node constructed


    firstNode->m_data = 1;
    firstNode->m_nxtPointer = secondNode;

    secondNode->m_data = 2;
    secondNode->m_nxtPointer = thirdNode;

    thirdNode->m_data = 3;
    thirdNode->m_nxtPointer = NULL;

    print(firstNode);

    Linkedlist* new = (Linkedlist *)malloc(sizeof(Linkedlist));
    new->m_data = 1;
    new->m_nxtPointer = NULL;
    Head = new;

    push_back(&new, 2);
    print(new);

    insertAfterKey(&Head,2, 3);
    print(Head);

    push_front(&Head, 0);
    print(Head);

    push_back(&Tail, 4);
    print(Head);

    push_back(&Tail, 5);
    print(Head);

    Linkedlist *head = NULL;
    push_front(&head, 7);
    push_front(&head, 1);
    push_front(&head, 3);
    push_front(&head, 2);
    push_front(&head, 8);
    reverse(&head);
    print(head);

    printf("Length Of List %d \n", length(head));
    printf("Length Of List %d \n", Length(head));
    printf("\n ---- Before Deletion ---- \n");
    print(head);
    delete_at_pos(&head, 4);
    print(head);

    deleteList(&firstNode);
    deleteList(&new);
    return 0;
}