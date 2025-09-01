// #include<iostream>
// // #include "person.h"
// #include "Soldier.h"

// using namespace std;
// int main()
// {
//   // person *p=new person();
//   // p->Crawl();
  
//   Soldier *soldier=new Soldier();
//   soldier->Crawl();
//   soldier->FireWeapon();
//   return 0;
// }

#include<bits/stdc++.h>

using namespace std;

// class Model{
//   public:
//      Model()
//      {
//       cout<<"Model Constructor invoked"<<endl;
//      }
//      Model(int x) { cout << "Model constructor with " << x << endl; }
//      ~Model() { cout << "Model Destructor invoked" << endl;}
// };

// class Car:public Model{
//   public:
//       Car()
//       {
//         cout<<"Car Constructor invoked"<<endl;
//       }
//       Car(int y){ cout << "Car constructor with " << y << endl; }

//       ~Car() { cout << "Car Destructor invoked" << endl;}
// };

// int main()
// {
//   Model *car=new Car(3); //this calls the Base Constructor (Model Constructor) and then it calls Car Constructor; for both Base Class type pointer and Derived Class type pointer 
//   delete car; // this calls the model destructor only as the pointer type is Model 
//               // but if the pointer type is derived class then the Derived class destructor calls first then the Base Class Destructor calls 
  
//   return 0;
// }

#include "GameObject.h"

int main()
{
  GameObject obj1;
  cout<<obj1.id<<endl;

  return 0;
}