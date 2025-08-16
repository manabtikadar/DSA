#include<bits/stdc++.h>

using namespace std;

string restore_original(string s)
{
  int m=s.size();

  int count_i=0;
  vector<int> indices_i;
  for(int k=0; k<m; k++)
  {
    if(s[k]=='i')
    {
      count_i++;
      indices_i.push_back(k);
    }
  }

  int original_string_length = (m + count_i)/2;

  if(2*original_string_length - count_i != m)
  {
    return "Impossible";
  }

  string ans;
  for(int k=m-1; k>=0 && original_string_length>0; k--)
  {
    ans += s[k];
    original_string_length--;
  }

  reverse(ans.begin(), ans.end());
  return ans;
}


int main()
{
  string s;
  cin >> s;
  cout << restore_original(s) << endl;
}