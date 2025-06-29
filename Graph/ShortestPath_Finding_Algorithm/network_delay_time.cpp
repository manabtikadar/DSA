#include<bits/stdc++.h>
using namespace std;  

class Solution {
public:
    void preparedAdjList(vector<vector<int>>& times, unordered_map<int,list<pair<int,int>>>& adjList)
    {
        for(auto time:times)
        {
            int u=time[0];
            int v=time[1];
            int w=time[2];

            adjList[u].push_back({v,w});
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> adjList;
        preparedAdjList(times,adjList);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> time_delay(n+1,INT_MAX);

        pq.push({0,k});
        time_delay[k]=0;

        while(!pq.empty())
        {
            auto it=pq.top();
            int front=it.second;
            int time=it.first;

            pq.pop();
            for(auto i:adjList[front])
            {
                int adjNode=i.first;
                int edW=i.second;

                if(time+edW<time_delay[adjNode])
                {
                    time_delay[adjNode]=time+edW;
                    pq.push({time+edW,adjNode});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1; i<=n; i++)
        {
            ans = max(ans,time_delay[i]);
        }

        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};

int main()
{
    int n = 4, k = 2;

    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};

    Solution obj;
    int ans = obj.networkDelayTime(times, n, k);
    cout << ans << endl; // Output: 2

    return 0;
}