#include<stdio.h>
#include<iostream>

using namespace std;

struct Queues
{
  int size;
  int front;
  int rear;
  int *Q;

};

void create(struct Queues *q,int size)
{
  q->size=size;
  q->front=0;
  q->rear=0;
  q->Q=(int *)malloc(size*sizeof(int));
}

void enqueue(struct Queues *q ,int x)
{
  if((q->rear+1)%q->size==q->front)
    printf("Queue is Full\n");
  else{
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
  }  
}

int dequeue(struct Queues *q)
{
  int z=-1;

  if(q->front==q->rear)
     printf("Queue is Empty\n");
  else
  {
    q->front=(q->front+1)%q->size;
    z=q->Q[q->front];
  } 
  return z;  
}

void Display(struct Queues q)
{ int i=q.front+1;
  do
  { printf("%d ",q.Q[i]);
    i=(i+1)%q.size;
  }while(i!=(q.rear+1)%q.size);
  printf("\n");
}
int main()
{ 
  struct Queues q;
  create (&q,5);

  enqueue(&q,10);
  enqueue(&q,20);
  enqueue(&q,30);
  enqueue(&q,40);
  enqueue(&q,50);
  enqueue(&q,60);
  //enqueue(&q,40);
  
  Display(q);
  dequeue(&q);
  Display(q);
  return 0;
}