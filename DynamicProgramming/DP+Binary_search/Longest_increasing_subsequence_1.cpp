#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solveOptimal(int n ,vector<int> array)
{
  if(n==0)
  {
    return 0;
  }

  vector<int> ans;
  ans.push_back(array[0]);

  for(int i=1;i<array.size();i++)
  {
    if(ans.back()<array[i])
    {
      ans.push_back(array[i]);
    }
    else
    {
      // find index of just large element
      int index = lower_bound(ans.begin(),ans.end(),array[i])-ans.begin();// binary search 
      ans[index]=array[i];
    }
  }
  return ans.size();
}

int main()
{
  vector<int> array= {3,25,5,6,6,6,6,4,7,2};
  int n = array.size();
  cout<<solveOptimal(n,array)<<endl;
  sort(array.begin(),array.end());
  for(int i=0; i<array.size();i++)
  {
    cout<<array[i]<<" ";
  }
  cout<<endl;
  // int index1 = upper_bound(array.begin(),array.end(),6)-array.begin();
  // cout<<index1<<endl;
  // int index2 = lower_bound(array.begin(),array.end(),6)-array.begin();
  // cout<<index2<<endl;
  return 0;
}