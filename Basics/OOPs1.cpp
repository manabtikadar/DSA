#include<iostream>
#include<stdio.h>

using namespace std;

class Rectangle // in class every thing is by default private but in structure everything is public.
{
public:
  int length;
  int breadth;

void initialise (int l, int b){
  length = l;
  breadth = b; 
}

int area(){
   return length*breadth;
}

int perimeter(){
  return 2*(length+breadth);
}

};


int main(){
  Rectangle r={0,0};

  //initialise(&r,10,15);
  int l,b;
  printf("Enter Length and Breadth :");
  cin>>l>>b;

  r.initialise(l,b);

  
  int a, peri;
  a = r.area();
  peri = r.perimeter();

  return 0;
}