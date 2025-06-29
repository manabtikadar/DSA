#include<iostream>

using namespace std;

class Rectangle
{
  private:
      int length;
      int breadth;
  public:  
      // default constructor
      Rectangle(){
        length = 0;
        breadth = 0;
      }
      // parameterised constructor
      Rectangle(int l, int b){
        length = l;
        breadth = b;
      }
      
      //facilitator
      int area(){
        return length*breadth;
      }

      int perimeter(){
        return 2*(length+breadth);
      }
      
      // mutater function
      void setLength(int l){
        length = l;
      }

      void setBreadth(int b){
        breadth = b;
      }
      
      // accesser function
      int getLength(){
        return length;
      }

      int getPerimeter(){
        return breadth;
      }

      // destructor
      ~Rectangle(){
        cout<<"Destructor";
      }

};

int main(){

  Rectangle r(10,5);

  cout<<"Area: "<<r.area()<<endl;
  
  cout<<"perimeter: "<<r.perimeter()<<endl;
  return 0;
}

