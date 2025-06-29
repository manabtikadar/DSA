#include<bits/stdc++.h>

using namespace std;
int node(int start_index, int end_index, int pivot, vector<int>& arr)
{
    int max_left_leaf_node = INT_MIN;
    int max_right_leaf_node = INT_MIN;
    //int n = arr.size();
    // if(pivot==start_index)
    // {
    //     max_left_leaf_node = arr[start_index];
    // }
    // if(pivot==end_index-1)
    // {
    //     max_right_leaf_node = arr[end_index];
    // }

    for(int i=start_index; i<=pivot; i++)
    {
        max_left_leaf_node = max(max_left_leaf_node, arr[i]);
    }
    for(int i=pivot+1; i<=end_index; i++)
    {
        max_right_leaf_node = max(max_right_leaf_node, arr[i]);
    }
    return max_left_leaf_node*max_right_leaf_node;
}
int solve(int start_index, int end_index, vector<int>& arr)
{
    if(start_index==end_index)
    {
        return 0;
    }
    if(end_index == start_index+1)
    {
        return arr[start_index]*arr[end_index];
    }
    int ans = INT_MAX;
    for(int k=start_index; k<end_index; k++)
    {
      int left=solve(start_index,k,arr);
      int right=solve(k+1,end_index,arr);
      
      int root_node = node(start_index,end_index,k,arr);
      ans = min(ans, root_node+left+right);
    }
    return ans;
}
int main(){
  vector<int> arr={1,2,3,4};//{7,5,12,2,2,3,13,8,4,9,12,9,3,10,4,13,7,5,15};
  int n = arr.size();
  cout<<solve(0,n-1,arr);
  return 0;
}