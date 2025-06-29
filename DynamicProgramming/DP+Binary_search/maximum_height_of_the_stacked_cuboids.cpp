#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
check(vector<int> base, vector<int> newbox)
{
  if(newbox[0]<=base[0] && newbox[1] <= base[1] && newbox[2] <= base[2])
     return true;
  else 
     return false;
}
int solve(int n, vector<vector<int>>& array)
{
  vector<int> current(n+1,0);
  vector<int> next(n+1,0);
  for(int curr=n-1 ; curr>=0; curr--)
  {
    for(int prev=curr-1;prev>=-1;prev--)
    {
      int include=0;
      if(prev==-1||check(array[curr],array[prev]))
      {
        include = array[curr][2] + next[curr+1];
      }

      int exclude = next[prev+1];

      current[prev+1]=max(include,exclude);
    }
    next = current;
  }
  return next[0];
}
int main()
{
  vector<vector <int>> cuboids = {{38,25,45},{76,35,3}};

  int n = cuboids.size();
  for(int i=0; i<n; i++)
  {
    sort(cuboids[i].begin(),cuboids[i].end());
  }
  sort(cuboids.begin(), cuboids.end(), [](const vector<int>& a, const vector<int>& b)
  {
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]<b[0];
  });
  for(int i=0; i<cuboids.size(); i++)
  {
    for(int j=0; j<cuboids[i].size(); j++)
    {
      cout<<cuboids[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<solve(n,cuboids)<<endl;
  return 0;
}