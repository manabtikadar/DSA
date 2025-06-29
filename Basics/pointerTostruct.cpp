#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Rectangle
{
  int length;
  int breadth;
};

int main(){
  
  /*struct Rectangle r={10,5};
  cout<<r.length<<endl;
  cout<<r.breadth<<endl;
  
  Rectangle *p=&r;
  cout<<p->length<<endl;
  cout<<p->breadth<<endl;*/

  // create an object in heap

  Rectangle *p;
  p = (Rectangle*)malloc(sizeof(Rectangle)); // malloc function returns a void pointer or a generic pointer so we have to type cast it using (type_of _variable *)
  p->length=15;
  p->breadth=7;

  cout<<p->length<<endl;
  cout<<p->breadth<<endl;

  

  return 0;
}