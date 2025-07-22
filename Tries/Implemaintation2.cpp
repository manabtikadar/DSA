#include<bits/stdc++.h>

using namespace std;

struct TrieNode
{
  TrieNode* links[26];
  int cntEndWith=0; // end with
  int cntPrefix=0; // count prefix
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

  void increaseEnd()
  {
    cntEndWith++;
  }

  bool isEnd()
  {
    return cntEndWith > 0;
  }
  
  void increasePrefx()
  {
      cntPrefix++;
  }
  
  void deleteEnd()
  {
      cntEndWith--;
  }

  void reducePrefix()
  {
      cntPrefix--;
  }

  int getPrefix()
  {
    return cntPrefix;
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
          if(!node->containsKey(word[i]))
          {
            node->put(word[i],new TrieNode());
            
          }
          node=node->get(word[i]);
          node->increasePrefx();
       }

       node->increaseEnd();
    }

    // Function to search a word in the trie
    // Time Complexity: O(m) where m is the length of the word
    int countWordsEqualTo(string word)
    {
        TrieNode* node=root;

        for(int i=0; i<word.size(); i++)
        {
          char ch=word[i];
          if(!node->containsKey(ch))
          {
            return 0;
          }

          node=node->get(ch);
        }

        return node->cntEndWith;
    }

    // Function to check if any word in the trie starts with the given prefix
    // Time Complexity: O(m) where m is the length of the prefix

    int countWordsStartingWith(string prefix)
    {
      TrieNode* node=root;

        for(int i=0; i<prefix.size(); i++)
        {
          char ch=prefix[i];
          if(!node->containsKey(ch))
          {
            return 0;
          }

          node=node->get(ch);
        }

        return node->getPrefix();   
    }

    void erase(string word)
    {
      TrieNode* node=root;

      for(int i=0; i<word.size(); i++)
      {
        if(!node->containsKey(word[i]))
        {
           cout<<"the word doesn't exist"<<endl;
           return;
        }
        
        node=node->get(word[i]);
        node->reducePrefix();
      }

      node->deleteEnd();
    }
};