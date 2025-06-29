#include<iostream>
#include<vector>

using namespace std;

int combination_sum(int n, int tar, vector<int> array, vector<int>& Temp, vector<vector<int>>& output)
{
  int count = 0;
  if(tar==0)
  {
    output.push_back(Temp);
    cout<<"{";
    for(int j=0; j<Temp.size(); j++)
    {
      cout<<Temp[j]<<" ";
    }
    cout<<"}"<<endl;
    return 1;
  }
  if(tar<0)
  {
    return 0;
  }
  for(int i=0; i<n; i++)
  {
    Temp.push_back(array[i]);
    count += combination_sum(n,tar-array[i],array,Temp,output);
    Temp.pop_back();
  }
  return count;
}

// Recursion + Memoization(Top Down Approach)
int combination_sum_memoization(int n, int tar, vector<int>& array, vector<int>& dp)
{
  int count = 0;
  if(tar==0)
  {
    return 1;
  }
  if(tar<0)
  {
    return 0;
  }
  
  if(dp[tar] != -1)
  {
    return dp[tar];
  }

  for(int i=0; i<n; i++)
  {
    count += combination_sum_memoization(n,tar-array[i],array,dp);
  }
  dp[tar]=count;
  
  return dp[tar];
}

// Bottom Up Approach (Tabulation)

int combination_sum_tabulation(int n, int tar, vector<int>& array)
{
  vector<int> dp(tar+1,0);
  dp[0]=1;

  for(int i=1; i<=tar; i++)
  {
    int count = 0;
    for(int j=0; j<n; j++)
    {
      if(i>=array[j])
      {
        count += dp[i-array[j]];
      }
    }
   dp[i] =count;
  }
  return dp[tar];
}

int main()
{
  vector<int> array={1,2,5};
  int n = array.size();
  int tar = 5;
  vector<int> Temp;
  vector<vector<int>> output;
  vector<int> dp(tar+1, -1);
  cout<<"Number of combination:"<<combination_sum_tabulation(n,tar,array)<<endl;
  return 0;
}