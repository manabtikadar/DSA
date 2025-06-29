#include<bits/stdc++.h>

using namespace std;
int solve(int index, bool canBuy, vector<int>& prices, int num_transaction) 
{
    if (index >= prices.size()||num_transaction==0) return 0;

    if (canBuy) {
        // Two options: Buy or skip
        int buy = -prices[index] + solve(index + 1, false, prices,num_transaction-1);
        int not_buy = solve(index + 1, true, prices,num_transaction);
        return max(buy, not_buy);
    } else {
        // Two options: Sell or skip
        int sell = prices[index] + solve(index + 1, true, prices,num_transaction-1);
        int not_sell = solve(index + 1, false, prices,num_transaction);
        return max(sell, not_sell);
    }
}
int solve_mem(int index, bool canBuy, vector<int>& prices, int num_transaction,vector<vector<vector<int>>>& dp) 
{
    if (index == prices.size()) 
        return 0;
    if(num_transaction==0)
        return 0;
    if(dp[index][canBuy][num_transaction]!=-1)
    {
        return dp[index][canBuy][num_transaction];
    }
    int profit=0;
    if (canBuy) {
        // Two options: Buy or skip
        int buy = -prices[index] + solve_mem(index + 1, false, prices,num_transaction,dp);
        int not_buy = solve_mem(index + 1, true, prices,num_transaction,dp);
        profit = max(buy, not_buy);
    } else {
        // Two options: Sell or skip
        int sell = prices[index] + solve_mem(index + 1, true, prices,num_transaction-1,dp);
        int not_sell = solve_mem(index + 1, false, prices,num_transaction,dp);
        profit = max(sell, not_sell);
    }
    dp[index][canBuy][num_transaction] = profit;
    return dp[index][canBuy][num_transaction];
}
int solve_tab(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

    for(int index=n-1; index>=0; index--)
    {
        for(int canBuy=0; canBuy<=1; canBuy++)
        {
            for(int num_transaction=1; num_transaction<=2; num_transaction++)
            {
                int profit=0;
                if (canBuy) {
                    // Two options: Buy or skip
                    int buy = -prices[index] + dp[index+1][0][num_transaction];
                    int not_buy = dp[index+1][1][num_transaction];
                    profit = max(buy, not_buy);
                } else {
                    // Two options: Sell or skip
                    int sell = prices[index] + dp[index+1][1][num_transaction-1];
                    int not_sell = dp[index+1][0][num_transaction];
                    profit = max(sell, not_sell);
                } 
                dp[index][canBuy][num_transaction] = profit;
            }
        }
    }
    return dp[0][1][2];
}
int solve_spaceoptim(vector<int>& prices)
{
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    vector<vector<int>> next(2,vector<int>(3,0));
    vector<vector<int>> curr(2,vector<int>(3,0));
    for(int index=n-1; index>=0; index--)
    {
        for(int canBuy=0; canBuy<=1; canBuy++)
        {
            for(int num_transaction=1; num_transaction<=2; num_transaction++)
            {
                int profit=0;
                if (canBuy) {
                    // Two options: Buy or skip
                    int buy = -prices[index] + next[0][num_transaction];
                    int not_buy = next[1][num_transaction];
                    profit = max(buy, not_buy);
                } else {
                    // Two options: Sell or skip
                    int sell = prices[index] + next[1][num_transaction-1];
                    int not_sell = next[0][num_transaction];
                    profit = max(sell, not_sell);
                } 
                curr[canBuy][num_transaction] = profit;
            }
            next = curr;
        }
    }
    return next[1][2];
}
int main()
{
  vector<int> prices={3,3,5,0,0,3,1,4};
  cout<<solve_spaceoptim(prices);
  return 0;
}
