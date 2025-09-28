// #include<bits/stdc++.h>
// using namespace std;

// void bfs_monsters(vector<pair<int>>& Monsters,vector<vector<vector<int>>>& visited,vector<vector<vector<int>>>& dist,vector<vector<char>>& Map)
// {
//   int n=Map.size();
//   int m=Map[0].size();

//   queue<pair<int,pair<int,int>>> q;
//   for(auto Monster:Monsters)
//   {
//     visited[Monste.first][Monster.second][1]=1;
//     q.push({0,{Monste.first,Monster.second}});
//     dist[Monster.first][Monster.second][1]=0;
//   }

//   vector<int> delrow={-1,0,1,0};
//   vector<int> delcol={0,1,0,-1};

//   while(!q.empty())
//   {
//     int row=q.front().second.first;
//     int col=q.front().second.second;

//     int dist=q.front().first;

//     for(int i=0; i<4; i++)
//     {
//       int nrow=row+delrow[i];
//       int ncol=col+delcol[i];

//       if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol][1])
//       {
//         visited[nrow][ncol][1]=1;
//         dist[nrow][ncol][1]=dist+1;
//         q.push({dist+1,{nrow,ncol}});
//       }
//     }
//   }
// }

// void bfs(pair<int,int> start,vector<vector<vector<int>>>& visited,vector<vector<vector<int>>>& dist,vector<vector<char>>& Map,vector<vector<char>>& move)
// {
//   int n=Map.size();
//   int m=Map[0].size();

//   queue<pair<int,pair<int,int>>> q;
//   visited[start.first][start.second][0]=1;
//   q.push({0,{start.first,start.second}});
//   dist[start.first][start.second][0]=0;

//   vector<int> delrow={-1,0,1,0};
//   vector<int> delcol={0,1,0,-1};
//   vector<char> dir={'U','R','D','L'};

//   while(!q.empty())
//   {
//     int row=q.front().second.first;
//     int col=q.front().second.second;

//     int dist=q.front().first;

//     for(int i=0;i<4;i++)
//     {
//       int nrow=row+delrow[i];
//       int ncol=col+delcol[i];

//       if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol][0])
//       {
//         visited[nrow][ncol][0]=1;
//         dist[nrow][ncol][0]=dist+1;
//         q.push({dist+1,{nrow,ncol}});
//         move[nrow][ncol]=dir[i];
//       }
//     }
//   }
// }

// bool Monsters(int n,int m,vector<vector<char>>& Map,string& path,int& dis)
// {
//   vector<vector<int>> visited(n,vector<vector<int>>(m,vector<int>(2,0)));
//   pair<int,int> start;
//   vector<pair<int,int>> Monsters;
//   for(int i=0; i<n; i++)
//   {
//     for(int j=0; j<m; j++)
//     {
//       if(Map[i][j]=='#')
//       {
//         visited[i][j][0]=1;
//         visited[i][j][1]=1
//       }
//       else if(Map[i][j]=='.')
//       {
//         visited[i][j]=0;
//         visited[i][j]=0;
//       }
//       else if(Map[i][j]=='M')
//       {
//         Monsters.push_back({i,j});
//       }
//       else if(Map[i][j]=='A')
//       {
//         start={i,j};
//       }
//     }
//   }
  
//   vector<vector<char>> move(n,vector<char>(m,' '));
//   vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, -1)));

//   pair<int,int> endpoint={-1,-1};
//   int distane=INT_MAX;

//   for(int i=0; i<n; i++)
//   {
//     if(dist[i][0][0]!=-1 && dist[i][0][0]<dist[i][0][1] && dist[i][0][0]<distance)
//     {
//       distance=dist[i][0][0];
//       endpoint={i,0};
//     }
//   }
//   for(int i=0; i<n; i++)
//   {
//     if(dist[i][m-1][0]!=-1 && dist[i][m-1][0]<dist[i][m-1][1] && dist[i][m-1][0]<distance)
//     {
//       distance=dist[i][m-1][0];
//       endpoint={i,m-1};
//     }
//   }

//   for(int j=0; j<m; j++)
//   {
//     if(dist[0][j][0]!=-1 && dist[0][j][0]<dist[0][j][1] && dist[0][j][0]<distance)
//     {
//       distance=dist[0][j][0];
//       endpoint={0,j};
//     }
//   }

//   for(int j=0; j<m; j++)
//   {
//     if(dist[n-1][j][0]!=-1 && dist[n-1][j][0]<dist[n-1][j][1] && dist[n-1][j][0]<distance)
//     {
//       distance=dist[n-1][j][0];
//       endpoint={n-1,j};
//     }
//   }

//   if(endpoint.first==-1)
//   {
//     return false;
//   }

//   int row=endpoint.first;
//   int col=endpoint.second;
//   int dis1=dist[row][col][0];
//   while(dis1!=0)
//   {
//     char m=move[row][col];
//     if(m=='U')
//     {
//       row=row+1;
//     }
//     else if(m=='D')
//     {
//       row=row-1;
//     }
//     else if(m=='R')
//     {
//       col = col-1;
//     }
//     else if(m=='L')
//     {
//       col = col+1;
//     }
//     path.push_back(m);
//     dis1--;
//   }

//   return true;
// }

// int main()
// {
//   int n,m;
//   cin>>n>>m;

//   vector<vector<char>> Map(n,vector<char>(m));
//   for(int i=0; i<n; i++)
//   {
//     for(int j=0; j<m; j++)
//     {
//       cin>>Map[i][j];
//     }
//   }

//   string path;
//   int dis;
//   if(Monsters(n,m,Map,path,dis))
//   {
//     cout<<"YES\n";
//     cout<<dis<<"\n";
//     cout<<path<<"\n";
//   }
//   else
//   {
//     cout<<"NO\n";
//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void bfs_monsters(vector<pair<int,int>>& Monsters, vector<vector<vector<int>>>& visited,
                  vector<vector<vector<int>>>& dist, vector<vector<char>>& Map)
{
    int n = Map.size();
    int m = Map[0].size();

    queue<pair<int,pair<int,int>>> q;
    for (auto Monster : Monsters)
    {
        visited[Monster.first][Monster.second][1] = 1;
        q.push({0,{Monster.first,Monster.second}});
        dist[Monster.first][Monster.second][1] = 0;
    }

    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};

    while(!q.empty())
    {
        int row=q.front().second.first;
        int col=q.front().second.second;
        int d=q.front().first;
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol][1] && Map[nrow][ncol] != '#')
            {
                visited[nrow][ncol][1]=1;
                dist[nrow][ncol][1]=d+1;
                q.push({d+1,{nrow,ncol}});
            }
        }
    }
}

void bfs(pair<int,int> start, vector<vector<vector<int>>>& visited,
         vector<vector<vector<int>>>& dist, vector<vector<char>>& Map,
         vector<vector<char>>& move)
{
    int n=Map.size();
    int m=Map[0].size();

    queue<pair<int,pair<int,int>>> q;
    visited[start.first][start.second][0]=1;
    q.push({0,{start.first,start.second}});
    dist[start.first][start.second][0]=0;

    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};
    vector<char> dir={'U','R','D','L'};

    while(!q.empty())
    {
        int row=q.front().second.first;
        int col=q.front().second.second;
        int d=q.front().first;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol][0] && Map[nrow][ncol] != '#')
            {
                visited[nrow][ncol][0]=1;
                dist[nrow][ncol][0]=d+1;
                q.push({d+1,{nrow,ncol}});
                move[nrow][ncol]=dir[i];
            }
        }
    }
}

bool MonstersSolve(int n,int m,vector<vector<char>>& Map,string& path,int& dis)
{
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2,0)));
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2,-1)));

    pair<int,int> start;
    vector<pair<int,int>> Monsters;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(Map[i][j]=='#')
            {
                visited[i][j][0]=1;
                visited[i][j][1]=1;
            }
            else if(Map[i][j]=='M')
            {
                Monsters.push_back({i,j});
            }
            else if(Map[i][j]=='A')
            {
                start={i,j};
            }
        }
    }

    vector<vector<char>> move(n, vector<char>(m,' '));

    bfs_monsters(Monsters,visited,dist,Map);
    bfs(start,visited,dist,Map,move);

    pair<int,int> endpoint={-1,-1};
    int distance=INT_MAX;

    // check borders
    for(int i=0;i<n;i++){
        if(dist[i][0][0]!=-1 && (dist[i][0][1]==-1 || dist[i][0][0]<dist[i][0][1]) && dist[i][0][0]<distance){
            distance=dist[i][0][0]; endpoint={i,0};
        }
        if(dist[i][m-1][0]!=-1 && (dist[i][m-1][1]==-1 || dist[i][m-1][0]<dist[i][m-1][1]) && dist[i][m-1][0]<distance){
            distance=dist[i][m-1][0]; endpoint={i,m-1};
        }
    }
    for(int j=0;j<m;j++){
        if(dist[0][j][0]!=-1 && (dist[0][j][1]==-1 || dist[0][j][0]<dist[0][j][1]) && dist[0][j][0]<distance){
            distance=dist[0][j][0]; endpoint={0,j};
        }
        if(dist[n-1][j][0]!=-1 && (dist[n-1][j][1]==-1 || dist[n-1][j][0]<dist[n-1][j][1]) && dist[n-1][j][0]<distance){
            distance=dist[n-1][j][0]; endpoint={n-1,j};
        }
    }

    if(endpoint.first==-1) return false;

    dis = distance;
    int row=endpoint.first, col=endpoint.second;
    while(make_pair(row,col)!=start)
    {
        char m=move[row][col];
        path.push_back(m);
        if(m=='U') row++;
        else if(m=='D') row--;
        else if(m=='R') col--;
        else if(m=='L') col++;
    }
    reverse(path.begin(), path.end());
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> Map(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>Map[i][j];
    }

    string path;
    int dis;
    if(MonstersSolve(n,m,Map,path,dis))
    {
        cout<<"YES\n";
        cout<<dis<<"\n";
        cout<<path<<"\n";
    }
    else cout<<"NO\n";
}
