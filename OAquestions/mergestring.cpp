#include<bits/stdc++.h>

using namespace std;

string customMerge(string s1, string s2)
{
  int n1=s1.size();
  int n2=s2.size();
  vector<int> feq_s1(26,0);
  vector<int> feq_s2(26,0);

  for(int i=0; i<s1.size(); i++)
  {
    feq_s1[s1[i]-'a']++;
  }

  for(int i=0; i<s2.size(); i++)
  {
    feq_s2[s2[i]-'a']++;
  }

  int i=0;
  int j=0;
  
  string ans="";
  while(i<n1 && j<n2)
  {
    if(feq_s1[s1[i]-'a']<feq_s2[s2[j]-'a'])
    {
      ans+=s1[i];
      i++;
    }
    else if(feq_s1[s1[i]-'a']>feq_s2[s2[j]-'a'])
    {
      ans+=s2[j];
      j++;
    }
    else
    {
      if(s1[i]<s2[j])
      {
        ans+=s1[i];
        i++;
      }
      else
      {
        ans+=s2[j];
        j++;
      }
    }
  }

  if(i<n1)
  {
    ans+=s1.substr(i);
  }

  if(j<n2)
  {
    ans+=s2.substr(j);
  }

  return ans;
}

int main()
{
  string s1 = "abaacbc";
  string s2 = "xaadc";
  string merged = customMerge(s1, s2);
  cout << "Merged string: " << merged << endl;
  return 0;
}