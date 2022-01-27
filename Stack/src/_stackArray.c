#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct stack
{
    int m_top;
    u_int32_t m_capacaity;
    int *m_array;
};

typedef struct stack stack;
typedef int ValueType;
typedef stack* PointerType;


PointerType create(u_int32_t _cap)
{
    PointerType stack = (PointerType)malloc(sizeof(stack));
    stack->m_capacaity = _cap;
    stack->m_top = -1;
    stack->m_array = (ValueType *)calloc(_cap, sizeof(ValueType));
    return stack;
}

bool isFull(PointerType _stack)
{
    return _stack->m_top == _stack->m_capacaity;
}

bool isEmpty(PointerType _stack)
{
    return _stack->m_top == -1;
}


void push(PointerType _stack, ValueType _item)
{
    if (isFull(_stack))
        return;
    _stack->m_array[++_stack->m_top] = _item;
    printf("%d pushed to stack\n", _item);
    return;
}

int pop(PointerType stack)
{
    if (isEmpty(stack))
        return 0;
    return stack->m_array[stack->m_top--];
}

int peek(PointerType stack)
{
    if (isEmpty(stack))
        return 0;
    return stack->m_array[stack->m_top];
}

void print(PointerType _stack)
{
    for (int i = _stack->m_top; i > -1; i--)
        printf("Element %d: %d \n", i, _stack->m_array[i]);
}

void delete(PointerType _stack)
{
    free(_stack->m_array);
    free(_stack);
    printf("Stack was Deleted\n");
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
	printf("Press 0 to exit \n");
	printf("Enter Your Choice: ");
	scanf("%d", &choice);

    switch (choice)
    {
        case 1:
        {
            printf("Enter Capacity: ");
            scanf("%d", &cap);
            newStack = create(cap);
            break;
        }

        case 2:
        {
            ValueType _data;
            printf("Enter Data: ");
            scanf("%d", &_data);

            push(newStack, _data);
            break;
        }

        case 3:
        {
            print(newStack);
            break;
        }

        case 4:
        {
            delete (newStack);
            break;
        }

        case 5:
        {
            pop(newStack);
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
                delete (newStack);
            return 0;
        }
    }

	printf("\n \n");
	goto Menu;

}
