#include<bits/stdc++.h>
using namespace std;

class SegmentTree
{
  private:
    vector<long long> Seg;
  public:
    SegmentTree(int n)
    {
      Seg.resize(4*n+1);
    }
    void build(int index,int low,int high,vector<long long>& arr)
    {
      if(low==high)
      {
        Seg[index]=arr[low];
        return;
      }

      int mid=(low+high)/2;
      build(2*index+1,low,mid,arr);
      build(2*index+2,mid+1,high,arr);

      Seg[index]=Seg[2*index+1]+Seg[2*index+2];
    }
    long long query(int index,int low,int high,int l,int r)
    {
      //no overlap
      if(low>r || high<l)
      {
        return 0;
      }
      //complete overlap
      if(low>=l && high<=r)
      {
        return Seg[index];
      }

      int mid=(low+high)/2;
      long long left=query(2*index+1,low,mid,l,r);
      long long right=query(2*index+2,mid+1,high,l,r);

      return (left+right);
    }
    void update(int index,int low,int high,int i,long long val)
    {
      if(low==high)
      {
        Seg[index]=val;
        return;
      }

      int mid=(low+high)/2;
      if(i<=mid)
      {
        update(2*index+1,low,mid,i,val);
      }
      else if(i>mid)
      {
        update(2*index+2,mid+1,high,i,val);
      }

      Seg[index]=Seg[2*index+1]+Seg[2*index+2];
    }
};

int main()
{
  int n,m;
  cin>>n>>m;

  vector<long long> arr(n);
  for(int i=0; i<n; i++)
  {
    cin>>arr[i];
  }
  
  SegmentTree sg(n);
  sg.build(0,0,n-1,arr);
  //vector<vector<int>> query(m,vector<int>(2));
  for(int i=0; i<m; i++)
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