
///////////////////////////////////////////////////////////
// Project : Generic_DataStructure_Library 
///////////////////////////////////////////////////////////


#include<iostream>
using namespace std;


///////////////////////////////////////////////////////////////////////////////////////
//                                                                                   
// Project Name  :  Generic_DataStructure_Library                                               
// Description   : This project is  provides the emulation of all the facilities and 
//                 functionalities provided by the database management system.
// Technology    :   C++ Programming                                                         
// Date          : 15/12/2022                                                        
// Author        : Thorat Swapnil Harishchandra                                      
//                                                                                   
///////////////////////////////////////////////////////////////////////////////////////


#define TRUE    1
#define FALSE   0

typedef int  BOOL;


template<class T>   //typename T = class T
struct node
{
    T  data;
    node <T> * next;
};

template <class T>
struct dnode
{
    T data;
    dnode<T> *next;
    dnode <T>*prev;
};

template<class T>
class Singly_linkedList
{
    private:
        node <T> * Head;      //struct node 
    public:
        Singly_linkedList();
        ~Singly_linkedList();
        BOOL InsertFirst(T);
        BOOL InsertLast(T);
        BOOL InsertAtPosition(T,T);
        void Display();
        int Count();
        BOOL DeleteFirst();
        BOOL DeleteLast();
        BOOL DeleteAtPosition(T);
};

template<class T>
class  SinglyCLL
{
    private:
        node <T> * Head;
        node <T> * Tail;
    public:
        SinglyCLL();
        ~SinglyCLL();
        BOOL InsertFirst(T no);
        BOOL InsertLast(T no);
        BOOL InsertAtPos(T no,T ipos);
        BOOL DeleteFirst();
        BOOL DeleteLast();
        BOOL DeleteAtPos(T ipos);
        void Display();
        int Count();
};


template<class T>
class Doubly_linkedList
{
    private:
        dnode <T> * Head;
    public:
        Doubly_linkedList();
        ~Doubly_linkedList();
        BOOL InsertFirst(T);
        BOOL InsertLast(T);
        BOOL InsertAtPosition(T,T);
        void Display();
        int Count();
        BOOL DeleteFirst();
        BOOL DeleteAtPosition(T);
        BOOL DeleteLast();
};

template<class T>
class DoublyCLL
{
    private:
        dnode <T> * Head;
        dnode <T> * Tail;
        int CountNode;
    public:
        DoublyCLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,T);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(T);

        int Count();
        void Display();
};

template <class T>            //<typename T
Singly_linkedList<T> ::Singly_linkedList()
{
    //cout<<"Inside constructor\n;"
    Head = NULL;
}

template <class  T>
Singly_linkedList<T>::~Singly_linkedList()
{
    //cout<"\nInside destructor \n";
    node <T>* temp1 = Head;      //class madhe use temp1 =  navigate
    node <T>* temp2;

    if(Head != NULL)
    {
                                                 //Navigate = Head;
            while(temp1 != NULL)
            {
                temp2 = temp1->next;
                delete(temp1);                                //delete Navigate;
                temp1 = temp2;
            }
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertFirst
//  Description   :  Used to insert at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Singly_linkedList<T>:: InsertFirst(T no)
{
    node <T> * newn = NULL;

    newn = new node<T>;     //Allocate memory

    if(newn == NULL)
    {
        return FALSE;
    }

    newn->next = NULL;   //Initialise pointer
    newn->data = no;     //Initialise data

    if(Head == NULL)    //Linkedlist is empty
    {
        Head = newn;
    }
    else                //LL Contains atleast one node
    {
        newn->next = Head;
        Head = newn;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertLast
//  Description   :  Used to insert at last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Singly_linkedList<T>::InsertLast(T no)
{
    node <T>* newn = NULL;
    node <T>* temp = Head;

    newn = new node <T>;  

    if(newn == NULL)
    {
        return FALSE;
    }
    newn->next = NULL;  //Initialise data 
    newn->data = no;    //Initialise pointer

    if(Head == NULL)    //Linkedlist is empty
    {
        Head = newn;
    }
    else                //LL contains atleast one node
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertAtPosition
//  Description   :  Used to Insert At Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
BOOL Singly_linkedList<T>::InsertAtPosition(T pos,T no)
{
    
    if((Head == NULL)  || (pos > Count()+1 ) || (pos <= 0))
    {
        return FALSE;
    }

    if(pos == 1)
    {
        return(InsertFirst(no));
    }
    else if(pos == (Count()) +1)
    {
        return(InsertLast(no));
    }
    else
    {
        node <T> * newn = NULL;
        node <T> * temp = Head;

        newn = new node <T>;
        if(newn == NULL)
        {
            return FALSE;
        }
        newn->next = NULL;
        newn->data = no;

        for(int i = 1; i<= (pos-2); i++)  //for(int i = 0; i<(pos); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteFirst
//  Description   :  Used to Delete at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
BOOL Singly_linkedList<T>::DeleteFirst()
{
    node <T> * temp = Head;

    if(Head == NULL)
    {
        return FALSE;
    }
    else
    {
        Head = Head->next;
        delete(temp);
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteLast
//  Description   :  Used to Delete at Last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
BOOL Singly_linkedList<T>::DeleteLast()
{
    if(Head == NULL)
    {
        return FALSE;
    }
    else if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        node <T> * temp1 = Head;
        node <T> * temp2 = NULL;

        while(temp1->next->next != NULL)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = NULL;
        delete(temp2);
    }
    return TRUE;
}


////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteAtPosition
//  Description   :  Used to Delete at Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Singly_linkedList<T>::DeleteAtPosition(T pos)
{
    
    int size = 0, iCnt = 0;
    node <T> * temp = NULL;
    node <T> * tempdelete = NULL;

    if((Head == NULL) || (pos > Count()) ||(pos <= 0))
    {
        return FALSE;
    }
    else if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == (Count()))
    {
        DeleteLast();
    }
    else        // Logic
    {
        node <T> *temp = Head;

        for(iCnt = 1; iCnt < pos-1 ; iCnt++)
        {
            temp = temp -> next;
        }

        tempdelete = temp->next;
        temp->next = temp->next->next;
        delete(tempdelete);
    }
}



////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Display
//  Description   :  Used to display elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template <class T>
void Singly_linkedList <T>::Display()
{
    node <T> * temp = Head;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"--> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}


////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Count
//  Description   :  Used to Count elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
int Singly_linkedList<T>::Count()
{
    node <T> * temp = Head;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

template<class T>
SinglyCLL<T>::SinglyCLL()    //Defualt Constructor
{
  Head = NULL;
  Tail = NULL;
}

template <class T>
SinglyCLL <T> ::~SinglyCLL()
{
  node <T> * temp1=Head;
  node <T> * temp2;
  
    while(temp1!=Tail)
    {
      temp2=temp1->next;
      delete(temp1);
      temp1=temp2;
    }

}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertFirst
//  Description   :  Used to insert at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::InsertFirst(T no)
{
  node <T> * newn = NULL;   //initialised

  newn = new node<T>;     
  newn->data = no;     
  newn->next = NULL;    

  if((Head == NULL) && (Tail == NULL))    
  {
    Head = newn;
    Tail = newn;          
  }
  else         
  {
    newn->next = Head;
    Head = newn;
  }
  Tail->next = Head;       
}
////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertLast
//  Description   :  Used to insert at last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::InsertLast(T no)
{
  node <T> * newn = NULL;   

  newn = new node <T>;     
  newn->data = no;     
  newn->next = NULL;    

  if((Head == NULL) && (Tail == NULL))    //If LL is empty
  {
    Head = newn;
    Tail = newn;          
  }
  else         // If LL contains atleast one node
  {
    Tail->next = newn;
    Tail = newn;
  }
  Tail->next = Head;       
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertAtPosition
//  Description   :  Used to Insert At Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::InsertAtPos(T no,T ipos)
{
   int iSize = Count(); 
  if((ipos <1) || (ipos>iSize+1))
  {
    cout<<"Invalid position\n";
    return FALSE;
  }
  if(ipos ==1)
  {
    InsertFirst(no);
  }
  else if(ipos == iSize +1)
  {
    InsertLast(no);
  }
  else
  {
     node <T> * newn = NULL;   

     newn = new node <T>;     

     newn->data = no;     
     newn->next = NULL;   //Initialise pointer

     node<T> * temp = Head;
     int iCnt = 0;

     for(iCnt =1; iCnt<ipos-1; iCnt++)
     {
       temp = temp->next;
     }

     newn->next = temp->next;
     temp->next  = newn;
  }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteFirst
//  Description   :  Used to Delete at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::DeleteFirst()
{
  if(Head == NULL && Tail == NULL)     //If  LL is empty
  {
    return FALSE;
  }
  else if(Head == Tail)     //if LL contains 1 node
  {
    delete Head;
    Head = NULL;
    Tail = NULL;
  }
  else              //if LL contains more than 1 node
  {
    Head = Head ->next;
    delete Tail->next;

    Tail->next = Head;
  }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteLast
//  Description   :  Used to Delete at Last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::DeleteLast()
{
  if(Head == NULL && Tail == NULL)     //If  LL is empty
  {
    return FALSE;
  }
  else if(Head == Tail)     //if LL contains 1 node
  {
    delete Head;
    Head = NULL;
    Tail = NULL;
  }
  else              //if LL contains more than 1 node
  {
    node <T> * temp = Head;   

   while(temp->next != Tail)   
   {
     temp = temp->next;
   }

   delete Tail;
   Tail = temp;

   Tail->next = Head;
  }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteAtPosition
//  Description   :  Used to Delete at Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL SinglyCLL<T>::DeleteAtPos( T ipos)
{
  int iSize = Count();  

  if((ipos < 1) || (ipos > iSize+1))
  {
    cout<<"Invalid position\n";
    return FALSE;
  }
  if(ipos ==1)
  {
    DeleteFirst();
  }
  else if(ipos == iSize +1)
  {
    DeleteLast();
  }
  else
  {
    node <T> * temp1 = Head;
    int iCnt = 0;

    for(iCnt =1; iCnt<ipos-1; iCnt++)
    {
      temp1 = temp1->next;
    }
    node <T> * temp2 = temp1->next;
    temp1->next =temp2->next;
    delete temp2;

  }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Display
//  Description   :  Used to display elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::Display()
{
   node <T> * temp = Head;          

   if(Head == NULL && Tail == NULL)   //fillter
   {
     return;
   }
   
   do
   {
     cout<<"|"<<temp->data<<"|->";
     temp = temp->next;
   }while(temp != Head);              //Head =  temp->next

   cout<<endl;
}


////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Count
//  Description   :  Used to Count elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCLL<T>::Count()        
{
  int iCnt = 0;
  node <T> * temp = Head;

  if(Head == NULL && Tail == NULL)   //fillter
  {
    return FALSE;
  }
  do
  {
    iCnt++;
    temp = temp->next;
  }while(temp != Head);

  return iCnt;
}          

template<class T>
Doubly_linkedList<T>:: Doubly_linkedList()
{
    Head = NULL;
}

template<class T>
Doubly_linkedList<T> :: ~Doubly_linkedList()
{
    dnode <T>*temp = Head;

    if(Head != NULL)
    {
        while(Head !=NULL)
        {
            Head = Head->next;
            delete temp;
            temp = Head;
        }
    }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertFirst
//  Description   :  Used to insert at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Doubly_linkedList<T>::InsertFirst(T no)
{
    dnode<T> * newn = NULL;

    newn = new dnode<T>;
    if(newn == NULL)
    {
        return FALSE;
    }

    newn->next = NULL;
    newn->prev = NULL;
    newn->data = no;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        Head->prev = newn;
        newn->next = Head;
        Head = newn;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertLast
//  Description   :  Used to insert at last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Doubly_linkedList<T>::InsertLast(T no)
{
    dnode <T> * newn = NULL;
    dnode <T> * temp = Head;

    newn = new dnode <T>;

    if(newn == NULL)
    {
        return FALSE;
    }

    newn->next = NULL;
    newn->prev = NULL;
    newn->data =- no;
    
    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    return TRUE;
    
}


////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertAtPosition
//  Description   :  Used to Insert At Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Doubly_linkedList <T>::InsertAtPosition(T no ,T pos)
{
    if((Head == NULL) || (pos > Count()+1) || (pos <= 0))
    {
        return FALSE;
    }

    if(pos == 1)
    {
        return(InsertFirst(no));
    }
    else if(pos == (Count()) + 1)
    {
        return(InsertLast(no));
    }
    else
    {
        dnode <T> * newn = NULL;
        dnode <T> * temp = Head;

        newn = new dnode <T>;
        if(newn == NULL)
        {
            return FALSE;
        }

        newn->next = NULL;
        newn->prev = NULL;
        newn->data = no;

        for(int i = 1; i<=(pos-2); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;

        newn->prev = temp;
        temp->next = newn;
    }

    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteFirst
//  Description   :  Used to Delete at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Doubly_linkedList<T>::DeleteFirst()
{
    dnode<T> * temp = Head;

    if(Head == NULL)
    {
        return FALSE;
    }
    else
    {
        Head = Head -> next;
        Head->prev = NULL;

        delete temp;
    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteLast
//  Description   :  Used to Delete at Last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Doubly_linkedList<T>:: DeleteLast()
{
    if(Head == NULL)
    {
        return FALSE;
    }
    else if(Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        dnode<T> * temp = Head;

        while((temp->next) != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }

    return TRUE;
    
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteAtPosition
//  Description   :  Used to Delete at Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  BOOL
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
BOOL Doubly_linkedList<T>::DeleteAtPosition(T pos)
{
    if((Head == NULL) || (pos > Count()) || (pos <= 0))
    {
        return FALSE;
    }
    else if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == (Count()))
    {
        DeleteLast();
    }
    else
    {
        dnode <T> * temp = Head;

        for(int i = 1; i<= (pos-2); i++)
        {
            temp = temp ->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

    }
    return TRUE;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Display
//  Description   :  Used to display elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void Doubly_linkedList<T>:: Display()
{
    dnode <T>* temp = Head;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"-->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Count
//  Description   :  Used to Count elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int Doubly_linkedList<T>::Count()
{
    dnode <T> * temp = Head;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}


template<class T>
DoublyCLL<T>::DoublyCLL()      
{
    Head = NULL;
    Tail = NULL;
    CountNode = 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertFirst
//  Description   :  Used to insert at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertFirst(T iNo)  
{
  dnode <T> * newn = NULL;
  newn = new dnode <T>;

  newn->data = iNo;
  newn->next = NULL;
  newn->prev = NULL;

  if(CountNode == 0)
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

  Head->prev = Tail;
  Tail->next = Head;

  CountNode++;

}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertLast
//  Description   :  Used to insert at last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertLast(T iNo)
{
  dnode <T> * newn = NULL;
  newn = new dnode <T>;

  newn->data = iNo;
  newn->next = NULL;
  newn->prev = NULL;

  if(CountNode == 0)
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
  CountNode++;
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  InsertAtPosition
//  Description   :  Used to Insert At Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::InsertAtPos(T iNo,T iPos)
{
   if((iPos < 1) ||(iPos >CountNode+1))
   {
     cout<<"Invalid position\n";
     return;
   }
   
   if(iPos == 1)
   {
     InsertFirst(iNo);
   }
   else if(iPos == CountNode+1)
   {  
     InsertLast(iNo); 
   }
   else
   {
      dnode <T> * newn = NULL;
      newn = new dnode<T>;

      newn->data = iNo;
      newn->next = NULL;
      newn->prev = NULL;

      dnode <T> * temp = Head;

      for(int i = 1; i<iPos-1; i++)       
      {
        temp = temp->next;
      }

      newn ->next = temp ->next;
      temp->next->prev = newn;
      temp->next = newn;
      newn->prev = temp;

      CountNode++;      
   }

}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteFirst
//  Description   :  Used to Delete at first position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(CountNode == 0)
    {
      return;
    }
    else if(CountNode == 1)
    {
      delete Head;
      Head = NULL;
      Tail = NULL;
    }
    else
    {
      Head = Head->next;
      delete Tail->next;
    }

    Tail->next = Head;
    Head->prev = Tail;
    CountNode--;
  
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteLast
//  Description   :  Used to Delete at Last position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::DeleteLast()
{
    if(CountNode == 0)
    {
      return;
    }
    else if(CountNode == 1)
    {
      delete Head;
      Head = NULL;
      Tail = NULL;
    }
    else
    {
      Tail = Tail->prev;
      delete Head->prev;
    }
   
    Tail->next = Head;
    Head->prev = Tail;
    CountNode--;
}
////////////////////////////////////////////////////////////////////////////
//
//  Function name :  DeleteAtPosition
//  Description   :  Used to Delete at Position of Linked List
//  Parameters    :  Addreass of first pointer & data of node
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyCLL<T>::DeleteAtPos(T iPos)
{
  if((iPos < 1) ||(iPos >CountNode))
   {
     cout<<"Invalid position\n";
     return;
   }
   
   if(iPos == 1)
   {
     DeleteFirst();
   }
   else if(iPos == CountNode)
   {  
     DeleteLast(); 
   }
   else
   {
      dnode <T> * temp = Head;
      for(int i = 1; i<iPos-1; i++)       
      {
        temp = temp->next;
      }

      temp->next = temp->next->next;
      delete temp ->next->prev;
      temp->next->prev = temp;

      CountNode--;
   }
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Display
//  Description   :  Used to display elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  void
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>::Display()
{
  int i = 0;
  dnode <T> * temp = Head;   

  for(i= 1; i<= CountNode; i++)    
  {
    cout<<"|"<<temp->data<<"|->";
    temp = temp->next;
  }
  cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////
//
//  Function name :  Count
//  Description   :  Used to Count elements of Linked List
//  Parameters    :  First pointer
//  Return Value  :  int
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T>::Count()
{
  return CountNode;
}


int main(void)
{
     
    Singly_linkedList<float>obj1;
    
    Doubly_linkedList<float>obj2;

    
    SinglyCLL<float>obj3;
    int iRet1 = 0;

    DoublyCLL<float>obj4;
    int iRet2 = 0;
    

    //"This is a Singly Linked list \n";
    cout<<"***************************************************************\n";
    cout<<"                 Singly Linked List                            \n";
    cout<<"***************************************************************\n\n";
  

    cout<<"    >>>>>>>>>> INSERTFIRST <<<<<<<<<<<                       "<<"\n\n";
    obj1.InsertFirst(11.11);
    obj1.InsertFirst(21.21);
    obj1.InsertFirst(51.51);
    obj1.InsertFirst(100.10);
    obj1.Display();
    cout<<"\nThe Total Number of Nodes Are  ==> \t\t "<<obj1.Count()<<"\n\n";
    
    cout<<"            >>>>>>>>> INSERTLAST <<<<<<<<<<<            "<<"\n\n";
    obj1.InsertLast(101.10);
    obj1.InsertLast(111.11);
    obj1.InsertLast(121.12);
    obj1.Display();
    cout<<"\n The Total Number of Nodes Are  ==> \t\t "<<obj1.Count()<<"\n\n";

    cout<<"             >>>>>>>>>INSERTATPOSITION <<<<<<<<<<<       "<<"\n\n";
    obj1.InsertAtPosition(4,65.5);
    obj1.InsertAtPosition(3,55.5);
    obj1.Display();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<obj1.Count()<<"\n\n";

    cout<<"               >>>>>>>> DELETEFIRST<<<<<<<<<<<<               "<<"\n\n";
    obj1.DeleteFirst();
    obj1.Display();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<obj1.Count()<<"\n\n";

   
    cout<<"               >>>>>>>>>>>> DELETEFLAST <<<<<<<<<           "<<"\n\n";
    obj1.DeleteLast();
    obj1.Display();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<obj1.Count()<<"\n\n";

  
    cout<<"              >>>>>>>>>> DELETEATPOSITION <<<<<<<<<<<           "<<"\n\n";
    obj1.DeleteAtPosition(3);
    obj1.Display();
    cout<<"\n The Total Number of Nodes Are  ==> \t \t "<<obj1.Count()<<"\n\n";
    

    // This is  a Doubly Linked list
    cout<<"***************************************************************\n";
    cout<<"                 Doubly Linked List                            \n";
    cout<<"***************************************************************\n\n";
  

    cout<<"         >>>>>>>>>> INSERTFIRST <<<<<<<<<<<                  "<<"\n\n";
    obj2.InsertFirst(22.11);
    obj2.InsertFirst(31.21);
    obj2.InsertFirst(61.51);
    obj2.InsertFirst(200.10);
    obj2.Display();
    cout<<"\nThe Total Number of Nodes Are  ==> \t\t "<<obj2.Count()<<"\n\n";
    
    cout<<"            >>>>>>>>> INSERTLAST <<<<<<<<<<<            "<<"\n\n";
    obj2.InsertLast(301.10);
    obj2.InsertLast(110.11);
    obj2.InsertLast(150.12);
    obj2.Display();
    cout<<"\n The Total Number of Nodes Are  ==> \t\t "<<obj2.Count()<<"\n\n";

    cout<<"             >>>>>>>>>INSERTATPOSITION <<<<<<<<<<<       "<<"\n\n";
    obj2.InsertAtPosition(4,76.5);
    obj2.InsertAtPosition(3,68.5);
    obj2.Display();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<obj2.Count()<<"\n\n";

    cout<<"               >>>>>>>> DELETEFIRST<<<<<<<<<<<<               "<<"\n\n";
    obj2.DeleteFirst();
    obj2.Display();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<obj2.Count()<<"\n\n";

   
    cout<<"               >>>>>>>>>>>> DELETEFLAST <<<<<<<<<           "<<"\n\n";
    obj2.DeleteLast();
    obj2.Display();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<obj2.Count()<<"\n\n";

  
    cout<<"              >>>>>>>>>> DELETEATPOSITION <<<<<<<<<<<           "<<"\n\n";
    obj2.DeleteAtPosition(3);
    obj2.Display();
    cout<<"\n The Total Number of Nodes Are  ==> \t \t "<<obj1.Count()<<"\n\n";

   
    cout<<"***************************************************************\n";
    cout<<"                 Singly Circular Linked List                          \n";
    cout<<"***************************************************************\n\n";
  

    cout<<"         >>>>>>>>>> INSERTFIRST <<<<<<<<<<<                  "<<"\n\n";
    obj3.InsertFirst(50.11);
    obj3.InsertFirst(20.21);
    obj3.InsertFirst(90.51);
    obj3.InsertFirst(100.10);
    obj3.Display();
    iRet1 = obj3.Count();
    cout<<"\nThe Total Number of Nodes Are  ==> \t\t "<<iRet1<<"\n\n";
    
    cout<<"            >>>>>>>>> INSERTLAST <<<<<<<<<<<            "<<"\n\n";
    obj3.InsertLast(205.10);
    obj3.InsertLast(115.11);
    obj3.InsertLast(139.12);
    obj3.Display();
    iRet1 = obj3.Count();
    cout<<"\n The Total Number of Nodes Are  ==> \t\t "<<iRet1<<"\n\n";

    cout<<"             >>>>>>>>>INSERTATPOSITION <<<<<<<<<<<       "<<"\n\n";
    obj3.InsertAtPos(60.7,3);
    obj3.InsertAtPos(70.7,4);
    obj3.Display();
    iRet1 = obj3.Count();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<iRet1<<"\n\n";

    cout<<"               >>>>>>>> DELETEFIRST<<<<<<<<<<<<             "<<"\n\n";
    obj3.DeleteFirst();
    obj3.Display();
    iRet1 = obj3.Count();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<iRet1<<"\n\n";

   
    cout<<"               >>>>>>>>>>>> DELETEFLAST <<<<<<<<<           "<<"\n\n";
    obj3.DeleteLast();
    obj3.Display();
    iRet1 = obj3.Count();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<iRet1<<"\n\n";

  
    cout<<"              >>>>>>>>>> DELETEATPOSITION <<<<<<<<<<<       "<<"\n\n";
    obj3.DeleteAtPos(3);
    obj3.Display();
    iRet1 = obj3.Count();
    cout<<"\n The Total Number of Nodes Are  ==> \t \t "<<iRet1<<"\n\n"; 
    
    
    //DoublyCircular Link List
    cout<<"***************************************************************\n";
    cout<<"                 Doubly Circular Linked List                    \n";
    cout<<"***************************************************************\n\n";
  

    cout<<"         >>>>>>>>>> INSERTFIRST <<<<<<<<<<<                  "<<"\n\n";
    obj4.InsertFirst(40.11);
    obj4.InsertFirst(30.21);
    obj4.InsertFirst(20.51);
    obj4.InsertFirst(10.10);
    obj4.Display();
    iRet2 = obj4.Count();
    cout<<"\nThe Total Number of Nodes Are  ==> \t\t "<<iRet2<<"\n\n";
    
    cout<<"            >>>>>>>>> INSERTLAST <<<<<<<<<<<            "<<"\n\n";
    obj4.InsertLast(15.10);
    obj4.InsertLast(16.11);
    obj4.InsertLast(17.12);
    obj4.Display();
    iRet2 = obj4.Count();
    cout<<"\n The Total Number of Nodes Are  ==> \t\t "<<iRet2<<"\n\n";

    cout<<"             >>>>>>>>>INSERTATPOSITION <<<<<<<<<<<       "<<"\n\n";
    obj4.InsertAtPos(78.7,3);
    obj4.InsertAtPos(77.7,4);
    obj4.Display();
    iRet2 = obj4.Count();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<iRet2<<"\n\n";

    cout<<"               >>>>>>>> DELETEFIRST<<<<<<<<<<<<             "<<"\n\n";
    obj4.DeleteFirst();
    obj4.Display();
    iRet2 = obj4.Count();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<iRet2<<"\n\n";

   
    cout<<"               >>>>>>>>>>>> DELETEFLAST <<<<<<<<<           "<<"\n\n";
    obj4.DeleteLast();
    obj4.Display();
    iRet2 = obj4.Count();
    cout<<"\n\n The Total Number of Nodes Are  ==> \t\t "<<iRet2<<"\n\n";

  
    cout<<"              >>>>>>>>>> DELETEATPOSITION <<<<<<<<<<<       "<<"\n\n";
    obj4.DeleteAtPos(3);
    obj4.Display();
    iRet2 = obj4.Count();
    cout<<"\n The Total Number of Nodes Are  ==> \t \t "<<iRet2<<"\n\n"; 
     
    
 

   

    return(0);
}