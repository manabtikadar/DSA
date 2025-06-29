#include<iostream>
#include<list>

using namespace std;
int main(){
  list<int> l;
  list<int> n(5,100); // list of 5 initialize with 100
  cout<<"print n:"<<endl;
  for(int i:n)
  {
    cout<<i<<" ";
  }cout<<endl;

  l.push_back(1);
  l.push_front(2);

  list<int> p(l); // create a list p and copy list l to p

  for(int i:l)
  {
    cout<<i<<" ";
  }cout<<endl;

  l.erase(l.begin());  
  cout<<"after erase:"<<endl;
  for(int i:l)
  {
    cout<<i<<" ";
  }cout<<endl;

  cout<<"size of list:"<<l.size()<<endl;
}