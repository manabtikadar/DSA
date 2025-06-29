#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
      queue<pair<int,int>> q;
      q.push({row,col});
      visited[row][col]=1;

      while(!q.empty())
      {
        int frontRow = q.front().first;
        int frontCol = q.front().second;
        q.pop();

        vector<int> delrow = {-1,-1,0,+1,+1,+1,0,-1};
        vector<int> delcol = {0,+1,+1,+1,0,-1,-1,-1};

        for(int i=0; i<8; i++)
        {
          int nrow = frontRow + delrow[i];
          int ncol = frontCol + delcol[i];

          if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && !visited[nrow][ncol] && grid[nrow][ncol]=='1')
          {
            q.push({nrow,ncol});
            visited[nrow][ncol]=1;
          }
        }
      }
    }
    int numIslands(vector<vector<char>>& grid)
    {
      vector<pair<int,int>> nodes;
      for(int i=0; i<grid.size(); i++)
      {
        for(int j=0; j<grid[0].size();j++)
        {
          if(grid[i][j]=='1')
          {
            nodes.push_back({i,j});
          }
        }
      }

      vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
      int count =0;

      for(int i=0; i<nodes.size(); i++)
      {
        int row = nodes[i].first;
        int col = nodes[i].second;
        if(!visited[row][col])
        {
          count++;
          bfs(row, col, grid, visited);
        }
      }

      return count;
    }
};

int main() {
    // n: row, m: column
    vector<vector<char>> grid
    {
        {'0', '1', '1', '0'},
        {'1', '1', '1', '1'},
        {'0', '0', '0', '1'},
        {'0', '1', '0', '0'},
        {'1', '0', '1', '0'}
    };

        
    Solution obj;
    cout << obj.numIslands(grid) << endl;
        
    return 0;
}