#include<bits/stdc++.h>
using namespace std;

int divisableByK(vector<int>& arr, int k)
{

  vector<int> remainderCount(k,0);
  for(int i=0; i<arr.size(); i++)
  {
    int remainder = arr[i]%k;
    remainderCount[remainder]++;
  }

  int count=remainderCount[0]*(remainderCount[0]-1);
  for(int i=1; i<k; i++)
  {
    
      count += remainderCount[i]*remainderCount[k-i];
  }

  return count/2;
}

int main()
{
  vector<int> a = {1, 2, 3, 4, 5, 6, 10, 20};
  int k = 5;
  cout << divisableByK(a, k) << endl;  // Output: 4
  return 0;

}