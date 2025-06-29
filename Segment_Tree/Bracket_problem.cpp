// #include<bits/stdc++.h>
// using namespace std;

// class SegmentTree{
// public:
//     struct Node{
//         int openings;
//         int closings;
//         int full;
//     };
// public:
//     vector<Node> seg;
//     SegmentTree(int n)
//     {
//         seg.resize(4*n+1);
//     }
//     void build(int index, int low, int high, string s)
//     {
//         if(low==high)
//         {
//             if(s[low]=='(')
//             {
//                 seg[index].openings = 1;
//                 seg[index].closings = 0;
//                 seg[index].full = 0;
//             }
//             else
//             {
//                 seg[index].openings = 0;
//                 seg[index].closings = 1;
//                 seg[index].full = 0;
//             }
//             return;
//         }

//         int mid = (low+high)/2;
//         build(2*index+1, low, mid, s);
//         build(2*index+2, mid+1, high, s);

//         int min_pairs = min(seg[2*index+1].openings, seg[2*index+2].closings);
//         seg[index].openings = seg[2*index+1].openings + seg[2*index+2].openings - min_pairs;
//         seg[index].closings = seg[2*index+1].closings + seg[2*index+2].closings - min_pairs;
//         seg[index].full = seg[2*index+1].full + seg[2*index+2].full + min_pairs;
//     }

//     Node query(int index, int low, int high, int l, int r)
//     {
//         // no overlap
//         if(low > r || high < l)
//         {
//             return {0,0,0};
//         }
//         else if(low>=l && high<=r)
//         {
//             // complete overlap
//             return seg[index];
//         }
//         else
//         {
//             // partial overlap
//             int mid = (low+high)/2;
//             Node left = query(2*index+1, low, mid, l, r);
//             Node right = query(2*index+2, mid+1, high, l, r);
            
//             Node result;
//             int min_pairs = min(left.openings, right.closings);
//             result.openings = left.openings + right.openings - min_pairs;
//             result.closings = left.closings + right.closings - min_pairs;
//             result.full = left.full + right.full + min_pairs;

//             return result;
//         }
//     }
// };

// void solve()
// {
//     string s;
//     cin>>s;
//     int m;
//     cin>>m;
//     int n = s.size();
//     SegmentTree seg(n);
//     seg.build(0, 0, n-1, s);

//     while(m--)
//     {
//         int l, r;
//         cin>>l>>r;

//         SegmentTree::Node ans = seg.query(0, 0, n-1, l-1, r-1);
//         int result = ans.full * 2; // each full pair contributes 2 to the length
//         cout << result << endl;
//     }

// }

// int main()
// {
//    solve();
//    return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// Global Node
struct Node {
    int openings;
    int closings;
    int full;
    
    Node():openings(0), closings(0), full(0) {}
    // constructor
    Node(int _open, int _close, int _full)
    {
        openings = _open;
        closings = _close;
        full = _full;
    }
};

class SegmentTree {
public:
    vector<Node> seg;

    SegmentTree(int n) {
        seg.resize(4 * n + 1);
    }

    void build(int index, int low, int high, string s) {
        if (low == high) {
            if (s[low] == '(') {
                // seg[index].openings = 1;
                // seg[index].closings = 0;
                // seg[index].full = 0;
                seg[index] = Node(1, 0, 0);
            } else {
                // seg[index].openings = 0;
                // seg[index].closings = 1;
                // seg[index].full = 0;
                seg[index] = Node(0, 1, 0);
            }
            return;
        }

        int mid = (low + high) / 2;
        build(2 * index + 1, low, mid, s);
        build(2 * index + 2, mid + 1, high, s);

        int min_pairs = min(seg[2 * index + 1].openings, seg[2 * index + 2].closings);
        // seg[index].openings = seg[2 * index + 1].openings + seg[2 * index + 2].openings - min_pairs;
        // seg[index].closings = seg[2 * index + 1].closings + seg[2 * index + 2].closings - min_pairs;
        // seg[index].full = seg[2 * index + 1].full + seg[2 * index + 2].full + min_pairs;
        seg[index] = Node(
            seg[2 * index + 1].openings + seg[2 * index + 2].openings - min_pairs,
            seg[2 * index + 1].closings + seg[2 * index + 2].closings - min_pairs,
            seg[2 * index + 1].full + seg[2 * index + 2].full + min_pairs
        );
    }

    Node query(int index, int low, int high, int l, int r) {
        if (low > r || high < l) {
            return Node(0, 0, 0);
        } else if (low >= l && high <= r) {
            return seg[index];
        } else {
            int mid = (low + high) / 2;
            Node left = query(2 * index + 1, low, mid, l, r);
            Node right = query(2 * index + 2, mid + 1, high, l, r);

            // Node result;
            int min_pairs = min(left.openings, right.closings);
            // result.openings = left.openings + right.openings - min_pairs;
            // result.closings = left.closings + right.closings - min_pairs;
            // result.full = left.full + right.full + min_pairs;
            Node result = Node(
                left.openings + right.openings - min_pairs,
                left.closings + right.closings - min_pairs,
                left.full + right.full + min_pairs
            );

            return result;
        }
    }
};
void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    int n = s.size();
    SegmentTree seg(n);
    seg.build(0, 0, n - 1, s);

    while (m--) {
        int l, r;
        cin >> l >> r;

        Node ans = seg.query(0, 0, n - 1, l - 1, r - 1);
        int result = ans.full * 2; // each full pair contributes 2 to the length
        cout << result << endl;
    }
}
int main() {
    solve();
    return 0;
}