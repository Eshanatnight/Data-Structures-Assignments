#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5


/* Stack-Array Implementaion */
struct CircularQueue
{
    int front, rear;
	int size;
	int *m_items;
};

typedef struct CircularQueue circularQueue;
typedef struct CircularQueue* PointerType;
typedef int ValueType;
typedef int* ValPointerType;

/* Sudo Constructor to initialize */
void CircularQueue(PointerType _this)
{
	printf("Enter the size: ");
	scanf("%d", &_this->size);
	_this->m_items = (ValPointerType)calloc((_this->size), sizeof(ValueType));
	_this->front = _this->rear = -1;
}

/* Check if the queue is full */
bool isFull(PointerType _this)
{
    if ((_this->rear == (_this->front - 1) % (SIZE - 1)) || (_this->front == 0 && _this->rear == SIZE - 1))
        return true;
    return false;
}

/* Check if the queue is empty */
bool isEmpty(PointerType _this)
{
    if (_this->front == -1)
        return true;
    return false;
}

/* Adding an element */
void enQueue(PointerType _this, ValueType _elem)
{
    if (isFull(_this))
        printf("\n Queue is full!! \n");

    else
    {
        // Insert First Elem
        if (isEmpty(_this))
        {
            _this->front = _this->rear = 0;
            _this->m_items[_this->rear] = _elem;
        }

        else if (_this->rear == SIZE - 1 && _this->front != 0)
        {
            _this->rear = 0;
            _this->m_items[_this->rear] = _elem;
        }

        else
        {
            _this->rear++;
            _this->m_items[_this->rear] = _elem;
        }

        printf("Inserted -> %d\n", _elem);
        printf("enQueue Performed!\n\n");
    }
}

/* Removing an element */
int deQueue(PointerType _this)
{
    if (isEmpty(_this))
    {
        printf("\n Queue is empty !! \n");
        return -1;
    }

    else
    {
        int element = _this->m_items[_this->front];
        _this->m_items[_this->front] = -1;
        if (_this->front == _this->rear)
        {
            _this->front = -1;
            _this->rear = -1;
        }
        else if (_this->front == SIZE - 1)
            _this->front = 0;

        else
            _this->front++;

        printf("\n Deleted element -> %d \n", element);
        return element;
    }
}

/* Display the queue */
void printQueue(PointerType _this)
{
	if (_this->front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are:\n");

    if (_this->rear >= _this->front)
    {
        for (int i = _this->front; i <= _this->rear; i++)
            printf("Element[%d]: %d\n",i ,_this->m_items[i]);
    }

    else
    {
        for (int i = _this->front; i < SIZE; i++)
            printf("Element[%d]: %d\n",i, _this->m_items[i]);

        for (int i = 0; i <= _this->rear; i++)
            printf("Element[%d]: %d\n",i, _this->m_items[i]);
    }
}

/* Delete Array */
void Free(PointerType _this)
{
    for (ValPointerType i = _this->m_items; i != (_this->m_items) + (_this->size) ; i++)
		free(_this->m_items);
	printf("Deleted!!\n");
}


int main()
{
	int choice;
	circularQueue newQueue;

	/* ------------------------------------------ */

	Menu:
		printf("Menu:\n");
		printf("Enter 1 to create Queue\n");
		printf("Enter 2 to enQueue\n");
		printf("Enter 3 to deQueue\n");
		printf("Press 4 to Print\n");
		printf("Press 0 to Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d", &choice);

        switch (choice)
		{
				// to create a new queue
			case 1:
			{
				CircularQueue(&newQueue);
				printf("New Queue Created!\n\n");
				break;
			}

			// to perform enQueue
			case 2:
			{
                ValueType value;
                printf("Enter data: ");
                scanf("%d", &value);
                enQueue(&newQueue, value);
				break;
			}

			// to perfrom deQueue
			case 3:
			{
				deQueue(&newQueue);
				printf("deQueue Preformed!\n\n");
				break;
			}

			// to print the Queue
			case 4:
			{
				printQueue(&newQueue);
				break;
			}

			// to breakout
			case 0:
			{
				Free(&newQueue);
				return 0;
			}

		}

	goto Menu;
}