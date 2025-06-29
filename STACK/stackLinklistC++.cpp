#include<stdio.h>
#include<iostream>

using namespace std;
class Node
{ 
  public:
  int data;
  Node *next;
};
class Stack
{
  private:
     Node *top;
  public:
     Stack(){top=NULL;}
     void push(int x);
     int pop();
     void Display();
     ~Stack(){  };

};

int Stack::pop()
{
 struct Node *t;
 int x=-1; 
 if(top==NULL)
    cout<<"stack is empty"<<endl;
 else
 {
  t=top;
  top=top->next;
  x=t->data;
  delete t;
 }
 return x;
}

void Stack::push(int x)
{
  struct Node *t;
  t=(struct Node *)malloc(sizeof(struct Node));
 
  if(t==NULL)
    cout<<"Stack is Full"<<endl;
  else 
  {
   t->data=x;
   t->next=top;
   top=t;
  }    
}

void Stack::Display()
{
  struct Node *p;
  p=top;
  while(p!=NULL)
  {
    cout<<p->data<<" ";
    p=p->next;
  }
  cout<<endl;
}
int main()
{
  Stack stk;
  stk.push(10);
  stk.push(20);
  stk.push(30);

  stk.Display();
  cout<<stk.pop()<<endl;
  return 0;
}