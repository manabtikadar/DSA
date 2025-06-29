#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int minimum_cost_ticket(vector<int>& days, vector<int>& cost_array, int i, vector<int>& costs, int Total_cost, vector<int>& cost_plan)
{
  int min_cost=INT16_MAX;
  //base Case
  if(i>=days.size())
  {
    costs.push_back(Total_cost);
    return Total_cost;
  }

  for(int j=0;j<cost_plan.size();j++)
  {
    Total_cost=Total_cost+cost_array[j];
    int current_day = days[i] + cost_plan[j] - 1;
    bool found = false;
    int p = i;
    for (int k = 0; k < days.size(); k++) {
        if (days[k] > current_day) {
            i = k;
            found = true;
            break;
        }
    }
    if (!found) {
        i = current_day;
    }
    min_cost = min(min_cost,minimum_cost_ticket(days,cost_array,i,costs,Total_cost,cost_plan));
    Total_cost=Total_cost-cost_array[j];
    i = p;
  }
  return min_cost;
}

int solve(int n, vector<int>& days, vector<int>& cost_array, int index)
{
  //BASE CASE
  if(index>=n)
  {
    return 0;
  }

  //1 day pass
  int option1 = cost_array[0] + solve(n,days,cost_array,index+1);

  int i;
  // 7 day pass
  for(i=index;i<n&&days[i]<days[index]+7;i++);
  int option2 = cost_array[1]+solve(n,days,cost_array,i);

  //30 day pass
  // 7 day pass
  for(i=index;i<n&&days[i]<days[index]+30;i++);
  int option3 = cost_array[2]+solve(n,days,cost_array,i);

  return min(option1,min(option2,option3));
}
//Top - Down
int solve_memoization(int n, vector<int>& days, vector<int>& cost_array, int index, vector<int>& dp)
{
  //BASE CASE
  if(index>=n)
  {
    return 0;
  }
  if(dp[index]!=-1)
  {
    return dp[index];
  }

  //1 day pass
  int option1 = cost_array[0] + solve_memoization(n,days,cost_array,index+1,dp);

  int i;
  // 7 day pass
  for(i=index;i<n&&days[i]<days[index]+7;i++);
  int option2 = cost_array[1]+solve_memoization(n,days,cost_array,i,dp);

  //30 day pass
  // 7 day pass
  for(i=index;i<n&&days[i]<days[index]+30;i++);
  int option3 = cost_array[2]+solve_memoization(n,days,cost_array,i,dp);

  dp[index]=min(option1,min(option2,option3));
  return dp[index];
}

// Tabulation
int solve_tabulation(int n, vector<int>& days, vector<int>& cost_array, int index)
{
  vector<int> dp(n+1,0);
  //BASE CASE
  dp[n]=0;

  for(int j=n-1; j>=0;j--)
  {
    // 1 day pass
    int option1 = cost_array[0] + dp[j+1];

    int i; 
    // 7 day pass
    for(i=j;i<n&&days[i]<days[j]+7;i++);
    int option2 = cost_array[1]+dp[i];

    for(i=j;i<n&&days[i]<days[j]+30;i++);
    int option3 = cost_array[2]+dp[i];

    dp[j]=min(option1,min(option2,option3));
  }

  return dp[index];
}

//space optimization
int minimumCost_spaceoptim(int n, vector<int> days, vector<int> cost)
{
  int ans = 0;

  queue<pair<int,int>> month;
  queue<pair<int,int>> weekly;

  for(int day:days)
  {
    //step1: remove expired days
    while(!month.empty() && month.front().first+30<=day)
    {
      month.pop();
    }

    while(!weekly.empty() && weekly.front().first+7<=day)
    {
      weekly.pop();
    }

    // step2: add cost for current day
    weekly.push(make_pair(day,ans+cost[1]));
    month.push(make_pair(day,ans+cost[2]));

    ans=min(ans+cost[0],min(weekly.front().second,month.front().second));
  }

  return ans;
}

int main()
{
  vector<int> days={1,3,4,5,7,8,10};
  // vector<int> cost_array={2,7,15};
  // vector<int> days={1,2,3,4,5,6,7,8,9,10,30,31};
  vector<int> cost_array={2,7,15};
  vector<int> cost_plan={1,7,30};
  vector<int> costs;
  int n = days.size();
  int Total_cost=0;
  int i=0;
  // cout<<minimum_cost_ticket(days,cost_array,i,costs,Total_cost,cost_plan)<<endl;
  cout<<solve_tabulation(n,days,cost_array,i)<<endl;
  cout<<minimumCost_spaceoptim(n,days,cost_array)<<endl;
  cout<<"{";
  for(int i=0;i<costs.size();i++)
  {
    cout<<costs[i]<<" ";
  }
  cout<<"}"<<endl;
  
  return 0;
}