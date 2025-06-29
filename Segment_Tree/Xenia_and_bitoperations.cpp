#include<bits/stdc++.h>
#include<cmath>
using namespace std;

class SegmentTree {
public:
    vector<int> seg;
    SegmentTree(int n)
    {
      seg.resize(4*n+1);
      //build(0, 0, n-1, arr);
    }
    void build(int index, int low, int high, vector<int>& arr, bool orr)
    {
      if(low==high)
      {
        seg[index] = arr[low];
        return;
      }
      int mid=(low+high)/2;
      build(2*index+1, low, mid, arr, !orr);
      build(2*index+2, mid+1, high, arr, !orr);
      
      if(orr)
        seg[index] = seg[2*index+1] ^ seg[2*index+2];
      else
        seg[index] = seg[2*index+1]|seg[2*index+2];
    }

    int query(int index, int low, int high, int l, int r)
    {
      //no overlap
      if(low > r || high < l)
      {
        return INT_MAX;
      }
      else if(low>=l && high<=r)
      {
        // complete overlap
        return seg[index];
      }
      
      //partial overlap
      int mid = (low+high)/2;
      int left = query(2*index+1, low, mid, l, r);
      int right = query(2*index+2, mid+1, high, l, r);
      return min(left,right);
    }

    void update(int index, int low, int high, int i, int val, bool orr)
    {
      if(low==high)
      {
        seg[index] = val;
        return;
      }
      int mid = (low+high)/2;
      if(i<=mid)
      {
        update(2*index+1, low, mid, i, val, !orr);
      }
      else
      {
        update(2*index+2, mid+1, high, i, val, !orr);
      }

      if(orr)
        seg[index] = seg[2*index+1] ^ seg[2*index+2];
      else
        seg[index] = seg[2*index+1]|seg[2*index+2];
    }
};

// vector<int> operations(vector<int>& a, int size)
// {
//    vector<int> arr1;
//    int i=0, j=0;
//    while(i<size)
//    {
//       int c=a[i]|a[i+1];                                      
//       arr1.push_back(c);
//       i=i+2;
//    }
   
//    vector<int> arr2;
//    while(j<arr1.size())
//    {
//       int c=arr1[j]^arr1[j+1];                                      
//       arr2.push_back(c);
//       j=j+2;                                     
//    }
//    return arr2;
// }
void solve()
{
  int n,m;
  cin>>n>>m;
  int size=pow(2,n);
  
  vector<int> a(size);
  for(int i=0; i<size; i++) cin>>a[i];
  SegmentTree seg(size);
  if(n%2==0)
  {
    seg.build(0, 0, size-1, a, true); // even n means we start with OR operation
  }
  else
  {
    seg.build(0, 0, size-1, a, false); // odd n means we start with XOR operation
  }
  while(m--)
  {
    int p,b; // index and value
    cin>>p>>b;
    seg.update(0,0,size-1,p-1,b, n%2==0); // update the segment tree, passing true if n is even, false if odd
    a[p-1]=b;
    
    cout<<seg.seg[0]<<endl; // output the root of the segment tree
  }
  
  // cout<<ans[0]<<endl;
}
int main()
{
  solve();
  return 0;
}