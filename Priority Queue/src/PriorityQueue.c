#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


void Free(void* _ptr)
{
    free(_ptr);
    _ptr = NULL;
}

typedef struct node {
	int data;
	short priority;

	struct node* next;
} Node;

typedef struct node* PointerType;
typedef struct node** ReferenceType;
typedef int ValueType;
typedef short PriorityType;

PointerType newNode(ValueType _data, PriorityType _priority)
{
	PointerType temp = (PointerType)lloc(sizeof(Node));
	temp->data = _data;
	temp->priority = _priority;
	temp->next = NULL;

	return temp;
}

ValueType peek(ReferenceType head)
{
	return (*head)->data;
}


ValueType pop(ReferenceType head)
{
	PointerType temp = *head;
    int td;
    td = (*head)->data;
	(*head) = (*head)->next;
	Free(temp);
    return td;
}

void push(ReferenceType head, ValueType _data, PriorityType _priority)
{
	PointerType start = (*head);
	PointerType temp = newNode(_data, _priority);

	if ((*head)->priority > _priority)
    {
		temp->next = *head;
		(*head) = temp;
	}
	else
    {
		while (start->next != NULL && start->next->priority < _priority)
        {
			start = start->next;
		}

		temp->next = start->next;
		start->next = temp;
	}
}


bool isEmpty(ReferenceType head)
{
	return (*head) == NULL;
}

void Clear(PointerType _headref)
{
    while(_headref != NULL)
    {
        pop(&_headref);
        _headref = _headref->next;
    }

    _headref = NULL;
}

int main()
{

    PointerType priorityQueue = NULL;
    PriorityType _priority;
    ValueType _data;
    int choice;

Menu:
    printf("\n\nx------------------------------x\n \n");
    printf("Menu: \n");
    printf("Press 1 for Creating a New Queue\n");
    printf("Press 2 for Push an Element\n");
    printf("Press 3 for Pop an Element\n");
    printf("Press 4 to Peek Top\n");
    printf("Press 5 to Check is the Queue is Empty or not\n");
    printf("Press 0 to Exit\n");
    scanf("%d", &choice);

	switch (choice)
    {

        case 1:
        {
            if(priorityQueue != NULL)
            {
                char _ch;
                printf("The Queue is Not Empty\n");
                printf("Do You Want to Proceed?(Y/N): ");
                scanf("%c", _ch);
                if (_ch == 'Y')
                {
                    printf("Enter Data: ");
                    scanf("%d", &_data);
                    printf("Enter Priority: ");
                    scanf("%d", &_priority);
                    priorityQueue = newNode(_data, _priority);
                    break;
                }

                if (_ch =='N')
                    break;

                else
                {
                    printf("Unknown Input Breaking Out\n");
                    break;
                }
            }

            printf("Enter Data: ");
            scanf("%d", &_data);
            printf("Enter Priority: ");
            scanf("%d", &_priority);
            priorityQueue = newNode(_data, _priority);
            break;
        }

        case 2:
        {
            printf("Enter Data: ");
            scanf("%d", &_data);
            printf("Enter Priority: ");
            scanf("%d", &_priority);
            push(&priorityQueue, _data, _priority);
            break;
        }

        case 3:
        {
            printf("%d was Popped \n", pop(&priorityQueue));
        }

        case 4:
        {
            printf("Top data is: %d\n", peek(&priorityQueue));
            break;
        }

        case 5:
        {
            if (isEmpty(&priorityQueue))
                printf("Queue is Empty! \n");
            printf("Queue is not empty \n");
            break;
        }

        case 0:
        {
            if(!isEmpty(&priorityQueue))
                Clear(priorityQueue);
            return 0;
        }
    }
    goto Menu;
}
