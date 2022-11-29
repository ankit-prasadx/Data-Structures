#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node * next;
    struct node * prev;     // X
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


int main()
{

    return 0;
}
