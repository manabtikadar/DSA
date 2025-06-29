#include<iostream>
#include<stdio.h>

using namespace std;

struct Array{
  int A[10];
  int size;
  int Length;
};
struct Array* Merge(struct Array *arr1,struct Array *arr2){
  int i=0,j=0,k=0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
  while(i<arr1->Length && j<arr2->Length){
    if (arr1->A[i]<arr2->A[j])
       arr3->A[k++]=arr1->A[i++];
    else 
       arr3->A[k++]=arr2->A[j++];   
  }
  for(;i<arr1->Length;i++){
    arr3->A[k++]=arr1->A[i++];
  }
  for(;j<arr1->Length;j++){
    arr3->A[k++]=arr2->A[j++];
  }
  arr3->Length=arr1->Length+arr2->Length;
  arr3->size =10;
  return arr3;
}
void Display(struct Array arr){
  for(int i=0;i<arr.Length;i++){
    printf("%d ",arr.A[i]);
  }
  printf("\n");
}

int main(){
  struct Array arr1={{2,6,10,15,25},10,5};
  struct Array arr2={{3,4,7,18,20},10,5};
  struct Array *arr;
  arr=Merge(&arr1,&arr2);
  
  Display(arr1);
  Display(arr2);
  Display(*arr);
  return 0;
}