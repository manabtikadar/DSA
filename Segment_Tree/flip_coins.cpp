#include<bits/stdc++.h>

using namespace std;

class SGTreeLazyPropagation{
private:
  vector<int> seg,lazy;
public:
  SGTreeLazyPropagation(int n)
  {
    seg.resize(4*n+1);
    lazy.resize(4*n+1,0);
  }
  void build(int index, int low, int high, vector<int>& arr)
  {
    if(low==high)
    {
      seg[index]=arr[low];
      return;
    }

    int mid=(low+high)/2;
    build(2*index+1,low,mid,arr);
    build(2*index+2,mid+1,high,arr);

    seg[index]=seg[2*index+1] + seg[2*index+2];
  }
  void update(int index, int low, int high, int l, int r)
  {
    //first we update the previous remaining updates
    //and propagate downwords
    if(lazy[index])
    {
      seg[index] = (high-low+1)-seg[index];
      if(low!=high)
      {
        lazy[2*index+1]=(!lazy[2*index+1]);
        lazy[2*index+2]=(!lazy[2*index+2]);
      }

      lazy[index]=0;
    }

    //no overlap
    if(low>r || high<l)
    {
      return;
    }
    
    //complete overlap
    if(low>=l && high<=r)
    {
      seg[index] = (high-low+1)-seg[index];

      if(low!=high)
      {
        lazy[2*index+1]=(!lazy[2*index+1]);
        lazy[2*index+2]=(!lazy[2*index+2]);
      }
      return;
    }

    int mid=(low+high)/2;
    update(2*index+1,low,mid,l,r);
    update(2*index+2,mid+1,high,l,r);
    seg[index] = seg[2*index+1]+seg[2*index+2];
  }

  int query(int index, int low, int high, int l, int r)
  {

      if(lazy[index])
      {
        seg[index] = (high-low+1)-seg[index];
        if(low!=high)
        {
          lazy[2*index+1]=(!lazy[2*index+1]);
          lazy[2*index+2]=(!lazy[2*index+2]);
        }

        lazy[index]=0;
      }

    
      // no overlap
      if(low>r || high<l)
      {
        return 0;
      }
      else if(low>=l && high<=r)
      {
        // complete overlap
        return seg[index];
      }
      else
      {
        int mid = (low+high)/2;
        int left = query(2*index+1, low, mid, l,r);
        int right = query(2*index+2, mid+1, high, l,r);

        return left+right;
      }
  }
};

void solve()
{
  int n;
  cin>>n;
  vector<int> coins(n);
  for(int i=0; i<n; i++) cin>>coins[i];
  SGTreeLazyPropagation st(n);
  st.build(0,0,n-1,coins);

  int q;
  cin>>q;
  while(q--)
  {
    int type;
    cin>>type;
    if(type==1)
    {
      int l,r;
      cin>>l>>r;

      int ans=st.query(0,0,n-1,l,r);
      cout<<ans<<endl;
    }
    else{
      int l,r;
      cin>>l>>r;

      st.update(0,0,n-1,l,r);
      // for(int i=l; i<=r; i++)
      // {
      //   coins[i]=(!coins[i]);
      // }
    }
  }
}

int main()
{
  solve();
  return 0;
}