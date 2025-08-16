#include<bits/stdc++.h>

using namespace std;

vector<int> Zalgorithm(string s)
{
  int n=s.size();
  vector<int> z(n,0);

  int l=0;
  int r=0;
  for(int i=1; i<n; i++)
  {
    if(i>r)
    {
      l=r=i;
      while(r<n && s[r]==s[r-l])
      {
        r++;
      }
      r--;
      z[i]=r-l+1;
    }
    else
    {
      int k=i-l;
      if(i+z[k]<r+1)
      {
        z[i]=z[k];
      }
      else
      {
        l=i;
        while(r<n && s[r]==s[r-l])
        {
          r++;
        }
        r--;
        z[i]=r-l+1;
      }
    }
  }

  return z;
}

vector<int> matchpattern(string text, string pattern)
{
  string s = pattern + "$" + text;
  vector<int> z = Zalgorithm(s);
  vector<int> result;

  int pattern_length = pattern.size();
  for(int i = pattern_length + 1; i < z.size(); i++)
  {
    if(z[i] == pattern_length)
    {
      result.push_back(i - (pattern_length + 1));
    }
  }
  
  return result;
}

int main()
{
  string text, pattern;
  cout << "Enter the text: ";
  cin >> text;
  cout << "Enter the pattern: ";
  cin >> pattern;

  vector<int> matches = matchpattern(text, pattern);
  
  if(matches.empty())
  {
    cout << "Pattern not found in the text." << endl;
  }
  else
  {
    cout << "Pattern found at indices: ";
    for(int index : matches)
    {
      cout << index << " ";
    }
    cout << endl;
  }

  return 0;
}