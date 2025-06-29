#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
class Solution {
public:
    void preparedAdjList(vector<vector<int>>& roads, unordered_map<int,list<pair<int,int>>>& adjList)
    {
        for(auto road:roads)
        {
            int u=road[0];
            int v=road[1];
            int w=road[2];

            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,list<pair<int,int>>> adjList;
        preparedAdjList(roads,adjList);

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> time_delay(n,LLONG_MAX);
        vector<int> ways(n,0);

        pq.push({0,0});
        time_delay[0]=0;
        ways[0]=1;

        while(!pq.empty())
        {
            auto it=pq.top();
            int front=it.second;
            long long time=it.first;

            pq.pop();
            for(auto i:adjList[front])
            {
                int adjNode=i.first;
                long long edW=i.second;

                if(time+edW < time_delay[adjNode])
                {
                    time_delay[adjNode]=time+edW;
                    ways[adjNode]=(ways[front]%MOD);
                    pq.push({time_delay[adjNode],adjNode});
                }
                else if(time+edW == time_delay[adjNode])
                {
                    ways[adjNode]=(ways[adjNode]+ways[front])%MOD;
                }
            }
            
        }

        return ways[n-1]%MOD;
    }
};

int main()
{
    int n = 7;
    vector<vector<int>> roads = {{0, 1, 2}, {0, 2, 4}, {1, 3, 2}, {1, 4, 4}, {2, 5, 3}, {3, 6, 1}, {4, 6, 2}, {5, 6, 1}};

    Solution sol;
    int result = sol.countPaths(n, roads);
    cout << "Number of ways to arrive at destination: " << result << endl;

    return 0;
}