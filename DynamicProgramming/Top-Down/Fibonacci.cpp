#include<iostream>
#include<vector>
using namespace std;

// Top - Down Approach
int fibonacci(int n, vector<int> &dp)
{ //base Case
  if(n<=1)
  {
    return n;
  }
  //step 3
  if(dp[n]!=-1)
  {
    return dp[n];
  }
  
  //step 2
  dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);

  return dp[n];
}

// Tabulation method
int fibonacci_tabulation(int n) {
  // Step 1: Create a table to store Fibonacci numbers
  int dp[n + 1];

  // Step 2: Initialize base cases
  dp[0] = 0;
  dp[1] = 1;

  // Step 3: Fill the table iteratively
  for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

// space optimization
int fibonacci_space_optimization(int n) {
  // Step 2: Initialize base cases
  int prev1 = 1;
  int prev2 = 0;
  int current;
  // Step 3: Fill the table iteratively
  if(n==0)
  {
    return prev2;
  }
  for (int i = 2; i <= n; i++) {
      current = prev1 + prev2;
      prev2 = prev1;
      prev1 = current;
  }

  return current;
}

int main()
{
  int n;
  cin>>n;
  
  //step 1
  vector<int> dp(n+1);
  for(int i=0; i<=n; i++)
  {
    dp[i]=-1;
  }

  cout<<fibonacci_space_optimization(n)<<endl;
  return 0;
}