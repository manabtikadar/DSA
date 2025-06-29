#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

struct Terms
{
  int coeff;
  int exp;
};

struct Poly
{
  int n; // number of terms 
  struct Terms *terms; //structure type array of terms
};

void create(struct Poly *P)
{
  printf("Enter the number of non-zero Elements: ");
  scanf("%d",&P->n);

  P->terms = (struct Terms*)malloc(P->n*sizeof(struct Terms));

  printf("Enter Terms:\n");
  for(int i=0;i<P->n;i++)
  {
    scanf("%d%d",&P->terms[i].coeff,&P->terms[i].exp);
  }
}

void Display(struct Poly p)
{
  int i;
  printf("P(x)=");
  for(i=0;i<p.n;i++)
  { if(i != p.n-1)
    printf("%dx^%d+",p.terms[i].coeff,p.terms[i].exp);
    else printf("%dx^%d",p.terms[i].coeff,p.terms[i].exp);
  }
  printf("\n");
}

struct Poly *add(struct Poly *p1 ,struct Poly *p2)
{
  struct Poly *sum;
  sum = (struct Poly *)malloc(sizeof(struct Poly));

  sum->terms=(struct Terms *)malloc((p1->n+p2->n)*sizeof(struct Terms));

  int i=0,j=0,k=0;
  while(i<p1->n&&j<p2->n)
  {
    if(p1->terms[i].exp>p2->terms[j].exp)
       sum->terms[k++]=p1->terms[i++];
    else if(p1->terms[i].exp<p2->terms[j].exp)
       sum->terms[k++]=p2->terms[j++];
    else 
    {
       sum->terms[k]=p1->terms[i++];
       sum->terms[k++].coeff += p2->terms[j++].coeff;
    }      
  }
  for(;i<p1->n;i++)sum->terms[k++]=p1->terms[i++];
  for(;j<p2->n;j++)sum->terms[k++]=p2->terms[j++];
  sum->n=k;
  return sum;
}


int main(){
  struct Poly p1;
  struct Poly p2;
  create(&p1);
  create(&p2);
  
  struct Poly *p3;
  p3 = add(&p1,&p2);

  Display(p1);
  Display(*p3);
  return 0;
}