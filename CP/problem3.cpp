#include<bits/stdc++.h>

using namespace std;

void solve()
{
  int n;
  cin>>n;
  
  vector<int> a(n);
  
  for(int i=0; i<n; i++)
  {
    int x;
    cin>>x;
    a[i] = x;
  }
  
  queue<int> q;
  q.push(a[0]);
  int count=1;
  for(int i=1; i<n; i++)
  {
      // if(q.size()>=3)
      // {
      //   if(q.front()+1<q.back())
      //   {
      //     int temp=q.back();
      //     count++;
      //     while(!q.empty())
      //     {
      //       q.pop();
      //     }
      //     q.push(temp);
      //     cout<<"queue Size:"<<q.size()<<endl;
      //     cout<<"Count:"<<count<<endl;
      //   }
      //   else
      //   {
      //     q.push(a[i]);
      //     cout<<"queue Size:"<<q.size()<<endl;
      //     cout<<"Count:"<<count<<endl;
      //   }
      // }
      int flag = 1;
      int flag2 = 1;
      if(a[i-1]+1>=a[i])
      {
         q.push(a[i]);
         flag2 = 0;
         cout<<"queue Size:"<<q.size()<<endl;
         cout<<"Count:"<<count<<endl;                              
      }
      else
      {
         count++;
         while(!q.empty())
         {
          q.pop();
         }
         q.push(a[i]);
         flag=0;
         cout<<"queue Size:"<<q.size()<<endl;
         cout<<"Count:"<<count<<endl;                              
      }

      if(q.size()>=3)
      {
        if(q.front()+1<q.back())
        {
          int temp=q.back();
          count++;
          while(!q.empty())
          {
            q.pop();
          }
          q.push(temp);
          cout<<"queue Size:"<<q.size()<<endl;
          cout<<"Count:"<<count<<endl;
        }
        else if(flag2==1)
        {
          q.push(a[i]);
          cout<<"queue Size:"<<q.size()<<endl;
          cout<<"Count:"<<count<<endl;
        }
        else
        {
          continue;
        }
      }
  }

  // if(q.size()>=3)
  // {
  //   if(q.front()+1<q.back())
  //   {
  //     count++;
  //   }
  // }
  cout<<count<<endl;
  return;
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