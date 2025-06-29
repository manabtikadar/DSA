#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(int n, vector<vector<int>>& envelopes)
{
  if(n==0)
  {
    return 0;
  }
  sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) return a[1] > b[1]; // Sort by height in descending order
    return a[0] < b[0];  // Sort by width in ascending order
  });
  // vector<vector<int>> ans;
  // ans.push_back(envelopes[0]);

  // for(int i=1; i<n; i++)
  // {
  //   if(envelopes[i][1]>ans.back()[1])
  //   {
  //     ans.push_back(envelopes[i]);
  //   }
  //   else
  //   {
  //     int index = lower_bound(ans.begin(),ans.end(),envelopes[i])-ans.begin();
  //     ans[index]=envelopes[i];
  //   }
  // }
  // return ans.size();
  vector<int> lis;  // Store only heights
  lis.push_back(envelopes[0][1]);

  for (int i = 1; i < n; i++) {
      int h = envelopes[i][1]; // Only consider heights
      
      if(envelopes[i][1]>lis.back())
      {
        lis.push_back(envelopes[i][1]);
      }
      else
      {
        int index = lower_bound(lis.begin(), lis.end(), h)-lis.begin();
        lis[index]=h;
      }
      
  }

  return lis.size();
}

int main()
{
  vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
  int n = envelopes.size();
  // vector<int> a=envelopes.back();
  // sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
  //   if (a[0] == b[0]) return a[1] > b[1]; // Sort by height in descending order
  //   return a[0] < b[0];  // Sort by width in ascending order
  // });
  // for(int i=0; i<envelopes.size(); i++)
  // {
  //   cout<<envelopes[i][0]<<" "<<envelopes[i][1]<<endl;
  // }
  cout<<solve(n,envelopes)<<endl;
  return 0;
}