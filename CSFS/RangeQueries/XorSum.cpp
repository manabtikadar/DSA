#include<bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
  vector<int> Seg;
public:
  SegmentTree(int n)
  {
    Seg.resize(4*n+1);
  }
  void build(int index,int low,int high,vector<int>& arr)
  {
    if(high==low)
    {
      Seg[index]=arr[low];
      return;
    }

    int mid=low+(high-low)/2;
    build(2*index+1,low,mid,arr);
    build(2*index+2,mid+1,high,arr);

    Seg[index]=(Seg[2*index+1]^Seg[2*index+2]);
  }
  int query(int index,int low,int high,int l,int r)
  {
    //no overlap
    if(low > r || high< l)
    {
      return 0;
    }
    else if(low>=l && high<=r)
    {
      return Seg[index];
    }

    int mid=low+((high-low)/2);
    int left=query(2*index+1,low,mid,l,r);
    int right=query(2*index+2,mid+1,high,l,r);

    return (left^right);
  }
  void update(int index,int low,int high,int i,int val)
  {
    if(low==high)
    {
      Seg[index]=val;
      return;
    }

    int mid=low+((high-low)/2);
    if(i<=mid)
    {
      update(2*index+1,low,mid,i,val);
    }
    else
    {
      update(2*index+2,mid+1,high,i,val);
    }

    Seg[index]=(Seg[2*index+1]^Seg[2*index+2]);
  }
};

int main()
{
  int n,q;
  cin>>n>>q;
  vector<int> arr(n);
  for(int i=0; i<n; i++)
  {
    cin>>arr[i];
  }

  SegmentTree st(n);
  st.build(0,0,n-1,arr);

  while(q--)
  {
      int l,r;
      cin>>l>>r;
      l--;r--;
      cout<<st.query(0,0,n-1,l,r)<<endl;
  }
    

  return 0;
}