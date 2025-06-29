#include<iostream>
#include<stdio.h>

using namespace std;

class Student {
  private:
      string student_name;
      int age;
      int height;

  public:
  int getAge(){
    return this->age;
  }   
}

int main(){

  return 0;
}