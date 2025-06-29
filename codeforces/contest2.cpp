#include<bits/stdc++.h>
using namespace std;

void solve(){

  int n;
  cout<<"enter n:";
  cin>>n;
  int a[n],b[n];
  cout<<"\n Enter array a:";
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<"\n Enter array b:";
  for(int i=0;i<n;i++)
  {
    cin>>b[i];
  }


  int diff=0;
  for(int i=0; i<n-1; i++)
  {
    if(a[i]>b[i+1])
    {
      
      diff+=(a[i]-b[i+1]);
    }
  }
  diff += a[n-1];
  cout<<diff<<"\n";
}

int main()
{ int t;
  cin >> t;
  
  
  while (t--) {
      solve();
  }    
  
  return 0;
}