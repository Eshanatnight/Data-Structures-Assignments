#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Sudo overload of the stdlib free() (for debugablity) */
void Free(void* _ptr)
{
    free(_ptr);
    _ptr = NULL;
}

/* Node Structure */
struct Node
{
    int m_data;
    struct Node* m_prevPointer;
    struct Node* m_nextPointer;
};

    typedef struct Node node;
    typedef struct Node* NodePointerType;
    typedef int ValueType;


/* Function Get New Node */
static NodePointerType getnode(int data)
{
    NodePointerType newNode = (NodePointerType)malloc(sizeof(node));
    newNode->m_data = data;
    newNode->m_prevPointer = newNode->m_nextPointer = NULL;
    return newNode;
}

/* Deque Struct */
struct deque
{
    NodePointerType front;
    NodePointerType rear;
    u_int32_t size;       /* size of the deque */
};

typedef struct deque deque;
typedef struct deque* DequePointerType;

void Deque(DequePointerType _this)
{
    _this->front = _this->rear = NULL;
    _this->size = 0;
}

/* Function to check whether deque is empty or not */
bool isEmpty(DequePointerType _this)
{
    return (_this->front == NULL);
}

/* Function to return the number of elements in the deque */
u_int32_t size(DequePointerType _this)
{
    return _this->size;
}

/* Function to insert an element at the front end */
void insertFront(DequePointerType _this, int data)
{
    NodePointerType newNode = getnode(data);
    if (newNode == NULL)
        printf("OverFlow\n");
    else
    {
        if (_this->front == NULL)
            _this->rear = _this->front = newNode;

        else
        {
            newNode->m_nextPointer = _this->front;
            _this->front->m_prevPointer = newNode;
            _this->front = newNode;
        }

        (_this->size)++;
    }
}

/* Function to insert an element at the rear end */
void insertRear(DequePointerType _this, int data)
{
    NodePointerType newNode = getnode(data);

    if (newNode == NULL)
        printf("OverFlow\n");

    else
    {
        if (_this->rear == NULL)
            _this->front = _this->rear = newNode;

        else
        {
            newNode->m_prevPointer = _this->rear;
            _this->rear->m_nextPointer = newNode;
            _this->rear = newNode;
        }

        (_this->size)++;
    }
}


/* Function to delete the element from the front end */
void deleteFront(DequePointerType _this)
{
    if (isEmpty(_this))
        printf("UnderFlow\n");

    else
    {
        NodePointerType temp = _this->front;
        _this->front = _this->front->m_nextPointer;

        if (_this->front == NULL)
            _this->rear = NULL;
        else
            _this->front->m_prevPointer = NULL;
        Free(temp);

        (_this->size)--;
    }
}


/* Function to delete the element from the rear end */
void deleteRear(DequePointerType _this)
{
    if (isEmpty(_this))
        printf("UnderFlow\n");

    else
    {
        NodePointerType temp = _this->rear;
        _this->rear = _this->rear->m_prevPointer;

        if (_this->rear == NULL)
            _this->front = NULL;
        else
            _this->rear->m_nextPointer = NULL;
        Free(temp);

        (_this->size)--;
    }
}

/* Function to return the element at the front end */
ValueType getFront(DequePointerType _this)
{
    if (isEmpty(_this))
        return -1;
    return _this->front->m_data;
}

/* Function to return the element at the rear end */
ValueType getRear(DequePointerType _this)
{
    if (isEmpty(_this))
        return -1;
    return _this->rear->m_data;
}

/* Function to delete all the elements from Deque */
void erase(DequePointerType _this)
{
    _this->rear = NULL;
    while (_this->front != NULL)
    {
        NodePointerType temp = _this->front;
        _this->front = _this->front->m_nextPointer;
        Free(temp);
    }

    _this->size = 0;
}

/* Function to Print Deque */
void displayDeque(DequePointerType _this)
{
    NodePointerType temp = _this->front;
    int i = 0;
    while (temp != NULL)
    {
        printf("Element [%d]: %d\n", i, temp->m_data);
        temp = temp->m_nextPointer;
        i++;
    }
}

int main()
{
	int choice;
	deque newDeque;

	/* ------------------------------------------ */

	Menu:
		printf("Menu:\n");
		printf("Enter 1 to create Deque\n");
		printf("Enter 2 to Push\n");
		printf("Enter 3 to Delete\n");
		printf("Press 4 to Print\n");
        printf("Press 5 to Get Size\n");
        printf("Press 6 to Get Data\n");
		printf("Press 0 to Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			// to create a new queue
			case 1:
			{
				Deque(&newDeque);
				printf("New Deque Created!\n\n");
				break;
			}

			// to perform Push
			case 2:
			{
                ValueType _data;
                printf("Enter Data: ");
                scanf("%d", &_data);
                int ch;
                printf("Press 1 to Push Front\n");
                printf("Press 2 to Push Rear\n");
                printf("Enter Your Choice: ");
                scanf("%d", &ch);
                switch (ch)
                {
                    case 1:
                    {
                        insertFront(&newDeque, _data);
                        break;
                    }

                    case 2:
                    {
                        insertRear(&newDeque, _data);
                        break;
                    }
                }

                break;
            }

            // to perfrom Delete
			case 3:
			{
				int ch;
                printf("Press 1 to Delete Front\n");
                printf("Press 2 to Delete Rear\n");
                printf("Press 2 to Delete entire Deque\n");
                printf("Enter Your Choice: ");
                scanf("%d", &ch);
                switch (ch)
                {
                    case 1:
                    {
                        deleteFront(&newDeque);
                        break;
                    }

                    case 2:
                    {
                        deleteRear(&newDeque);
                        break;
                    }

                    case 3:
                    {
                        erase(&newDeque);
                        break;
                    }

                    default:
                        break;
                }

                break;
            }

            // to print the Queue
			case 4:
			{
				displayDeque(&newDeque);
				break;
			}

            // to get size of the Deque
            case 5:
            {
                printf("The size of the Deque is: %d\n", size(&newDeque));
                break;
            }

            case 6:
            {
				int ch;
                printf("Press 1 to Get Front\n");
                printf("Press 2 to Get Rear\n");
                printf("Enter Your Choice: ");
                scanf("%d", &ch);
                switch (ch)
                {
                    case 1:
                        {
                            printf("The Value of Front is: %d\n",getFront(&newDeque));
                            break;
                        }

                    case 2:
                        {
                            printf("The Value of Front is: %d\n",getRear(&newDeque));
                            break;
                        }

                    default:
                        break;
                }
                break;
            }

            // to breakout
			case 0:
			{
				if (&newDeque != NULL)
					erase(&newDeque);
				return 0;
			}
		}

	goto Menu;
}