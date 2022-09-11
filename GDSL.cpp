/*
    NAME: SAYALI SUBHASH MAHALE
    PROJECT NAME: GENERIC DATA STRUCTURES LIBRARY
*/ 

/*
    IMPLEMENTATION OF DATA STRUCTURES IN GENERIC FORMAT
    **DATA STRUCTURES USED**
    1)SINGLY LINEAR LINKED LIST
    2)DOUBLY LINEAR LINKED LIST
    3)SINGLY CIRCULAR LINKED LIST
    4)DOUBLY CIRCULAR LINKED LIST
    5)STACK
    6)QUEUE
*/ 

#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SINGLY LINKED LIST
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
    STRUCTURE NAME   : node
    DESCRIPTION      : Creates template of node which contains data & next pointer
*/ 
template <class T>
struct node
{
    T data;
    struct node * next;
};

/*
    CLASS NAME   : SinglyLL
*/ 
template <class T>
class SinglyLL
{
    public:
        struct node<T>* Head;
        int Count;

        SinglyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int CountNode();
};

/*
    CONSTRUCTOR NAME    :  SinglyLL
*/ 
template <class T>
SinglyLL<T>::SinglyLL()
{
    Head=NULL;
    Count=0;
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: T no
    RETURN VALUE    : void
    DESCRIPTION     : Insert data at first position in the Singly LL
*/ 
template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T>* newn=NULL;
    newn=new node<T>;

    newn->data=no;
    newn->next=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head=newn;
    }
}

/*
    FUNCTION NAME   : InsertLast
    INPUT PARAMETERS: T no
    RETURN VALUE    : void
    DESCRIPTION     : Insert data at Last position in the Singly LL
*/ 
template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T>* newn=NULL;
    newn=new node<T>;

    newn->data=no;
    newn->next=NULL;

    // if ll is empty
    if(Head==NULL)
    {
        Head=newn;
    }
    // if ll has at least one element or more
    else
    {
        struct node<T>* temp=Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
}

/*
    FUNCTION NAME   : InsertAtPos
    INPUT PARAMETERS: T no, int pos
    RETURN VALUE    : void
    DESCRIPTION     : Insert data at defined position in the Singly LL
*/ 
template<class T>
void SinglyLL<T>::InsertAtPos(T no,int pos)
{
    int size=0;
    size=CountNode();
    
    if((pos<1) || (pos>(size+1)))
    {
        cout<<"Position is invalid"<<endl;
        return;
    }

    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos==size+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T>* newn=NULL;
        newn=new node<T>;

        newn->data=no;
        newn->next=NULL;

        int iCnt=0;
        struct node<T>* temp=NULL;
        temp=Head;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Delete data of the first position from the Singly LL
*/ 
template<class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node<T>* temp=NULL;

    // IF LL is empty then return
    if(Head==NULL)
    {
        return;
    }
    // IF LL contains at least one node then delete first node 
    else
    {
        temp=Head;
        Head=Head->next;
        delete temp;
    }
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Delete data of the last position from the Singly LL
*/ 
template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct node<T>* temp=NULL;

    if(Head==NULL)
    {
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        temp=Head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: int pos
    RETURN VALUE    : void
    DESCRIPTION     : Delete data of the defined position from the Singly LL
*/ 
template<class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    int size=0;
    size=CountNode();

    if((pos<1) || (pos>(size+1)))
    {
        cout<<"Position is invalid"<<endl;
        return;
    }

    if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos==size)
    {
        DeleteLast();
    }
    else
    {
        struct node<T>* temp1=NULL;
        struct node<T>* temp2=NULL;
        temp1=Head;

        int iCnt=0;
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next->next;
        delete temp1->next;
        temp1->next=temp2;
    }
}

/*
    FUNCTION NAME   : Display
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Display nodes of Singly LL
*/ 
template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements from Linked List are : "<<endl;
    struct node<T>* temp=Head;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

/*
    FUNCTION NAME   : CountNode
    INPUT PARAMETERS: -
    RETURN VALUE    : int
    DESCRIPTION     : returns the total number of nodes
*/ 
template<class T>
int SinglyLL<T>::CountNode()
{
    Count=0;
    struct node<T>* temp=Head;
    while(temp!=NULL)
    {
        Count++;
        temp=temp->next;
    }
    return Count;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DOUBLY LINKED LIST

/*
    STRUCTURE NAME   : nodeLL
    DESCRIPTION      : Creates template of nodeLL which contains data, next pointer & prev pointer
*/ 
template<class T>
struct nodeDLL
{
    T data;
    struct nodeDLL * next;
    struct nodeDLL * prev;
};

/*
    CLASS NAME   : DoublyLL
*/ 
template<class T>
class DoublyLL
{
    public:
        struct nodeDLL<T>* Head;
        int Count;

        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int CountNode(); 
};

/*
    CONSTRUCTOR NAME    :  DoublyLL
*/ 
template<class T>
DoublyLL<T>::DoublyLL()
{
    Head=NULL;
    Count=0;
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: T no
    RETURN VALUE    : void
    DESCRIPTION     : Insert data at first position in the Doubly LL
*/ 
template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct nodeDLL<T>* newn=NULL;
    newn=new nodeDLL<T>;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        newn->next=Head;
        Head->prev=newn;
        Head=newn;
    }
}

/*
    FUNCTION NAME   : InsertLast
    INPUT PARAMETERS: T no
    RETURN VALUE    : void
    DESCRIPTION     : Insert data at Last position in the Doubly LL
*/ 
template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct nodeDLL<T>* newn=NULL;
    newn=new nodeDLL<T>;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(Head==NULL)
    {
        Head=newn;
    }
    else
    {
        struct nodeDLL<T>* temp=Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
}

/*
    FUNCTION NAME   : InsertAtPos
    INPUT PARAMETERS: T no, int pos
    RETURN VALUE    : void
    DESCRIPTION     : Insert data at defined position in the Doubly LL
*/ 
template<class T>
void DoublyLL<T>::InsertAtPos(T no,int pos)
{
    int size=0;
    size=CountNode();

    if((pos<1) || (pos>(size+1)))
    {
        cout<<"Position is invalid"<<endl;
        return;
    }

    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos==size+1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeDLL<T>* newn=NULL;
        newn=new nodeDLL<T>;

        newn->data=no;
        newn->next=NULL;

        int iCnt=0;
        struct nodeDLL<T>* temp=NULL;
        temp=Head;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
    }
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Delete data of the first position from the Doubly LL
*/ 
template<class T>
void DoublyLL<T>::DeleteFirst()
{
    struct nodeDLL<T>* temp=NULL;

    if(Head==NULL)
    {
        return;
    }
    if(Head->next==NULL)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        temp=Head;
        Head=Head->next;
        delete temp;
        Head->prev=NULL;
    }
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Delete data of the last position from the Doubly LL
*/ 
template<class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDLL<T>* temp=NULL;

    if(Head==NULL)
    {
        return;
    }
    else if(Head->next==NULL)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
        temp=Head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: int pos
    RETURN VALUE    : void
    DESCRIPTION     : Delete data of the defined position from the Doubly LL
*/ 
template<class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    int size=0;
    size=CountNode();

    if((pos<1) || (pos>(size+1)))
    {
        cout<<"Position is invalid"<<endl;
        return;
    }

    if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos==size)
    {
        DeleteLast();
    }
    else
    {
        struct nodeDLL<T>* temp=Head;

        int iCnt=0;
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
            temp=temp->next;
        }
       
        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
    }
}

/*
    FUNCTION NAME   : Display
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Display nodes of Singly LL
*/ 
template<class T>
void DoublyLL<T>::Display()
{
    cout<<"Elements from Linked List are : "<<endl;
    struct nodeDLL<T>* temp=Head;
    cout<<"NULL<=>";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"<=>";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

/*
    FUNCTION NAME   : CountNode
    INPUT PARAMETERS: -
    RETURN VALUE    : int
    DESCRIPTION     : returns the total number of nodes
*/ 
template<class T>
int DoublyLL<T>::CountNode()
{
    Count=0;
    struct nodeDLL<T>* temp=Head;
    while(temp!=NULL)
    {
        Count++;
        temp=temp->next;
    }
    return Count;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// SINGLY CIRCULAR LINKED LIST

/*
    STRUCTURE NAME   : node
    DESCRIPTION      : Creates template of node which contains data & next pointer
*/ 
template<class T>
struct nodeSCLL
{
    T data;
    struct nodeSCLL * next;
};

/*
    CLASS NAME   : SinglyCLL
*/ 
template<class T>
class SinglyCLL
{
    public:
        struct nodeSCLL<T>* Head;
        struct nodeSCLL<T>* Tail;
        int Count;

        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int CountNode();
};

/*
    CONSTRUCTOR NAME    :  SinglyCLL
*/ 
template<class T>
SinglyCLL<T>::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: T no
    RETURN VALUE    : void
    DESCRIPTION     : Insert data at first position in the Singly Circular LL
*/
template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct nodeSCLL<T>* newn = NULL;
    newn = new nodeSCLL<T>;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))    // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else        // If LL constains atleast one nodeSCLL
    {
        newn -> next = Head;
        Head = newn;
    }
    Tail -> next = Head;
}

/*
    FUNCTION NAME   : InsertLast
    INPUT PARAMETERS: T no
    RETURN VALUE    : void
    DESCRIPTION     : Insert data at Last position in the Singly Circular LL
*/ 
template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct nodeSCLL<T>* newn = NULL;

    newn = new nodeSCLL<T>;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))    // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else        // If LL constains atleast one node
    {
        Tail -> next = newn;
        Tail = newn;
    }
    Tail -> next = Head;
}

/*
    FUNCTION NAME   : InsertAtPos
    INPUT PARAMETERS: T no, int pos
    RETURN VALUE    : void
    DESCRIPTION     : Insert data at defined position in the Singly Circular LL
*/ 
template<class T>
void SinglyCLL<T>::InsertAtPos(T no,int pos)
{
    int iSize = CountNode();

    if((pos < 1) || (pos > iSize+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeSCLL<T>* newn = NULL;

        newn = new nodeSCLL<T>;

        newn->data = no;
        newn->next = NULL;

        struct nodeSCLL<T>* temp = Head;
        int iCnt = 0;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp -> next;
        temp->next = newn;
    }
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Delete data of the first position from the Singly Circular LL
*/ 
template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(Head == NULL && Tail ==  NULL)       // If LL is empty
    {
        return;
    }
    else if(Head == Tail)       // If LL contains 1 node
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else    // If LL contains more than 1 node
    {
        Head = Head -> next;
        delete Tail->next;

        Tail->next = Head;
    }
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Delete data of the last position from the Singly Circular LL
*/ 
template<class T>
void SinglyCLL<T>::DeleteLast()
{
    if(Head == NULL && Tail ==  NULL)       // If LL is empty
    {
        return;
    }
    else if(Head == Tail)       // If LL contains 1 node
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
    }
    else    // If LL contains more than 1 node
    {
        struct nodeSCLL<T>* temp = Head;

        while(temp->next != Tail)
        {
            temp = temp->next;
        }

        delete Tail;
        Tail = temp;

        Tail->next = Head;
    }
}

/*
    FUNCTION NAME   : InsertFirst
    INPUT PARAMETERS: int pos
    RETURN VALUE    : void
    DESCRIPTION     : Delete data of the defined position from the Singly Circular LL
*/ 
template<class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
     int iSize = CountNode();

    if((pos < 1) || (pos > iSize))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iSize)
    {
        DeleteLast();
    }
    else
    {
        struct nodeSCLL<T>* temp1 = Head;
        int iCnt = 0;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp1 = temp1->next;
        }

        struct nodeSCLL<T>* temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;
    }
}

/*
    FUNCTION NAME   : Display
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Display nodes of Singly Circular LL
*/ 
template<class T>
void SinglyCLL<T>::Display()
{
    struct nodeSCLL<T>* temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return;
    }
    cout<<"<-";
    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp -> next;
    }while(temp != Head);

    cout<<endl;
}

/*
    FUNCTION NAME   : CountNode
    INPUT PARAMETERS: -
    RETURN VALUE    : int
    DESCRIPTION     : returns the total number of nodes
*/ 
template<class T>
int SinglyCLL<T>::CountNode()
{
    int iCnt = 0;
    struct nodeSCLL<T>* temp = Head;

    if(Head == NULL && Tail == NULL)
    {
        return 0;
    }

    do
    {
        iCnt++;
        temp = temp->next;
    }while(temp != Head);

    return iCnt;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DOUBLY CIRCULAR LINKED LIST
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct DCnode
{
    T data;
    struct DCnode<T> *next;
    struct DCnode<T> *prev;
};

template<class T>
class DoublyCLL
{
    private:
        struct DCnode<T> *Head;
        struct DCnode<T> *Tail;
        int Count;

    public:
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int);
        void Display();
        int Countnode();
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    Count = 0;
}

template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct DCnode<T> *newn = NULL;
    newn = new DCnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Tail->next = Head;
    Head->prev = Tail;

    Count++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct DCnode<T> *newn = NULL;
    newn = new DCnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(Head == NULL && Tail == NULL)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count++;
}

template<class T>
void DoublyCLL<T>::Display()
{
    struct DCnode<T> *temp = NULL;
    temp = Head;

    cout<<"Nodes of Doubly Circular Linked List are : "<<endl;

    do 
    {
        cout<<"|"<<temp->data<<"| <->";
        temp = temp->next;
    }while(temp != Tail->next);
    cout<<"NULL"<<endl;
}

template<class T>
int DoublyCLL<T>::Countnode()
{
    return Count;
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Head->prev;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count--;
}

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(Head == NULL & Tail == NULL)
    {
        return;
    }

    if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete Tail->next;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Count--;
}

template<class T>
void DoublyCLL<T>::InsertAtPosition(T no, int ipos)
{
    if((ipos < 1) || (ipos > (Count+1)))
    {
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (Count+1))
    {
        InsertLast(no);
    }
     else
    {
        struct DCnode<T> *newn = NULL;
        newn = new DCnode<T>;
        newn->data = no;
        newn->next = NULL;

        struct DCnode<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        Count++;
    }
}

template<class T>
void DoublyCLL<T>::DeleteAtPosition(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct DCnode<T> *temp = Head;

        for(int iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        Count--;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// STACK
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
    STRUCTURE NAME   : nodeSt
    DESCRIPTION      : Creates template of nodeSt which contains data & next pointer
*/ 
template<class T>
struct nodeSt
{
    T data;
    struct nodeSt *next;
};

/*
    CLASS NAME   : Stack
*/ 
template<class T>
class Stack
{
    public:
        struct nodeSt<T> *Head;
        int Count;

        Stack();
        void Push(T);        // InsertLast
        void Pop();            // DeleteFirst
        void Display();
        int CountNode();
};

/*
    CONSTRUCTOR NAME    :  Stack
*/
template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

/*
    FUNCTION NAME   : Push
    INPUT PARAMETERS: T no
    RETURN VALUE    : void
    DESCRIPTION     : Push data in the stack
*/
template<class T>
void Stack<T>::Push(T no)
{
    struct nodeSt<T> *newn = NULL;
    newn = new nodeSt<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next=Head;
    Head=newn;
    Count++;
}

/*
    FUNCTION NAME   : Pop
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Pop data from the stack
*/
template <class T>
void Stack<T>::Pop()       // Deletefirst
{
    T no;   // int no;

    if(Count == 0)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }

    no = Head -> data;
    struct nodeSt<T> *temp = Head;
    Head = Head->next;
    delete temp;

    Count--;
    cout<<"Removed element is : "<<no<<endl;
}

/*
    FUNCTION NAME   : Display
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Display data of the stack
*/
template<class T>
void Stack<T>::Display()
{
    cout<<"Elements from Stack are : "<<endl;
    struct nodeSt<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

/*
    FUNCTION NAME   : CountNode
    INPUT PARAMETERS: -
    RETURN VALUE    : int
    DESCRIPTION     : Count number of data of the stack
*/
template<class T>
int Stack<T>::CountNode()
{
    return Count;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// QUEUE

/*
    STRUCTURE NAME   : nodeQ
    DESCRIPTION      : Creates template of nodeQ which contains data & next pointer
*/ 
template<class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

/*
    CLASS NAME   : Queue
*/ 
template<class T>
class Queue
{
    public:
        struct nodeQ<T> *Head;
        int Count;

        Queue();
        void Enqueue(T);        // InsertLast
        void Dequeue();            // DeleteFirst
        void Display();
};

/*
    CONSTRUCTOR NAME    :  Queue
*/
template<class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}

/*
    FUNCTION NAME   : Push
    INPUT PARAMETERS: T no
    RETURN VALUE    : void
    DESCRIPTION     : Push data in the queue
*/
template<class T>
void Queue<T>::Enqueue(T no)
{
    struct nodeQ<T> *newn = NULL;
    newn = new nodeQ<T>;

    newn->data = no;
    newn->next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct nodeQ<T> *temp = Head;
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }
    Count++;
}

/*
    FUNCTION NAME   : Pop
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Pop data from the queue
*/
template <class T>
void Queue<T>::Dequeue()       // Deletefirst
{
    T no;   // int no;

    if(Count == 0)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    no = Head -> data;
    struct nodeQ<T> *temp = Head;
    Head = Head->next;
    delete temp;

    Count--;
    cout<<"Removed element is : "<<no<<endl;
}

/*
    FUNCTION NAME   : Display
    INPUT PARAMETERS: -
    RETURN VALUE    : void
    DESCRIPTION     : Display data of the queue
*/
template<class T>
void Queue<T>::Display()
{
    cout<<"Elements from Queue are : "<<endl;
    struct nodeQ<T> *temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    int choice=0;
    int option=0;
    int number=0;
    int position=0;

    cout<<"************************************************************************"<<endl;
    cout<<"Welcome to GENERIC DATA STRUCTURES WORLD!!"<<endl;
    cout<<endl;
    cout<<"CHOICES"<<endl;
    cout<<"1    :   SINGLY LINKED LIST"<<endl;
    cout<<"2    :   DOUBLY LINKED LIST"<<endl;
    cout<<"3    :   SINGLY CIRCULAR LINKED LIST"<<endl;
    cout<<"4    :   STACK"<<endl;
    cout<<"5    :   QUEUE"<<endl;
    cout<<"************************************************************************"<<endl;
    cout<<"Which GENERIC DATA STRUCTURE you want to use??"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    cout<<endl;
    cout<<"************************************************************************"<<endl;
    
    if(choice==1)
    {
        cout<<"Your linked list is SINGLY LINKED LIST"<<endl;
        cout<<"Integer Linked List (Enter only INTEGERS)"<<endl;
        SinglyLL<int>obj1;
        option=0;

        cout<<endl;
        cout<<"OPTIONS"<<endl;  
        cout<<"1    :   Insert First"<<endl;
        cout<<"2    :   Insert Last"<<endl;
        cout<<"3    :   Insert At Position"<<endl;
        cout<<"4    :   Delete First"<<endl;
        cout<<"5    :   Delete Last"<<endl;
        cout<<"6    :   Delete At Position"<<endl;
        cout<<"7    :   Display "<<endl;
        cout<<"8    :   Count Nodes"<<endl;
        cout<<"0    :   Exit"<<endl; 
        cout<<"************************************************************************"<<endl;

        while(1)
        { 
            cout<<"Enter operation choice you want to perform :";
            cin>>option;      

            if(option==1)
            {
                cout<<"Enter Number : ";
                cin>>number;
                obj1.InsertFirst(number);
            }
            else if(option==2)
            {
                cout<<"Enter Number : ";
                cin>>number;
                obj1.InsertLast(number);
            }
            else if(option==3)
            {
                cout<<"Enter Number : ";
                cin>>number;
                cout<<"Enter Position : ";
                cin>>position;
                obj1.InsertAtPos(number,position);
            }
            else if(option==4)
            {
                obj1.DeleteFirst();
                cout<<"Deleted Successfully!!"<<endl;
            }
            else if(option==5)
            {
                obj1.DeleteLast();
                cout<<"Deleted Successfully!!"<<endl;
            }
            else if(option==6)
            {
                cout<<"Enter Position : ";
                cin>>position;
                obj1.DeleteAtPos(position);
                cout<<"Deleted Successfully!!"<<endl;
            }
            else if(option==7)
            {
                cout<<"Nodes in Singly ll are :"<<endl;
                obj1.Display();
                cout<<"************************************************************************"<<endl;
            }
            else if(option==8)
            {
                cout<<"Nodes in Singly ll after deleting are :"<<endl;
            }
            else if(option==0)
            {
                cout<<"EXIT!!"<<endl;
                cout<<"************************************************************************"<<endl;
                return 0;
            }
            else
            {
                cout<<"Enter valid OPERATION CHOICE!!"<<endl;
            }   
        }
    }
    else if(choice==2)
    {
        cout<<"Your linked list is DOUBLY LINKED LIST"<<endl;
        DoublyLL<float>obj2;
        option=0;

        cout<<endl;
        cout<<"OPTIONS"<<endl;  
        cout<<"1    :   Insert First"<<endl;
        cout<<"2    :   Insert Last"<<endl;
        cout<<"3    :   Insert At Position"<<endl;
        cout<<"4    :   Delete First"<<endl;
        cout<<"5    :   Delete Last"<<endl;
        cout<<"6    :   Delete At Position"<<endl;
        cout<<"7    :   Display "<<endl;
        cout<<"8    :   Count Nodes"<<endl;
        cout<<"0    :   Exit"<<endl; 
        cout<<"************************************************************************"<<endl;

        while(1)
        { 
            cout<<"Enter operation choice you want to perform :";
            cin>>option;      

            if(option==1)
            {
                cout<<"Enter Number : ";
                cin>>number;
                obj2.InsertFirst(number);
            }
            else if(option==2)
            {
                cout<<"Enter Number : ";
                cin>>number;
                obj2.InsertLast(number);
            }
            else if(option==3)
            {
                cout<<"Enter Number : ";
                cin>>number;
                cout<<"Enter Position : ";
                cin>>position;
                obj2.InsertAtPos(number,position);
            }
            else if(option==4)
            {
                obj2.DeleteFirst();
                cout<<"Deleted Successfully!!"<<endl;
            }
            else if(option==5)
            {
                obj2.DeleteLast();
                cout<<"Deleted Successfully!!"<<endl;
            }
            else if(option==6)
            {
                cout<<"Enter Position : ";
                cin>>position;
                obj2.DeleteAtPos(position);
                cout<<"Deleted Successfully!!"<<endl;
            }
            else if(option==7)
            {
                cout<<"Nodes in Doubly ll are :"<<endl;
                obj2.Display();
                cout<<"************************************************************************"<<endl;
            }
            else if(option==8)
            {
                cout<<"Nodes in Doubly ll after deleting are :"<<endl;
            }
            else if(option==0)
            {
                cout<<"EXIT!!"<<endl;
                cout<<"************************************************************************"<<endl;
                return 0;
            }
            else
            {
                cout<<"Enter valid oOPERATION CHOICE!!"<<endl;
            }  
        } 
    }
    else if(choice==3)
    {
        cout<<"Your linked list is SINGLY CIRCULAR LINKED LIST"<<endl;
        cout<<"Characters Linked List (Enter only CHARACTERS)"<<endl;
        SinglyCLL<char>obj3;
        option=0;
        char character='\0';

        cout<<endl;
        cout<<"OPTIONS"<<endl;  
        cout<<"1    :   Insert First"<<endl;
        cout<<"2    :   Insert Last"<<endl;
        cout<<"3    :   Insert At Position"<<endl;
        cout<<"4    :   Delete First"<<endl;
        cout<<"5    :   Delete Last"<<endl;
        cout<<"6    :   Delete At Position"<<endl;
        cout<<"7    :   Display "<<endl;
        cout<<"8    :   Count Nodes"<<endl;
        cout<<"0    :   Exit"<<endl; 
        cout<<"************************************************************************"<<endl;

        while(1)
        { 
            cout<<"Enter operation choice you want to perform :";
            cin>>option;  

            if(option==1)
            {
                cout<<"Enter character : ";
                cin>>character;
                obj3.InsertFirst(character);
            }
            else if(option==2)
            {
                cout<<"Enter character : ";
                cin>>character;
                obj3.InsertLast(character);
            }
            else if(option==3)
            {
                cout<<"Enter character : ";
                cin>>character;
                cout<<"Enter Position : ";
                cin>>position;
                obj3.InsertAtPos(character,position);
            }
            else if(option==4)
            {
                obj3.DeleteFirst();
                cout<<"Deleted Successfully!!"<<endl;
            }
            else if(option==5)
            {
                obj3.DeleteLast();
                cout<<"Deleted Successfully!!"<<endl;
            }
            else if(option==6)
            {
                cout<<"Enter Position : ";
                cin>>position;
                obj3.DeleteAtPos(position);
                cout<<"Deleted Successfully!!"<<endl;
            }
            else if(option==7)
            {
                cout<<"Nodes in Doubly ll are :"<<endl;
                obj3.Display();
                cout<<"************************************************************************"<<endl;
            }
            else if(option==8)
            {
                cout<<"Nodes in Doubly ll after deleting are :"<<endl;
            }
            else if(option==0)
            {
                cout<<"EXIT!!"<<endl;
                cout<<"************************************************************************"<<endl;
                return 0;
            }
            else
            {
                cout<<"Enter valid oOPERATION CHOICE!!"<<endl;
            }  
        } 
    } 
    else if(choice==4)
    {
        cout<<"Your Data structure is STACK"<<endl;
        cout<<"Characters Stack(Enter only CHARACTERS)"<<endl;
        Stack<char>obj4;
        option=0;
        char character='\0';

        cout<<endl;
        cout<<"OPTIONS"<<endl;  
        cout<<"1    :   Push"<<endl;
        cout<<"2    :   Pop Last"<<endl;
        cout<<"3    :   Display"<<endl;
        cout<<"0    :   EXIT!"<<endl;
        cout<<"************************************************************************"<<endl;

        while(1)
        { 
            cout<<"Enter operation choice you want to perform :";
            cin>>option;      

            if(option==1)
            {
                cout<<"Enter character : ";
                cin>>character;
                obj4.Push(character);
            }
            else if(option==2)
            {
                cout<<"Enter character : ";
                cin>>character;
                obj4.Pop();
            }
            else if(option==3)
            {
                obj4.Display();
            }
            else if(option==0)
            {
                cout<<"EXIT!!"<<endl;
                cout<<"************************************************************************"<<endl;
                return 0;
            }
            else
            {
                cout<<"Enter valid OPERATION CHOICE!!"<<endl;
            }  
        }
    }
    else if(choice==5)
    {
        cout<<"Your Data structure is QUEUE"<<endl;
        cout<<"Integers QUEUE(Enter only Integers)"<<endl;
        Stack<int>obj5;
        option=0;
        number=0;

        cout<<endl;
        cout<<"OPTIONS"<<endl;  
        cout<<"1    :   Enqueue"<<endl;
        cout<<"2    :   Dequeue"<<endl;
        cout<<"3    :   Display"<<endl;
        cout<<"0    :   EXIT!"<<endl;
        cout<<"************************************************************************"<<endl;

        while(1)
        { 
            cout<<"Enter operation choice you want to perform :";
            cin>>option;      

            if(option==1)
            {
                cout<<"Enter number : ";
                cin>>number;
                obj5.Push(number);
            }
            else if(option==2)
            {
                cout<<"Enter number : ";
                cin>>number;
                obj5.Pop();
            }
            else if(option==3)
            {
                obj5.Display();
            }
            else if(option==0)
            {
                cout<<"EXIT!!"<<endl;
                cout<<"************************************************************************"<<endl;
                return 0;
            }
            else
            {
                cout<<"Enter valid OPERATION CHOICE!!"<<endl;
            }  
        }
    }
    else
    {
        cout<<"Please Enter valid CHOICE!!"<<endl;
        cout<<"************************************************************************"<<endl;
        cout<<endl;
    }
    
    return 0;
}