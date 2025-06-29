#include<iostream>

using namespace std;

/*void fun(int *A)
{
  cout<<sizeof(*A)/sizeof(int)<<endl;// it does not give the size of an array it gives the size of a pointer wich is 4 bytes 
}
int main()
{
  int A[]={2,4,6,8,10};
  int n=5;
  
  cout<<sizeof(A)/sizeof(int)<<endl;

  for(int x:A)
  cout<<x<<" "<<endl;
  fun(A);
  return 0;
}*/




/*void fun(int A[],int n) // or we can Write "void fun(int *A)"
{  
  //for(int a:A) // it's an Error
  for(int i=0;i<n;i++)
  cout<<A[i]<<endl;
}

int main()
{
  int A[]={2,4,6,8,10};
  int n=5;
  fun(A,n);

  for(int x:A)
  cout<<x<<" ";

  return 0;
}*/

// functions Return as an array


int * fun(int size)
{
  int *p;
  p = new int[size];

  for(int i=0;i<size;i++)
  p[i]=i++;

  return p;

}

int main(){
  int *ptr,sz=5;

  ptr = fun(sz);

  for(int i=0;i<sz;i++)
  cout<<ptr[i]<<endl;

  return 0;
}