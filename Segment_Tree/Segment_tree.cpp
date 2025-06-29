#include<bits/stdc++.h>

using namespace std;

class SegmentTree {
public:
    vector<int> seg;
    SegmentTree(int n)
    {
      seg.resize(4*n+1);
      //build(0, 0, n-1, arr);
    }
    void build(int index, int low, int high, int arr[])
    {
      if(low==high)
      {
        seg[index] = arr[low];
        return;
      }
      int mid=(low+high)/2;
      build(2*index+1, low, mid, arr);
      build(2*index+2, mid+1, high, arr);

      seg[index] = min(seg[2*index+1], seg[2*index+2]);
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

    void update(int index, int low, int high, int i, int val)
    {
      if(low== high)
      {
        seg[index] = val;
        return;
      }
      int mid = (low+high)/2;
      if(i<=mid)
      {
        update(2*index+1, low, mid, i, val);
      }
      else
      {
        update(2*index+2, mid+1, high, i, val);
      }

      seg[index]=min(seg[2*index+1], seg[2*index+2]);
    }
};

// void build(int index, int low, int high, int arr[], int seg[])
// {
//   if(low==high)
//   {
//     seg[index] = arr[low];
//     return;
//   }
//   int mid=(low+high)/2;
//   build(2*index+1, low, mid, arr, seg);
//   build(2*index+2, mid+1, high, arr, seg);

//   seg[index] = min(seg[2*index+1], seg[2*index+2]);
// }

// int query(int index, int low, int high, int l, int r, int seg[])
// {
//   //no overlap
//   if(low > r || high < l)
//   {
//     return INT_MAX;
//   }
//   else if(low>=l && high<=r)
//   {
//     // complete overlap
//     return seg[index];
//   }
  
//   //partial overlap
//   int mid = (low+high)/2;
//   int left = query(2*index+1, low, mid, l, r, seg);
//   int right = query(2*index+2, mid+1, high, l, r, seg);
//   return min(left,right);
// }

// void update(int index, int low, int high, int i, int val, int seg[])
// {
//   if(low== high)
//   {
//     seg[index] = val;
//     return;
//   }
//   int mid = (low+high)/2;
//   if(i<=mid)
//   {
//     update(2*index+1, low, mid, i, val, seg);
//   }
//   else
//   {
//     update(2*index+2, mid+1, high, i, val, seg);
//   }

//   seg[index]=min(seg[2*index+1], seg[2*index+2]);
// }

// void solve()
// {
//   int n;
//   cin>>n;
//   int arr[n];
//   for(int i=0; i<n; i++) cin>>arr[i];
//   int seg[4*n];
//   build(0, 0, n-1, arr, seg);

//   int q;
//   cin>>q;
//   while(q--)
//   {
//     int type;
//     cin>>type;
//     if(type == 1)
//     {
//       int l,r;
//       cin>> l >> r;
//       cout<< query(0,0,n-1,l,r,seg)<<endl;
//     }
//     else
//     {
//       int i,val;
//       cin>>i>>val;
//       update(0,0,n-1,i,val,seg);
//       arr[i]=val;
//     }
//   }
// }

void solve2()
{
  int n1;
  cin>>n1;
  int arr1[n1];
  for(int i=0; i<n1; i++) cin>>arr1[i];
  SegmentTree sg1(n1);
  sg1.build(0,0,n1-1,arr1);

  int n2;
  cin>>n2;
  int arr2[n2];
  for(int i=0; i<n2; i++) cin>>arr2[i];
  SegmentTree sg2(n2);
  sg2.build(0,0,n2-1,arr2);

  int q;
  cin>>q;
  while(q--)
  {
    int type;
    cin>>type;
    if(type==1)
    {
      int l1, r1, l2, r2;
      cin>>l1>>r1>>l2>>r2;
      int ans1 = sg1.query(0,0,n1-1,l1,r1);
      int ans2 = sg2.query(0,0,n2-1,l2,r2);
      cout<<min(ans1,ans2)<<endl;
    }
    else
    {
      int arrNo,i,val;
      cin>>arrNo>>i>>val;
      if(arrNo == 1)
      {
        sg1.update(0,0,n1-1,i,val);
        arr1[i]=val;
      }
      else if(arrNo == 2)
      {
        sg2.update(0,0,n2-1,i,val);
        arr2[i]=val;
      }
      else
      {
        cout<<"Invalid array number"<<endl;
      }
    }
  }

}
int main()
{
  solve2();
  return 0;
}