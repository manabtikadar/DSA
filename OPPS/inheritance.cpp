#include<iostream>
#include<stdio.h>

using namespace std;

class Human{
  public:
  int height;
  int weight;
  // private: if we inherit a private element in public mode in child class it is non accessible in child class !!
  int age;

  public:
  int getAge(){
    return this->age;
  }
  void setWeight(int w){
    this->weight=w;
  }
};

class Male: protected Human{

  public:
  string colour;

  void sleep(){
    cout<<"Male Sleeping"<<endl;
  }

  int getHeight(){
    return this->height;        // (we can access height , although it is a protected veriable but we can access it in child class also.)
  }
};

int main(){

  Male m1;
  cout<<m1.getHeight()<<endl;
  /*cout<<m1.height<<endl;*/           // (can't accessable because height is a protected veriable )

  // Male object1;
  // cout<<object1.age<<endl;
  // cout<<object1.height<<endl;
  // cout<<object1.weight<<endl;


  // cout<<object1.colour<<endl;

  // object1.setWeight(84);
  // cout<<object1.weight<<endl;

  // object1.sleep();


  return 0;

}