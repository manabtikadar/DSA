// A string is a palindrome if the reverse of the string is the same as the original string. An analyst at HackerRank is tasked to analyze an array of n strings that consist of lowercase English characters.

// In one operation, the analyst chooses 4 integers, namely, x, y, i, j such that
// 1 ≤ x, y ≤ n,
// 1 ≤ i ≤ length(arr[x]),
// 1 ≤ j ≤ length(arr[y])

// and then swaps arr[x][i] and arr[y][j] using 1-based indexing.

// The analyst wishes to determine the maximum number of palindromic strings that can be obtained by performing the operation any number of times, possibly 0.


#include<bits/stdc++.h>

using namespace std;

int maxPalindromicStrings(vector<string>& arr)
{
  int n=arr.size();
  if(n==0) return 0;

  unordered_map<char, int> freq;

  for(int i=0; i<n; i++)
  {
    for(char c : arr[i])
    {
      freq[c]++;
    }
  }

  int oddLengthStringsDemand=0;
  for(auto it : arr)
  {
    if(it.length()%2!=0)
    {
      oddLengthStringsDemand++;
    }
  }

  int unpairedCharsSupply =0;
  for(auto it : freq)
  {
    if(it.second % 2 != 0)
    {
      unpairedCharsSupply++;
    }
  }

  if (unpairedCharsSupply > oddLengthStringsDemand) {
        int sacrificedStrings = (unpairedCharsSupply - oddLengthStringsDemand) / 2;
        return n - sacrificedStrings;
    } else {
        return n;
    }
}

int main()
{
    vector<string> arr = {"abc", "a", "cba", "b"};
    cout << maxPalindromicStrings(arr) << endl;
    return 0;
}
