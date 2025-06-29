#include<iostream>
#include<vector>

using namespace std;

void PowerSet(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
  if(index >= nums.size())
  { cout<<"{";
    for(int i:output)
    {
      cout<<i;
    }
    cout<<"}";
    ans.push_back(output);
    return;
  }

  // exclude
  PowerSet(nums, output, index+1, ans);

  // include
  output.push_back(nums.at(index));
  PowerSet(nums, output, index+1, ans);
}

void Subsequences(string a, string output1, int index, vector<string> &ans1)
{
  if(index >= a.length())
  { cout<<"{"<<output1<<"}";
    ans1.push_back(output1);
    return;
  }

  // exclude
  Subsequences(a, output1, index+1, ans1);

  // include
  output1.push_back(a[index]);
  Subsequences(a, output1, index+1, ans1);
}

int main()
{
  // vector<vector<int>> ans;
  // vector<int> output;
  // vector<int> nums={1,2,3};
  int index = 0;
  //PowerSet(nums, output, index, ans);

  vector<string> ans1;
  string output1="";
  string a="abc";
  
  Subsequences(a,output1,index,ans1);
}