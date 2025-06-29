#include<iostream>
#include<stdlib.h>

using namespace std;

struct LTMatrix{
  int *A;
  int n;
};

void set(struct LTMatrix *m,int i,int j,int k){
  int n =(i*(i-1)/2)+(j-1);
  if(i>=j){
    m->A[n] = k;
  }
}

int get(struct LTMatrix *m, int i, int j){
  int n =(i*(i-1)/2)+(j-1);
  if(i>=j){
    return m->A[n];
  }
  else return 0;
}

void Display(struct LTMatrix m){
 // int k= m.n*(m.n+1)/2;
  int i,j;
  for(i=1;i<=m.n;i++){
    for(j=1;j<=m.n;j++){
      if(i>=j){
        cout<<m.A[(i*(i-1)/2)+(j-1)]<<" ";
      }
      else cout<<"0 ";
    }
    cout<<endl;
  }
}

int main(){
  struct LTMatrix m;
  printf("Enter the dimension:");
  scanf("%d",&m.n);
  m.A = (int *)malloc(m.n*(m.n+1)/2*sizeof(int));
  

  int d;
  printf("\nEnter All the Elements:\n");
  for(int i=1;i<=m.n;i++){
    for(int j=1;j<=m.n;j++){
        scanf("%d",&d);
        set(&m,i,j,d);
    }
  }

  
  /*set(&m,1,1,3);
  set(&m,2,1,5);
  set(&m,2,2,9);
  set(&m,3,1,6);
  set(&m,3,2,4);
  set(&m,3,3,2);*/

  printf("\n\n");
  
  Display(m);

  //get(&m,3,3);

  return 0;
}