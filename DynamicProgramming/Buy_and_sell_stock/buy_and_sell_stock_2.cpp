#include<bits/stdc++.h>

using namespace std;
int solve(int index, bool canBuy, vector<int>& prices) {
    if (index >= prices.size()) return 0;

    if (canBuy) {
        // Two options: Buy or skip
        int buy = -prices[index] + solve(index + 1, false, prices);
        int not_buy = solve(index + 1, true, prices);
        return max(buy, not_buy);
    } else {
        // Two options: Sell or skip
        int sell = prices[index] + solve(index + 1, true, prices);
        int not_sell = solve(index + 1, false, prices);
        return max(sell, not_sell);
    }
}
int solve_mem(int index, vector<int>& prices, bool Buy, vector<vector<int>>& dp)
{
    int n=prices.size();
    if(index>=n)
    {
      return 0;
    }
    if(dp[index][Buy]!=-1)
    {
        return dp[index][Buy];
    }
    int profit = 0;
    // buy allowd
    if(Buy==1)
    {
        // we have two chooses now 1. buy 2. don't buy
        //buy
        int buy = -prices[index]+solve_mem(index+1,prices,0,dp);
        // Don't buy
        int not_buy = solve_mem(index+1,prices,1,dp);

        profit=max(buy,not_buy);
    }
    else
    {
        // we have two chooses now 1. buy 2. don't buy
        //buy
        int sell = prices[index]+solve_mem(index+1,prices,1,dp);
        // Don't buy
        int not_sell = solve_mem(index+1,prices,0,dp);

        profit=max(sell,not_sell);
    }
    dp[index][Buy]=profit;
    return dp[index][Buy];
}
int solve_tab(vector<int>& prices) {
    vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
    
    for(int index=prices.size()-1; index>=0; index--)
    {
        for(int canBuy=0; canBuy<2; canBuy++)
        {
            int profit=0;
            if (canBuy) {
                // Two options: Buy or skip
                int buy = -prices[index] + dp[index+1][0];
                int not_buy = dp[index+1][1];
                profit = max(buy, not_buy);
            } else {
                // Two options: Sell or skip
                int sell = prices[index] + dp[index+1][1];
                int not_sell = dp[index+1][0];
                profit = max(sell, not_sell);
            }
            dp[index][canBuy]=profit;
        }
    }
    return dp[0][1];
}
int solve_spaceoptim(vector<int>& prices) {
    vector<int> next(2,0);
    vector<int> curr(2,0);
    for(int index=prices.size()-1; index>=0; index--)
    {
        for(int canBuy=0; canBuy<2; canBuy++)
        {
            int profit=0;
            if (canBuy) {
                // Two options: Buy or skip
                int buy = -prices[index] + next[0];
                int not_buy = next[1];
                profit = max(buy, not_buy);
            } else {
                // Two options: Sell or skip
                int sell = prices[index] + next[1];
                int not_sell = next[0];
                profit = max(sell, not_sell);
            }
            curr[canBuy]=profit;
        }
        next=curr;
    }
    return next[1];
}
int main()
{
  vector<int> prices={7,6,4,3,1};
  cout<<solve_spaceoptim(prices);
  return 0;
}
