#include<bits/stdc++.h>

using namespace std;
int solve(int start, int end)
{
    if(end<=start)
    {
        return 0;
    }
    int ans=INT_MAX;
    for(int i=start ; i<=end; i++)
    {
      int lower = solve(start,i-1);
      int higher = solve(i+1,end);

      ans = min(ans, i+max(higher,lower));
    }
    return ans;
}
int solve_mem(int start, int end, vector<vector<int>>& dp)
{
    if(end<=start)
    {
        return 0;
    }
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
    int ans=INT_MAX;
    for(int i=start ; i<=end; i++)
    {
      int lower = solve_mem(start,i-1,dp);
      int higher = solve_mem(i+1,end,dp);

      ans = min(ans, i+max(higher,lower));
    }
    dp[start][end]=ans;
    return dp[start][end];
}
int solve_tab(int n)
{   
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    int ans=INT_MAX;
    for(int start=n; start>=1; start--)
    {
        for(int end=start; end<=n; end++)
        {
            if(start==end)
            {
                continue;
            }
            else
            {
                int ans = INT_MAX;
                for(int i=start ; i<=end; i++)
                {
                    int lower =dp[start][i-1];
                    int higher =dp[i+1][end];

                    ans = min(ans, i+max(higher,lower));
                }
                dp[start][end]=ans;
            }
        }
        
    }
    return dp[1][n];
}
int main()
{
  map<pair<int,int>, int> maxi;
  int n=arr.size();

  for(int i=0; i<n; i++)
  {
      maxi[{i,i}]=arr[i];
      for(int j=i+1; j<n; j++)
      {
        maxi[{i,j}]=max(arr[j],maxi[{i,j-1}]);
      }
  }

  for(int i=0; i<n; i++)
  {
      for(int j=i; j<n; j++)
      {
          cout<<"for range "<< i <<"-->"<<j<<" max is "<<maxi[{i,j}]<<endl;
      }
  }
  cout<<solve_tab(n);
  return 0;
}