#include<stdio.h>
#define Queue_h
#ifdef Queue_h

class Node
{
  public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
 private: 
   int size;
   int front;
   int rear;
   Node **Q;

 public:
    Queue(){front=rear=-1;size=10;Q=new Node*[size];}
    Queue(int size){front=rear=-1;this->size=size;Q=new Node*[this->size];}
    void enqueue(Node *x);
    Node* dequeue();
    void Display();
    int isEmpty(){return front==rear;}
};

void Queue::enqueue(struct Node *x)
{
  if(rear==size-1)
    printf("Queue is Full\n");
  else{
    rear++;
    Q[rear]=x;
  }  
}

Node* Queue::dequeue()
{
  Node* z=NULL;

  if(front==rear)
     printf("Queue is Empty\n");
  else
  {
    front++;
    z=Q[front];
  } 
  return z;  
}

void Queue::Display()
{ int i;
  for(i=front+1;i<=rear;i++)
  {
    printf("%d ",Q[i]);
  }
  printf("\n");
}

#endif