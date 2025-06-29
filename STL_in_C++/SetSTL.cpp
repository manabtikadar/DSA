#include<iostream>
#include<set>

using namespace std;
int main()
{
  // set stores only unique elements. if you insert 5 ,5 times then set store 5 only 1 times
  // Implementation sing BST . Insert or Delete No Modification Done
  // Element Turn in sorted Order
  set<int> s;

  s.insert(5);
  s.insert(5);
  s.insert(5);
  s.insert(1);
  s.insert(1);
  s.insert(6);
  s.insert(6);
  s.insert(0);

  for(auto i : s){
    cout<<i<<endl;
  }cout<<endl;
  
  set<int>::iterator it = s.begin(); 
  it++;
  s.erase(it);
  for(auto i : s){
    cout<<i<<endl;
  }cout<<endl;

  cout<<"5 is present or not? ->"<<s.count(5)<<endl;

  set<int>::iterator itr=s.find(5);
  cout<<"value present at itr->"<<*itr<<endl;

  for(auto it=itr; it!=s.end();it++)
  {
    cout<<*it<<" ";
  }cout<<endl;
}