#include<iostream>
#include<stdio.h>

using namespace std;
// MONOLITHIC STYYLE OF PROGRAMMING
/*int main()
{ 
  int length=0,breadth=0;

  printf("Enter Length and Breadth");
  cin>>length>>breadth;

  int area = length*breadth;
  int peri = 2*(length+breadth);

  printf("Area = %d\nPerimeter = %d\n",area,peri);
  
  return 0;
}*/





// MODULER PROGRAMMING / PROCEDURAL POGRAMMING
/*int area(int length,int breadth){
   return length*breadth;
}

int perimeter(int length,int breadth){
  return 2*(length+breadth);
}
int main(){
  int length=0,breadth=0;

  int a, peri;
  a = area(length,breadth);
  peri = perimeter(length,breadth);

  printf("Area=%d\nPerimeter=%d\n", a, peri);

  return 0;
}*/

struct Rectangle
{
  int length;
  int breadth;
};
void initialise (struct Rectangle *r, int l, int b){
  r->length = l;
  r->breadth = b; 
}

int area(struct Rectangle r){
   return r.length*r.breadth;
}

int perimeter(struct Rectangle r){
  return 2*(r.length+r.breadth);
}

int main(){
  struct Rectangle r={0,0};

  //initialise(&r,10,15);
  int l,b;
  printf("Enter Length and Breadth :");
  cin>>l>>b;

  initialise(&r,l,b);

  
  int a, peri;
  a = area(r);
  peri = perimeter(r);

  return 0;
}



