#include<iostream>
#include<vector>

using namespace std;
int main()
{
  vector<int> v;
  vector<int> a(5,1); // (5,1) means it will create a vector of size 5 and fill all the elements with 1 , if we don't declare 1 it will fill all the elements with 0
  vector<int> last(a); // copy all the elements of a in last vector
  cout<<"print a"<<endl;
  for(int i:a){
    cout<<i<<" ";
  }cout<<endl;

  cout<<"print last"<<endl;
  for(int i:last){
    cout<<i<<" "; 
  }cout<<endl;

  cout<<"Capacity->"<<v.capacity()<<endl;

  v.push_back(1);
  cout<<"Capacity->"<<v.capacity()<<endl;

  v.push_back(2);
  cout<<"Capacity->"<<v.capacity()<<endl;

  v.push_back(3);
  cout<<"Capacity->"<<v.capacity()<<endl;
  cout<<"Size->"<<v.size()<<endl;

  cout<<"Element at 2nd Index->"<<v.at(2)<<endl;
  cout<<"front->"<<v.front()<<endl;
  cout<<"back->"<<v.back()<<endl;

  cout<<"before pop:"<<endl;
  for(int i:v){
    cout<<i<<" ";
  }cout<<endl;

  v.pop_back();

  cout<<"after pop:"<<endl;
  for(int i:v){
    cout<<i<<" ";
  }cout<<endl; 

  cout<<"before clear Size"<<v.size()<<endl;
  v.clear();// it will clear all the elements but the capacity of the vector will not change will be same as previous one
  cout<<"after clear size->"<<v.size()<<endl; 
  
  vector<int> numbers={10,20,30,40,50};

  vector<int> ::iterator endit = numbers.end();
  cout<<*(--endit)<<endl; // numbers.end() does not point to a valid element in the container. instead, it points just past the last element

  // Declare an iterator for The Vector
  vector<int> ::iterator it;
  cout<<"Elements in the Vector: ";
  
  //use the iterator to traverse the vector
  for(it = numbers.begin(); it!=numbers.end(); it++){
    cout<< *it << " ";
  }cout<<endl;
}