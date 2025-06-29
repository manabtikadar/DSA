#include<iostream>
#include<stdio.h>
using namespace std;

// int main(){
//   int A[5];
//   A[0]=15;
//   A[1]=25;
//   A[2]=10;

//   cout<<sizeof(A)<<endl; // for c++ language
//   cout<<A[1];
//   printf("\n%d\n",A[2]);  // for c language
  
//   int B[10]={2,4,6,8,10,12};

//   for(int x:B){
//     cout<<x<<endl;
//   }
//   int n;
//   cout<<"Enter Size";
//   cin>>n;
//   int A[n];
  
//   return 0;
// }


struct Rectangle 
{
  int length;
  int breadth;
  char x;
};
//struct Rectangle r1; // accessable for all the functions in the pogramme
int main()
{
  struct Rectangle r1; // local variable
  r1.length = 10;
  r1.breadth = 5;
  printf("%d", sizeof(r1));// it should take 9 bytes but it takes 12 bytes because it is easy to read computer for reading 4 bytes at a time , so for charecter it also allocate 4 bytes but use only 1 byte
  return 0;
}