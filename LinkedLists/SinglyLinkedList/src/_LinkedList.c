#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Linkedlist
{
	struct Linkedlist* m_nxtPointer;
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

Linkedlist* Head = NULL;
Linkedlist* Head2 = NULL;
Linkedlist* Tail1 = NULL;

/* Length Function (ITERATIVE) */
int length(Linkedlist* headRef)
{
	Linkedlist* temp = headRef;
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

/* To print */
void print(Linkedlist* __list)
{
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
void merge(Linkedlist* headRef1, Linkedlist* headRef2)
{
	Linkedlist* temp = headRef1;

	while (headRef1 != NULL && headRef2 != NULL)
	{
		headRef1 = headRef1->m_nxtPointer;
	}
	headRef1->m_nxtPointer = headRef2;
	printf("Lists Merged \n");
	headRef1 = temp;
	Head2 = NULL;
	print(headRef1);
	return;
}

/* To Append */
void push_back(Linkedlist** headRef, int newData)
{
	//* Heap Allocated
	Linkedlist* newNode = (Linkedlist*)malloc(sizeof(Linkedlist));

	Linkedlist* prev = *headRef;

	newNode->m_data = newData;
	if (*headRef == NULL)
	{
		*headRef = newNode;
		return;
	}
	while (prev->m_nxtPointer != NULL)
		prev = prev->m_nxtPointer;

	prev->m_nxtPointer = newNode;
	Tail1 = newNode;
	return;
}

/* To insert after (By KeyItem) */
void insertAfterKey(Linkedlist** headRef, int keyData, int newData)
{
	Linkedlist* temp = *headRef;

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

	Linkedlist* newNode = (Linkedlist*)malloc(sizeof(Linkedlist));

	newNode->m_data = newData;
	if (temp->m_nxtPointer == NULL)
		Tail1 = newNode;

	newNode->m_nxtPointer = temp->m_nxtPointer;

	temp->m_nxtPointer = newNode;

	return;
}

/* To Insert After (By Pointer) */
void insertAfter(Linkedlist* prevNode, int newData)
{
	if (prevNode == NULL)
	{
		printf("the given previous node cannot be NULL \n");
		printf("initialize a new node \n");
		return;
	}

	Linkedlist* newNode = (Linkedlist*)malloc(sizeof(Linkedlist));

	newNode->m_data = newData;

	newNode->m_nxtPointer = prevNode->m_nxtPointer;

	prevNode->m_nxtPointer = newNode;

	return;
}

/* To Push a New Elem in front */
void push_front(Linkedlist** headRef, int newData)
{
	Linkedlist* newNode = (Linkedlist*)malloc(sizeof(Linkedlist));

	newNode->m_data = newData;

	newNode->m_nxtPointer = (*headRef);

	(*headRef) = newNode;

	return;
}

/* To Delete a node based on data*/
void delete(Linkedlist** headRef, int key)
{
	Linkedlist* temp = *headRef;
	Linkedlist* prev;

	if (temp != NULL && temp->m_data == key)
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

	if (temp == NULL)
		return;

	prev->m_nxtPointer = temp->m_nxtPointer;
	Free(temp);
	printf("Node Was deleted sussessfully \n");
	return;
}

/* To Delete a node at a specific position */
void delete_at_pos(Linkedlist** headRef, int _pos)
{
	if (*headRef == NULL)
	{
		printf("List Empty");
		return;
	}

	Linkedlist* temp = *headRef;  //Temporary

	if (_pos == 0)
	{
		*headRef = temp->m_nxtPointer;
		Free(temp);
		printf("Node was deleted Successfully \n"); //Free Up old head
		Head = *headRef; //! to be tested
		return;
	}

	for (int i = 0; temp != NULL && i < _pos - 1; i++)
		temp = temp->m_nxtPointer;

	if (temp == NULL || temp->m_nxtPointer == NULL)
	{
		printf("Position is greater than the number of nodes \n \n");
		return;
	}

	Linkedlist* m_nxtPointerFromDel = temp->m_nxtPointer->m_nxtPointer;
	Free(temp->m_nxtPointer);// Free's the memory
	temp->m_nxtPointer = m_nxtPointerFromDel; // Unlinks here
}

/* To delete an entire list */
void deleteList(Linkedlist** headRef)
{
	Linkedlist* _current = *headRef;
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
	Tail1 = NULL;
}

/* To Create A new Head node */
Linkedlist* Create(int data)
{
	Linkedlist* headNode = (Linkedlist*)calloc(1, sizeof(Linkedlist));
	if (Head != NULL)
	{
		printf("Error a List is already initialized \n");
		printf(" LIST NEEDS TO BE DELETED! \n");
		print(Head);
		deleteList(&Head);
	}

	else
	{
		Head = headNode;
		Tail1 = headNode;
		headNode->m_data = data;
	}
	printf("New List Created \n");
	return headNode;
}

/* Reversing a Linked List */
void reverse(Linkedlist** headRef)
{
	Linkedlist* current = *headRef;
	Linkedlist* prev = NULL, * m_nxtPointer = NULL;

	while (current != NULL) {
		m_nxtPointer = current->m_nxtPointer;

		current->m_nxtPointer = prev;

		prev = current;
		current = m_nxtPointer;
	}
	*headRef = prev;
}

/* function to swap data of two nodes a and b*/
void swap(Linkedlist* a, Linkedlist* b)
{
	int temp = a->m_data;
	a->m_data = b->m_data;
	b->m_data = temp;
}

/* Bubble sort the given linked list */
void sort(Linkedlist* headRef)
{
	bool swapped = false;
	Linkedlist* temp;
	Linkedlist* prev = NULL;

	/* Checking for empty list */
	if (headRef == NULL)
		return;

	do
	{
		swapped = false;
		temp = headRef;

		while (temp->m_nxtPointer != prev)
		{
			if (temp->m_data > temp->m_nxtPointer->m_data)
			{
				swap(temp, temp->m_nxtPointer);
				swapped = true;
			}
			temp = temp->m_nxtPointer;
		}
		prev = temp;
	} while (swapped);
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
	printf("Press 5 for Sorting the LinkedList \n");
	printf("Press 6 for Reversing the LinkedList \n");
	printf("Press 7 to find the length of the LinkedList \n"); //* sub menu
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
		Head = Create(_data);
		break;
	}

	case 2:
	{
		int _data;
		printf("Enter Data: ");
		scanf("%d", &_data);
		printf("Press 1 for Pushing Back an Element \n");
		printf("Press 2 for Pushing to the front of the List \n");
		printf("Press 3 to insert after a cirten node (recuires a pointer to previous node) \n");
		printf("Enter Your Choice: ");
		scanf("%d", &subChoice);
		switch (subChoice)
		{
		case 1:
		{
			push_back(&Tail1, _data);
			break;
		}

		case 2:
		{
			push_front(&Head, _data);
			break;
		}

		case 3:
		{
			int chk;
			printf("Press 1 for key based insertion \n");
			printf("Press 2 for pointer based insertion \n");
			printf("Enter Your Choice: ");
			scanf("%d", &chk);
			switch (chk)
			{
			case 1:
			{
				int _key;
				printf("Enter The data after which you want to insert: ");
				scanf("%d", &_key);
				insertAfterKey(&Head, _key, _data);
				break;
			}

			case 2:
			{
				printf("Reqires a pointer to the previous node \n");
				printf("Used \"Head Node\" beacause i did not save any pointer seperately \n");
				insertAfter(Head, _data);
				break;
			}
			}
			break;
		}
		}
	}

	case 3:
	{
		print(Head);
		break;
	}

	case 4:
	{
		int chk;
		printf("Press 1 to delete a node at a specific position \n");
		printf("Press 2 to delete a node with a key value \n");
		printf("Press 3 to delete the entire list \n");
		printf("Enter your Choice: ");
		scanf("%d", &chk);
		switch (chk)
		{
		case 1:
		{
			int _pos;
			printf("Enter The Position: ");
			scanf("%d", &_pos);
			delete_at_pos(&Head, _pos);
			break;
		}

		case 2:
		{
			int _key;
			printf("Enter Key Value: ");
			scanf("%d", &_key);
			delete(&Head, _key);
			break;
		}

		case 3:
		{
			deleteList(&Head);
			break;
		}
		}
		break;
	}

	case 5:
	{
		// Bubble Sort Used due to complexity issues
		sort(Head);
		break;
	}

	case 6:
	{
		reverse(&Head);
		break;
	}

	case 7:
	{
		printf("Length of the List: %d (found iteratively) \n", length(Head));
		printf("Length of the List: %d (found recursively) \n", Length(Head));
		printf("Not Exactly sure of which one was more efficient so did both \n");
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

	/* Merge implementaiton in a menu based is not present */
	/* Free Function has been sudo-overloded to set the freeed up pointer to point to null */
	/* Check Line 12 */
	/* There is a bug that prints the list after pushing an elem (might be a VScode WSL Bug not sure) */
}