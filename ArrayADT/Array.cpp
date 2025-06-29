#include<stdio.h>
#include<iostream>

struct Array
{
  int *A;
  int size;
  int Length;
};

void Display(struct Array arr){
   for(int i=0; i<arr.Length;i++){
    printf("%d ", arr.A[i]);
   }
}

void append(struct Array *arr, int new_element){
     if (arr->Length<arr->size){
      arr->A[arr->Length] = new_element;
      arr->Length++;
     }
}

void Insert(struct Array *arr,int index,int value){
    int i;
    for(i=arr->Length; i>index; i--){
      arr->A[i]=arr->A[i-1];
    }
    arr->A[index]=value;
    arr->Length++;
}

int Delete(struct Array *arr, int index){
  int x = arr->A[index];
  if(index>=0 && index<arr->Length)
  {
    for(int i = index; i<arr->Length-1;i++){
    arr->A[i]=arr->A[i+1];
    }
    arr->Length--;
    return x;
  }  
  return 0;
}

int main(){

  int n,i;
  struct Array arr;
  printf("Enter The Size of an Array\n");
  scanf("%d", &arr.size);
   
  arr.A = new int[arr.size]; 

  printf("Enter the number of elements\n");
  scanf("%d",&n);
  
  arr.Length=0;

  for(int i=0; i<n; i++){
    scanf("%d",&arr.A[i]);
  }
  
  arr.Length = n;
  
  append(&arr, 10);
  printf("\n%d\n", arr.Length);
  Display(arr);
  Insert(&arr, 4, 12);
  printf("\n%d\n", arr.Length);
  Display(arr);
  printf("\n");
  
  
  printf("\n%d\n",Delete(&arr,4));
  Display(arr);
  return 0;
}


