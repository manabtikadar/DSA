#include<bits/stdc++.h>

using namespace std;

class FenwickTree
{
private:
  int n;
  vector<long long> fen;
public:
  FenwickTree(int n)
  {
    this->n = n;
    fen.assign(n+1,0);
  }
  
  // 1 base indexing
  void update(int i,int add)
  {
    while(i<=n)
    {
      fen[i]+=add;
      i += (i&(-i));
    }
  }

  int sum(int i)
  {
    int s=0;
    while(i>0)
    {
      s+=fen[i];
      i -= (i&(-i));
    }
    return s;
  }

  int rangeSum(int l,int r)
  {
    return sum(r)-sum(l-1);
  }
};
int main()
{
  int n;
  cin>>n;
  int arr[n+1];
  for(int i=1; i<=n; i++)
  {
    cin>>arr[i];
  }

  FenwickTree fen(n);
  for(int i=1; i<=n; i++)
  {
    fen.update(i, arr[i]);
  }

  cout<<fen.rangeSum(1, n)<<endl;
  cout<<fen.rangeSum(2, 4)<<endl;
  fen.update(3, 6);
  cout<<fen.rangeSum(1, n)<<endl;
  cout<<fen.rangeSum(2, 4)<<endl;
  return 0;
}