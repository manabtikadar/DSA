#define Queue_h
#ifdef Queue_h



struct Node
{
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

struct Queue 
{
  int size ;
  int front;
  int rear;
  Node **Q;
};

void create(struct Queue *q, int size)
{
  q->size=size;
  q->front=0;
  q->rear =0;
  q->Q =(Node **)malloc(q->size*sizeof(Node *)); 

}

void enqueue(struct Queue *q,Node *x)
{
  if((q->rear+1)%q->size==q->front)
  {
    printf("Queue is FULL!..");
  }
  else
  {
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
  }
}

Node *dequeue(struct Queue *q)
{
  Node *z=NULL;
  if(q->front==q->rear)
  {
    printf("Queue is Empty!...");
  }
  else
  {
    q->front=(q->front+1)%q->size;
    z=q->Q[q->front];
  }
  return z;
}

int isEmpty(struct Queue q)
{
  return q.front==q.rear;
}

#endif