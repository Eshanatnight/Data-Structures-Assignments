#include <stdio.h>
#include <stdlib.h>

struct CircularLinkedList
{
    int m_data;
    struct CircularLinkedList *m_nxtPointer;
};

typedef struct CircularLinkedList CircularLinkedList;

static CircularLinkedList *Head = NULL;
static CircularLinkedList *Tail = NULL;

/* Creates a CLL [Returns pointer to node] */
CircularLinkedList* create(int _data)
{
    CircularLinkedList *newNode = (CircularLinkedList *)calloc(1, (sizeof(CircularLinkedList)));
    newNode->m_data = _data;
    newNode->m_nxtPointer = newNode;
    printf("\nNew List Created \n");
    return newNode;
}

/* Prints the length of the list */
int length(CircularLinkedList* headRef)
{
    int length = 0;
    CircularLinkedList *temp = headRef;

    do
    {
        temp = temp->m_nxtPointer;
        length++;
    } while (temp != headRef);
    return length;
}

/* Sudo overloded Free Function */
void Free(void* __pointer)
{
    free(__pointer);
    __pointer = NULL;
    return;
}

/* To print */
void print(CircularLinkedList* _listHead)
{
    CircularLinkedList *temp = _listHead;

        do
        {
            printf("Element: %d \n", temp->m_data);
            temp = temp -> m_nxtPointer;
        } while (temp != _listHead);

    printf("\n X-----------------------------------------------------X \n \n");
    return;
}

/* To Delete a headnode */
void deleteFirst(CircularLinkedList** headRef)
{
    if(*headRef == NULL)
    {
        printf("\nList is empty\n");
        return;
    }


    CircularLinkedList *temp = *headRef;
    CircularLinkedList *prev = *headRef;

    if (prev->m_nxtPointer == prev)
    {
        *headRef = NULL;
        return;
    }

    while (prev->m_nxtPointer != *headRef)
        prev = prev->m_nxtPointer;

    prev->m_nxtPointer = temp->m_nxtPointer;
    *headRef = prev->m_nxtPointer;
    Free(temp);
    printf("Node Was deleted sussessfully \n");
    return;
}

/* To Delete a tailnode */
void deleteLast(CircularLinkedList** headRef)
{
    if(*headRef == NULL)
    {
        printf("\nList is empty\n");
        return;
    }


    CircularLinkedList *current = *headRef;
    CircularLinkedList *prev;

    if (current->m_nxtPointer == current)
    {
        *headRef = NULL;
        return;
    }

    while (current->m_nxtPointer != *headRef)
    {
        prev = current;
        current = current->m_nxtPointer;
    }

    prev->m_nxtPointer = current->m_nxtPointer;
    *headRef = prev->m_nxtPointer;
    Free(current);
    printf("Node Was deleted sussessfully \n");
    return;
}

/* Index Based Deletion */
void deleteAtIndex(CircularLinkedList** headRef, int _index)
{
    int _len = length(*headRef);
    int _count = 1;
    CircularLinkedList *prev = *headRef, *next = *headRef;

    if(*headRef == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    if (_index > _len || _index < 0 )
    {
        printf("\nIndex is not Found\n");
        return;
    }

    if (_index == 0)
    {
        deleteFirst(headRef);
        return;
    }

    while (_len > 0)
    {
        if (_index == _count)
        {
            prev->m_nxtPointer = next->m_nxtPointer;
            Free(next);
            return;
        }

        prev = prev->m_nxtPointer;
        next = prev->m_nxtPointer;

        _len--;
        _count++;
    }

    return;
}

/* Delete the entire list */
void deleteList(CircularLinkedList** headRef)
{
    CircularLinkedList *temp = *headRef;
    CircularLinkedList *next = NULL;

    do
    {
        next = temp->m_nxtPointer;
        Free(temp);
        temp = next;
    } while (temp != *headRef);

    printf("\nList Deleted Successfully\n\n");
}

/* Pushes Front An Element */
void push_front(CircularLinkedList** headRef, int newData)
{
    //* Heap Allocated
    CircularLinkedList *ptr1 = (CircularLinkedList *)malloc(sizeof(CircularLinkedList));
    CircularLinkedList *temp = *headRef;
    ptr1->m_data = newData;
    ptr1->m_nxtPointer = *headRef;

    /* If linked list is not NULL then set the next of last node */
    if (*headRef != NULL)
    {
        while (temp->m_nxtPointer != *headRef)
            temp = temp->m_nxtPointer;
        temp->m_nxtPointer = ptr1;
    }
    else
        ptr1->m_nxtPointer = ptr1; /* For the first node */

    *headRef = ptr1;
    return;
}

/* Pushes Back an Element */
void push_back(CircularLinkedList** headRef, int _data )
{
    CircularLinkedList *newNode = malloc(sizeof(CircularLinkedList));
    newNode->m_data = _data;
    newNode->m_nxtPointer = *headRef;
    CircularLinkedList *temp = *headRef;

    if (*headRef != NULL)
    {
        while (temp->m_nxtPointer != *headRef)
            temp = temp->m_nxtPointer;
        temp->m_nxtPointer = newNode;
    }

    else
        newNode->m_nxtPointer = newNode; /* For the first node */

    return;
}

/* puses an element after a key node */
void push_after_key(CircularLinkedList** headRef, int _key, int _data)
{
    CircularLinkedList *temp = *headRef;

    if (temp == NULL)
    {
        printf("the given previous node cannot be null \n");
        printf("initialize a new node \n");
        printf("Linked List Empty\n");
        return;
    }

    while (temp->m_data != _key)
    {
        if (temp->m_nxtPointer == *headRef)
        {
            printf("%d Key Not Present \n", _key);
            return;
        }
        temp = temp->m_nxtPointer;
    }

    CircularLinkedList *newNode = malloc(sizeof(CircularLinkedList));
    newNode->m_data = _data;

    if (temp->m_nxtPointer == *headRef)
        Tail = newNode;

    newNode->m_nxtPointer = temp->m_nxtPointer;

    temp->m_nxtPointer = newNode;
}



int main()
{
    int choice = 0, subChoice;

    Menu:
    printf("**----MENU----** \n");
    printf("Enter 1 for Creating A New LinkedList \n");
    printf("Enter 2 to Push an Element \n"); //* sub menu
    printf("Enter 3 for printing the LinkedList \n");
    printf("Enter 4 for Deletion \n"); //* sub menu
    printf("Press 5 to find the length of the LinkedList \n");
    printf("Press 0 to exit \n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        int _data;
        printf("Enter data: ");
        scanf("%d", &_data);
        Head = create(_data);
        break;
    }

    case 2:
    {
        int _data;
        printf("Enter Data: ");
        scanf("%d", &_data);
        printf("Press 1 for Pushing Back an Element \n");
        printf("Press 2 for Pushing to the front of the List \n");
        printf("Press 3 to insert after a cirten node \n");
        printf("Enter Your Choice: ");
        scanf("%d", &subChoice);
        switch (subChoice)
        {
            case 1:
            {
                push_back(&Head, _data);
                break;
            }

            case 2:
            {
                push_front(&Head, _data);
                break;
            }

            case 3:
            {
                int _key;
                printf("Enter The data after which you want to insert: ");
                scanf("%d", &_key);
                push_after_key(&Head, _key, _data);
                break;
            }
        }

        break;
    }

    case 3:
    {
        print(Head);
        break;
    }

    case 4:
    {
        int chk;
        printf("Press 1 to delete the Head Node\n");
        printf("Press 2 to delete the Tail Node \n");
        printf("Press 3 to delete a node at a specific index \n");
        printf("Press 4 to delete the entire list \n");
        printf("Enter your Choice: ");
        scanf("%d", &chk);

        switch (chk)
        {
            case 1:
            {
                deleteFirst(&Head);
                break;
            }

            case 2:
            {
                deleteLast(&Head);
                break;
            }

            case 3:
            {
                size_t _pos;
                printf("Enter The Position: ");
                scanf("%d", &_pos);
                deleteAtIndex(&Head, _pos);
                break;
            }

            case 4:
            {
                deleteList(&Head);
                break;
            }
        }
        break;
    }

    case 5:
    {
        printf("\nLength of the List is: %d \n", length(Head));
        break;
    }

    case 0:
    {
        if (Head != NULL)
            deleteList(&Head);
        return 0;
    }

    }


    printf("\n \n");
    goto Menu;

}