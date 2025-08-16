#include<bits/stdc++.h>

using namespace std;


// int solve(int index, vector<int>& array)
// {
//     if(index>= array.size())
//     {
//       return 0;
//     }

//     int include = array[index] + solve(index+2, array);
//     int exclude = solve(index+1, array);

//     return max(include, exclude);
// }
// // Maximum Sum of Non-Adjacent Elements
// int maximumSumOfNonAdjacent(vector<int>& array) {
//     int n = array.size();
//     if (n == 0) return 0;
//     if (n == 1) return array[0];

//    return solve(0, array);
// }

// int main()
// {
//   vector<int> array = {9,9,8,2};
//   cout << "Maximum Sum of Non-Adjacent Elements: " << maximumSumOfNonAdjacent(array) << endl;
//   return 0;
// }
long long count_commas(long long n)
{
  long long total =0;

  if(n>=1000LL)
  {
    total += (min(n,999999LL)-999LL)*1;
  }
  
  if(n>=1000000LL)
  {
    total+= (min(n,999999999LL)-999999LL)*2;
  }

  if(n>=1000000000LL)
  {
    total+=(min(n,9999999999999LL)-999999999LL)*3;
  }

  return total;
}
int main()
{
  long long N;
  cin >> N;
  cout << "Total number of commas needed: " << count_commas(N) << endl;
  return 0;
}