#include<bits/stdc++.h>

using namespace std;

// to find first M prime numbers
vector<int> sieve_algorithm(int n, int m)
{
   vector<bool> is_prime(n+1,true);
   vector<int> primes;
   
   is_prime[0]=is_prime[1]=false;
   for(int p=2; p*p<=n; p++)
   {
     if(is_prime[p])
     {
       for(int i=p*p; i<=n; i+=p)
       {
         is_prime[i]=false;
       }
     }
   }
   
   int count=0;
   for(int i=2; i<=n; i++)
   {
     if(count>=m)
     {
      break;
     }
     if(is_prime[i])
     {
       count++;
       primes.push_back(i);
     }
   }
   
   return primes;
}

int solve(int index, vector<int>& primes, int n)
{
  if(n==0)
  {
    return 0;
  }
  if(n<0)
  {
    return INT32_MAX;
  }
  
  if(index>=primes.size() && n!=0)
  {
    return INT32_MAX;
  }
  // take 
  int take = INT32_MAX;
  if (n - primes[index] >= 0) {
      int temp = solve(index, primes, n - primes[index]);
      if (temp != INT32_MAX) take = 1 + temp;
  }
  // non_take
  int non_take = solve(index+1,primes,n);

  return min(take,non_take);
}

// recursion + memoization
int solve_mem(int index, vector<int>& primes, int n, vector<vector<int>>& dp)
{
  if(n==0)
  {
    return 0;
  }
  if(n<0)
  {
    return INT32_MAX;
  }
  
  if(index>=primes.size() && n!=0)
  {
    return INT32_MAX;
  }
  if(dp[index][n]!=-1)
  {
    return dp[index][n];
  }
  // take 
  int take = INT32_MAX;
  if (n - primes[index] >= 0) {
      int temp = solve_mem(index, primes, n - primes[index],dp);
      if (temp != INT32_MAX) take = 1 + temp;
  }
  // non_take
  int non_take = solve_mem(index+1,primes,n,dp);

  return dp[index][n]=min(take,non_take);
}

// tabulation Method
int solve_tab(int n, int m, vector<int>& primes)
{
  vector<vector<int>> dp(primes.size()+1,vector<int>(n+1,0));

  for(int j=0; j<dp[0].size(); j++)
  {
    dp[primes.size()][j]=INT32_MAX;
  }

  dp[primes.size()][0]=0;

  for(int i=primes.size()-1; i>=0; i--)
  {
    for(int j=1; j<=n; j++)
    {
      int take = INT32_MAX;
      if (j - primes[i] >= 0) {
          int temp = dp[i][j-primes[i]];
          if (temp != INT32_MAX) take = 1 + temp;
      }
      // non_take
      int non_take = dp[i+1][j];

      dp[i][j]=min(take,non_take);
    }
  }
  return dp[0][n];

}

// space_optim
int solve_optim(int n, int m, vector<int>& primes)
{
  //vector<vector<int>> dp(primes.size()+1,vector<int>(n+1,0));
  vector<int> curr(n+1,0);
  vector<int> next(n+1,INT_MAX);
  // for(int j=0; j<dp[0].size(); j++)
  // {
  //   dp[primes.size()][j]=INT32_MAX;
  // }

  next[0]=0;

  for(int i=primes.size()-1; i>=0; i--)
  {
    for(int j=1; j<=n; j++)
    {
      int take = INT32_MAX;
      if (j - primes[i] >= 0) {
          int temp = curr[j-primes[i]];
          if (temp != INT32_MAX) take = 1 + temp;
      }
      // non_take
      int non_take = next[j];

      curr[j]=min(take,non_take);
    }
    next = curr;
  }
  return next[n];

}
int main()
{
  int n=11;
  int m=3;
  vector<int> primes = sieve_algorithm(n,m);
  vector<vector<int>> dp(primes.size(),vector<int>(n+1,-1));
  cout<<primes.size()<<endl;
  for(int i=0; i<primes.size(); i++)
  {
    cout<<primes[i]<<",";
  }
  cout<<endl;

  cout<<solve_optim(n,m,primes);
  return 0;
}