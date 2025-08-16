#include<bits/stdc++.h>

using namespace std;

class Solution {
    void preparedLPS(string needle, vector<int>& LPS)
    {
        int m=needle.size();
        LPS[0]=0;
        int length=0;
        
        int i=1;
        while(i<m)
        {
            if(needle[i]==needle[length])
            {
                length++;
                LPS[i]=length;
                i++;
            }
            else
            {
                if(length!=0)
                {
                    length=LPS[length-1];
                }
                else
                {
                    LPS[i]=0;
                    i++;
                }
            }
        }

    }
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        vector<int> LPS(m,0);
        preparedLPS(needle,LPS);
        for(int i=0; i<m; i++) {
            cout << LPS[i] << " ";
        }

        int i=0;
        int j=0;

        while(i<n)
        {
            
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }

            if(j==m)
            {
                return (i-j);
            }
            else if(haystack[i]!=needle[j])
            {
                if(j!=0)
                {
                    j=LPS[j-1];

                }
                else
                {
                    i++;
                }

            }
            
        }
        
        return -1;
    }
};

int main() {
    Solution solution;
    // take input example
    string haystack, needle;
    cout << "Enter the haystack string: ";
    cin >> haystack;
    cout << "Enter the needle string: ";
    cin >> needle;
    int result = solution.strStr(haystack, needle);
    if (result != -1) {
        cout << "The index of the first occurrence of '" << needle << "' in '" << haystack << "' is: " << result << endl;
    } else {
        cout << "The needle string was not found in the haystack string." << endl;
    }

    // string haystack = "hello";
    // string needle = "ll";
    // int result = solution.strStr(haystack, needle);
    // cout << "The index of the first occurrence of '" << needle << "' in '" << haystack << "' is: " << result << endl;
    return 0;
}