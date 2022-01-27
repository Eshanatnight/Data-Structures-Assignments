#include <stdio.h>
#include <stdlib.h>

void Free(void *_ptr)
{
    free(_ptr);
    _ptr = NULL;
}

struct Node
{
    int m_data;
    struct Node *m_nxtPointer;
};

typedef struct Node Node;
typedef struct Node *PointerType;
typedef struct Node **ReferenceType;
typedef int ValueType;

PointerType Create(ValueType _data)
{
    PointerType newNode = NULL; // Set to Null For Debug
    newNode = (PointerType)malloc(sizeof(Node));
    newNode->m_data = _data;
    newNode->m_nxtPointer = NULL;
    return newNode;
}

void push_back(PointerType _head, ValueType _data)
{
    if (_head == NULL)
        return;

    //* Heap Allocated
    PointerType newNode = (PointerType )malloc(sizeof(Node));
    PointerType prev = _head;

    newNode->m_nxtPointer = NULL;
    newNode->m_data = _data;
    if (_head == NULL)
    {
        _head = newNode;
        return;
    }
    while (prev->m_nxtPointer != NULL)
        prev = prev->m_nxtPointer;
    prev->m_nxtPointer = newNode;

    return;
}

void Print(ReferenceType _headref)
{
    if (*_headref == NULL)
        return;
    PointerType __list = *_headref;
    if (__list != NULL)
    {
        while (__list != NULL)
        {
            printf("Element: %d \n", __list->m_data);
            __list = __list->m_nxtPointer;
        }

        printf("\n X-----------------------------------------------------X \n \n");
    }

    else
        printf("List Empty \n");
}

/* Merge Function */
PointerType merge(PointerType headRef1, PointerType headRef2)
{
    PointerType temp = headRef1;

    while (headRef1 != NULL && headRef1->m_nxtPointer != NULL && headRef2 != NULL)
    {
        headRef1 = headRef1->m_nxtPointer;
    }
    headRef1->m_nxtPointer = headRef2;
    printf("Lists Merged \n");
    headRef1 = temp;
    Print(&headRef1);
    return headRef1;
}

/* Reverse Function */
PointerType Reverse(ReferenceType _headref)
{
    PointerType prev = NULL;
    PointerType current = *_headref;
    PointerType next = NULL;

    while (current != NULL)
    {
        next = current->m_nxtPointer;
        current->m_nxtPointer = prev;
        prev = current;
        current = next;
    }
    *_headref = prev;
}

int main()
{
    PointerType list1, list2;
    list1 = Create(1);
    push_back(list1, 2);
    push_back(list1, 3);
    push_back(list1, 4);
    push_back(list1, 5);
    Print(&list1);

    list2 = Create(6);
    push_back(list2, 7);
    push_back(list2, 8);
    push_back(list2, 9);
    push_back(list2, 0);
    Print(&list2);

    merge(list1, list2);
    Print(&list1);
    return 0;
}
