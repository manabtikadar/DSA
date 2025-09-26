#include<bits/stdc++.h>git 

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
  void update(int index, int low, int high, int l, int r,int val)
  {
    //first we update the previous remaining updates
    //and propagate downwords
    if(lazy[index]!=0)
    {
      seg[index] += (high-low+1)*lazy[index];
      if(low!=high)
      {
        lazy[2*index+1]+=lazy[index];
        lazy[2*index+2]+=lazy[index];
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
      seg[index] += (high-low+1)*val;

      if(low!=high)
      {
        lazy[2*index+1] +=val;
        lazy[2*index+2] +=val;
      }
      return;
    }

    int mid=(low+high)/2;
    update(2*index+1,low,mid,l,r,val);
    update(2*index+2,mid+1,high,l,r,val);
    seg[index] = seg[2*index+1]+seg[2*index+2];
  }

  int query(int index, int low, int high, int l, int r)
  {

      if(lazy[index]!=0)
      {
        seg[index] += (high-low+1)*lazy[index];
        if(low!=high)
        {
          lazy[2*index+1] +=lazy[index];
          lazy[2*index+2] +=lazy[index];
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

class SGTreeLazyPropagationMin{
private:
  vector<int> seg,lazy;
public:
  SGTreeLazyPropagationMin(int n)
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

    seg[index] = min(seg[2*index+1] ,seg[2*index+2]);
  }
  void update(int index, int low, int high, int l, int r,int val)
  {
    //first we update the previous remaining updates
    //and propagate downwords
    if(lazy[index]!=0)
    {
      seg[index] += lazy[index];
      if(low!=high)
      {
        lazy[2*index+1]+=lazy[index];
        lazy[2*index+2]+=lazy[index];
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
      seg[index] += *val;

      if(low!=high)
      {
        lazy[2*index+1] +=val;
        lazy[2*index+2] +=val;
      }
      return;
    }

    int mid=(low+high)/2;
    update(2*index+1,low,mid,l,r,val);
    update(2*index+2,mid+1,high,l,r,val);
    seg[index] = min(seg[2*index+1],seg[2*index+2]);
  }

  int query(int index, int low, int high, int l, int r)
  {

      if(lazy[index]!=0)
      {
        seg[index] += lazy[index];
        if(low!=high)
        {
          lazy[2*index+1] +=lazy[index];
          lazy[2*index+2] +=lazy[index];
        }

        lazy[index]=0;
      }
    
      // no overlap
      if(low>r || high<l)
      {
        return INT_MAX;
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

        return min(left,right);
      }
  }
};

void solve()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];

  SGTreeLazyPropagation st(n);
  st.build(0,0,n-1,arr);

  int q;
  cin>>q;

  while(q--)
  {
    int type;
    cin>>type;
    if(type == 1)
    {
      int l,r;
      cin>>l>>r;

      cout<<st.query(0,0,n-1,l,r)<<endl;
    }
    else{
      int l,r,val;
      cin>>l>>r>>val;

      st.update(0,0,n-1,l,r,val);
    }
  }

}

int main()
{
  solve();
  return 0;
}