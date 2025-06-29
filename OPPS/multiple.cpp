#include<iostream>

using namespace std;

class Animal {

  public:
  int age;
  int weight;


  public:
  void beark(){
    cout << "bearking" << endl;
  }

  void setage(int n){
    this->age=n;
  }
};

class Human{
  public:
  string color;

  public:
  void speak(){
    cout << "speaking" << endl;
  }


};

class Hybrid: public Animal, public Human{
 
};
int main(){
  Hybrid obj1;
  obj1.speak();
  obj1.beark();

  return 0;
}