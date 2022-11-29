#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

// Structre Defination
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};


typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

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
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
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
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    temp = *First;
    
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
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
    printf("Elements of Linked List are :\n");

    while (First != NULL)
    {
        printf("NULL<=> |%d|<=> ",First->data);
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
    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        *First = (*First)->next;
        free((*First)->prev);
        (*First)->prev = NULL;
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
    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
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
        newn->prev = NULL;

        temp = *First;
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
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
        temp2->next->prev = temp1;
        free(temp2);
    }
}