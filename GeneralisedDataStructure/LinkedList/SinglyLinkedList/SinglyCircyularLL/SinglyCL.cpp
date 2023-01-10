#include<iostream>
using namespace std;

#pragma pack(1)

template <class T>
struct node
{
    T data;
    struct node * next;
};

template <class T>
class SinglyCLL
{
    public:
        struct node <T> * First;
        struct node <T> * Last;
        // int iCount;

        SinglyCLL();
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
SinglyCLL <T> :: SinglyCLL()
{
    First = NULL;
    Last = NULL;
    // iCount = 0;
}

template <class T>
void SinglyCLL <T> :: InsertFirst(T value)
{
    struct node <T> * newn = new struct node <T>;

    newn->data = value;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
}

template <class T>
void SinglyCLL <T> :: InsertLast(T value)
{
    struct node <T> * newn = new struct node <T>;

    newn->data = value;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))    // Empty LL
    {
        First = Last = newn;
        (Last)->next = First;
    }
    else    // LL contains atleast one node
    {
        (Last)->next = newn;
        Last = newn;
        (Last)->next = First;
    }
}


template <class T>
void SinglyCLL <T> :: InsertAtPos(T value, int iPos)
{
    struct node <T> * newn = NULL;
    struct node <T> * temp = First;
    int iCnt = 0;
    int iNodeCnt = 0;

    iNodeCnt = Count();

    if((iPos < 1) || (iPos > (iNodeCnt+1)))
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
        // struct node <T> * newn = new struct node <T>;
        newn = new struct node <T>;

        newn->data = value;
        newn->next = NULL;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void SinglyCLL <T> :: DeleteFirst()
{
    struct node <T> * temp = First;

    if((First == NULL) && (Last == NULL))     // Empty LL
    {
        return;
    }
    else if(First == Last)        // Single Node in LL
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        // If LL contains more than one node
    {
        First = (First)->next;
        delete temp;
        (Last)->next = First;
    }
}

template <class T>
void SinglyCLL <T> :: DeleteLast()
{
    struct node <T> * temp = First;

    if((First == NULL) && (Last == NULL))     // Empty LL
    {
        return;
    }
    else if(First == Last)        // Single Node in LL
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else        // If LL contains more than one node
    {
        while(temp->next != (Last))
        {
            temp = temp -> next;
        }
        delete temp->next;

        Last = temp;
        (Last) -> next = First;
    }
}

template <class T>
void SinglyCLL <T> :: DeleteAtPos(int iPos)
{
    int iNodeCnt = 0;
    int iCnt = 0;
    struct node <T> * temp1 = First;
    struct node <T> * temp2 = NULL;
    
    iNodeCnt = Count();

    if((iPos < 1) || (iPos > (iNodeCnt)))
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
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1-> next;

        temp1->next = temp2->next;
        delete temp2;
    }
}

template <class T>
void SinglyCLL <T> :: Display()
{
    struct node <T> * temp = First;

    cout<<"Elements of Linked list are : "<<"\n";

    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    } while (temp != Last->next);
    cout<<"\n";
}

template <class T>
int SinglyCLL <T> :: Count()
{
    struct node <T> * temp = First;
    int iCnt = 0;
    do
    {
        iCnt++;
        temp = temp->next;
    } while (temp != Last->next);
    return iCnt;
}


int main()
{
    int iRet = 0;

    ////////////////////////////////////////////////////////////////
    SinglyCLL <int>obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);
    obj1.InsertAtPos(105,5);
    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of nodes in integer linked list are : "<<iRet<<"\n";

    obj1.DeleteAtPos(5);
    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    iRet = obj1.Count();
    cout<<"Number of nodes in integer linked list are : "<<iRet<<"\n";
    
    ////////////////////////////////////////////////////////////////
    SinglyCLL <double>obj2;

    obj2.InsertFirst(51.25);
    obj2.InsertFirst(21.75);
    obj2.InsertFirst(11.99);
    obj2.InsertLast(101.987);
    obj2.InsertLast(111.154);
    obj2.InsertLast(121.5245);
    obj2.InsertAtPos(105.965,5);
    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes in double linked list are : "<<iRet<<"\n";

    obj2.DeleteAtPos(5);
    obj2.DeleteFirst();
    obj2.DeleteLast();

    obj2.Display();
    iRet = obj2.Count();
    cout<<"Number of nodes in double linked list are : "<<iRet<<"\n";
    
    ////////////////////////////////////////////////////////////////
    SinglyCLL <char>obj3;

    obj3.InsertFirst('c');
    obj3.InsertFirst('b');
    obj3.InsertFirst('a');
    obj3.InsertLast('d');
    obj3.InsertLast('e');
    obj3.InsertLast('f');
    obj3.InsertAtPos('l',5);
    obj3.Display();
    iRet = obj3.Count();
    cout<<"Number of nodes in character linked list are : "<<iRet<<"\n";

    obj3.DeleteAtPos(5);
    obj3.DeleteFirst();
    obj3.DeleteLast();

    obj3.Display();
    iRet = obj3.Count();
    cout<<"Number of nodes in character linked list are : "<<iRet<<"\n";

    ////////////////////////////////////////////////////////////////
    SinglyCLL <float>obj4;

    obj4.InsertFirst(51.25f);
    obj4.InsertFirst(21.75f);
    obj4.InsertFirst(11.99f);
    obj4.InsertLast(101.987f);
    obj4.InsertLast(111.154f);
    obj4.InsertLast(121.5245f);
    obj4.InsertAtPos(105.965f,5);
    obj4.Display();
    iRet = obj4.Count();
    cout<<"Number of nodes in float linked list are : "<<iRet<<"\n";

    obj4.DeleteAtPos(5);
    obj4.DeleteFirst();
    obj4.DeleteLast();

    obj4.Display();
    iRet = obj4.Count();
    cout<<"Number of nodes in float linked list are : "<<iRet<<"\n";
    
    ////////////////////////////////////////////////////////////////
    return 0;
}
