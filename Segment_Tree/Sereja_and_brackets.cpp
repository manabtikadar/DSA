#include<bits/stdc++.h>

using namespace std;

int longestCorrectbracketSequence(string s) {
    int n = s.size();
    int length = 0;
    stack<char> st;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
           st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(!st.empty() && st.top()=='(')
            {
              st.pop();
              length += 2;
            }
        }
    }

    return length;
}

int main()
{
  string s="())(())";

  cout << longestCorrectbracketSequence(s) << endl;

  return 0;
}