#include<iostream>
#include<vector>

using namespace std;
int size(vector<int>& array)
{
  return array.size();
}

int largestSequence(vector <int>& array, int i, int maxLength, vector<vector <int>>& ans, vector<int>& Temp, vector<int> dp)
{
  // Base Case
  if(i>=array.size())
  { 
    
    return Temp.size();
  }

  if(dp[i] != -1)
  {
    return dp[i];
  }
   
   
   // Include
   int include = 0;
   if (Temp.empty() || (Temp.back() < array[i]))
   {
    Temp.push_back(array[i]);
    include = largestSequence(array,i+1,maxLength,ans,Temp,dp);
    Temp.pop_back();
   }
   
   int exclude = largestSequence(array,i+1,maxLength,ans,Temp,dp);
   dp[i]=max(include,exclude);
   return dp[i];
}

int largestSequence_tabulation(vector <int>& array)
{
    int n = array.size();

    vector<int> dp(n, 1);  
    int maxLength = 0;
    if (n == 0) dp[0]=0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (array[i] > array[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}


int main()
{
  vector<int> array= {3,25,5,4,6,2};
  int length=array.size();
  vector<vector <int>> ans;
  vector<int> Temp;
  int maxLength=0;
  int i=0;
  vector<int> dp(length, -1);
  cout<<"length of max largest subsequence:"<<largestSequence(array,i,maxLength,ans,Temp,dp)<<endl;
  cout<<"length of max largest subsequence:"<<largestSequence_tabulation(array)<<endl;
  for(int i=0;i<ans.size();i++)
  {
    for(int j=0;j<ans[i].size();j++)
    {
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}

// #include <iostream>
// #include <vector>

// using namespace std;

// void findLongestSequence(vector<int>& array, int index, vector<int>& temp, vector<vector<int>>& longest, int& maxLength) {
//     if (index == array.size()) {
//         if (temp.size() > maxLength) {
//             longest.clear();   
//             longest.push_back(temp);
//             maxLength = temp.size();
//         } else if (temp.size() == maxLength) {
//             longest.push_back(temp);  
//         }
//         return;
//     }

    
//     if (temp.empty() || array[index] > temp.back()) {
//         temp.push_back(array[index]);
//         findLongestSequence(array, index + 1, temp, longest, maxLength);
//         temp.pop_back();
//     }
//     findLongestSequence(array, index + 1, temp, longest, maxLength);
// }

// int main() {
//     vector<int> array = {3, 25, 5, 4, 6, 2};
//     vector<int> temp;
//     vector<vector<int>> longest;
//     int maxLength = 0;
//     findLongestSequence(array, 0, temp, longest, maxLength);

//     cout << "Longest Increasing Subsequences:" << endl;
//     for (auto& seq : longest) {
//         for (int num : seq) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

