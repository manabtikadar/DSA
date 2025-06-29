#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int knapsack_Memoization(vector<int> weight, vector<int> value, int i, int capacity,vector<vector<int>> dp)
{
  if(i>=weight.size())
  {
    return 0;
  }
  if(dp[i][capacity]!=-1)
  {
    return dp[i][capacity];
  }

  //include
  int include=0;
  // int exclude=0;
  if(weight[i]<=capacity)
  {
     include = value[i]+knapsack_Memoization(weight,value,i+1,capacity-weight[i],dp);
  }

  //exclude
  int exclude = knapsack_Memoization(weight,value,i+1,capacity,dp);
  dp[i][capacity]=max(include,exclude);

  return dp[i][capacity];
}

int knapsack_Tabulation(vector<int> weight, vector<int> value, int n, int capacity)
{
  vector<vector<int>> dp(n,vector<int>(capacity+1, 0));
  // base case
  for(int w=0;w<=capacity;w++)
  {
    if(weight[0]<=w)
    {
      dp[0][w]=value[0];
    }
    else
    {
      dp[0][w]=0;
    }
  }

  for(int i=1;i<n;i++)
  {
    for(int w=0;w<=capacity;w++)
    {
      int include=0;
      if(weight[i]<=w)
      {
        include = value[i]+dp[i-1][w-weight[i]];
      }
      int exclude = dp[i-1][w];

      dp[i][w]=max(include,exclude);
    }
  }
  for(int i=0; i<n;i++)
  {
    cout<<"{";
    for(int j=0; j<=capacity; j++)
    {
      cout<<dp[i][j]<<" ";
    }
    cout<<"}"<<endl;
  }
  return dp[n-1][capacity];
}

// reverse call from knapsack_Tabulation2
int knapsack_Tabulation2(vector<int> weight, vector<int> value, int n, int capacity)
{
  vector<vector<int>> dp(n+1,vector<int>(capacity+1, 0));
  // base case
  for(int w=0;w<=capacity;w++)
  {
    dp[n][w]=0;
  }
  
  // take care of other recursive callS
  for(int i=n-1;i>=0;i--)
  {
    for(int w=0;w<=capacity;w++)
    {
      int include = 0;
      if(weight[i]<=w)
      {
        include = value[i]+dp[i+1][w-weight[i]];
      }
      int exclude = dp[i+1][w];

      dp[i][w]=max(include,exclude);
    }
  }
  for(int i=0; i<=n;i++)
  {
    cout<<"{";
    for(int j=0; j<=capacity; j++)
    {
      cout<<dp[i][j]<<" ";
    }
    cout<<"}"<<endl;
  }
  return dp[0][capacity];
}
// space complexity --> O(n*w)
int knapsack_spaceoptim(vector<int> weight, vector<int> value, int n, int capacity)
{
  vector<int> next(capacity+1,0);

  for(int i=n-1;i>=0;i--)
  {
    vector<int> current(capacity+1,0);
    for(int k=0;k<=capacity;k++)
    {
      int include =0;
      if(weight[i]<=k)
      {
        include=value[i]+next[k-weight[i]];
      }
      
      int exclude=next[k];

      current[k]=max(include,exclude);
    }

    for(int j=0; j<=capacity;j++)
    {
      next[j]=current[j];
    }
  }
  return next[capacity];
}

int knapsack_spaceoptim2(vector<int> weight, vector<int> value, int n, int capacity)
{
  vector<int> prev(capacity+1,0);

  for(int w=0;w<=capacity;w++)
  {
    if(weight[0]<=w)
    {
      prev[w]=value[0];
    }
  }

  for(int i=1;i<n;i++)
  {
    vector<int> current(capacity+1,0);
    for(int k=0;k<=capacity;k++)
    {
      int include =0;
      if(weight[i]<=k)
      {
        include=value[i]+prev[k-weight[i]];
      }
      
      int exclude=prev[k];

      current[k]=max(include,exclude);
    }

    for(int j=0; j<=capacity;j++)
    {
      prev[j]=current[j];
    }
  }
  return prev[capacity];
}

// space optim --> O(w)
int knapsack_more_spaceoptim(vector<int>& weight, vector<int>& value, int n,int capacity)
{
  vector<int> current(capacity+1, 0);

  // basecase analysis
  for(int w=0; w<=capacity; w++)
  {
    if(weight[0]<=w)
    {
      current[w]=value[0];
    }
  }
  for(int i=1;i<n;i++)
  {
    for(int w=capacity; w>=0; w--)
    {
      int include = 0;
      if(weight[i]<=w)
      {
        include = value[i]+current[w-weight[i]];
      }

      int exclude = current[w];

      current[w]=max(include,exclude);
    }
  }
  cout<<"{";
  for(int i=0; i<=capacity; i++)
  {
    cout<<current[i]<<" ";
  }
  cout<<"}";
  return current[capacity];
}

int main()
{
  // vector<int> weight={25, 4, 25, 49, 9, 11, 31};
  // vector<int> values={86, 55, 17, 31, 88, 82, 27};
  vector<int> weight={1,2,4,5};
  vector<int> values={5,4,8,6};
  int i=0;
  int n = weight.size();
  int maxWeight = 5; //60
  vector<vector<int>> dp(n,vector<int>(maxWeight+1, -1));
  // cout<<"Kanpsack Memoization: "<<knapsack_Memoization(weight,values,i,maxWeight,dp)<<endl;
  cout<<"Kanpsack Memoization: "<<knapsack_Tabulation(weight,values,n,maxWeight)<<endl;
  cout<<"Kanpsack Memoization: "<<knapsack_Tabulation2(weight,values,n,maxWeight)<<endl;
  // cout<<"Kanpsack Memoization: "<<knapsack_spaceoptim(weight,values,n,maxWeight)<<endl;
  // cout<<"Kanpsack Memoization: "<<knapsack_spaceoptim2(weight,values,n,maxWeight)<<endl;
  cout<<"Kanpsack Memoization: "<<knapsack_more_spaceoptim(weight,values,n,maxWeight)<<endl;
  return 0;
}