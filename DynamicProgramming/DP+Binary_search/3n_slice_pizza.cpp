#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(vector<int>& pizza_slices, int n,vector<int>& dp)
{
  if(n==0)
  {
    return 0;
  }
  // if(n==1)
  // {
  //   return pizza_slices[0];
  // }
  if(dp[n]!=-1)
  {
    return dp[n];
  }
  
  int ans = INT32_MIN;
  for(int i=0; i<n; i++)
  {
    int k,j;
    if(i==0)
    {
      j = pizza_slices.size()-1;
      k = i+1;
    }
    else
    {
      j = i-1;
      k = (i + 1) % pizza_slices.size();
    }
    vector<int> temp = pizza_slices;

    // Ensure correct erase order: higher indices first to avoid shifting
    vector<int> indices = {j, i, k};
    sort(indices.rbegin(), indices.rend());

    for (int idx : indices) {
        temp.erase(temp.begin() + idx);
    }
    ans = max(ans, pizza_slices[i]+solve(temp,n-3,dp));
  }
  dp[n]=ans;
  return dp[n];
}

int max_slices(int start_index, int end_index, vector<int> slices, int n)
{
  if(n==0||start_index>end_index)
  {
    return 0;
  }

  // take the current slice
  int take = slices[start_index]+max_slices(start_index+2, end_index, slices, n-1);
  // don't take the current slice
  int non_take = 0 + max_slices(start_index+1, end_index, slices, n);

  return max(take,non_take);
}
int max_slices_mem(int start_index, int end_index, vector<int> slices, int k,vector<vector<int>>& dp)
{
    if(k==0||start_index>end_index)
    {
        return 0;
    }
    if(dp[start_index][k]!=-1)
    {
        return dp[start_index][k];
    }

    // take the current slice
    int take = slices[start_index]+max_slices_mem(start_index+2, end_index, slices, k-1, dp);
    // don't take the current slice
    int non_take = 0 + max_slices_mem(start_index+1, end_index, slices, k, dp);

    dp[start_index][k]=max(take,non_take);
    return dp[start_index][k];
}
int max_slices_tab(int start_index, int end_index, vector<int> slices, int n)
{   
    vector<vector<int>> dp(n+1, vector<int>((end_index-start_index)+3, 0));
    int k=(end_index-start_index);
    for(int i=1;i<=n;i++)
    {
        for(int j=k; j>=0; j--)
        {
            int take = slices[start_index+j]+dp[i-1][j+2];
            int non_take = 0+dp[i][j+1];
            dp[i][j]=max(take,non_take);
        }
    }
    return dp[n][0];
}
int max_slices_optim(int start_index, int end_index, vector<int> slices, int n)
{
    vector<int> next1(n+1,0);
    vector<int> next2(n+1,0);
    vector<int> current(n+1,0);
    int k=end_index-start_index;
    for(int i=k;i>=0;i--)
    {
        for(int j=1; j<=n; j++)
        {
            int take=slices[start_index+i]+next2[j-1];
            int non_take=0+next1[j];
            current[j]=max(take,non_take);
        }
        next2=next1;
        next1=current;
    }
    return next1[n];
}
int main()
{
  vector<int> pizza_slices = {8,9,8,6,1,1};
  int n = pizza_slices.size();
  cout<<max(max_slices(0,n-2,pizza_slices,n/3),max_slices(1,n-1,pizza_slices,n/3));
}
