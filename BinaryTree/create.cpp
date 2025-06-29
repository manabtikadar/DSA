#include<stdio.h>
#include<stdlib.h>
//#include "Queue.h"
#include "Stack.h"

using namespace std;

struct Node *root = NULL;

void Treecreate()
{
  struct Node *p,*t;
  int x;
  struct Queue q;
  create(&q,100);
  printf("Enter Root Value:");
  scanf("%d",&x);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data=x;
  root->lchild=root->rchild=NULL;
  enqueue(&q,root);
  while(!isEmpty(q))
  {
    p=dequeue(&q);
    printf("Enter left child of %d :", p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
      t=(struct Node *)malloc(sizeof(struct Node));
      t->data=x;
      t->lchild=t->rchild=NULL;
      p->lchild=t;
      enqueue(&q,t);
    }

    printf("Enter right child of %d :", p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
      t=(struct Node *)malloc(sizeof(struct Node));
      t->data=x;
      t->lchild=t->rchild=NULL;
      p->rchild=t;
      enqueue(&q,t);
    }
  }
}

void preorder(struct Node *p)
{
  if(p)
  {
    printf("%d ",p->data);
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

void Ipreorder(struct Node *p)
{
  struct Stack stk;
  Stackcreate(&stk,100);
  while(p!=NULL || !isEmptyStack(stk))
  {
    if(p)
    {
      printf("%d ",p->data);
      push(&stk,p);
      p=p->lchild;
    }
    else
    {
      p=pop(&stk);
      p=p->rchild;
    }
  }
}



void inorder(struct Node *p)
{
  if(p)
  { 
    inorder(p->lchild);
    printf("%d ",p->data);
    inorder(p->rchild);
  }
}

void Iinorder(struct Node *p)
{
  struct Stack stk;
  Stackcreate(&stk,100);
  while(p!=NULL || !isEmptyStack(stk))
  {
    if(p)
    {
      
      push(&stk,p);
      p=p->lchild;
    }
    else
    {
      p=pop(&stk);
      printf("%d ",p->data);
      p=p->rchild;
    }
  }
}

void postorder(struct Node *p)
{
  if(p)
  {
   
    postorder(p->lchild);
    postorder(p->rchild);
    printf("%d ",p->data);
  }
}

void Ipostorder(struct Node *p)
{ 
  struct Stack stk;
  long int temp;
  Stackcreate(&stk,100);
  while(p!=NULL || !isEmptyStack(stk))
  {
    if(p!=NULL)
    {
      push(&stk,p);
      p=p->lchild;
    }
    else
    {
      temp=(long int)pop(&stk);
      if(temp>0)
      {
        push(&stk,(Node *)(-temp));
        p=((Node *)temp)->rchild;
      }
      else{
       p = (Node *)(-temp); 
       printf("%d ",p->data);
       p=NULL;
      }
    }
  }
}


int main()
{ 
  Treecreate();
  //Ipreorder(root);
  printf("\n");
  //Iinorder(root);
  printf("\n");
  Ipostorder(root);
  return 0;
}