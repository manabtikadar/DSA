#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int>& obstacles,int current_lane, int current_pose, int& jump, int destination)
{
  if(current_pose==destination)
  {
    return 0;
  }

  // move forward
  if(obstacles[current_pose+1]!=current_lane)
  {
    return solve(obstacles,current_lane,current_pose+1,jump,destination);
  }
  else
  {
    //sideway jump
    int ans = INT16_MAX;
    for(int i=1; i<=3; i++)
    {
      if(i!=current_lane && obstacles[current_pose]!=i)
      {
        ans = min(ans,solve(obstacles,i,current_pose,jump,destination));
      }
    }
    jump = ans+1;
    return ans+1;
  }
}

int solve_memoization(vector<int>& obstacles,int current_lane, int current_pose, int& jump, int destination, vector<vector<int>>& dp)
{
  if(current_pose==destination)
  {
    return 0;
  }
  if(dp[current_lane][current_pose]!=-1)
  {
    return dp[current_lane][current_pose];
  }

  // move forward
  if(obstacles[current_pose+1]!=current_lane)
  {
    dp[current_lane][current_pose] = solve_memoization(obstacles,current_lane,current_pose+1,jump,destination,dp);
    return dp[current_lane][current_pose];
  }
  else
  {
    //sideway jump
    int ans = INT16_MAX;
    for(int i=1; i<=3; i++)
    {
      if(i!=current_lane && obstacles[current_pose]!=i)
      {
        ans = min(ans,1+solve_memoization(obstacles,i,current_pose,jump,destination,dp));
      }
    }
    dp[current_lane][current_pose] = ans;
    return dp[current_lane][current_pose];
  }
}
// tabulation
int solve_tabulation(vector<int>& obstacles) {
  int n = obstacles.size();
  vector<vector<int>> dp(4, vector<int>(n, INT16_MAX)); 
  dp[1][n-1] = dp[2][n-1] = dp[3][n-1] = 0;

  for (int i = n - 2; i >= 0; i--) {
      for (int j = 1; j <= 3; j++) {
          if (obstacles[i] != j) { 
              dp[j][i] = dp[j][i+1]; 

              int ans = INT16_MAX;
              for (int k = 1; k <= 3; k++) {
                  if (k != j && obstacles[i] != k) {
                      ans = min(ans, 1 + dp[k][i+1]);
                  }
              }
              dp[j][i] = min(dp[j][i], ans);
          }
      }
  }
  return dp[2][0]; 
}

// Tabulation
int solve_tabulation2(vector<int>& obstacles)
{
  int n = obstacles.size()-1;
  vector<vector<int>> dp(4, vector<int>(obstacles.size(), INT16_MAX)); 
  dp[0][n] = dp[1][n] = dp[2][n] = dp[3][n] = 0;

  for (int i = n - 1; i >= 0; i--) {
      for (int j = 1; j <= 3; j++) {
        if(obstacles[i+1]!=j)
        {
          dp[j][i]=dp[j][i+1];
        }
        else
        {
          //sideway jump
          int ans = INT16_MAX;
          for(int k=1; k<=3; k++)
          {
            if(k!=j && obstacles[i]!=k)
            {
              ans = min(ans,1+dp[k][i+1]);
            }
          }
          dp[j][i] = ans;
        }
      }
  }
  return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
}

int solve_spaceoptim(vector<int>& obstacles)
{
  int n = obstacles.size()-1;
  vector<int> curr(4,INT16_MAX);
  vector<int> next(4,0);
 

  for (int i = n - 1; i >= 0; i--) {
      for (int j = 1; j <= 3; j++) {
        if(obstacles[i+1]!=j)
        {
          curr[j]=next[j];
        }
        else
        {
          //sideway jump
          int ans = INT16_MAX;
          for(int k=1; k<=3; k++)
          {
            if(k!=j && obstacles[i]!=k)
            {
              ans = min(ans,1+next[k]);
            }
          }
          curr[j] = ans;
        }
      }
      next = curr;
  }
  return min(curr[2],min(1+curr[1],1+curr[3]));
}

int main()
{
  vector<int> obstacles={0,2,1,0,3,0};
  int current_lane = 2;
  int current_pose = 0;
  int jump = 0;
  int destination = obstacles.size()-1;
  vector<vector<int>> dp(4,vector<int>(obstacles.size(),-1));
  cout<<solve_memoization(obstacles,current_lane,current_pose,jump,destination,dp)<<endl;
  cout<<solve_tabulation2(obstacles)<<endl;
  cout<<solve_spaceoptim(obstacles)<<endl;
  return 0;
}