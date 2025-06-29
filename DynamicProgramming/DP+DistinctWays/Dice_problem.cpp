#include<iostream>
#include<vector>

using namespace std;

int solve_1(int num_dice, int num_faces, int sum , int target_sum, int index)
{
    if(index>=num_dice)
    {
        return sum == target_sum ? 1 : 0;
    }
    int ans=0;
    for(int i=1; i<=num_faces; i++)
    {
        sum = sum+i;
        ans += solve(num_dice, num_faces, sum, target_sum, index+1);
        sum = sum-i;
    }
    return ans;
}
int solve_mem1(int num_dice, int num_faces, int sum , int target_sum, int index, vector<vector<int>>& dp)
{   
    if(sum>target_sum)
    {
        return 0;
    }
    if(index>=num_dice)
    {
        return sum == target_sum ? 1 : 0;
    }
    if(dp[index][sum]!=-1)
    {
        return dp[index][sum];
    }
    long long int ans=0;
    for(int i=1; i<=num_faces; i++)
    {
        ans += solve_mem1(num_dice, num_faces, sum+i, target_sum, index+1,dp);
    }
    dp[index][sum]=(ans%MOD);
    return dp[index][sum];
}
int solve_2(int num_dice, int num_faces, int target_sum)
{
    if(target_sum<0)
    {
        return 0;
    }
    if(num_dice==0 && target_sum != 0)
    {
        return 0;
    }
    if(num_dice!=0 && target_sum == 0)
    {
        return 0;
    }
    if(num_dice==0 && target_sum==0)
    {
        return 1;
    }
    int ans=0;
    for(int i=1; i<=num_faces; i++)
    {
        ans += solve_2(num_dice-1,num_faces,target_sum-i);
    }
    return ans;
}
int solve_mem(int num_dice, int num_faces, int target_sum, vector<vector<int>>& dp)
{
    if(target_sum<0)
    {
        return 0;
    }
    if(num_dice==0 && target_sum != 0)
    {
        return 0;
    }
    if(num_dice!=0 && target_sum == 0)
    {
        return 0;
    }
    if(num_dice==0 && target_sum==0)
    {
        return 1;
    }
    if(dp[num_dice][target_sum]!=-1)
    {
        return dp[num_dice][target_sum];
    }
    long long int ans=0;
    for(int i=1; i<=num_faces; i++)
    {
        ans += solve_mem(num_dice-1,num_faces,target_sum-i,dp);
    }
    dp[num_dice][target_sum]=(ans%MOD);
    return dp[num_dice][target_sum];
}
int solve_tab(int num_dice, int num_faces, int target_sum)
{
    vector<vector<long long int>> dp(num_dice+1,vector<long long int>(target_sum+1,0));
    dp[0][0]=1;
    for(int i=1;i<=num_dice;i++)
    {
        for(int j=i;j<=target_sum;j++)
        {   
            long long int ans=0;
            for(int k=1; k<=num_faces; k++)
            {
              if(j-k>=0)
              {
                ans = ans + dp[i-1][j-k];
              } 
            }
            dp[i][j]=(ans%MOD);
        }
    }
    return (dp[num_dice][target_sum]%MOD);
}
int solve_optim(int num_dice, int num_faces, int target_sum)
{
    vector<long long int> prev(target_sum+1,0);
    vector<long long int> curr(target_sum+1,0);
    prev[0]=1;
    for(int i=1;i<=num_dice;i++)
    {
        for(int j=1;j<=target_sum;j++)
        {   
            long long int ans=0;
            for(int k=1; k<=num_faces; k++)
            {
                if(j-k>=0)
                {
                  ans = ans+prev[j-k];
                } 
            }
            curr[j]=(ans%MOD);
        }
        prev=curr;
    }
    return (prev[target_sum]%MOD);
}
int main()
{
  int num_dice=3;
  int num_faces=6;
  int sum=0;
  int target_sum=12;
  int index=0;
  int ans=0;
  cout<<solve(num_dice, num_faces, sum, target_sum, index)<<endl;
  return 0;
}