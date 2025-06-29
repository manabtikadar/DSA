#include<bits/stdc++.h>

using namespace std;

void solve()
{
  int n; 
  cin>>n;
  
  vector<int> d(n);
  for(int i=0; i<n; i++)
  {
    cin>>d[i];                              
  }
  vector<pair<int, int>> obstacles(n);
  for(int i=0; i<n; i++)
  {
    cin>>obstacles[i].first;
    cin>>obstacles[i].second;
  }
  int sum=0;
  stack<int> s;
  bool possible = true;
  for(int i=0; i<n; i++)
  {
    if(d[i]==-1)
    {
      s.push(i);                               
    }
    else
    {
      sum += d[i];                               
    }
    
    while(sum<obstacles[i].first)
    {
       if(s.empty())
       {
         cout<<-1<<endl;
         possible=false;
         break;
       }
       else
       {
         d[s.top()]=1;
         sum++;
         s.pop();
       }
    }
    
    while(sum+s.size()>obstacles[i].second)
    {
      if(s.empty())
      {
        cout<<-1<<endl;
        possible = false;
        break;
      }
      else
      {
        d[s.top()]=0;
        s.pop();
      }
    }
    if(!possible) break;
  }  
    
  if(possible)
  {
    while (!s.empty()) { // Handle leftover -1s
      d[s.top()] = 0;
      s.pop();
    }
    for(int i=0; i<n; i++)
    {
      cout<<d[i]<<" ";                               
    }
    cout<<endl;
  }  
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    solve();                               
  }
  return 0;
}