#include<bits/stdc++.h>
using namespace std;

// class SegmentTree {
// public:
//     vector<int> seg;
//     SegmentTree(int n){
//         seg.resize(4*n);
//     }
//     void build(int index, int low, int high, vector<int>& arr)
//     {
//         if(low==high)
//         {
//             seg[index] = arr[low];
//             return;
//         }

//         int mid = (low+high)/2;
//         build(2*index+1, low, mid, arr);
//         build(2*index+2, mid+1, high, arr);

//         seg[index] = seg[2*index+1] + seg[2*index+2];
//     }

//     int query(int index, int low, int high, int l, int r)
//     {
//         // no overlap
//         if(low>r || high<l)
//         {
//           return 0;
//         }
//         else if(low>=l && high<=r)
//         {
//           // complete overlap
//           return seg[index];
//         }
//         else
//         {
//           int mid = (low+high)/2;
//           int left = query(2*index+1, low, mid, l,r);
//           int right = query(2*index+2, mid+1, high, l,r);

//           return left+right;
//         }
//     }

//     void update(int index, int low, int high, int i, int val)
//     {
//         if(low==high)
//         {
//             seg[index] += val;
//             return;
//         }

//         int mid = (low+high)/2;
//         if(i<=mid)
//         {
//           update(2*index+1, low, mid, i, val);
//         }
//         else
//         {
//           update(2*index+2, mid+1, high, i, val);
//         }

//         seg[index] = seg[2*index+1] + seg[2*index+2];
//     }
// };

// void solve()
// {
//    int n;
//    cin>>n;
//    vector<int> arr(n);
//    int maxi=INT_MIN;
//    for(int i=0; i<n; i++)
//    {
//       cin>>arr[i];
//       maxi = max(maxi, arr[i]);
//    }
//    maxi += 1;
//    //cout<<maxi<<endl;
//    vector<int> freq(maxi,0);
//    for(int i=0; i<n; i++)
//    {
//      freq[arr[i]]++;
//    }
//    SegmentTree st(maxi);
//    st.build(0,0,maxi-1,freq);
//    //cout<<st.seg[0]<<endl;
//    int count=0;
//    for(int i=0; i<n; i++)
//    {
//       freq[arr[i]]--;
//       st.update(0,0,maxi-1,arr[i],-1);

//       count+=st.query(0,0,maxi-1,1,arr[i]-1);
//    }

//    cout<<count<<endl;
// }

// int main()
// {
//   solve();
//   return 0;
// }

class SGTree {
public: vector<int> seg;
public:
	SGTree(int n) {
		seg.resize(4 * n);
	}
 
	void build(int ind, int low, int high, int arr[]) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}
 
		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
 
	int query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return 0;
 
		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];
 
		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return left + right;
	}
	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] += val;
			return;
		}
 
		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
	}
};
void solve5() {
	int n;
	cin >> n;
	int arr[n];
	int mx = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	mx += 1;
	int freq[mx];
	memset(freq, 0, sizeof freq);
	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}
 
	SGTree st(mx);
	st.build(0, 0, mx - 1, freq);
	//cout << st.seg[0] << endl;
 
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		freq[arr[i]]--;
		st.update(0, 0, mx - 1, arr[i], -1);
 
		cnt += st.query(0, 0, mx - 1, 0, arr[i] - 1);
	}
 
	cout << cnt << endl;
 
}
signed main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	solve5();
	return 0;
}