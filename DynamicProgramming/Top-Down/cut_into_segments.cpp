#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int count_segment(vector<int>& arr, int count, int Temp)
{
 if(arr[0]==0)
 {
  if(count>Temp)
  {
    Temp = count;
  }
  cout<<"Total count:"<<count<<endl;
  return Temp;
 }
 if(arr[0]<0)
 {
  return INT16_MIN;
 }
 for(int i=1;i<arr.size();i++)
 {
  if(arr[0]>=arr[i])
  {
    // cout<<arr[i]<<" "<<arr[0]-arr[i]<<endl;
    arr[0]=arr[0]-arr[i];
    count++;
    // cout<<count<<endl;
    Temp = count_segment(arr,count,Temp);
    arr[0]=arr[0]+arr[i];
    count--;
  }
 }
 return Temp;
}

int solve(int n, int x, int y, int z)
{
  if(n==0)
  {
    return 0;
  }
  if(n<0)
  {
    return INT16_MIN;
  }

  int a=solve(n-x,x,y,z)+1;
  int b=solve(n-y,x,y,z)+1;
  int c=solve(n-z,x,y,z)+1;

  return max(a,max(b,c));
}

// Top down Approach
int solve_memorization(int n, int x, int y, int z, vector<int> dp)
{
  if(n==0)
  {
    return 0;
  }
  if(n<0)
  {
    return INT16_MIN;
  }
  if(dp[n]!=-1)
  {
    return dp[n];
  }
  int a=solve_memorization(n-x,x,y,z,dp)+1;
  int b=solve_memorization(n-y,x,y,z,dp)+1;
  int c=solve_memorization(n-z,x,y,z,dp)+1;
  
  dp[n]=max(a,max(b,c));
  return dp[n];
}

// solve Tabulation
int solve_tabulation(int n, int x, int y, int z)
{
  vector<int> dp(n+1, INT16_MIN);
  dp[0] = 0;

  for(int i=1; i<n+1; i++)
  {
    if(i-x>=0)
    {
      dp[i]=max(dp[i], dp[i-x]+1);
    }
    if(i-y>=0)
    {
      dp[i]=max(dp[i], dp[i-y]+1);
    }
    if(i-z>=0)
    {
      dp[i]=max(dp[i], dp[i-z]+1);
    }
  }
  if(dp[n]<0)
  {
    return 0;
  }
  else{
    return dp[n];
  }
}

// space optimization
// int solve_spaceOptim(int n, int x, int y, int z)
// {
//   int prev = 0;
//   int current;

//   for(int i=1; i<=n; i++)
//   {
//     if(i-x>=0)
//     {
//       current = max()
//     }
//   }
// }

int main()
{
  vector<int> arr = {16,5,2,2};
  int count=0;
  int Temp=0;
  cout<<count_segment(arr,count,Temp);
  // int n=16;
  // int x=5;
  // int y=2;
  // int z=2;
  // vector<int> dp(n+1,-1);
  // cout<<solve_tabulation(n,x,y,z);
   return 0;
}