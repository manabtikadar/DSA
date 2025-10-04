#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,q;
  cin>>n>>q;
  //vector<vector<char>> Forest;
  vector<vector<int>> PrefixSum(n,vector<int>(n,0));
  for(int i=0; i<n; i++)
  {
    int sum=0;
    for(int j=0; j<n; j++)
    {
      char ch;
      cin>>ch;
      if(ch=='*')
      {
        sum++;
      }
      PrefixSum[i][j]=sum;
    }
  }

  // for(int i=0; i<n; i++)
  // {
  //   for(int j=0; j<n; j++)
  //   {
  //     cout<<PrefixSum[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  
  cout<<endl; 

  for(int j=0;j<n;j++)
  {
    for(int i=1;i<n;i++)
    {
      PrefixSum[i][j]=PrefixSum[i][j]+PrefixSum[i-1][j];
    }
  }

  // for(int i=0; i<n; i++)
  // {
  //   for(int j=0; j<n; j++)
  //   {
  //     cout<<PrefixSum[i][j]<<" ";
  //   }x2
  //   cout<<endl;
  // }
  
  while(q--)
  {
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1--;
    x2--;
    y1--;
    y2--;
    
    int a=PrefixSum[x2][y2];
    int b=0;
    if(y1-1>=0 && y1-1<n)
    {
      b=PrefixSum[x2][y1-1];
    }
    int c=0;
    if(x1-1>=0 && x1-1<n)
    {
      c=PrefixSum[x1-1][y2];
    }
    int d=0;
    if(x1-1>=0 && x1-1<n && y1-1>=0 && y1-1<n)
    {
      d=PrefixSum[x1-1][y1-1];
    }
    int ans=a-b-c+d;

    cout<<ans<<endl;

  }
  return 0;
}