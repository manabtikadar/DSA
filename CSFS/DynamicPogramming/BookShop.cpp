#include <bits/stdc++.h>
using namespace std;

int solveMem(int i, int cost, int n, vector<int>& price, vector<int>& pages, vector<vector<int>>& dp) {
    if (cost == 0) return 0;
    if (cost < 0) return -1e9;  // effectively "minus infinity"
    if (i >= n) return 0;

    if (dp[i][cost] != -1) return dp[i][cost];

    // take
    int take = pages[i] + solveMem(i + 1, cost - price[i], n, price, pages, dp);
    int not_take = solveMem(i + 1, cost, n, price, pages, dp);

    return dp[i][cost] = max(take, not_take);
}
int solveTab(int n,int cost,vector<int>& price,vector<int>& pages)
{
  vector<vector<int>> dp(n+1,vector<int>(cost+1,0));

  for(int i=n-1; i>=0; i--)
  {
    for(int c=1; c<=cost; c++)
    {
      int take=INT_MIN;
      if(c-price[i]>=0)
      {
       take=pages[i]+dp[i+1][c-price[i]];
      }
      int not_take=dp[i+1][c];

      dp[i][c]=max(take,not_take);
    }
  }

  return dp[0][cost];
}
int BookShop(int n, int cost, vector<int>& price, vector<int>& pages) {
    //vector<vector<int>> dp(n, vector<int>(cost + 1, -1));
    return solveTab(n,cost,price,pages);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, cost;
    cin >> n >> cost;
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    cout << BookShop(n, cost, price, pages) << "\n";
    return 0;
}
