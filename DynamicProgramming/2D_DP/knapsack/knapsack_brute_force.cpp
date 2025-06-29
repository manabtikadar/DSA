#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
// Brute force Approach
void knapsack_bruteforce(vector<int> arr, int i, vector<int>& Temp, vector<vector<int>>& output,vector<int> values,vector<vector<int>>& subset_values, vector<int>& Temp_values)
{
  if(i>=arr.size())
  {
    cout<<"{";
    for(int i=0;i<Temp.size();i++)
    {
      cout<<Temp[i]<<" ";
    }
    cout<<"}"<<" ";
    cout<<"{";
    for(int i=0;i<Temp_values.size();i++)
    {
      cout<<Temp_values[i]<<" ";
    }
    cout<<"}"<<endl;
    output.push_back(Temp);
    subset_values.push_back(Temp_values);
    return;
  }

  //include
  Temp.push_back(arr[i]);
  Temp_values.push_back(values[i]);
  knapsack_bruteforce(arr,i+1,Temp,output,values,subset_values,Temp_values);
  Temp.pop_back();
  Temp_values.pop_back();
  //excludde
  knapsack_bruteforce(arr,i+1,Temp,output,values,subset_values,Temp_values);
  return;
}

void solve_knapsack(vector<vector<int>> subset_values,int maxWeight,vector<vector<int>> output, vector<vector<int>>& output1, vector<int>& final_values)
{
  for(int i=0;i<output.size();i++)
  {
    int sum=0;
    int total_value=0;
    for(int j=0; j<output[i].size();j++)
    {
      sum += output[i][j];
      total_value += subset_values[i][j];
    }
    if(sum<=maxWeight)
    {
      output1.push_back(output[i]);
      final_values.push_back(total_value);
    }
  }

}

//knapsack Brute force 2
int knapsack_bruteforce2(vector<int> weight, vector<int> value, int i, int capacity)
{
  if(i==0)
  {
    if(weight[i]<=capacity)
    { 
      return value[0];
    }

    return 0;
  }

  //include
  int include=0;
  // int exclude=0;
  if(weight[i]<=capacity)
  {
     include = value[i]+knapsack_bruteforce2(weight,value,i-1,capacity-weight[i]);
  }

  //exclude
  int exclude = knapsack_bruteforce2(weight,value,i-1,capacity);
  return max(include,exclude);
}

//knapsack brute force 3
int knapsack_bruteforce3(vector<int> weight, vector<int> value, int i, int capacity)
{
  if(i>=weight.size())
  {
    return 0;
  }

  //include
  int include=0;
  // int exclude=0;
  if(weight[i]<=capacity)
  {
     include = value[i]+knapsack_bruteforce3(weight,value,i+1,capacity-weight[i]);
  }

  //exclude
  int exclude = knapsack_bruteforce3(weight,value,i+1,capacity);
  return max(include,exclude);
}


int main()
{
  vector<int> weight={25, 4, 25, 49, 9, 11, 31};
  vector<int> values={86, 55, 17, 31, 88, 82, 27};
  int n = weight.size();
  vector<int> Temp;
  vector<vector<int>> subset_values;
  vector<int> Temp_values;
  vector<vector<int>> output;
  int i=0;
  int maxWeight = 60;
  cout<<"Kanpsack brute force2: "<<knapsack_bruteforce2(weight,values,n-1,maxWeight)<<endl;
  cout<<"Kanpsack brute force3: "<<knapsack_bruteforce3(weight,values,i,maxWeight)<<endl;
  knapsack_bruteforce(weight,i,Temp,output,values,subset_values,Temp_values);
  cout<<"Print Output:"<<endl;
  // for(int i=0;i<output.size();i++)
  // {
  //   cout<<"{";
  //   for(int j=0; j<output[i].size();j++)
  //   {
  //     cout<<output[i][j]<<" ";
  //   }
  //   cout<<"}"<<endl;
  // }
  vector<vector<int>> output1;
  vector<int> final_values;
  solve_knapsack(subset_values,maxWeight,output,output1,final_values);
  for(int i=0;i<output1.size();i++)
  {
    cout<<"{";
    for(int j=0; j<output1[i].size();j++)
    {
      cout<<output1[i][j]<<" ";
    }
    cout<<"}"<<" "<<final_values[i]<<endl;
  }

  auto max_it = max_element(final_values.begin(),final_values.end());
  int Max_value = *max_it;
  cout<<"Max value The thief can Take:"<<Max_value<<endl;

  int index = distance(final_values.begin(),max_it);
  cout<<"and The products are :"<<"{";
  for(int j=0; j<output1[index].size();j++)
  {
    cout<<output1[index][j]<<" " ;
  }
  cout<<"}"<<endl;
  return 0;
}