#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//   int x,y,hcf,lcm,i;
//   cout<<"Enter The first number:";
//   cin>>x;
//   cout<<"Enter The first number:";
//   cin>>y;
//   if(x<y)
//   {
//     i=x;
//   }
//   else{
//     i=y;
//   }
//   cout<<"i = "<<x<<endl;
//   while(i>=1)
//   {
//     if(x%i==0 && y%i==0)
//     {
//       hcf = i;
//       break;
//     }
//     i--;
//   }

//   lcm = (x*y)/hcf;
//   cout<<"hcf = "<<hcf<<endl;
//   cout<<"lcm = "<<lcm<<endl;
//   return 0;
// }

int solve(vector<int>& arr)
{
  int total=0;
  int n=arr.size();

  for(int i=0; i<n; i++)
  {
    if(arr[i]>arr[i+1])
    {
      int delta=arr[i]-arr[i+1];
      total+=delta;
      int need=(arr[i]<0)?1:-1;
      for(int k=0; k<=i; k++)
      {
        arr[k] += (delta*need);
      }
    }
  }
  if(arr[0]!=0)
  {
    return total+1;
  }
  else{
    return total;
  }
}

int main()
{
  vector<int> arr={3,2,1};
  cout<<solve(arr);
  return 0;
}