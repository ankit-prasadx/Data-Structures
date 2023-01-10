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
class SinglyLL
{
    public:
        // Characteristics
        struct node <T> * First;
        int iCount;

        // Behaviours
        SinglyLL();

        void InsertFirst(T value);
        void InsertLast(T value);
        void InsertAtPos(T value,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
};

template <class T>
SinglyLL <T> :: SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL <T> :: InsertFirst(T value)
{
    // Step 1: Allocate the memory for node
    struct node <T> * newn = new struct node <T>;

    // Step 2: Initialize node
    newn->data = value;
    newn->next = NULL;

    // Step 3: Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    // If LL is contains at least one node
    {
        newn->next = First;
        First = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL <T> :: InsertLast(T value)
{
    // Step 1: Allocate the memory for node
    struct node <T> * newn = new struct node <T>;

    // Step 2: Initialize node
    newn->data = value;
    newn->next = NULL;

    // Step 3: Check if LL is empty or not
    if(First == NULL)   // if(iCount == 0)
    {
        First = newn;
        iCount++;
    }
    else    // If LL is contains at least one node
    {
        struct node <T> * temp = First;
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL <T> :: InsertAtPos(T value, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position";
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(value);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(value);
    }
    else
    {
        struct node <T> * newn = new struct node <T>;
        
        newn->data = value;
        newn->next = NULL;

        struct node <T> * temp = First;
        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL <T> :: DeleteFirst()  // if(iCount == 0)
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)    // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct node <T> * temp = First;
        First = First->next;
        delete temp;
        iCount--;
    }
}

template <class T>
void SinglyLL <T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)    // else if(iCount == 1)
    {
        delete First;
        First = NULL;
        iCount--;
    }
    else
    {
        struct node <T> * temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = NULL;
        iCount--;
    }
}

template <class T>
void SinglyLL <T> :: DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position";
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        struct node <T> * temp1 = First;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        struct node <T> * temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

template <class T>
void SinglyLL <T> :: Display()
{
    cout<<"Elements of LL are :"<<"\n";
    struct node <T> * temp = First;

    while (temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}


int main()
{
    ////////////////////////////////////////////////////////////////
    SinglyLL <int>obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);
    obj1.InsertAtPos(105,5);
    obj1.Display();
    cout<<"Number of nodes in integer linked list are : "<<obj1.iCount<<"\n";

    obj1.DeleteAtPos(5);
    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    cout<<"Number of nodes in integer linked list are : "<<obj1.iCount<<"\n";
    
    ////////////////////////////////////////////////////////////////
    SinglyLL <double>obj2;

    obj2.InsertFirst(51.25);
    obj2.InsertFirst(21.75);
    obj2.InsertFirst(11.99);
    obj2.InsertLast(101.987);
    obj2.InsertLast(111.154);
    obj2.InsertLast(121.5245);
    obj2.InsertAtPos(105.965,5);
    obj2.Display();
    cout<<"Number of nodes in double linked list are : "<<obj2.iCount<<"\n";

    obj2.DeleteAtPos(5);
    obj2.DeleteFirst();
    obj2.DeleteLast();

    obj2.Display();
    cout<<"Number of nodes in double linked list are : "<<obj2.iCount<<"\n";
    
    ////////////////////////////////////////////////////////////////
    SinglyLL <char>obj3;

    obj3.InsertFirst('c');
    obj3.InsertFirst('b');
    obj3.InsertFirst('a');
    obj3.InsertLast('d');
    obj3.InsertLast('e');
    obj3.InsertLast('f');
    obj3.InsertAtPos('l',5);
    obj3.Display();
    cout<<"Number of nodes in character linked list are : "<<obj3.iCount<<"\n";

    obj3.DeleteAtPos(5);
    obj3.DeleteFirst();
    obj3.DeleteLast();

    obj3.Display();
    cout<<"Number of nodes in character linked list are : "<<obj3.iCount<<"\n";

    ////////////////////////////////////////////////////////////////
    SinglyLL <float>obj4;

    obj4.InsertFirst(51.25f);
    obj4.InsertFirst(21.75f);
    obj4.InsertFirst(11.99f);
    obj4.InsertLast(101.987f);
    obj4.InsertLast(111.154f);
    obj4.InsertLast(121.5245f);
    obj4.InsertAtPos(105.965f,5);
    obj4.Display();
    cout<<"Number of nodes in float linked list are : "<<obj4.iCount<<"\n";

    obj4.DeleteAtPos(5);
    obj4.DeleteFirst();
    obj4.DeleteLast();

    obj4.Display();
    cout<<"Number of nodes in float linked list are : "<<obj4.iCount<<"\n";
    
    ////////////////////////////////////////////////////////////////
    return 0;
}
