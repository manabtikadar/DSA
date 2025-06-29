#include<iostream>
#include<vector>
using namespace std;

int maximumsum1(vector<int> array, int i, int temp, vector<int> dp)
{
  if(i>=array.size())
  {
    cout<<"temp "<<temp<<endl;
    if(temp>dp[i])
    {
      dp[i]=temp;
    }
    return dp[i];
  }

  //include
  temp = temp+array[i];
  dp[i+2]=maximumsum1(array, i+2, temp,dp);
  return dp[i+2];
  temp = temp-array[i];
  //exclude
  temp = temp+0;
  dp[i+1]=maximumsum1(array, i+1, temp,dp);
  return dp[i+1];
}

int maximumsum(vector<int> array, int i, int temp, vector<int>&dp)
{
  if(i>=array.size())
  {
    cout<<"temp "<<temp<<endl;
    return temp;
  }
  if(dp[i]!=-1)
  {
    return dp[i];
  }

  //include
  temp = temp+array[i];
  int inc =maximumsum(array, i+2, temp,dp);
  temp = temp-array[i];
  //exclude
  temp = temp+0;
  int exc =maximumsum(array, i+1, temp,dp);
  dp[i]=max(inc,exc);
  return dp[i];
}

// Top-Down Approach
int maximumsum2(vector<int> array,int n, vector<int>& dp)
{
  if(n<0)
  {
    return 0; 
  }
  if(n==0)
  {
    dp[n]=array[n];
    return dp[n];
  }
  if(dp[n]!=-1)
  {
    return dp[n];
  }
  
  int incl = maximumsum2(array,n-2,dp)+array[n];
  int excl = maximumsum2(array,n-1,dp)+0;

  dp[n]=max(incl,excl);
  return dp[n];
}

// Tabulation 
int maximumsum3(vector<int> array)
{
  int n= array.size();
  vector<int> dp(n,0);
  int incl,excl;
   dp[0]=array[0];

  for(int i=1;i<n;i++)
  {
    // int incl = dp[i-2]+array[i];
    // int excl = dp[i-1]+0;
    if(i-2<0)
    {
       incl = array[i];
    }
    else
    { 
       incl = dp[i-2]+array[i];
    }
    if(i-1<0)
    {
       excl = 0;
    }
    else
    { 
       excl = dp[i-1]+0;
    }
    dp[i]= max(incl,excl);
  }
  return dp[n-1];
}
// space optimization
int maximumsum4(vector<int> array)
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
  vector<int> array={9,9,8,2};
  int n=array.size();
  vector<int> dp(n,-1);
  int i=0;
  int maxSum=0;
  int temp=0;
  cout<<maximumsum2(array,n-1,dp)<<endl;
  for(int i=0;i<dp.size();i++)
  {
    cout<<dp[i]<<" ";
  }
  cout<<endl;
  return 0;
}