// #include <bits/stdc++.h>
// using namespace std;

// void solve()
// {
//   double n;
//   cout<<"Enter The value of n:";
//   cin>>n;

//   double x = n, h = 0;
  
//   while(x!=1&&x>3)
//   {
//     h++;
//     x = floor(x/4);
//   }

//   cout<<"maximum number of coins: "<<pow(2,h)<<endl;

// }

// int main()
// {
//   double t;
//   cin>>t;
//   while(t--)
//   {
//     solve();
//   }
//   return 0;
// }


#include <bits/stdc++.h>
using namespace std;

long long factorial(long long n)
{
  long long result=1,i;
  for(i=2;i<=n;i++)
  {
    result *= i;
  }
   
  return result;
}


void solve()
{
  long long n ,d, f;
  cout<<"\nEnter the value n and d: ";
  cin>>n>>d;
  
  f = factorial(n);
  long long sum = f*d;

  cout<<"1 ";
  if(sum%3 == 0)
  {
    cout<<"3 ";
  }
  if(d==0 || d==5)
  {
    cout<<"5 ";
  }
  if(n>=7)
  {
    cout<<"7 ";
  }
  if(sum%9==0)
  {
    cout<<"9 ";
  }

}

int main()
{
  double t;
  cin>>t;
  while(t--)
  {
    solve();
  }
  return 0;
}