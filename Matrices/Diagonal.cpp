#include<iostream>
#include<stdio.h>

using namespace std;

struct Matrix
{
  int A[10];
  int n;
};

void Set(struct Matrix *m,int i,int j,int x){
  if (i==j){
    m->A[i-1]=x;
  }
}

int get(struct Matrix *m,int i,int j){
  if(i==j)
    return m->A[i-1];
  else 
    return 0;
}

void Display(struct Matrix m){
  int k,l;
  for(k=0;k<m.n;k++){
    for(l=0;l<m.n;l++){
        if(k==l)
           printf("%d ",m.A[k]);
        else
           printf("0 ");   
    }
    printf("\n");
  }
}

int main(){
  struct Matrix m;
  m.n=4;

  Set(&m,1,1,5);
  Set(&m,2,2,8);
  Set(&m,3,3,9);
  Set(&m,4,4,12);
  Display(m);

  return 0;
}

