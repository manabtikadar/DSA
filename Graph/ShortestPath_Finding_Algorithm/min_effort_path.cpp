#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,
                       vector<pair<int,pair<int,int>>>,
                       greater<pair<int,pair<int,int>>>> pq;

        int start_row=0;
        int start_col=0;
        
        int end_row=n-1;
        int end_col=m-1;
        pq.push({0,{start_row,start_col}});
        effort[start_row][start_col]=0;
        
        vector<int> delrow={-1,0,+1,0};
        vector<int> delcol={0,+1,0,-1};
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            int diff=top.first;
            int row=top.second.first;
            int col=top.second.second;
            
            if(row==end_row && col==end_col)
            {
                return diff;
            }
            for(int i=0; i<4; i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    int new_effort=max(abs(heights[row][col]-heights[nrow][ncol]),diff);

                    if(new_effort<effort[nrow][ncol])
                    {
                        effort[nrow][ncol]=new_effort;
                        pq.push({new_effort,{nrow,ncol}});
                    }
                }
            }

        }

        return 0;
    }
};

int main()
{
    // Driver Code.

    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution obj;

    int ans = obj.minimumEffortPath(heights);

    cout << ans;
    cout << endl;

    return 0;
}