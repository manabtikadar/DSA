#include<iostream>
#include<queue>

using namespace std;
int main(){
  queue<string> q;

  q.push("Manab");
  q.push("Rajnish");
  q.push("Sagnik");

  cout<<"First Element->"<<q.front()<<endl;
  q.pop();
  cout<<"First Element->"<<q.front()<<endl;

  cout<<"size of the queue after pop->"<<q.size()<<endl;
}