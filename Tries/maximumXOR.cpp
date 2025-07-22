#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
  TrieNode* links[2];

  bool isContainsKey(int bit)
  {
    return links[bit] != nullptr;
  }

  TrieNode* get(int bit)
  {
    return links[bit];
  }

  void put(int bit, TrieNode* node)
  {
    links[bit] = node;
  }
};

class Trie
{
  private:
    TrieNode* root;
  public:
    Trie()
    {
      root = new TrieNode();
    }

    void insert(int num)
    {
      TrieNode* node=root;
      for(int i=31; i>=0; i--)
      {
        int bit=(num>>i)&1;
        if(!node->isContainsKey(bit))
        {
          node->put(bit, new TrieNode());
        }
        node = node->get(bit);
      }
    }

    int getMaxXor(int num)
    {
      TrieNode* node=root;
      int maxXor=0;
      for(int i=31; i>=0; i--)
      {
        int bit=(num>>i)&1;
        if(node->isContainsKey(1-bit))
        {
          maxXor |= (1<<i);
          node = node->get(1-bit);
        }
        else
        {
          node = node->get(bit);
        }
      }
      return maxXor;
    }

   
};

int maximumXOR(int n, int m, vector<int>& arr1, vector<int>& arr2)
{
  Trie trie;

  for(int i=0; i<n; i++)
  {
    trie.insert(arr1[i]);
  }

  int maxXor = INT_MIN;
  for(int i=0; i<m; i++)
  {
    int currentXor = trie.getMaxXor(arr2[i]);
    maxXor=max(maxXor, currentXor);
  }

  return maxXor;
}
bool comp(const vector<int>& a, const vector<int>& b)
{
   return a[1] < b[1];
}
vector<int> maxXorwithQueries(vector<int>& nums, vector<vector<int>>& quries)
{
  vector<vector<int>> orderedquries;
  for(int i=0; i<quries.size(); i++)
  {
    orderedquries.push_back({quries[i][0], quries[i][1], i});
  }

  sort(orderedquries.begin(), orderedquries.end(),comp);

  sort(nums.begin(),nums.end());

  vector<int> ans(quries.size(),0);
  Trie trie;
  int i=0;
  for(int j=0; j<orderedquries.size(); j++)
  {
    while(i<nums.size() && nums[i]<=orderedquries[j][1])
    {
      trie.insert(nums[i]);
      i++;
    }
    ans[orderedquries[j][2]] = trie.getMaxXor(orderedquries[j][0]);
  }
  return ans;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> arr1(n), arr2(m);

  for(int i=0; i<n; i++)
  {
    cin >> arr1[i];
  }

  for(int i=0; i<m; i++)
  {
    cin >> arr2[i];
  }

  cout << maximumXOR(n, m, arr1, arr2) << endl;

  return 0;
}