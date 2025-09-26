#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

// Time complexity of DP => (number of sub problems * Transition time)

class Solution {
private:
    // int solve(int i, int amount, vector<int>& coins)
    // {
    //     int n=coins.size();
    //     if(amount==0)
    //     {
    //         return 1;
    //     }
    
    //     if(amount<0)
    //     {
    //         return 0;
    //     }

    //     if(amount>0 && i>=n)
    //     {
    //         return 0;
    //     }

    //     int ans=solve(i,amount-coins[i],coins)+solve(i+1,amount,coins);

    //     return ans;
    // }

    // int solveMem(int i, int amount, vector<int>& coins,vector<vector<int>>& dp)
    // {
    //     int n=coins.size();
    //     if(amount==0)
    //     {
    //         return 1;
    //     }
    
    //     if(amount<0)
    //     {
    //         return 0;
    //     }

    //     if(amount>0 && i>=n)
    //     {
    //         return 0;
    //     }

    //     if(dp[i][amount]!=-1)
    //     {
    //         return dp[i][amount];
    //     }
    //     int ans=(solveMem(i,amount-coins[i],coins,dp)%MOD+solveMem(i+1,amount,coins,dp)%MOD)%MOD;
        
    //     dp[i][amount]=ans%MOD;
    //     return ans;
    // }
public:
    int solveTab(int amount, vector<int>& coins)
    {
      int n=coins.size();
      vector<vector<int>> dp(n+1,vector<int>(amount+1,0));

      for(int i=0; i<=n; i++)
      {
        dp[i][0]=1;
      }

      for(int i=n-1; i>=0; i--)
      {
        for(int a=1; a<=amount; a++)
        {
          int skipping = dp[i+1][a];

          int picking = 0;
          if(a-coins[i]>=0)
          {
            picking += dp[i][a-coins[i]];
          }
          
          // transition 
          dp[i][a]=((skipping%MOD)+(picking%MOD))%MOD;
        }
      }

      return dp[0][amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        //vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        //return solveMem(0,amount,coins,dp)%MOD;

        return solveTab(amount,coins)%MOD;
    }
};

int main()
{
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> coins(n);
    for(int i=0; i<n; i++)
    {
        cin>>coins[i];
    }

    Solution obj;
    cout<<obj.change(x,coins)<<endl;

    return 0;
}