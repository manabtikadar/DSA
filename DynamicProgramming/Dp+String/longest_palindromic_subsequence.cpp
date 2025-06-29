#include<bits/stdc++.h>

using namespace std;
int solve(int index1, int index2, string text1, string text2)
{
    int len1 = text1.size();
    int len2 = text2.size();

    if(index1>=len1||index2>=len2)
    {
        return 0;
    }
    if(text1[index1]==text2[index2])
    {
        return 1+solve(index1+1,index2+1,text1,text2);
    }
    else
    {
        return max(solve(index1+1,index2,text1,text2),solve(index1,index2+1,text1,text2));
    }
}
int solve_mem(int index1, int index2, string text1, string text2,vector<vector<int>>& dp)
{
    int len1 = text1.length();
    int len2 = text2.length();

    if(index1==len1||index2==len2)
    {
        return 0;
    }
    if(dp[index1][index2]!=-1)
    {
        return dp[index1][index2];
    }
    int ans=0;
    if(text1[index1]==text2[index2])
    {
        ans=1+solve_mem(index1+1,index2+1,text1,text2,dp);
    }
    else
    {
        ans=max(solve_mem(index1+1,index2,text1,text2,dp),solve_mem(index1,index2+1,text1,text2,dp));
    }
    return dp[index1][index2]=ans;
}

int solve_optim(string text1,string text2)
{
    int len1 = text1.size();
    int len2 = text2.size();
    vector<int> next(len2+1,0);
    vector<int> curr(len2+1,0);

    for(int index1=len1-1; index1>=0; index1--)
    {
        for(int index2=len2-1; index2>=0; index2--)
        {
            int ans=0;
            if(text1[index1]==text2[index2])
            {
                ans=1+next[index2+1];
            }
            else
            {
                ans=max(next[index2],curr[index2+1]);
            }
            curr[index2]=ans;
        }
        next=curr;
    }
    return next[0];
}
int main()
{
  string text1="bbbab";
  string text2=text1;
  reverse(text2.begin(),text2.end());
  
  cout<<solve_optim(text1,text2);
  return 0;
}