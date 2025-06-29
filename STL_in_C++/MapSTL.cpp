#include<iostream>
#include<map>

using namespace std;
int main(){

  // insert , find , erase , count in case of map O(n)
  // map is implemented using red-black Tree, but Unordered map is implemented using Hash Table
  map<int,string> m;
  m[1]="Manab";
  m[2]="Rajnish";
  m[13]="Sagnik";
  //m[4] = "Ankur";
  
  m.insert({5,"Ankur"});

  cout<<"before erase"<<endl;
  for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
  }

  cout<<"finding 13 ->"<<m.count(13)<<endl;
  cout<<"finding -13 ->"<<m.count(-13)<<endl;
  
  m.erase(13);
  cout<<"after erase"<<endl;
  for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
  }cout<<endl;

  auto it = m.find(5);
  for( auto i=it; i != m.end();i++){
    cout<<(*i).first<<" "<<(*i).second<<endl;
  }

}