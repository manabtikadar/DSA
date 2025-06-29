#include<stdio.h>
#include<iostream>
#include"Queue1.h"

class Tree
{
private:
  Node *root;  
public:
  Tree(){root=NULL;}
  void CreateTree();
  void Preorder(){Preorder(root);}//dummy function
  void Preorder(Node *p);
  void Postorder(){Postorder(root);}
  void Postorder(Node *p);
  void Inorder(){Inorder(root);}
  void Inorder(Node *p);
  void Levelorder(){Levelorder(root);}
  void Levelorder(Node *p);
  int Height(Node *p);
};

void Tree::CreateTree()
{
  Node *p,*t;
  int x;
  Queue q(100);
  printf("Enter Root Value:");
  scanf("%d",&x);
  root = new Node;
  root->data=x;
  root->lchild=root->rchild=NULL;
  q.enqueue(root);
  while(!q.isEmpty())
  {
    p=q.dequeue();
    printf("Enter left child of %d :", p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
      t=new Node; 
      t->data=x;
      t->lchild=t->rchild=NULL;
      p->lchild=t;
      q.enqueue(t);
    }

    printf("Enter right child of %d :", p->data);
    scanf("%d",&x);
    if(x!=-1)
    {
      t=new Node;
      t->data=x;
      t->lchild=t->rchild=NULL;
      p->rchild=t;
      q.enqueue(t);
    }
  }
}

void Tree::Preorder(Node *p)
{
  if(p)
  {
    printf("%d ",p->data);
    Preorder(p->lchild);
    Preorder(p->rchild);
  }
}

void Tree::Inorder(Node *p)
{
  if(p)
  { 
    Inorder(p->lchild);
    printf("%d ",p->data);
    Inorder(p->rchild);
  }
}

void Tree::Postorder(Node *p)
{
  if(p)
  {
   
    Postorder(p->lchild);
    Postorder(p->rchild);
    printf("%d ",p->data);
  }
}

void Tree::Levelorder(Node *root)
{
  Queue q1(100);

  printf("%d ",root->data);
  q1.enqueue(root);

  while(!q1.isEmpty())
  {
    root=q1.dequeue();
    if(root->lchild)
    {
      printf("%d ",root->lchild->data);
      q1.enqueue(root->lchild);
    }
    if(root->rchild)
    {
      printf("%d ",root->rchild->data);
      q1.enqueue(root->rchild);
    }
  }

}

int Tree::Height(Node *root)
{
  int x=0;int y=0;
  if(root==NULL)
     return 0;
  x=Height(root->lchild);
  y=Height(root->rchild);
  if(x>y)
    return x+1;
  else 
    return y+1;     
}

int main()
{
  Tree t;
  t.CreateTree();
  t.Preorder();
  printf("\n");
  t.Postorder();
  printf("\n");
  t.Inorder();
  printf("\n");
  t.Levelorder();
  
  return 0;
}