#include<iostream>
#include<vector>
using namespace std;
bool isallowed(int x, int y, vector<vector<int>>& visited,vector<vector<int>> maze,int n)
{
  if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && maze[x][y]==1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void mazesolve(vector<vector<int>> maze, int x, int y, int n, vector<vector<int>>& visited,vector<string>& ans, string path)
{
  if(x==n-1 && y==n-1)
  { 
    cout<<path<<endl;
    ans.push_back(path);
    return;
  }
  
  visited[x][y]=1;
  
  // Down
  int newx=x+1;
  int newy=y;
  if(isallowed(newx,newy,visited,maze,n))
  {
    path.push_back('D');
    mazesolve(maze,newx,newy,n,visited,ans,path);
    path.pop_back();
  }
  //up
  newx=x-1;
  newy=y;
  if(isallowed(newx,newy,visited,maze,n))
  {
    path.push_back('U');
    mazesolve(maze,newx,newy,n,visited,ans,path);
    path.pop_back();
  }
  //right
  newx=x;
  newy=y+1;
  if(isallowed(newx,newy,visited,maze,n))
  {
    path.push_back('R');
    mazesolve(maze,newx,newy,n,visited,ans,path);
    path.pop_back();
  }
  //left
  newx=x;
  newy=y-1;
  if(isallowed(newx,newy,visited,maze,n))
  {
    path.push_back('L');
    mazesolve(maze,newx,newy,n,visited,ans,path);
    path.pop_back();
  }
  
  visited[x][y]=0;
}

int main()
{
  vector<vector<int>> maze ={{1,0,0,0},{1,1,1,1},{1,1,0,1},{0,1,1,1}};
  int n = 4;
  int scrx = 0;
  int scry = 0;
  vector<vector<int>> visited(n, vector<int>(n, 0));
  vector<string> ans;
  string path = "";
  if (maze[0][0] == 1)
  {
      mazesolve(maze,scrx,scry, n, visited, ans, path);
  }
  else
  {
      cout << "No path exists!" << endl;
  }
  
  return 0;
}