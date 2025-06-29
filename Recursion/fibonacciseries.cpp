#include<iostream>

using namespace std;

int fibonacci(int n){
  int t0=0, t1=1, s,i;

  if (n<=1)
    return n;

  for(i=2;i<=n;i++){
    s = t0+t1;
    t0= t1;
    t1= s;
  }  

  return s;
}

int main(){
  return 0;
}