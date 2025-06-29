#include<iostream>

using namespace std;

class Node
{
public:
  int data;
  Node *next;

};
class LinkedList
{
private:
  Node *first;
public:
  LinkedList(){first=NULL;}
  LinkedList(int A[],int n);
  ~LinkedList();

  void Dispaly();
  void Insert(int index,int x);
  int Delete(int index);
  int Length();
};

LinkedList::LinkedList(int A[],int n)
{
  int i=0;
  struct Node *t,*last;
  first = new Node;
  first->data=A[0];
  first->next=NULL;
  last = first;

  for(i=1;i<n;i++)
  {
     t= new Node;
     t->data = A[i];
     t->next = NULL;
     last->next = t;
     last = t;
  }
}

LinkedList::~LinkedList()
{
  Node *p=first;
  while(first)
  {
    first=first->next;
    delete p;
    p=first;
  }
}

void LinkedList::Dispaly()
{ Node *p=first;
  while(p!=NULL)
  {
     printf("%d ",p->data);
     p=p->next;
  }
  printf("\n");
}

int LinkedList::Length()
{ 
  Node *p=first;
  int len=0;
  while(p != NULL)
  {
    len++;
    p=p->next;
  }
  return len;
}

void LinkedList::Insert(int index,int x)
{
  struct Node *t,*p=first;

  if(index<0||index>Length())
    return;
  t=new Node;
  t->data=x;


  if(index==0)
  {  t->next=first;
    first=t;
  }
  else
  {
    for(int i=0;i<index-1;i++)
        p=p->next;
    t->next=p->next;
    p->next=t;    
  }
}

int LinkedList::Delete(int index)
{ 
  Node *p=first;
  struct Node *q=NULL;
  int x=-1,i;
  if(index<1||index>Length())
  {
    return x;
  }


  if(index==1)
  {
   x=first->data;
   first=first->next;
   delete p;
  }
  else
  {
    for(i=0;i<index-1&&p;i++)
    {
      q=p;
      p=p->next;
    }
    if(p)
    {
      q->next=p->next;
      x=p->data;
      delete p;//c++
      // free(p) in c language
    }
  }
  return x;
}

int main()
{ 
  int A[]={1,2,3,4,5};
  LinkedList l(A,5);
  
  //cout<<l.Delete(1)<<endl;
  l.Insert(0,8);
  l.Dispaly();
  return 0;
}