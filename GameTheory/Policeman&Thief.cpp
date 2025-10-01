#include<bits/stdc++.h>
using namespace std;

struct State{
  int P,T;
  bool P_turn;
}

vector<State> adj_rev[100][100][2];
bool winning[100][100][2];
bool losing[100][100][2];
bool visited[100][100][2];
int degree[100][100][2];

int main()
{
  int n,m;
  cin>>n>>m;
  vector<string> a(n);
  for(int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  
  for(int P=0; P<n*m; P++)
  {
    for(int T=0; T<n*m; T++)
    {
      for(int P_turn=0; P_turn<=1; P_turn++)
      {
        int Px=P/m;
        int Py=P%m;
        int Tx=T/m;
        int Ty=T%m;

        if(a[Px][Py]=='*' || a[Tx][Ty]=='*')
        {
          continue;
        }
      }
    }
  }
}

