// #include<bits/stdc++.h>
// using namespace std;

// void solve(){

//   int n;
//   cout<<"enter n:";
//   cin>>n;
//   int a[n],b[n];
//   cout<<"\n Enter array a:";
//   for(int i=0;i<n;i++)
//   {
//     cin>>a[i];
//   }
//   cout<<"\n Enter array b:";
//   for(int i=0;i<n;i++)
//   {
//     cin>>b[i];
//   }


//   int diff=0;
//   for(int i=0; i<n-1; i++)
//   {
//     if(a[i]>b[i+1])
//     {
      
//       diff+=(a[i]-b[i+1]);
//     }
//   }
//   diff += a[n-1];
//   cout<<diff<<"\n";
// }

// int main()
// { int t;
//   cin >> t;
  
  
//   while (t--) {
//       solve();
//   }    
  
//   return 0;
// }

// #include<bits/stdc++.h>
 
// using namespace std;
 
// void solve()
// {
//    long long n;
//    cin>>n;
//    vector<long long> numbers;
//    int p=10;
//    while(true)
//    {
//       long long div=p+1;
//       if(div>n) break;
      
//       //long long x=n/div;
//       if(n%div==0)
//       {
//           long long x=n/div;
//           numbers.push_back(x);                                    
//       }
//       if (p > LLONG_MAX / 10) break;
//       p*=10;
//    }
   
//    int n1=numbers.size();
//    if(n1==0)
//    {
//       cout<<"0";                                      
//    }
//    else
//    {
//      cout<<n1<<endl;
//      for(int i=0; i<n1; i++)
//      {
//          cout<<numbers[i]<<" ";                                     
//      }
//    }
//    return;
// }
 
// int main()
// {
//    int t;
//    cin>>t;
   
//    while(t--)
//    {
//       solve();
//       cout<<endl;
//    }
   
//    return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> numbers;

    long long p = 10;  
    while (true) {
        long long div = p + 1;
        if (div > n) break;

        if (n % div == 0) {
            numbers.push_back(n / div);
        }

        if (p > LLONG_MAX / 10) break; 
        p *= 10;
    }

    if (numbers.empty()) {
        cout << 0 << "\n";
    } else {
        cout << numbers.size() << "\n";
        for (auto x : numbers) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
