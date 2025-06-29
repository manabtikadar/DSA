#include<iostream>
#include<stdio.h>

using namespace std;

struct Array{
  int A[20];
  int size;
  int Length;
};

int BinarySearch(struct Array arr,int key){
  int l,h,mid;
  l=0;
  h=arr.Length-1;
  while(l<=h){
    mid = (l+h)/2;
    if(key==arr.A[mid])
        return mid;
    else if (key<arr.A[mid])
        h=mid-1;
    else l=mid+1;        
  }
  return -1;
}

int RBinarySearch(struct Array arr, int l, int h, int key){
  int mid=(l+h)/2;
  if(l<=h){
    if(key==arr.A[mid])
      return mid;
    else if(key<arr.A[mid])
      return RBinarySearch(arr,l,mid-1,key);
    else 
       return RBinarySearch(arr,mid+1,h,key);    
  }
  return -1;

}

int main(){
  struct Array arr ={{2,3,4,5,6},10,5};
  
  printf("%d\n",BinarySearch(arr,5));
  printf("%d\n",RBinarySearch(arr,0,5,4));
  return 0;
}