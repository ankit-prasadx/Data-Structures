#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First, int No)
{
    // Step 1 : Allocate the memory for new node
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    // Step 2 : Initialize the Value
    newn->data = No;
    newn->next = NULL;

    // Step 3 : Cheack Linked list is empty or not
    if(*First == NULL)
    {
        *First = newn;
    }
    else    // If Linked list contains at least one node
    {
        newn->next = *First;
        *First = newn;
    }

}

void Dispaly(PNODE First)
{
    printf("Elements of Linked List are : \n");
    while (First != NULL)
    {
        printf("| %d | -> ",First->data);
        First = First->next;
    }
    printf("NULL\n");
}

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

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head, 51);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 11);

    Dispaly(Head);
    iRet = Count(Head);

    printf("Number of elements are : %d\n",iRet);

    return 0;
}