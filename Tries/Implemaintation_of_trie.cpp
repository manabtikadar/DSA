#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
  TrieNode* links[26];
  bool flag=false;
  bool containsKey(char ch)
  {
    return links[ch-'a'] != nullptr;
  }

  void put(char ch, TrieNode* node)
  {
    links[ch-'a']=node;
  }
   
  TrieNode* get(char ch)
  {
    return links[ch-'a'];
  }

  bool setEnd()
  {
    flag = true;
  }

  bool isEnd()
  {
    return flag;
  }
};

class Trie
{
  private:
    TrieNode* root;
  public:
    Trie(){
        root=new TrieNode();
    }
    
    // Function to insert a word into the trie
    // Time Complexity: O(m) where m is the length of the word
    void insert(string word)
    {
        TrieNode* node=root;

        for(int i=0; i<word.size(); i++)
        {
            char ch=word[i];
            if(!node->containsKey(ch))
            {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
        }

        node->setEnd();
    }

    // Function to search a word in the trie
    // Time Complexity: O(m) where m is the length of the word
    bool search(string word)
    {
        TrieNode* node=root;

        for(int i=0; i<word.size(); i++)
        {
            char ch=word[i];
            if(!node->containsKey(ch))
            {
              return false;
            }
            node = node->get(ch);
        }

        return node->isEnd();
    }

    // Function to check if any word in the trie starts with the given prefix
    // Time Complexity: O(m) where m is the length of the prefix

    bool startsWith(string prefix)
    {
        TrieNode* node=root;

        for(int i=0; i<prefix.size(); i++)
        {
            char ch=prefix[i];
            if(!node->containsKey(ch))
            {
              return false;
            }
            node = node->get(ch);
        }

        return true;
    }
};