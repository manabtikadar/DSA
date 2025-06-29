#include<stdio.h>
#include<iostream>

/*struct Queues
{
  int size;
  int front;
  int rear;
  int *Q;

};

void create(struct Queues *q,int size)
{
  q->size=size;
  q->front=-1;
  q->rear=-1;
  q->Q=(int *)malloc(size*sizeof(int));
}

void enqueue(struct Queues *q ,int x)
{
  if(q->rear==q->size-1)
    printf("Queue is Full\n");
  else{
    q->rear++;
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
    q->front++;
    z=q->Q[q->front];
  } 
  return z;  
}

void Display(struct Queues q)
{ int i;
  for(i=q.front+1;i<=q.rear;i++)
  {
    printf("%d ",q.Q[i]);
  }
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
  
  Display(q);
  dequeue(&q);
  Display(q);
  return 0;
}*/

class Queues
{
 private: 
   int size;
   int front;
   int rear;
   int *Q;

 public:
    Queues(){front=rear=-1;size=10;Q=new int[size];}
    Queues(int size){front=rear=-1;this->size=size;Q=new int[size];}
    void enqueue(int x);
    int dequeue();
    void Display();
};

// void create(struct Queues *q,int size)
// {
//   q->size=size;
//   q->front=-1;
//   q->rear=-1;
//   q->Q=(int *)malloc(size*sizeof(int));
// }

void Queues::enqueue(int x)
{
  if(rear==size-1)
    printf("Queue is Full\n");
  else{
    rear++;
    Q[rear]=x;
  }  
}

int Queues::dequeue()
{
  int z=-1;

  if(front==rear)
     printf("Queue is Empty\n");
  else
  {
    front++;
    z=Q[front];
  } 
  return z;  
}

void Queues::Display()
{ int i;
  for(i=front+1;i<=rear;i++)
  {
    printf("%d ",Q[i]);
  }
  printf("\n");
}
int main()
{ 
  Queues q(3);
  //create (&q,5);

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  
  q.Display();
  q.dequeue();
  q.Display();
  return 0;
}