#include<bits/stdc++.h>

using namespace std;

int check(string temp, int i, int j)
{
  stack<char> s;
  
  for(int k=0; k<temp.length(); k++)
  {
    if(k==i || k==j) continue;
    if(temp[k]=='(')
    {
      s.push(temp[k]);                               
    }
    else
    {
      if (s.empty()) return 0;
      s.pop();                               
    }
  }
  return s.empty() ? 1 : 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.length();
        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            //if (s[i] != '(') continue;  

            for (int j = 0; j < n && !found; j++) {
                //if (s[j] != ')') continue;  

                if (i == j) continue;  
                if(s[i]==s[j])
                {
                  continue;
                }
                else
                {
                  // string temp = s;
          
                  // if (i > j) {
                  //     temp.erase(temp.begin() + i);
                  //     temp.erase(temp.begin() + j);
                  // } else {
                  //     temp.erase(temp.begin() + j);
                  //     temp.erase(temp.begin() + i);
                  // }

                  if (check(s,i,j) == 0) {
                      cout << "YES\n";
                      found = true;
                  }

                }
                
            }
        }

        if (!found) {
            cout << "NO\n";
        }
    }

    return 0;
  
}