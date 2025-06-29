#include<iostream>
#include<vector>

using namespace std;

// using recursion
int maxRobbery(vector<int> ARR, int i, int temp, int flag)
{
  // Base Condition
  if(i>=ARR.size())
  { 
   return temp;
  }
  //inc
  temp = temp + ARR[i];
  if(i==0)
  {
    flag = 1;
  }
  int m = maxRobbery(ARR,i+2,temp,flag);
  temp = temp - ARR[i];
  //exclude
  if(i==0)
  {
    flag = 0;
  }
  int n = maxRobbery(ARR,i+1,temp,flag);
  if(flag==1 && i==(ARR.size()-1))
  {
    return n;
  }
  return max(m,n);
}

// Top Down Approach
int maxRobbery_memorization(vector<int> ARR, int i, int temp, int flag, vector<int> dp)
{
  // Base Condition
  if(i>=ARR.size())
  { 
    return temp;
  }
  if(dp[i]!=-1)
  {
    return dp[i];
  }
  //inc
  temp = temp + ARR[i];
  if(i==0)
  {
    flag = 1;
  }
  int m = maxRobbery_memorization(ARR,i+2,temp,flag,dp);
  temp = temp - ARR[i];
  //exclude
  if(i==0)
  {
    flag = 0;
  }
  int n = maxRobbery_memorization(ARR,i+1,temp,flag,dp);
  if(flag==1 && i==(ARR.size()-1))
  {
    dp[i]=n;
    return dp[i];
  }
  dp[i] = max(m,n);
  return dp[i];
}

// Tabulation
int House_robbery_optimized(vector<int> array)
{
  int n= array.size();
  int prev1=0,prev2=0;

  for(int i=0;i<n;i++)
  {
    prev1 = prev1+array[i];
    prev2 = prev2+0;
    
    int current= max(prev1,prev2);
    prev1=prev2;
    prev2=current;
  }
  return prev2;
}

int main()
{
  vector<int> ARR={60,10,30,40,500,600};
  int temp = 0;
  int flag = 0;
  int i = 0;
  int n = ARR.size();
  vector<int> first,last;
  for(int i=0;i<n;i++)
  {
    if(i!=n-1)
    {
      first.push_back(ARR[i]);
    }
    if(i!=0)
    {
      last.push_back(ARR[i]);
    }
  }
  cout<<"first MAX :"<<House_robbery_optimized(first)<<endl;
  cout<<"last MAX :"<<House_robbery_optimized(last)<<endl;
  cout<<"final MAX :"<<max(House_robbery_optimized(first),House_robbery_optimized(last));
  return 0;
}