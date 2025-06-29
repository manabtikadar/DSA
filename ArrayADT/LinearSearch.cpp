#include<iostream>
#include<stdio.h>

using namespace std;

struct Array{
   int A[20];
   int size;
   int Length;

};

void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int LinearSearch(struct Array *arr, int key){
  for(int i=0;i<arr->Length;i++){
    if(arr->A[i]==key){
      //return i;
      swap(&arr->A[i],&arr->A[i-1]);
      return i;
    }
  }
  return -1;
}

int main(){

  struct Array arr={{2,4,6,8,10,12},10,6};
  //cout<<"Enter the search element";
  int n;
  cout<<"Enter the search element : ";
  cin>>n;
  int x = LinearSearch(&arr,n);
  if (x==-1)
       printf("Search is unsuccessful");
  else     
       printf("Search is successful and index is %d\n",x);

  return 0;
}