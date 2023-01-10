#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;      // X
};

template <class T>
class DoublyLL
{
    public:
        struct node <T> * First;
        struct node <T> * Last;

        DoublyLL();

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
DoublyLL <T> :: DoublyLL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void DoublyLL <T> :: InsertFirst(T value)
{
    struct node <T> * newn = new struct node <T>;

    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
}

template <class T>
void DoublyLL <T> :: InsertLast(T value)
{
    struct node <T> * newn = new struct node <T>;

    newn->data = value;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
}

template <class T>
void DoublyLL <T> :: InsertAtPos(T value, int ipos)
{
    int NodeCnt = 0;
    int iCnt = 0;
    struct node <T> * newn = NULL;
    struct node <T> * temp = NULL;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > (NodeCnt + 1)))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(value);
    }
    else if(ipos == NodeCnt+1)
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

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;    // X
        temp->next = newn;
        newn->prev = temp;      // X
    }
}

template <class T>
void DoublyLL <T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))  // LL is empty
    {
        return;
    }
    else if(First == Last) // LL contains 1 node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // LL contains more than 1 node
    {
        First = First -> next;
        delete (First)->prev;
        First->prev = NULL;
    }
}

template <class T>
void DoublyLL <T> :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))  // LL is empty
    {
        return;
    }
    else if(First == Last) // LL contains 1 node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // LL contains more than 1 node
    {
        Last = Last -> prev;
        delete Last->next;
        Last->next = NULL;
    }
}

template <class T>
void DoublyLL <T> :: DeleteAtPos(int ipos)
{
    struct node <T> * temp = NULL;
    int iCnt = 0;
    int NodeCnt = 0;
    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}

template <class T>
void DoublyLL <T> :: Display()
{
    struct node <T> * temp = First;

    cout<<"Elements of Linked list are : "<<"\n";
    cout<<"NULL<=> ";

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int DoublyLL <T> :: Count()
{
    struct node <T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}


int main()
{
    int iRet = 0;
    
    DoublyLL <int>iobj;

    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);
    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iobj.InsertLast(121);

    iobj.Display();
    iRet = iobj.Count();
    cout<<"Elements of int LL are : "<<iRet<<"\n";

    iobj.InsertAtPos(105,5);

    iobj.Display();
    iRet = iobj.Count();
    cout<<"Elements of int LL are : "<<iRet<<"\n";

    iobj.DeleteAtPos(5);

    iobj.Display();
    iRet = iobj.Count();
    cout<<"Elements of int LL are : "<<iRet<<"\n";

    iobj.DeleteFirst();
    iobj.DeleteLast();

    iobj.Display();
    iRet = iobj.Count();
    cout<<"Elements of int LL are : "<<iRet<<"\n";

    DoublyLL <char>cobj;

    cobj.InsertFirst('c');
    cobj.InsertFirst('b');
    cobj.InsertFirst('a');
    cobj.InsertLast('d');
    cobj.InsertLast('e');
    cobj.InsertLast('f');

    cobj.Display();
    iRet = cobj.Count();
    cout<<"Elements of char LL are : "<<iRet<<"\n";

    cobj.InsertAtPos('x',5);

    cobj.Display();
    iRet = cobj.Count();
    cout<<"Elements of char LL are : "<<iRet<<"\n";

    cobj.DeleteAtPos(5);

    cobj.Display();
    iRet = cobj.Count();
    cout<<"Elements of char LL are : "<<iRet<<"\n";

    cobj.DeleteFirst();
    cobj.DeleteLast();

    cobj.Display();
    iRet = cobj.Count();
    cout<<"Elements of char LL are : "<<iRet<<"\n";

    return 0;
}