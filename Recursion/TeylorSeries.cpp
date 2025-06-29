#include<iostream>

using namespace std;

double Teylor(int x, int n){
  static double p=1, f=1;
  double r;
  if(n==0){
    return 1;
  }
  else{
    r=Teylor(x,n-1);
    p=p*x;
    f=f*n;
    return r+(p/f);
  }

  }
int main(){

  printf("%lf", Teylor(3,10));
  return 0;
}


//Horner's rule 
int exponential(int x, int n){
  static int s=1;
  if (n==0)
      return s;
  else
      s=1+(x/n)*s;
      return exponential(x,n-1);    
}