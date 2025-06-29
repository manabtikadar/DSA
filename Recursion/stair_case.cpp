#include<iostream>

using namespace std;

int CountDistinctwayToClimbStair(int nStairs)
{
  if(nStairs<0)
  {
    return 0;
  }
  if(nStairs==0)
  {
    return 1;
  }

  return CountDistinctwayToClimbStair(nStairs-1)+CountDistinctwayToClimbStair(nStairs-2);
}

int main(){
  int n;
  cout<<"n: ";
  cin>>n;
  
  printf("Number of distinct ways to climb stairs:%d", CountDistinctwayToClimbStair(n));

}