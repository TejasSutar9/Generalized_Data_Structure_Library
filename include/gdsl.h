////////////////////////////////////////////////////////////////////////////
//          Generalized Data Structure Library
////////////////////////////////////////////////////////////////////////////

/*
----------------------------------------------------------------------------------------------------
Type                    Name of Class for node                  Name of class for functionality
----------------------------------------------------------------------------------------------------

Singly Linear           SinglyLLLnode                           SinglyLLL           Done
Singly Circular         SinglyCLLnode                           SinglyCLL           Done
Doubly Linear           DoublyLLLnode                           DoublyLLL           Done
Doubly Circular         SinglyCLLnode                           DoublyCLL           Done
Stack                   Stacknode                               Stack               Done
Queue                   Queuenode                               Queue               Done
----------------------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////
//          Singly Linear Linked List using Generic Approach
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        } 
};

template <class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

template <class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"\n\nSingly Linear Linked List gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst
//  Input :             Data of node
//  Output :            Nothing
//  Description :       Used to insert node at first position
//  Author :            Tejas Pradip Sutar
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertFirst(T no)    
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast
//  Input         :     Data of node
//  Output        :     None
//  Description   :     Inserts new node at last position of linked list
//  Author :            Tejas Pradip Sutar
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)     // Updated
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst
//  Input         :     None
//  Output        :     None
//  Description   :     Deletes first node from linked list
//  Author :            Tejas Pradip Sutar
//  Date :              06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    // else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast
//  Input         :     None
//  Output        :     None
//  Description   :     Deletes last node from linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    // else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input         :     None
//  Output        :     Displays linked list elements
//  Description   :     Prints all elements of linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)   
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input         :     None
//  Output        :     Integer (number of nodes)
//  Description   :     Returns total number of nodes in linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyLLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos
//  Input         :     Data of node, Position
//  Output        :     None
//  Description   :     Inserts node at specified position
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos
//  Input         :     Position
//  Output        :     None
//  Description   :     Deletes node from specified position
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyLLL<T> :: DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////
//          Doubly Linear Linked List using Generic Approach
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(int no)
        {
           this->data = no;
           this->next = NULL;
           this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyLLL       
//  Input         :     None
//  Output        :     None
//  Description   :     Constructor to initialise Doubly Linear Linked List
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"\n\nDoubly Linear Linked List gets created.\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at beginning of doubly linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////
    
template <class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);
    
    if(this->first == NULL)
    {
        this->first = newn;
    }

    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;    
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at end of doubly linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);
    
    if(this->first == NULL)
    {
        this->first = newn;
    }

    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos       
//  Input         :     Data of node, Position
//  Output        :     Nothing
//  Description   :     Inserts node at given position in doubly linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    int iCnt = 0;

    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    if((pos < 1) && (pos > this->iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }

    else if(pos == iCount + 1)
    {
        this->InsertLast(no);
    }

    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;
        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes first node of doubly linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                     // LL is Empty
    {
        return;
    }

    else if(this->first->next == NULL)          // LL contains 1 node
    {
        delete(this->first);
        this->first = NULL;
    }

    else                                        // LL contains more than 1 node
    {
        this->first = this->first->next;

        delete(this->first->prev);
        this->first->prev = NULL;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes last node of doubly linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                     // LL is Empty
    {
        return;
    }

    else if(this->first->next == NULL)          // LL contains 1 node
    {
        delete(this->first);
        this->first = NULL;
    }

    else                                        // LL contains more than 1 node
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete(temp->next);
        temp->next = NULL;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos       
//  Input         :     Position
//  Output        :     Nothing
//  Description   :     Deletes node from given position in doubly linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;

    DoublyLLLnode<T> *temp = NULL;

    if((pos < 1) && (pos > this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }

    else if(pos == iCount)
    {
        this->DeleteLast();
    }

    else
    {
        temp = this->first;
        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete(temp->next->prev);
        temp->next->prev = temp;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display       
//  Input         :     None
//  Output        :     Displays linked list
//  Description   :     Used to display all elements of linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    cout<<"NULL <=> ";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count       
//  Input         :     None
//  Output        :     Integer
//  Description   :     Returns number of nodes present in linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     06/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////
//          Singly Circular Linked List using Generic Approach
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);            
};

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     SinglyCLL       
//  Input         :     None
//  Output        :     None
//  Description   :     Constructor to initialise Singly Circular Linked List
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout<<"\n\nSingly Circular Linked List gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at beginning of circular linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }

    else
    {
        newn->next = this->first;
        this->first = newn;
    }
    last->next = this->first;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at end of circular linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;
    SinglyCLLnode<T> * temp = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }

    else
    {
        this->last->next = newn;     
        this->last = newn;
    }
    this->last->next = this->first;
    
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes first node of circular linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }

    else
    {
        temp = this->first;

        this->first = this->first->next;
        delete temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes last node of circular linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }

    else
    {
        temp = this->first;

        while(temp->next != this->last)
        {
            temp =temp->next;
        }
        delete this->last;
        
        this->last = temp;
        this->last->next = this->first;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display       
//  Input         :     None
//  Output        :     Displays linked list
//  Description   :     Used to display all elements of linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
        temp = this->first;
    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    } while (temp != this->last->next);
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count       
//  Input         :     None
//  Output        :     Integer
//  Description   :     Returns number of nodes present in linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
int SinglyCLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos       
//  Input         :     Data of node, Position
//  Output        :     Nothing
//  Description   :     Inserts node at given position in circular linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: InsertAtPos(T no,int pos)
{
    int iCount = 0;
    int iCnt = 0;

    SinglyCLLnode<T> * newn = NULL;
    SinglyCLLnode<T> * temp = NULL;

    iCount = Count();
    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }

    else if(pos == this->iCount+1)
    {
        InsertLast(no);
    }

    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = this->first;
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos       
//  Input         :     Position
//  Output        :     Nothing
//  Description   :     Deletes node from given position in circular linked list
//  Author        :     Tejas Pradip Sutar 
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    int iCount = 0;
    int iCnt = 0;

    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;

    iCount = Count();
    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }

    else if(pos == this->iCount)
    {
        DeleteLast();
    }

    else
    {
        temp = this->first;
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }

}

////////////////////////////////////////////////////////////////////////////
//          Doubly Circular Linked List using Generic Approach
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> * next;
        DoublyCLLnode<T> * prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyCLL
{
private:
    DoublyCLLnode<T> * first;
    DoublyCLLnode<T> * last;
    int iCount;

public:
    DoublyCLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void InsertAtPos(T no, int pos);
    void DeleteAtPos(int pos);
};

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DoublyCLL       
//  Input         :     None
//  Output        :     None
//  Description   :     Constructor to initialise Doubly Circular Linked List
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"\n\nDoubly Circular Linked List gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertFirst       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at beginning of doubly circular linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> * newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last  = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertLast       
//  Input         :     Data of node
//  Output        :     Nothing
//  Description   :     Inserts node at end of doubly circular linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> * newn = NULL;

    newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last  = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }

    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteFirst       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes first node of doubly circular linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    DoublyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last  = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;

        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteLast       
//  Input         :     None
//  Output        :     Nothing
//  Description   :     Deletes last node of doubly circular linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    DoublyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last  = NULL;
    }
    else
    {
        temp = this->last;
        this->last = this->last->prev;
        delete temp;

        this->last->next = this->first;
        this->first->prev = this->last;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display       
//  Input         :     None
//  Output        :     Displays linked list
//  Description   :     Used to display all elements of linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Linked List is empty\n";
        return;
    }

    temp = this->first;

    cout<<" <=> ";
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != this->last->next);

    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count       
//  Input         :     None
//  Output        :     Integer
//  Description   :     Used to display all elements of linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyCLL<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     InsertAtPos       
//  Input         :     Data of node, Position
//  Output        :     Nothing
//  Description   :     Inserts node at given position in doubly circular linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyCLLnode<T> * newn = NULL;
    DoublyCLLnode<T> * temp = NULL;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode<T>(no);
    
        temp = this->first;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     DeleteAtPos       
//  Input         :     Position
//  Output        :     Nothing
//  Description   :     Deletes node from given position in doubly circular linked list
//  Author        :     Tejas Pradip Sutar
//  Date          :     07/01/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    DoublyCLLnode<T> * temp = NULL;
    DoublyCLLnode<T> * target = NULL;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = this->first;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;

        delete target;
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////
//                      Stack using Generic Approach
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)

template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> * next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Stack
{
    private:
        Stacknode<T> *first;
        int iCount;

    public:
        Stack();

        void push(T);             // It will be InsertFirst
        T pop();                  // It will be DeleteFirst
        T peep();
        void Display();
        int Count();

};

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Stack
//  Input         :     None
//  Output        :     None
//  Description   :     Constructor to initialise Stack
//  Author        :     Tejas Pradip Sutar
//  Date          :     18/02/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
Stack<T> :: Stack()
{
    cout<<"\n\nStack gets created successfully...\n";

    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Push
//  Input         :     Data of node
//  Output        :     None
//  Description   :     Inserts element at top of stack
//  Author        :     Tejas Pradip Sutar
//  Date          :     18/02/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T> :: push(T no)              
{
    Stacknode<T> * newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Pop
//  Input         :     None
//  Output        :     Returns top element
//  Description   :     Removes and returns top element from stack
//  Author        :     Tejas Pradip Sutar
//  Date          :     18/02/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
T Stack<T> :: pop()                
{
    T Value = 0;
    Stacknode<T> * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Peep
//  Input         :     None
//  Output        :     Returns top element
//  Description   :     Returns top element without removing it
//  Author        :     Tejas Pradip Sutar
//  Date          :     18/02/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input         :     None
//  Output        :     Displays stack elements
//  Description   :     Prints all elements of stack from top to bottom
//  Author        :     Tejas Pradip Sutar
//  Date          :     18/02/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T> :: Display()
{
    Stacknode<T> * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input         :     None
//  Output        :     Integer
//  Description   :     Returns total number of elements in stack
//  Author        :     Tejas Pradip Sutar
//  Date          :     18/02/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////
//                      Queue using Generic Approach
////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> * next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:
        Queue();

        void enqueue(T);             // It will be InsertLast
        T dequeue();                  // It will be DeleteFirst
        void Display();
        int Count();

};

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Queue
//  Input         :     None
//  Output        :     None
//  Description   :     Constructor to initialise Queue
//  Author        :     Tejas Pradip Sutar
//  Date          :     18/02/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
Queue<T> :: Queue()
{
    cout<<"\n\nQueue gets created successfully...\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Enqueue
//  Input         :     Data of node
//  Output        :     None
//  Description   :     Inserts element at rear end of queue
//  Author        :     Tejas Pradip Sutar
//  Date          :     18/02/2026
//
////////////////////////////////////////////////////////////////////////////


template <class T>
void Queue<T> :: enqueue(T no)              
{
    Queuenode<T> * newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }

    else
    {
        this->last->next = newn;
        this->last = this->last->next;
    }
    
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Dequeue
//  Input         :     None
//  Output        :     Returns front element
//  Description   :     Removes and returns front element from queue
//  Author        :     Tejas Pradip Sutar
//  Date          :     18/02/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
T Queue<T> :: dequeue()                
{
    int Value = 0;
    Queuenode<T> * temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;

    this->iCount--;
    return Value;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Display
//  Input         :     None
//  Output        :     Displays queue elements
//  Description   :     Prints all elements of queue from front to rear
//  Author        :     Tejas Pradip Sutar
//  Date          :     18/02/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> :: Display()
{
    Queuenode<T> * temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function Name :     Count
//  Input         :     None
//  Output        :     Integer
//  Description   :     Returns total number of elements in queue
//  Author        :     Tejas Pradip Sutar
//  Date          :     18/02/2026
//
////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T> :: Count()
{
    return this->iCount;
}


///////////////////////////// End of Library ///////////////////////////////
