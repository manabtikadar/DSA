// #include <bits/stdc++.h>
// using namespace std;

// // bool iscycleBfs(int node,unordered_map<int,list<int>>& adjList,vector<int>& visited,vector<int>& parent, vector<int>& ans)
// // {
// //     queue<int> q;
// //     q.push(node);
// //     visited[node]=1;
// //     parent[node]=-1;

// //     while(!q.empty())
// //     {
// //       int front_node=q.front();
// //       q.pop();

// //       for(auto neighbour:adjList[front_node])
// //       {
// //         if(!visited[neighbour])
// //         {
// //           visited[neighbour]=1;
// //           parent[neighbour]=front_node;
// //           q.push(neighbour);
// //         }
// //         else if(visited[neighbour] && parent[front_node]!=neighbour)
// //         {
// //           ans.push_back(neighbour);
// //           int curr=front_node;
// //           while(curr!=neighbour)
// //           {
// //             ans.push_back(curr);
// //             curr=parent[curr];
// //           }
// //           ans.push_back(neighbour); 
// //           reverse(ans.begin(), ans.end());
// //           return true;
// //         }
// //       }
// //     }

// //     return false;
// // }

// bool iscycleBfs(int node, unordered_map<int,list<int>>& adjList,
//                 vector<int>& visited, vector<int>& parent, vector<int>& ans)
// {
//     queue<int> q;
//     q.push(node);
//     visited[node] = 1;
//     parent[node] = -1;

//     while (!q.empty()) {
//         int front_node = q.front();
//         q.pop();

//         for (auto neighbour : adjList[front_node]) {
//             if (!visited[neighbour]) {
//                 visited[neighbour] = 1;
//                 parent[neighbour] = front_node;
//                 q.push(neighbour);
//             }
//             else if (visited[neighbour] && parent[front_node] != neighbour) {
//                 // cycle found, reconstruct
//                 int curr = front_node;
//                 ans.push_back(neighbour);

//                 while (curr != neighbour) {
//                     ans.push_back(curr);
//                     curr = parent[curr];
//                 }
//                 ans.push_back(neighbour);

//                 reverse(ans.begin(), ans.end());
//                 return true;
//             }
//         }
//     }
//     return false;
// }


// vector<int> RoundTrip(int n, int m, vector<vector<int>>& edges) {
//     unordered_map<int, list<int>> adjList;

//     for (auto edge : edges) {
//         int u = edge[0];
//         int v = edge[1];
//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }

//     vector<int> parent(n + 1, -1);
//     vector<int> visited(n + 1, 0);

//     vector<int> ans;
//     for (int i = 1; i <= n; i++) {
//         if (!visited[i]) {
//             bool iscycle = iscycleBfs(i, adjList, visited, parent,ans);
//             if(iscycle)
//             {
//                return ans;
//             }
//         }
//     }

//     return {};
// }

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> edges(m, vector<int>(2));
//     for (int i = 0; i < m; i++) {
//         cin >> edges[i][0] >> edges[i][1];
//     }

//     vector<int> ans = RoundTrip(n, m, edges);

//     if (ans.size()==0) {
//         cout << "No cycle detected" << endl;
//     } else {
//         cout << ans.size() << endl;
//         for (auto it : ans) {
//             cout << it << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }


#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
 
int n, m;
int sv, ev;
vector<vector<int>> g;
vector<int> vis;
vector<int> parent;
 
 
bool dfs(int u, int p)
{
	vis[u] = true;
	parent[u] = p;
	for(auto v: g[u])
	{
		if(v == p) continue;
		if(vis[v]) 
		{
			sv = v; 
			ev = u; 
			return true;
		} 
		if(!vis[v]) 
			if(dfs(v,u)) 
				return true;
	}
	return false;
}
 
 
bool visit_all()
{
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
			if(dfs(i,-1)) return true;
	}
	return false;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	parent.resize(n+1);
	for(int i =0 ; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	if(!visit_all())
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
	int tv = ev;
	vector<int> ans;
	ans.push_back(ev);
	while(tv != sv)
	{
		ans.push_back(parent[tv]);
		tv = parent[tv];
	}
	ans.push_back(ev);
	cout << ans.size() << endl;
	for(auto c: ans)
	{
		cout << c << " ";
	}
 
}

