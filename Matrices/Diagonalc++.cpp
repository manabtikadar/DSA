#include<iostream>
#include<stdio.h>

using namespace std;

class Diagonal
{ private:
  int *A;
  public:
  int n;

  public:
  //constructor
  Diagonal(int value){
    n = value;
    A = new int[n];
  }
  void Set(int i, int j,int x);
  int get(int i, int j);
  void Display();
  ~Diagonal(){
    delete []A;
  }
};

void Diagonal::Set(int i,int j,int x){
  if (i==j){
    A[i-1]=x;
  }
}

int Diagonal::get(int i,int j){
  if(i==j)
    return A[i-1];
  else 
    return 0;
}

void Diagonal::Display(){
  int k,l;
  for(k=0;k<n;k++){
    for(l=0;l<n;l++){
        if(k==l)
           printf("%d ",A[k]);
        else
           printf("0 ");   
    }
    printf("\n");
  }
}

int main(){
  Diagonal m(4);
  //m.Diagonal(4);

  m.Set(1,1,5);
  m.Set(2,2,8);
  m.Set(3,3,9);
  m.Set(4,4,12);
  m.Display();
  m.~Diagonal();
  return 0;
}

