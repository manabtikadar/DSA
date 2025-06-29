#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*int main()
{
  // int a = 10;
  // int *p;
  // p = &a;

  // cout<<a<<endl;
  // printf("using pointer %d %d",*p, &a);

  int A[5]={2,4,6,8,10};
  int *p;
  // *initialisation of a pointer*
  p = A; // name of an array itself is a starting address of an array so we don't use the "&A" for initializing the pointer.

  //p = &A[0] ; // if we want to use "&" the we have to write "&A[0]", as if wea are accessing the address of the first element of the array
  
  for(int i=0;i<5;i++)
  cout<<p[i]<<endl;
  return 0;
}*/

// *array created in heap*

/*int main()
{
  int *p;
  //p = (int*)malloc(5*sizeof(int));
  p = new int[5];
  
  p[0]=10;p[1]=15;p[2]=14;p[3]=21;p[4]=31;

  for(int i=0;i<5;i++)
  cout<<p[i]<<endl;

  delete [ ] p;//c++
  free(p); //c 
  return 0;
}*/

struct Rectangle 
{ 
  int length;
  int breadth;

};


int main()
{
  int *p1;
  char *p2;
  float *p3;
  double *p4;
  struct Rectangle *p5;
  
  cout<<sizeof(p1)<<endl;
  cout<<sizeof(p2)<<endl;
  cout<<sizeof(p3)<<endl;
  cout<<sizeof(p4)<<endl;
  cout<<sizeof(p5)<<endl;


  return 0;
}