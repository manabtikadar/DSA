#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
  int data;
  struct Node *next;
}*first=NULL,*Second=NULL,*third=NULL;

void create(int A[],int n)
{
  int i;
  struct Node *t,*last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data=A[0];
  first->next=NULL;
  last = first;

  for(i=1;i<n;i++)
  {
     t= (struct Node *)malloc(sizeof(struct Node));
     t->data = A[i];
     t->next = NULL;
     last->next = t;
     last = t;
  }
}

void create2(int A[],int n)
{
  int i;
  struct Node *t,*last;
  Second = (struct Node *)malloc(sizeof(struct Node));
  Second->data=A[0];
  Second->next=NULL;
  last = Second;

  for(i=1;i<n;i++)
  {
     t= (struct Node *)malloc(sizeof(struct Node));
     t->data = A[i];
     t->next = NULL;
     last->next = t;
     last = t;
  }
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

void RDisplay(struct Node *p)
{
  if(p!=NULL)
  {
    printf("%d ",p->data);
    RDisplay(p->next);
  }
  //printf("\n");
}

/*void RDisplay1(struct Node *p)
{
  if(p!=NULL)
  {
    
    RDisplay1(p->next);
    printf("%d ",p->data);
  }
  
}*/

int count(struct Node *p)
{
  int c=0;
  while(p != NULL)
  {
    c++;
    p=p->next;
  }
  return c;
}

int Rcount(struct Node *p)
{
  if(p == NULL)
    return 0;
  else 
    return Rcount(p->next)+1;  
}

int Add(struct Node *p)
{
  int sum=0;
  while(p)
  {
    sum = sum + p->data;
    p=p->next;
  }
  return sum;
}

int Radd(struct Node *p)
{
  if(p == NULL)
     return 0;
  else 
     return Radd(p->next)+p->data;   
}

int Max(struct Node *p)
{
  int m = INT32_MIN;//(-32768)
  while(p != NULL)
  {
    if(p->data>m)
      m = p->data;
    p=p->next;   
  }
  return m;
}

int Rmax(struct Node *p)
{
  int x=0;
  if(p==0)
     return INT32_MIN;
  x=Rmax(p->next);
  return x>p->data?x:p->data;   
}

struct Node * LSearch(struct Node *p,int key)
{ struct Node *q=NULL;
  
  while(p!=NULL)
  {
    if(p->data==key)
    { 
      q->next=p->next;
      p->next=first;
      first=p;
      return p;
    }
    q=p;
    p = p->next;  
  }
  return NULL;

}

struct Node * Rlsearch(struct Node *p,int key)
{
  if(p==NULL)
    return NULL;
  else if (p->data=key)
    return p;
  else 
    return Rlsearch(p->next,key);    
}

void Insert(struct Node *p,int index,int x)
{
  struct Node *t;

  if(index<0||index>count(p))
    return;
  t=(struct Node *)malloc(sizeof(struct Node));
  t->data=x;


  if(index==0)
  {  t->next=first;
    first=t;
  }
  else
  {
    for(int i=0;i<index-1;i++)
        p=p->next;
    t->next=p->next;
    p->next=t;    
  }


}

void SortedInsert(struct Node *p,int x)
{
  struct Node *t,*q=NULL;
  t=(struct Node *)malloc(sizeof(struct Node));
  t->data=x;
  t->next=NULL;

  if(first==NULL)
     first=t;
  else   
  {
    while(p && p->data<x)
   {
    q=p;
    p=p->next;
   }
   if(p==first)
   {
     t->next=first;
     first=t;
   }
   else
   {
    t->next=q->next;
    q->next=t;
   }

  }
 
}

int Delete(struct Node *p, int pos)
{
  struct Node *q=NULL;
  int x=-1,i;
  if(pos<1||pos>count(p))
  {
    return x;
  }


  if(pos==1)
  {
   x=first->data;
   first=first->next;
   delete p;
  }
  else
  {
    for(i=0;i<pos-1&&p;i++)
    {
      q=p;
      p=p->next;
    }
    if(p)
    {
      q->next=p->next;
      x=p->data;
      delete p;//c++
      // free(p) in c language
    }
  }
  return x;
}


int isSorted(struct Node *p)
{
  int x=INT32_MIN;
  while(p != NULL)
  {
    if(p->data<x)
    {
      return false;
    }
    x=p->data;
    p=p->next;

  }
  return true;
}

void RemoveDuplicates(struct Node *p)
{
  struct Node *q=p->next;

  while(q!=NULL)
  {
   if(p->data!=q->data)
   {
    p=q;
    q=q->next;
   }
   else{
    p->next=q->next;
    delete q;
    q = p->next;
   } 
  }

}

void Reverse1(struct Node *p)
{
  int *A,i=0;
  struct Node *q=p;
  A=(int *)malloc(count(first)*sizeof(int));

  while(q!=NULL)
  {
    A[i]=q->data;
    q=q->next;
    i++;
  }
  q=p;
  i--;
  while(q!=NULL)
  {
    q->data=A[i];
    q=q->next;
    i--;
  }
}

void Reverse2(struct Node *p)
{
  struct Node *q=NULL,*r=NULL;

  while(p!=NULL)
  {
    r=q;
    q=p;
    p=p->next;
    q->next=r;
  }
  first=q;
}

void Reverse3(struct Node *q,struct Node *p)
{
  if(p)
  {
    Reverse3(p,p->next);
    p->next=q;
  }
  else
     first = q;
}

void Concat(struct Node *p,struct Node *q)
{
  third=p;

  while(p->next!=NULL)
  {
    p=p->next;
  }
  p->next=q;
}

void Merge(struct Node *p,struct Node *q)
{
  struct Node *last;
  if(p->data < q->data)
  {
    third=last=p;
    p=p->next;
    third->next=NULL;
  }
  else{
    third=last=q;
    q=q->next;
    third->next=NULL;
  }

  while(p && q)
  {
    if(p->data<q->data)
    {
      last->next=p;
      last=p;
      p=p->next;
      last->next=NULL;
    }
    else{
      last->next=q;
      last=q;
      q=q->next;
      last->next=NULL;
    }
    
    }
    if(p != NULL)
       last->next=p;
    else
       last->next=q;   
  }

int isLoop(struct Node *p)
{
  struct Node *q=p;
  do
  {
    p=p->next;
    q=q->next;
    q=(q!=NULL)?q->next:NULL;

  } while (p&&q&&p!=q);

  return (p==q)?1:0;
  
}



int main()
{ 
  struct Node *t1,*t2;
  int A[]={10,20,30,40,50};
  int B[]={5,15,25,35,45};
  //first = (struct Node *)malloc(sizeof(struct Node));
  create(A,5);
  
  t1=first->next->next;
  t2=first->next->next->next->next;
  t2->next=t1;
  
  /*RDisplay(first);
  //RDisplay1(first);
  printf("\n%d",count(first));
  printf("\n%d",Rcount(first));
  printf("\n%d",Add(first));
  printf("\n%d",Radd(first));
  printf("\n%d",Max(first));
  printf("\n%d",Rmax(first));
  //printf("\n%d",LSearch(first,10));
  temp=LSearch(first,10);
  temp=LSearch(first,15);
  if(temp)
     printf("\nkey is Found %d\n",temp->data);
  else 
     printf("Key is not found");
  Display(first); */   

  // Insert(first,0,10);
  // Insert(first,3,15); 
  // Display(first); 
  // SortedInsert(first,35);
  // Display(first);
  // printf("\n%d\n",Delete(first,3));
  // Display(first);
  // printf("\n%d\n",isSorted(first));
  //RemoveDuplicates(first);
  //Display(first);

  // Reverse3(NULL,first);
  // Display(first);
  // Merge(first,Second);
  // Display(third);
  printf("%d",isLoop(first));
  
  return 0;
}