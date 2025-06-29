#include<iostream>

using namespace std;

// void isSorted(int n, int arr[10])
// {
//   if(n==1)
//   {
//     cout<<"is sorted"<<endl;
//     return;
//   }
//   else
//   {
//     if(arr[n-2]<=arr[n-1])
//     {
//       isSorted(n-1,arr);
//     }
//     else
//     {
//       cout<<"is not sorted"<<endl;
//       return;
//     }
    
//   }
// }

bool issorted(int *arr, int size)
{
  if(size == 0 || size == 1)
  {
    return true;
  }
  if(arr[0] > arr[1])
  {
    return false;
  }
  else{
    bool remainingPart = issorted(arr+1, size-1);
    return remainingPart;
  }
}

int add(int *arr, int size)
{
  if(size==0)
  { 
    return 0;
  }
  if(size == 1)
  {
    return arr[0];
  }
  int reaminingPart = add(arr+1, size-1);
  int sum = arr[0]+ reaminingPart;
  return sum;
}

bool search(int num,int *arr, int size)
{
  if(size==0)
  {
    return false;
  }

  if(arr[0]==num)
  {
    return true;
  }
  else{
    bool remaining = search(num,arr+1,size-1);
    return remaining;
  }
}

bool binarySearch(int *arr, int s, int e, int k)
{
  if(s>e)
  {
    return false;
  }
  int mid = (s+e)/2;

  if(arr[mid]==k)
  {
    return true;
  }
  else if(k<arr[mid])
  {
    return binarySearch(arr, s, mid-1, k);
  }
  else
  {
    return binarySearch(arr,mid+1,e,k);
  }
}


int main()
{ int key = 14;
  int size=5;
  int arr[10]={2,4,6,10,14};
  // cout<<issorted(arr,size)<<endl;
  // cout<<add(arr,size)<<endl;
  // cout<<search(num,arr,size);
  cout<<binarySearch(arr,0,size-1,key)<<endl;
  return 0;


}