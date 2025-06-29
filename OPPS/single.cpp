#include<iostream>

using namespace std;

class Animal {

  public:
  int age;
  int weight;


  public:
  void speak(){
    cout << "Speaking" << endl;
  }

  void setage(int n){
    this->age=n;
  }
};

class Dog: public Animal{
  
};

int main(){
  Dog d;
  d.speak();
  d.setage(84);
  cout<<d.age<<endl;

  return 0;
}