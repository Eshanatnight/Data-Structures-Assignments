#include <stdio.h>
#include <stdlib.h>

// sudo overload of the free function
void Free(void* _ptr)
{
	free(_ptr);
	_ptr = NULL;
	return;
}

struct node
{
	int m_data;
	struct node* m_nxtPointer;
};

typedef struct node node;
typedef struct node* NodePointerType;
typedef int ValueType;

// Function That Creates a node
NodePointerType createNode(int _data)
{
	NodePointerType newNode = (NodePointerType)malloc(sizeof(node));
	newNode->m_data = _data;
	newNode->m_nxtPointer = NULL;
	return newNode;
}

struct Queue
{
	NodePointerType front;
	NodePointerType rear;
};

typedef struct Queue Queue;
typedef struct Queue* QueuePointerType;


// Function That creates a new Queue
QueuePointerType createQueue()
{
	struct Queue* q = (QueuePointerType)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
	return q;
}

// Function that performs enQueue
void enQueue(QueuePointerType q)
{
	ValueType key;
	printf("Enter data: ");
	scanf("%d", &key);
	NodePointerType newNode = createNode(key);
	if (q->rear == NULL)
	{
        q->front = q->rear = newNode;
        return;
	}

	q->rear->m_nxtPointer = newNode;
	q->rear = newNode;
	return;
}

// Function that performs deQueue
void deQueue(QueuePointerType queueRef)
{
	if (queueRef->front == NULL)
		return;

	NodePointerType temp = queueRef->front;
	queueRef->front = queueRef->front->m_nxtPointer;

	if (queueRef->front == NULL)
		queueRef->rear = NULL;
	Free(temp);
	return;
}

// print queue function
void printQueue(QueuePointerType q)
{
	QueuePointerType newNode = q;
	while (newNode->rear != newNode->front)
	{
		printf("Element: %d\n", newNode->front->m_data);
		newNode->front = newNode->front->m_nxtPointer;
	}
	printf("Element: %d\n", newNode->front->m_data);
	return;
}

int main()
{

	int choice;
	QueuePointerType newQueue;

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
				newQueue = createQueue();
				printf("New Queue Created!\n\n");
				break;
			}

			// to perform enQueue
			case 2:
			{
				enQueue(newQueue);
				printf("enQueue Performed!\n\n");
				break;
			}

			// to perfrom deQueue
			case 3:
			{
				deQueue(newQueue);
				printf("deQueue Preformed!\n\n");
				break;
			}

			// to print the Queue
			case 4:
			{
				printQueue(newQueue);
				break;
			}

			// to breakout
			case 0:
			{
				if (newQueue != NULL)
					Free(newQueue);
				return 0;
			}
		}

	goto Menu;
}