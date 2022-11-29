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
    // Logic
}

void Dispaly(PNODE First)
{
    // Logic
}

int main()
{
    PNODE Head = NULL;

    InsertFirst(&Head, 51);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 11);

    Dispaly(Head);

    return 0;
}

/*
    void InsertFirst(PPNODE First, int No);
    void InsertLast(PPNODE First, int No);
    void InsertAtPos(PPNODE First, int No, int Pos);
    
    void DeleteFirst(PPNODE First);
    void DeleteLast(PPNODE First);
    void DeleteAtPos(PPNODE First, int Pos);

    void Display(PNODE First);
    int Count(PNODE First);

*/
///////////////////////////////////////////////////
/*
    InsertFirst(&Head, 11);
    InsertLast(&Head, 11);
    InsertAtPos(&Head, 11, 5);
    
    DeleteFirst(&Head);
    DeleteLast(&Head);
    DeleteAtPos(&Head, 5);
    
    Display(Head);
    Count(Head);

*/

/*
    Topics To read from C programming for Data Structures

    Premitive data types
    Size of all data types
    Loops(while & for)
    Dynamic memory (malloc & calloc)
    Pointer and its types
    Pointer to  Pointer
    Call by value and Call by Address
    Structure declaration
    Self Referential Pointer
    Memory allocation of Structure
    Direct and indirect accessing of Structure
    typedef and its uses
*/