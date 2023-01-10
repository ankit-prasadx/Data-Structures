#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
struct node
{
    T data;
    struct node * next;
    struct node * prev;
};

template <class T>
class DoublyCLL
{
    public:
        struct node <T> * First;
        struct node <T> * Last;

        DoublyCLL();
        
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
DoublyCLL <T> :: DoublyCLL()    // Default Constructor
{
    First = NULL;
    Last = NULL;
}

template <class T>
void DoublyCLL <T> :: InsertFirst(T value)
{
    struct node <T> * newn = new struct node <T>;
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))     // LL is Empty
    {
        First = newn;
        Last = newn;
    }
    else        // If LL contains one or more nodes
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    First->prev = Last;
    Last->next = First;
}

template <class T>
void DoublyCLL <T> :: InsertLast(T value)
{
    struct node <T> * newn = new struct node <T>;
    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))     // LL is Empty
    {
        First = newn;
        Last = newn;
    }
    else        // If LL contains one or more nodes
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    First->prev = Last;
    Last->next = First;
}

template <class T>
void DoublyCLL <T> :: Display()
{
    struct node <T> * temp = First;
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked List is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    do
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }while(temp != Last->next);

    cout<<"\n";
}

template <class T>
int DoublyCLL <T> :: Count()
{
    int iCnt= 0;
    struct node <T> * temp = First;
    if((First == NULL) && (Last == NULL))
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp != Last->next);

    return iCnt;
}

template <class T>
void DoublyCLL <T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))     // Empty LL
    {
        return;
    }
    else if(First == Last)        // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        // More than one node
    {
        First = First->next;
        // delete First->prev);
        delete Last->next;

        First->prev = Last;
        Last->next = First;
    }
}

template <class T>
void DoublyCLL <T> :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))     // Empty LL
    {
        return;
    }
    else if(First == Last)        // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        // More than one node
    {
        Last = Last->prev;
        // delete Last->next;
        delete First->prev;

        First->prev = Last;
        Last->next = First;
    }
}

template <class T>
void DoublyCLL <T> :: InsertAtPos(T value, int iPos)
{
    int iNodeCnt = 0;
    int iCnt = 0;
    struct node <T> * newn = NULL;
    struct node <T> * temp = NULL;
    iNodeCnt = Count();


    if((iPos < 1) || (iPos > iNodeCnt+1))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(value);
    }
    else if(iPos == iNodeCnt+1)
    {
        InsertLast(value);
    }
    else
    {
        newn = new struct node <T>;
        newn->data = value;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
}

template <class T>
void DoublyCLL <T> :: DeleteAtPos(int iPos)
{
    int iNodeCnt = 0;
    int iCnt = 0;
    struct node <T> * temp = NULL;
    iNodeCnt = Count();


    if((iPos < 1) || (iPos > iNodeCnt))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {

        temp = First;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

int main()
{
    int iRet = 0;
    
    DoublyCLL <int>obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout<<"Elements of LL are : "<<iRet<<"\n";

    obj.InsertAtPos(105,5);

    obj.Display();
    iRet = obj.Count();
    cout<<"Elements of LL are : "<<iRet<<"\n";

    obj.DeleteAtPos(5);

    obj.Display();
    iRet = obj.Count();
    cout<<"Elements of LL are : "<<iRet<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout<<"Elements of LL are : "<<iRet<<"\n";

    return 0;
}