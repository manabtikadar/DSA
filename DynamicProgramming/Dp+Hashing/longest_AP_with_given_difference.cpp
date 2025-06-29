#include<bits/stdc++.h>

using namespace std;
int longestSubsequence(vector<int>& arr, int difference) {
    int n = arr.size();
    int ans = 0;
    unordered_map<int, int> dp;

    for(int i=0; i<n; i++)
    {
        int key = arr[i]-difference;
        int tempAns = 0;
        if(dp.count(key))
        {
            tempAns = dp[key];
        }

        dp[arr[i]]=1+tempAns;

        ans = max(ans,dp[arr[i]]);
    }
    return ans;
}
int main()
{
  vector<int> arr={1,2,3,4};
  int difference = 1;
  cout<<longestSubsequence(arr,difference);
  return 0;
}