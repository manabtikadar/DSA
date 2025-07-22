#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
  TrieNode* links[26];

  bool isContainsKey(char ch)
  {
    return links[ch-'a'] != nullptr;
  }

  TrieNode* get(char ch)
  {
    return links[ch-'a'];
  }

  void put(char ch, TrieNode* node)
  {
    links[ch-'a']=node;
  }
};

int countDistinctSubstring(string s)
{
  int cnt=0;
  TrieNode* root=new TrieNode();

  for(int i=0; i<s.size(); i++)
  {
    TrieNode* node=root;

    for(int j=i; j<s.size(); j++)
    {
      if(!node->isContainsKey(s[j]))
      {
        node->put(s[j],new TrieNode());
        cnt++;
      }

      node=node->get(s[j]);
    }
  }

  return cnt+1;
}

int main()
{
  string s;
  cin >> s;

  cout << countDistinctSubstring(s) << endl;

  return 0;
}