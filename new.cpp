#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// // int main()
// // {
// //   int x,y,hcf,lcm,i;
// //   cout<<"Enter The first number:";
// //   cin>>x;
// //   cout<<"Enter The first number:";
// //   cin>>y;
// //   if(x<y)
// //   {
// //     i=x;
// //   }
// //   else{
// //     i=y;
// //   }
// //   cout<<"i = "<<x<<endl;
// //   while(i>=1)
// //   {
// //     if(x%i==0 && y%i==0)
// //     {
// //       hcf = i;
// //       break;
// //     }
// //     i--;
// //   }

// //   lcm = (x*y)/hcf;
// //   cout<<"hcf = "<<hcf<<endl;
// //   cout<<"lcm = "<<lcm<<endl;
// //   return 0;
// // }

// int solve(vector<int>& arr)
// {
//   int total=0;
//   int n=arr.size();

//   for(int i=0; i<n; i++)
//   {
//     if(arr[i]>arr[i+1])
//     {
//       int delta=arr[i]-arr[i+1];
//       total+=delta;
//       int need=(arr[i]<0)?1:-1;
//       for(int k=0; k<=i; k++)
//       {
//         arr[k] += (delta*need);
//       }
//     }
//   }
//   if(arr[0]!=0)
//   {
//     return total+1;
//   }
//   else{
//     return total;
//   }
// }

// int main()
// {
//   int n;
//   cin>>n;
//   vector<int> arr(n);
//   for(int i=0; i<n; i++)
//   {
//     cin>>arr[i];
//   }
//   cout<<solve(arr);
//   return 0;
// }

// int main()
// {
//   int i=0;
//   while(true)
//   {
//     i++;
//   }

//   return 0;
// }


// int minWage(vector<int>& arr)
// {
//   int n=arr.size();

//   int x=0;
//   int y=x;
//   for(int i=0; i<n; i++)
//   {
//     y=y+arr[i];
//     if(y<0)
//     {
//       x+=(-y);
//       y=0;
//     }
//   }

//   return x;
// }

vector<string> folderName(vector<string> folder)
{
  int n=folder.size();
  map<string,int> mpp;
  vector<string> ans;
  for(int i=0; i<n; i++)
  {
    string s=folder[i];
    if(mpp.find(s)==mpp.end())
    {
      mpp[s]++;
      ans.push_back(s);
    }
    else
    {
      mpp[s]++;
      s+=to_string(mpp[s]-1);
      ans.push_back(s);
    }
  }
  return ans;
}

int main()
{
  vector<string> arr = {"home" , "myfirst" ,"downloads", "myfirst", "myfirst"};
  vector<string> result=folderName(arr);
  for(auto it:result)
  {
    cout<<it<<endl;
  }
  return 0;
}