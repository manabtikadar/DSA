#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    while(b!=0)
    {
      int temp=b;
      b=a%b;
      a=temp;
    }
    return a;
}

int solve(int n, vector<int>& arr)
{
  vector<int> computeGCD(n,0);
  int largest=arr[0];
  computeGCD[0]=arr[0];
  for(int i=1; i<n; i++)
  {
    largest=max(largest, arr[i]);
    computeGCD[i]=gcd(arr[i],largest);
  }

  sort(computeGCD.begin(), computeGCD.end());
  vector<int> B;
  int i=0;
  int j=n-1;
  while(i<=j)
  {
    int x=gcd(computeGCD[i], computeGCD[j]);

    B.push_back(x);
    i++;
    j--;
  }

  int sum=0;
  for(int i=0; i<B.size(); i++)
  {
    sum+=B[i];
  }

  return sum;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }

  cout << "Sum of GCDs: " << solve(n, arr) << endl;
  return 0;
}