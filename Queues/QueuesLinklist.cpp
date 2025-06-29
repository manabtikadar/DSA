#include<stdio.h>
#include<iostream>

using namespace std;

struct Node
{
  int data;
  struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
  struct Node *t= (struct Node *)malloc(sizeof(struct Node));
  if(t==NULL)
    printf("Queue is Full..\n");
  else
  {
    t->data=x;
    t->next=NULL;
    if(front==NULL)
       front=rear=t;
    else
    {
     rear->next=t;
     rear=t;
    }   
  }  

}

int dequeue()
{
  int x=-1;
  struct Node *p;
  if(front==NULL)
    printf("Queue is Empty\n");
  else
  {
    p=front;
    front=front->next;
    x=p->data;
    delete (p);
    if(front==NULL)
       rear=NULL;
      
  }  
}

void Display()
{
  struct Node *p;
  p=front;
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->next;
  }
  printf("\n");
}


int main()
{ 
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  
  Display();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  printf("%d %d\n",front,rear);
  Display();
  dequeue();
  //Display();
  printf("%d %d\n",front,rear);
  //Display();
  return 0;
}