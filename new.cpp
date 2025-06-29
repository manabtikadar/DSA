#include<iostream>

using namespace std;

int main()
{
  int x,y,hcf,lcm,i;
  cout<<"Enter The first number:";
  cin>>x;
  cout<<"Enter The first number:";
  cin>>y;
  if(x<y)
  {
    i=x;
  }
  else{
    i=y;
  }
  cout<<"i = "<<x<<endl;
  while(i>=1)
  {
    if(x%i==0 && y%i==0)
    {
      hcf = i;
      break;
    }
    i--;
  }

  lcm = (x*y)/hcf;
  cout<<"hcf = "<<hcf<<endl;
  cout<<"lcm = "<<lcm<<endl;
  return 0;
}