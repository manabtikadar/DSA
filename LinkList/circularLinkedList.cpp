#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node
{
  int data;
  struct Node *next;//self refferential Pointer
}*Head;

void create(int A[],int n)
{
  struct Node *t,*last;
  int i=0;
  Head=(struct Node *)malloc(sizeof(struct Node));
  Head->data=A[0];
  Head->next=Head;
  last=Head;
  for(i=1;i<n;i++)
  {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next=last->next;
    last->next=t;
    last=t;
  }
}

void Display(struct Node *h)
{
  do
  {
    printf("%d ",h->data);
    h=h->next;
  } while (h!=Head);
  printf("\n");
}

void RDisplay(struct Node *h)
{
  static int flag = 0;
  if(h!=Head || flag==0)
  {
    flag=1;
    printf("%d ",h->data);
    RDisplay(h->next);
  }
  flag = 0;
}
int Length(struct Node *t)
{
  int len = 0;
  do
  {
    len++;
    t=t->next;
  } while (t!=Head);
  return len;
}

void Insert(struct Node *p,int pos,int x)
{
  Node *t;
  int i;
  if(pos<0||pos>Length(Head))
     return;
  if(pos==0)
  {
    t=new Node;
    t->data=x;
    if(Head==NULL)
    {
      Head=t;
      Head->next=Head;
    }
    else
    {
     
     while(p->next!=Head)
          p=p->next;
     p->next=t;
     t->next=Head;
     Head=t;     
    }
  }
  else
  {
    t=new Node;
    t->data=x;
    for(i=0;i<pos-1;i++)
       p=p->next;
    t->next=p->next;
    p->next=t;   
  }
} 

int Delete(struct Node *p,int index)
{
  struct Node *q;
  int x;
  if(index<0||index>Length(Head))
     return -1;
  if(index==1)
  {//p=Head;
   while(p->next!= NULL)
        p=p->next;
   x=Head->data;
   if(p=Head)
   {
     delete Head;
     Head=NULL;
   }
   else
   {
    p->next=Head->next;
    delete Head;
    Head=p->next;
   }
  }
  else
  {
    //p=Head;
    for(int i=0;i<index-2;i++)
       p=p->next;
    q=p->next;
    p->next=q->next;
    x=q->data;
    delete q;

  }
  return x;
}


int main(){
  int A[]={2,3,4,5,6};
  create(A,5);
  
  
  Insert(Head,0,8);
  Delete(Head,3);
  Display(Head);

  return 0;
}