#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

/*      
    +-----------------+--------------+
    |   Old Name      |  New Name    |
    |-----------------|--------------|
    | struct node     |   NODE       |
    | struct node *   |   PNODE      |
    | struct node **  |   PPNODE     |
    +-----------------+--------------+
*/

///////////////////////////////////////////////////////////////////
//
// Function name : InsertFirst
// Description: Used to insert node at first position of Linked List
// Parameters: Address of First pointer & data of node
// Return Value: void
//
///////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE)); // Step 1 : Allocate memory

    newn->data = no;
    newn->next = NULL;

    if (*First == NULL) // If linked list is empty
    {
        *First = newn;
    }
    else // if linked list contains at least one node
    {
        newn->next = *First;
        *First = newn;
    }
}

///////////////////////////////////////////////////////////////////
//
// Function name : InsertLast
// Description: Used to insert node at last position of Linked List
// Parameters: Address of First pointer & data of node
// Return Value: void
//
///////////////////////////////////////////////////////////////////
void InsertLast(PPNODE First, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE)); // Step 1 : Allocate memory
    PNODE temp = *First;

    newn->data = no;
    newn->next = NULL;

    if (*First == NULL) // If linked list is empty
    {
        *First = newn;
    }
    else // if linked list contains at least one node
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////////////
//
// Function name : Display
// Description: Used to display elements of Linked List
// Parameters: First pointer
// Return Value: void
//
///////////////////////////////////////////////////////////////////
void Display(PNODE First)
{
    printf("Elements fron linked list are :\n");
    
    while (First != NULL)
    {
        printf("| %d | -> ", First->data);
        First = First->next;
    }
    printf("NULL\n");
}

///////////////////////////////////////////////////////////////////
//
// Function name : Count
// Description: Used to count elements of Linked List
// Parameters: First pointer
// Return Value: Integer
//
///////////////////////////////////////////////////////////////////
int Count(PNODE First)
{
    int iCnt = 0;

    while (First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}

///////////////////////////////////////////////////////////////////
//
// Function name : DeleteFirst
// Description: Used to delete node at first position of Linked List
// Parameters: Address of First pointer
// Return Value: void
//
///////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE First)
{
    PNODE temp = *First;

    if(*First == NULL)      // Empty Linked List
    {
        return;
    }
    else if((*First) -> next == NULL)   // Only 1 node in Linked List
    {
        free(*First);
        *First = NULL;
    }
    else    // More than 1 node in Linked List
    {
        (*First) = (*First) -> next;
        free(temp);
    }
}

///////////////////////////////////////////////////////////////////
//
// Function name : DeleteLast
// Description: Used to delete node at last position of Linked List
// Parameters: Address of First pointer
// Return Value: void
//
///////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE First)
{
    PNODE temp = *First;
    
    if(*First == NULL)      // Empty Linked List
    {
        return;
    }
    else if((*First) -> next == NULL)   // Only 1 node in Linked List
    {
        free(*First);
        *First = NULL;
    }
    else    // More than 1 node in Linked List
    {
        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

///////////////////////////////////////////////////////////////////////////
//
// Function name : InsertAtPos
// Description: Used to insert node at given position of Linked List
// Parameters: Address of First pointer, data of node, position to insert
// Return Value: void
//
///////////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE First, int no, int iPos)
{
    int NodeCnt = 0;
    int iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = Count(*First);

    if((iPos < 1) || (iPos > (NodeCnt + 1)))
    {
        printf("Invalid Poistion\n");
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(First,no);
    }
    else if(iPos == NodeCnt+1)
    {
        InsertLast(First,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *First;
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////
//
// Function name : DeleteAtPos
// Description: Used to delete node at given position of Linked List
// Parameters: Address of First pointer, position to element to delete
// Return Value: void
//
///////////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE First, int iPos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;
    int iCnt = 0;
    int NodeCnt = 0;

    NodeCnt = Count(*First);

    if((iPos < 1) || (iPos > NodeCnt))
    {
        printf("Invalid Position\n");
    }

    if(iPos == 1)
    {
        DeleteFirst(First);
    }
    else if(iPos == NodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;
        
        temp1->next = temp2->next;
        free(temp2);
    }
}


