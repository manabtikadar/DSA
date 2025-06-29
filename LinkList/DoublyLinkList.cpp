#include<iostream>
#include<stdio.h>

using namespace std;

struct Node
{
  struct Node *prev;
  int data;
  struct Node *next;

}*first;

void create(int A[],int n)
{
 struct Node *t,*last;
 first=(struct Node *)malloc(sizeof(struct Node));
 first->prev=NULL;
 first->data=A[0];
 first->next=NULL;
 last=first;
 for(int i=1;i<n;i++)
 {
  t=(struct Node *)malloc(sizeof(struct Node));
  //p->next=t;
  t->data=A[i];
  t->prev=last;
  t->next=last->next;//t->next=NULL;
  last->next=t;
  last=t;
 }
}

void ReverseDisplay(struct Node *p)
{
  
  while(p->next!=NULL)
  {
     
     p=p->next;
  }

  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->prev;
  }
  printf("\n");
}

void Display(struct Node *p)
{
  while(p!=NULL)
  {
     printf("%d ",p->data);
     p=p->next;
  }
  printf("\n");
}

int Length(struct Node *p)
{
  int len=0;

  while(p)
  {
    len++;
    p=p->next;

  }
  return len;
}

void Insert(int pos, int x)
{
  struct Node *p=first,*t;
  if(pos<0||pos>Length(first))
    return ;

  if(pos==0)
  {
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->prev=NULL;
    t->next=first;
    first->prev=t;
    first=t;
  }
  else{
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    for(int i=0; i<pos-1;i++)
    {
      p=p->next;
    }
    t->next=p->next;
    t->prev=p;
    if(p->next)
       p->next->prev=t;
    p->next=t;

  }  
}

int Delete(int pos)
{
  struct Node *p;
  if(pos<1||pos>Length(first))
     return -1;
  int x;
  if(pos==1)
  { 
    p=first;
    first=first->next;
    x=p->data;
    delete p;
    if(first)
       first->prev=NULL;
  }
  else
  {
    p=first;
    for(int i=0;i<pos-1;i++)
        p=p->next;
    p->prev->next=p->next;
    if(p->next)
      p->next->prev=p->prev;

    x=p->data;
    delete p;
  }   
}
void Reverse(struct Node *p)
{
  struct Node *temp;

  while(p!=NULL)
  {
    temp=p->next;
    p->next=p->prev;
    p->prev=temp;

    p=p->prev;
    if(p!=NULL && p->next==NULL)
       first=p;
  }
}

int main(){
  int A[]={1,2,3,4,5};
  create(A,5);
  // Insert(4,8);
  // printf("Length is :%d\n",Length(first));
  // Delete(1);
  Reverse(first);
  Display(first);
  //ReverseDisplay(first);
  return 0;
}