#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void preparedAdjList(vector<vector<int>>& flights,unordered_map<int,list<pair<int,int>>>& adjList)
    {
        for(auto flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            adjList[u].push_back({v,price});
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,list<pair<int,int>>> adjList;
        preparedAdjList(flights,adjList);

        vector<int> price(n,INT_MAX);

        queue<vector<int>> q;
        price[src]=0;
        q.push({0,src,0}); // price,num_stops,node;

        while(!q.empty())
        {
            auto it=q.front();
            int node=it[1];
            int stops=it[0];
            int cost=it[2];
            q.pop();
            for(auto i:adjList[node])
            {
                int adjNode=i.first;
                int edW = i.second;

                if(cost+edW<price[adjNode] && stops<=k)
                {
                    price[adjNode]=cost+edW;
                    q.push({stops+1,adjNode,price[adjNode]});
                }
            }
        }

        if(price[dst]==INT_MAX)
        {
            return -1;
        }

        return price[dst];
    }
};

int main()
{
    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};

    Solution sol;

    int result = sol.findCheapestPrice(n, flights, src, dst, K);
    cout << "The cheapest price from " << src << " to " << dst << " with at most " << K << " stops is: " << result << endl;

    return 0;
}