#include <stdio.h>
#include <stdlib.h>


/* Sudo Overload for free function [sets the pointer to NULL] */
void Free(void* _ptr)
{
    free(_ptr);
    _ptr = NULL;
}

struct DoublyLinkedList
{
    struct DoublyLinkedList *m_prevPointer;
    int m_data;
    struct DoublyLinkedList *m_nxtPointer;
};

typedef struct DoublyLinkedList DoublyLinkedList;
typedef DoublyLinkedList* PointerType;
typedef DoublyLinkedList** ReferenceType;
typedef int ValueType;

PointerType Head = NULL;

/* Creates A New Node */
PointerType create(ValueType newData)
{
    PointerType newNode = (PointerType)calloc(1, sizeof(DoublyLinkedList));
    newNode->m_prevPointer = NULL;
    newNode->m_data = newData;
    newNode->m_nxtPointer = NULL; //? Set To Null For less bugs
    Head = newNode;

    printf("New List Created \n");

    return newNode;
}

/* Length Function (RECURSSIVE) */
int Length(PointerType headRef)
{
    if (headRef == NULL)
        return 0;

    return 1 + Length(headRef->m_nxtPointer);
}

/* print Function */
void print(ReferenceType headRef)
{
    PointerType temp = *headRef;
    while (temp != NULL)
    {
        printf("Element: %d \n", temp->m_data);
        temp = temp->m_nxtPointer;
    }
}

/* Push Back Function */
void push_back(ReferenceType headRef, ValueType newData)
{
    PointerType temp = *headRef;
    PointerType newNode = (PointerType)malloc(sizeof(DoublyLinkedList));

    newNode->m_nxtPointer = NULL;
    newNode->m_data = newData;

    if (temp == NULL)
    {
        *headRef = newNode;
        return;
    }

    while (temp->m_nxtPointer != NULL)
        temp = temp->m_nxtPointer;

    temp->m_nxtPointer = newNode;
    newNode->m_prevPointer = temp;
}


/* Push Front Function */
void push_front(ReferenceType headRef, ValueType newData)
{
    PointerType temp = *headRef;
    PointerType newNode = (PointerType)malloc(sizeof(DoublyLinkedList));

    newNode->m_prevPointer = NULL;
    newNode->m_data = newData;

    if (temp == NULL)
    {
        newNode->m_nxtPointer = NULL;
        *headRef = newNode;
        return;
    }

    if (temp->m_prevPointer != NULL)
    {
        while (temp->m_prevPointer != NULL)
            temp = temp->m_prevPointer;
    }
    newNode->m_nxtPointer = temp;
    temp->m_prevPointer = newNode;
    *headRef = newNode;

    return;
}

/* Insert After Key */
void insertAfterKey(ReferenceType headRef, ValueType _key, ValueType _data)
{
    PointerType temp = *headRef;

    if (temp == NULL)
	{
		printf("the given previous node cannot be NULL \n");
		printf("initialize a new node \n");
		printf("Linked List Empty\n");
		return;
	}

    while (temp->m_data != _key)
        temp = temp->m_nxtPointer;

    PointerType newNode = (PointerType)malloc(sizeof(DoublyLinkedList));
    newNode->m_data = _data;

    newNode->m_nxtPointer = temp->m_nxtPointer;
    if (temp->m_nxtPointer != NULL)
    {
        temp->m_nxtPointer->m_prevPointer = newNode;
    }

    newNode->m_prevPointer = temp;
    temp->m_nxtPointer = newNode;

    return;
}

/* Insert After Function */
void insertAfter(PointerType _pointer, ValueType _data)
{
    if (_pointer == NULL)
	{
		printf("the given previous node cannot be NULL \n");
		printf("initialize a new node \n");
		return;
	}

    PointerType newNode = (PointerType)malloc(sizeof(DoublyLinkedList));
    newNode->m_data = _data;
    newNode->m_prevPointer = _pointer;
    newNode->m_nxtPointer = _pointer->m_nxtPointer;
    _pointer->m_nxtPointer->m_prevPointer = newNode;
    _pointer->m_nxtPointer = newNode;

    return;
}

/* To Delete a node based on data */
void delete(ReferenceType headRef, int key)
{
    PointerType temp = *headRef;
    PointerType prev;

    if (temp != NULL && temp->m_data == key)
    {
        *headRef = temp->m_nxtPointer;
        temp->m_prevPointer = NULL;
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
    temp->m_nxtPointer->m_prevPointer = prev;
    Free(temp);
    printf("Node Was deleted sussessfully \n");
	return;
}

/* To Delete a node at a specific position */
void delete_at_pos(ReferenceType headRef, int _pos)
{
    if (*headRef == NULL)
	{
		printf("List Empty \n");
		return;
	}

    PointerType temp = *headRef;

    if (_pos == 0)
    {
        *headRef = temp->m_nxtPointer;
        temp->m_nxtPointer->m_prevPointer = NULL;
        Free(temp);
        printf("Node was deleted Successfully \n");
        return;
    }

	for (int i = 0; temp != NULL && i < _pos - 1 ; i++)
		temp = temp->m_nxtPointer;

	if (temp == NULL || temp->m_nxtPointer == NULL)
	{
		printf("Position is greater than the number of nodes \n \n");
		return;
	}

    PointerType tempNext = temp->m_nxtPointer->m_nxtPointer;

    Free(temp->m_nxtPointer);
    temp->m_nxtPointer = tempNext;
    printf("Node was deleted Successfully \n");
    return;
}

/* To delete an entire list */
void deleteList(ReferenceType headRef)
{
    PointerType _current = *headRef;
    PointerType _next = NULL;

    while (_current != NULL)
    {
        _next = _current->m_nxtPointer;
        Free(_current);
        _current = _next;
    }

    *headRef = NULL;
	printf("List Was Deleted Successfully \n");
    return;
}

int main()
{
    int choice, subChoice;

Menu:
	printf("**----MENU----** \n");
	printf("Enter 1 for Creating A New LinkedList \n");
    printf("Enter 2 to Push an Element \n"); //* sub menu
	printf("Enter 3 for printing the LinkedList \n");
	printf("Enter 4 for Deletion \n"); //* sub menu
    printf("Press 5 to find the length of the LinkedList \n"); //* sub menu
	printf("Press 0 to exit \n");
	printf("Enter Your Choice: ");
	scanf("%d", &choice);

    switch (choice)
    {
        case 1:
        {
            ValueType _data;
            printf("Enter data: ");
            scanf("%d", &_data);
            Head = create(_data);
            break;
        }

        case 2:
        {
            ValueType _data;
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
            break;
        }

        case 3:
        {
            print(&Head);
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
            printf("Length of the List: %d \n", Length(Head));
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


	/* Free Function has been sudo-overloded to set the freeed up pointer to point to null */
}