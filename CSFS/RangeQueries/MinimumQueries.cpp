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
      if(low==high)
      {
        Seg[index]=arr[low];
        return;
      }
      int mid=low + (high - low) / 2;
      build(2*index+1,low,mid,arr);
      build(2*index+2,mid+1,high,arr);

      Seg[index]=min(Seg[2*index+1],Seg[2*index+2]);
    }
    int query(int index,int low,int high,int l,int r)
    {
      // no overlap
      if(low>r || high<l)
      {
        return INT_MAX;
      }
      if(low>=l && high<=r)
      {
        return Seg[index];
      }

      int mid=low + (high - low) / 2;
      int left=query(2*index+1,low,mid,l,r);
      int right=query(2*index+2,mid+1,high,l,r);

      return min(left,right);
    }
    void update(int index,int low,int high,int i,int val)
    {
      if(low==high)
      {
        Seg[index]=val;
        return;
      }
      int mid=low + (high - low) / 2;
      if(i<=mid)
      {
        update(2*index+1,low,mid,i,val);
      }
      else
      {
        update(2*index+2,mid+1,high,i,val);
      }

      Seg[index]=min(Seg[2*index+1],Seg[2*index+2]);
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
  
  SegmentTree sg(n);
  sg.build(0,0,n-1,arr);
  for(int i=0; i<q; i++)
  {
    int type;
    cin>>type;

    if(type==1)
    {
      int k,u;
      cin>>k>>u;
      k--;
      sg.update(0,0,n-1,k,u);
    }
    else if(type==2)
    {
      int a,b;
      cin>>a>>b;
      a--;
      b--;
      cout<<sg.query(0,0,n-1,a,b)<<endl;
    }
  }

  return 0;
}