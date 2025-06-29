#include<iostream>
#include<deque>

using namespace std;
int main()
{
  deque<int> d;
  d.push_back(1); //push element from back
  d.push_front(2);//push element from front

  for(int i:d){
    cout<<i<<" ";
  }cout<<endl;

  d.pop_back();  // pop element from back
  d.pop_front(); // pop element from front
  for(int i:d){
    cout<<i<<" ";
  }cout<<endl;

  d.push_back(1);
  d.push_front(2);

  cout<<"print First INdex Element->"<<d.at(1)<<endl;
  cout<<"front"<<d.front()<<endl;
  cout<<"back"<<d.back()<<endl;
  
  cout<<"empty or not->"<<d.empty()<<endl;

  cout<<"before erase:"<<d.size()<<endl;
  d.erase(d.begin(),d.begin()+1); // delete first element
  cout<<"after erase:"<<d.size()<<endl;
  for(int i:d){
    cout<<i<<" ";
  }cout<<endl;

}