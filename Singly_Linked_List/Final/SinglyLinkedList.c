#include "SinglyLL.h"

int main()
{
    // struct node * Head = NULL;
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head, 51);
    InsertFirst(&Head, 21);
    InsertFirst(&Head, 11);
    Display(Head);

    iRet = Count(Head);
    printf("Number of nodes are : %d\n", iRet);

    InsertLast(&Head, 101);
    InsertLast(&Head, 111);
    InsertLast(&Head, 121);

    Display(Head);

    iRet = Count(Head);
    printf("Number of nodes are : %d\n", iRet);
    
    InsertAtPos(&Head,105,5);
    Display(Head);

    iRet = Count(Head);
    printf("Number of nodes are : %d\n", iRet);
    
    DeleteAtPos(&Head,5);
    Display(Head);

    iRet = Count(Head);
    printf("Number of nodes are : %d\n", iRet);

    DeleteFirst(&Head);
    DeleteLast(&Head);
    Display(Head);
    
    iRet = Count(Head);
    printf("Number of nodes are : %d\n", iRet);


    return 0;
}