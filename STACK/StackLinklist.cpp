#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

struct Node 
{
  char data;
  struct Node *next;
}*top;

void push(char x)
{
 struct Node *t;
 t=(struct Node *)malloc(sizeof(struct Node));
 
 if(t==NULL)
    printf("Stack is Full\n");
 else 
 {
  t->data=x;
  t->next=top;
  top=t;
 }    
}

char pop()
{
 struct Node *t;
 //char x=; 
 char x='\0';
 if(top==NULL)
    printf("stack is empty\n");
 else
 {
  t=top;
  top=top->next;
  x=t->data;
  delete t;
 }
 return x;
}

// int isEmpty(struct Node *st)
// {
//   if(st->next==NULL)
//     return 1;
//   return 0;  
// }

int stackTop(struct Node *st)
{
  if(st != NULL)
     return st->data;
  return -1;   
}

void Display()
{
  struct Node *p;
  p=top;
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->next;
  }
  printf("\n");
}

int pre(char x)
{
  if(x=='+'||x=='-')
     return 1;
  else if(x=='*'||x=='/')
     return 2;
  return 0;      
}

int isOperand(char x)
{
  if(x == '+' || x == '-' || x == '*' || x == '/')
    return 0;
  else
    return 1;
}

char *InToPost(char *infix)
{ 
  int i=0,j=0;
  char *postfix;
  int len=strlen(infix);
  postfix=(char *)malloc((len+2)*sizeof(char));

  while(infix[i]!='\0')
  {
    if(isOperand(infix[i]))
      postfix[j++]=infix[i++];
    else
    {
      if(pre(infix[i])>pre(top->data))
        push(infix[i++]);
        
      else
        postfix[j++]=pop();
    }
  }
  while(top!=NULL)
  {
      postfix[j++]==pop();
  }  
  postfix[j]='\0';

  return postfix;
}

int main()
{ 
  // push(10);
  // push(20);
  // push(30);
  // push(40);
  // push(50);
  
  // Display();
  // printf("%d",pop());
  //char A[10]="a+b*c-d/e";
  char *infix = "a+b*c-d/e";
  push('#');


  char *postfix=InToPost(infix);

  int i=0;

  while(postfix[i]!='\0')
  {
    printf("%c ",postfix[i]);
    i++;
  }
  
  return 0;
}