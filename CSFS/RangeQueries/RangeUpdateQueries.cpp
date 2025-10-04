// #include<bits/stdc++.h>
// using namespace std;

// class SegmentTreeWithLazyPropagation
// {
// private:
//   vector<int> Seg,Lazy;
// public:
//   SegmentTreeWithLazyPropagation(int n)
//   {
//     Seg.resize(4*n+1);
//     Lazy.resize(4*n+1,0);
//   }
//   void build(int index,int low,int high,vector<int>& arr)
//   {
//     if(low==high)
//     {
//       Seg[index]=arr[low];
//       return;
//     }

//     int mid=low+(high-low)/2;
//     build(2*index+1,low,mid,arr);
//     build(2*index+2,mid+1,high,arr);

//     Seg[index]=Seg[2*index+1]+Seg[2*index+2];
//   }
//   void update(int index,int low,int high,int l,int r,int u)
//   {
//     if(Lazy[index]!=0)
//     {
//       Seg[index] += (high-low+1)*Lazy[index];
      
//       if(low!=high)
//       {
//         Lazy[2*index+1] += Lazy[index];
//         Lazy[2*index+2] += Lazy[index];
//       }

//       Lazy[index]=0;
//     }

//     //no overlap
//     if(high<l || low>r)
//     {
//       return;
//     }
//     // complete overlap
//     else if(low>=l && high<=r)
//     {
//       Seg[index]+=(high-low+1)*u;

//       if(low!=high)
//       {
//         Lazy[2*index+1] += u;
//         Lazy[2*index+2] += u;
//       }

//       return;
//     }

//     int mid = low+(high-low)/2;
//     update(2*index+1,low,mid,l,r,u);
//     update(2*index+2,mid+1,high,l,r,u);

//     Seg[index]=Seg[2*index+1]+Seg[2*index+2];
//   }
//   int query(int index,int low,int high,int k)
//   {
//     if(Lazy[index]!=0)
//     {
//       Seg[index] += (high-low+1)*Lazy[index];
      
//       if(low!=high)
//       {
//         Lazy[2*index+1] += Lazy[index];
//         Lazy[2*index+2] += Lazy[index];
//       }

//       Lazy[index]=0;
//     }
    
//     if(low==high)
//     {
//       return Seg[index];
//     }
//     int mid=low+(high-low)/2;
//     if(k<=mid)
//     {
//      return query(2*index+1,low,mid,k);
//     }
//     else
//     {
//      return query(2*index+2,mid+1,high,k);
//     }
//   }
// };

// int main()
// {
//   int n,q;
//   cin>>n>>q;
//   vector<int> arr(n);
//   for(int i=0;i<n;i++)
//   {
//     cin>>arr[i];
//   }

//   SegmentTreeWithLazyPropagation st(n);
//   st.build(0,0,n-1,arr);

//   for(int i=0;i<q;i++)
//   {
//     int type;
//     cin>>type;
//     if(type==1)
//     {
//       int l,r,u;
//       cin>>l>>r>>u;
//       l--;
//       r--;
//       st.update(0,0,n-1,l,r,u);
//     }
//     else
//     {
//       int k;
//       cin>>k;
//       k--;
//       cout<<st.query(0,0,n-1,k)<<endl;
//     }
//   }
//   return 0;
// }

#include<bits/stdc++.h>
using namespace std;

class SegmentTreeWithLazyPropagation {
private:
    vector<long long> Seg, Lazy; // long long to avoid overflow
public:
    SegmentTreeWithLazyPropagation(int n) {
        Seg.resize(4*n+1);
        Lazy.resize(4*n+1,0);
    }

    void build(int index,int low,int high,vector<int>& arr) {
        if(low==high) {
            Seg[index]=arr[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(2*index+1,low,mid,arr);
        build(2*index+2,mid+1,high,arr);
        Seg[index]=Seg[2*index+1]+Seg[2*index+2];
    }

    void update(int index,int low,int high,int l,int r,int u) {
        // Resolve lazy
        if(Lazy[index]!=0) {
            Seg[index] += (high-low+1)*Lazy[index];
            if(low!=high) {
                Lazy[2*index+1] += Lazy[index];
                Lazy[2*index+2] += Lazy[index];
            }
            Lazy[index]=0;
        }

        // No overlap
        if(high<l || low>r) return;

        // Complete overlap
        if(low>=l && high<=r) {
            Seg[index]+=(high-low+1)*u;
            if(low!=high) {
                Lazy[2*index+1] += u;
                Lazy[2*index+2] += u;
            }
            return;
        }

        int mid = low+(high-low)/2;
        update(2*index+1,low,mid,l,r,u);
        update(2*index+2,mid+1,high,l,r,u);
        Seg[index]=Seg[2*index+1]+Seg[2*index+2];
    }

    long long query(int index,int low,int high,int k) {
        // Resolve lazy
        if(Lazy[index]!=0) {
            Seg[index] += (high-low+1)*Lazy[index];
            if(low!=high) {
                Lazy[2*index+1] += Lazy[index];
                Lazy[2*index+2] += Lazy[index];
            }
            Lazy[index]=0;
        }

        if(low==high) {
            return Seg[index];
        }
        int mid=low+(high-low)/2;
        if(k<=mid) return query(2*index+1,low,mid,k);
        else return query(2*index+2,mid+1,high,k);
    }
};

int main() {
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    SegmentTreeWithLazyPropagation st(n);
    st.build(0,0,n-1,arr);
  
    while(q--) {
        int type;
        cin>>type;
        if(type==1) {
            int l,r,u;
            cin>>l>>r>>u;
            l--;
            r--;
            st.update(0,0,n-1,l,r,u);
        } else {
            int k;
            cin>>k;
            k--;
            cout<<st.query(0,0,n-1,k)<<endl;
        }
    }
    return 0;
}
