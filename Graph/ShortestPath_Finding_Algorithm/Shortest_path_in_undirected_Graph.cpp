#include<bits/stdc++.h>

using namespace std;

void preparedAdjList(vector<pair<int,int>>& edges, unordered_map<int, list<int>>& adjList)
{
	for(auto edge : edges)
	{
		int u=edge.first;
		int v=edge.second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
}
void bfs(int node,unordered_map<int,bool>& visited,unordered_map<int,int>& parent,unordered_map<int, list<int>>& adjList)
{
	queue<int> q;
	q.push(node);
	visited[node]=true;
	parent[node]=-1;

	while(!q.empty())
	{
		int front=q.front();
		q.pop();

		for(auto i:adjList[front])
		{
			if(!visited[i])
			{
				q.push(i);
				visited[i]=true;
				parent[i]=front;
			}
		}
	}
}
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	unordered_map<int, list<int>> adjList;
	preparedAdjList(edges,adjList);

	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;

	for(int i=0; i<n; i++)
	{
		if(!visited[i])
		{
			bfs(s,visited,parent,adjList);
		}
	}

  for(auto i:parent)
  {
    cout << i.first << " -> " << i.second << endl;
  }
	vector<int> ans;
	int node=t;
	ans.push_back(t);
	while(parent[node]!=-1)
	{
		int temp=node;
		ans.push_back(parent[temp]);
		node = parent[temp];
	}

	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
  int n = 9, m = 10, s = 0, t = 8;
  vector<pair<int,int>> edges = {{0,1},{0,3},{3,4},{4 ,5},{5, 6},{1,2},{2,6},{6,7},{7,8},{6,8}};

  vector<int> path = shortestPath(edges, n, m, s, t);

  if(path.size() == 0 || path[0] != s || path.back() != t)
  {
    cout << "No path found" << endl;
  }
  else
  {
    cout << "Shortest Path: ";
    for(int node : path)
    {
      cout << node << " ";
    }
    cout << endl;
  }

  return 0;
}