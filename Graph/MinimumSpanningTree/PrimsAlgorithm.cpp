#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
    {
        //create adjList
        unordered_map<int,list<pair<int,int>>> adjList;
        for(auto e : g)
        {
            int u=e.first.first;
            int v=e.first.second;
            int w=e.second;

            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }

        vector<int> key(n+1,INT_MAX);
        vector<bool> mst(n+1,false);
        vector<int> parent(n+1,-1);

        int src=1;
        key[src]=0;
        parent[src]=-1;

        for(int i=1; i<=n; i++)
        {
            int mini = INT_MAX;
            int u;

            for(int v=1; v<=n; v++)
            {
                if(mst[v]==false && key[v]<mini)
                {
                    u=v;
                    mini = key[v];
                }
            }

            mst[u]=true;
            for(auto neighbour:adjList[u])
            {
                int adjNode=neighbour.first;
                int edW=neighbour.second;

                if(mst[adjNode]==false && edW<key[adjNode])
                {
                    key[adjNode]=edW;
                    parent[adjNode]=u;
                }
            }
        }

        vector<pair<pair<int,int>,int>> result;
        for(int i=2; i<=n; i++)
        {
            result.push_back({{parent[i],i},key[i]});
        }

        return result;
        
    }

    vector<pair<pair<int, int>, int>> calculatePrimsMST2(int n, int m, vector<pair<pair<int, int>, int>> &g)
    {
        //create adjList
        unordered_map<int,list<pair<int,int>>> adjList;
        for(auto e : g)
        {
            int u=e.first.first;
            int v=e.first.second;
            int w=e.second;

            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }

        vector<int> key(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> mst(n+1,false);
        vector<int> parent(n+1,-1);

        int src=1;
        key[src]=0;
        pq.push({0,src}); // {key,node}
        parent[src]=-1;

        
        // using priority queue to get the minimum weight edge
        // in the above code we are using a simple for loop to get the minimum weight edge whose time complexity is O(n^2)
        // but using priority queue we can get the minimum weight edge in O(log n) time complexity so the overall time complexity of the algorithm will be O(m log n) where m is the number of edges and n is the number of vertices
        // and the space complexity will be O(n) for the priority queue and O(n) for the adjacency list
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int u=it.second;
            
            mst[u]=true;
            for(auto neighbour:adjList[u])
            {
                int adjNode=neighbour.first;
                int edW=neighbour.second;

                if(mst[adjNode]==false && edW<key[adjNode])
                {
                    parent[adjNode]=u;
                    pq.push({edW,adjNode});
                    key[adjNode]=edW;
                }
            }
        }

        vector<pair<pair<int,int>,int>> result;
        for(int i=2; i<=n; i++)
        {
            result.push_back({{parent[i],i},key[i]});
        }

        return result;
        
    }
};

int main()
{
    int n = 5; // number of vertices
    int m = 6; // number of edges
    vector<pair<pair<int, int>, int>> edges = {{{1, 2}, 3}, {{1, 3}, 1}, {{2, 3}, 7}, {{2, 4}, 5}, {{3, 4}, 2}, {{4, 5}, 6}};

    Solution sol;
    vector<pair<pair<int, int>, int>> mst = sol.calculatePrimsMST2(n, m, edges);
    int sum = 0;
    cout << "Edges in the Minimum Spanning Tree (MST):" << endl;
    for (auto edge : mst) {
        cout << edge.first.first << " - " << edge.first.second << " with weight " << edge.second << endl;
        sum += edge.second;
    }
    cout << "Total weight of MST: " << sum << endl;
    return 0;
}
