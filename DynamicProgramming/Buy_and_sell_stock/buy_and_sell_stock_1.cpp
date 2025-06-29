#include<bits/stdc++.h>

using namespace std;
int maxProfit(vector<int>& prices) {
  int n = prices.size();
  int profit = 0;
  int minimum = prices[0];
  // sell_day
  // if i sell the stock at ith day --> i have definately brought the stock in 0 th day -- i-1 th day --> and for maximium profit it have to buy the stock at minimum price 
  for(int i=1; i<n; i++)
  {
      int diff = prices[i]-minimum;
      profit = max(profit , diff);
      minimum = min(minimum,prices[i]);
  }

  return profit;
}
int main()
{
  vector<int> prices={7,1,5,3,6,4};
  cout<<maxProfit(prices);
  return 0;
}
