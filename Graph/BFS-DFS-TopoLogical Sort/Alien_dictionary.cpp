// Problem Statement: Given a sorted dictionary of an alien language having N words and k starting alphabets of a standard dictionary. Find the order of characters in the alien language.

// Note: Many orders may be possible for a particular test case, thus you may return any valid order.

// Examples:

// Example 1:
// Input: N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}
// Output: b d a c
// Explanation: 
// We will analyze every consecutive pair to find out the order of the characters.
// The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.
// The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary.
// The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary.
// The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary.
// So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.

// Example 2:
// Input: N = 3, K = 3
// dict = {"caa","aaa","aab"}
// Output: c a b
// Explanation: Similarly, if we analyze the consecutive pair 
// for this example, we will figure out [‘c’, ‘a’, ‘b’] is 
// a valid ordering.
#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
  void preparedAdjList(int N, int K, string dict[], unordered_map<char, list<char>>& adjList)
  {
    for(int i=0; i<N-1; i++)
    {
      string word1 = dict[i];
      string word2 = dict[i+1];
      int minLength = min(word1.length(),word2.length());

      for(int j=0; j<minLength; j++)
      {
        if(word1[j] != word2[j])
        {
          adjList[word1[j]].push_back(word2[j]);
          break;
        }
      }
    }
  }
  void printAdjList(unordered_map<char, list<char>>& adjList)
  {
    for(auto i : adjList)
    {
      cout << i.first << " -> ";
      for(auto j : i.second)
      {
        cout << j << ", ";
      }
      cout << endl;
    }
  }
	string findOrder(string dict[], int N, int K)
  {
     unordered_map<char, list<char>> adjList;
     preparedAdjList(N, K, dict, adjList);
     //printAdjList(adjList);
     
     vector<char> charecters;
     int count =0;
     for(char i = 'a'; i<='z'; i++)
     {
        if(count == K)
          break;
        count++;
        charecters.push_back(i);
     }
     unordered_map<char, int> indegree;

     for (char ch : charecters) {
        indegree[ch] = 0;
     }

     for(auto i: adjList)
     {
      for(auto j : adjList[i.first])
      {
        indegree[j]++;
      }
     }

     queue<char> q;
     for(auto i: indegree)
     {
        if(i.second == 0)
        {
          q.push(i.first);
        }
     }

     string ans ="";
     while(!q.empty())
     {
        char front = q.front();
        q.pop();
        ans += front;

        for(auto i:adjList[front])
        {
          indegree[i]--;
          if(indegree[i]==0)
          {
            q.push(i);
          }
        }
     }
     
     return ans;
  }
};

int main() {

	// int N = 5, K = 4;
	//string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
  int N = 3, K = 3;
  string dict[]={"caa","aaa","aab"};
	Solution obj;
	string ans = obj.findOrder(dict, N, K);

	for (auto ch : ans)
		cout << ch << ' ';
	cout << endl;

	return 0;
}