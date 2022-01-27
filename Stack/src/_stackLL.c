#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void Free(void* _ptr)
{
    free(_ptr);
    _ptr = NULL;
}

typedef struct stack
{
    int m_top;
    int m_data;
    struct stack *m_nxtPointer;
} stack;

typedef int ValueType;
typedef stack *PointerType;
typedef stack **ReferenceType;


PointerType create(ValueType _data)
{
    PointerType newNode = (PointerType)malloc(sizeof(stack));
    newNode->m_top = 0;
    newNode->m_data = _data;
    newNode->m_nxtPointer = NULL;

    return newNode;
}

bool isEmpty(PointerType Head)
{
    return Head->m_top == -1;
}

void push(ReferenceType headRef, ValueType _data)
{
    PointerType newNode = (PointerType)malloc(sizeof(stack));
    newNode->m_data = _data;
    newNode->m_top = (*headRef)->m_top++;
    newNode->m_nxtPointer = *headRef;
    *headRef = newNode;
    printf("%d pushed to stack\n", _data);
    return;
}

bool pop(ReferenceType headRef)
{
    if (isEmpty(*headRef))
        return false;

    PointerType temp = *headRef;
    *headRef = (*headRef)->m_nxtPointer;
    ValueType popped = temp->m_data;

    Free(temp);
    printf("%d value was popped\n", popped);

    return true;
}

int peek(PointerType head)
{
    if (isEmpty(head))
        return 0;
    return head->m_data;
}


void print(ReferenceType headRef)
{
    PointerType temp = *headRef;

    while(temp != NULL)
    {
        printf("Element: %d \n", temp->m_data);
        temp = temp->m_nxtPointer;
    }
}

void delete(ReferenceType headRef)
{
    PointerType temp = *headRef;
    PointerType prev;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->m_nxtPointer;
        Free(prev);
    }

    printf("Stack Was Deleted \n");
}

int main()
{
    u_int32_t choice, cap;
    PointerType newStack;

Menu:
	printf("**----MENU----** \n");
	printf("Enter 1 for Creating A New Stack \n");
    printf("Enter 2 to Push an Element \n");
    printf("Enter 3 for printing the Stack \n");
    printf("Enter 4 for Deletion \n");
    printf("Press 5 to Pop an Element \n");
    printf("Press 6 to peek an Element \n");
	printf("Press 0 to exit \n");
	printf("Enter Your Choice: ");
	scanf("%d", &choice);

    switch (choice)
    {
        case 1:
        {
            ValueType _data;
            printf("Enter Data: ");
            scanf("%d", &_data);
            newStack = create(_data);
            break;
        }

        case 2:
        {
            ValueType _data;
            printf("Enter Data: ");
            scanf("%d", &_data);

            push(&newStack, _data);
            break;
        }

        case 3:
        {
            print(&newStack);
            break;
        }

        case 4:
        {
            delete(&newStack);
            break;
        }

        case 5:
        {
            pop(&newStack);
            break;
        }

        case 6:
        {
            peek(newStack);
            break;
        }

        case 0:
        {
            if (newStack->m_top != -1)
                delete (&newStack);
            return 0;
        }
    }


	printf("\n \n");
	goto Menu;
}