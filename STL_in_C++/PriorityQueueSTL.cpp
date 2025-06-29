#include<iostream>
#include<queue>

using namespace std;
int main(){
   priority_queue<int> maxi; // based on MAX HEAP
   
   // MIN HEAP
   priority_queue<int,vector<int>, greater<int>> mini;

   maxi.push(1);
   maxi.push(3);
   maxi.push(2);
   maxi.push(0);
   
   cout<<"Size->"<<maxi.size()<<endl;
   int n = maxi.size();

   for(int i=0; i<n; i++){
    cout<<maxi.top()<<" ";
    maxi.pop();
   }cout<<endl;

   mini.push(1);
   mini.push(3);
   mini.push(2);
   mini.push(0);
   
   cout<<"Size->"<<mini.size()<<endl;
   int n1 = mini.size();

   for(int i=0; i<n1; i++){
    cout<<mini.top()<<" ";
    mini.pop();
   }cout<<endl;

   cout<<"is Empty or not ? ->"<<mini.empty()<<endl;
}