#include<iostream>

using namespace std;

// void Swap(string *a, int i, int j)
// {
//   char b = (*a)[i];
//   (*a)[i] = (*a)[j];
//   (*a)[j] = b;

//   return;
// }

void SwapTheString(string &a, int i, int n)
{ 
  int j = n-i-1;
  if(i>j )
  {
    printf("Swap The String Successfully\n");
    return;
  }
  else
  {
    swap(a[i],a[j]);
  }
  SwapTheString(a, i+1, n);
  return;
}

void isPalindrome(string a, int i, int j)
{
  if(i>j)
  {
    printf("the stirng is palindrome!\n");
    return;
  }

  if(a[i]==a[j])
  {
    i++;
    j--;
    isPalindrome(a,i,j);
  }
  else{
    printf("the stirng is not palindrome!\n");
  }
}

int Power(int a, int b)
{
  if(b==0)
  {
    return 1;
  }
  if(b==1)
  {
    return a;
  }

  int ans = Power(a,b/2);

  if(b%2==0)
  {
    return ans*ans;
  }
  else
  {
    return a*ans*ans;
  }
}
void Print(int arr[], int n)
{
  for(int i=0; i<n; i++)
  {
    cout<<arr[i]<<" ";
  }
  return ;
}


void BubbleSortArray(int *arr, int n)
{ 
  // Print(arr,n);
  cout<<endl;
  if(n==0||n==1)
  {
    return;
  }
  
  for(int j=0;j<n;j++)
  {
    if(arr[j]>arr[j+1])
    {
      swap(arr[j],arr[j+1]);
    }
  }

  BubbleSortArray(arr, n-1);
}

void InsertionSort(int *arr, int i, int n)
{ 
  // cout<<"Intermediate Stape"<<i<<":";
  // Print(arr,n+1);
  // cout<<endl;
  int j= i-1;
  if(i>n)
  {
    return;
  }
  
  int x = arr[i];
  while(arr[j]>x && j>-1)
  {
    arr[j+1]=arr[j];
    j--;
  }
  arr[j+1]=x;
  InsertionSort(arr,i+1,n);
}

int Merge(int *arr, int s, int mid, int e)
{
  int len1, len2, m,n,k,inversionCount=0;
  len1 = mid-s+1;
  len2 = e-mid;
  m=s;
  n=mid+1;
  k=0;
  int *c = new int[len1+len2];

  while(m<=mid && n<=e)
  {
    if(arr[m]<arr[n])
    {
      c[k++]=arr[m++];
    }
    else
    {
      c[k++]=arr[n++];
      inversionCount+=mid-m+1;
    }
  }

  while(m<=mid)
  {
    c[k++]=arr[m++];
  }

  while(n<=e)
  {
    c[k++]=arr[n++];
  }

  for(int i=s;i<=e;i++)
  {
    arr[i]=c[i-s];
  }

  delete []c;
  return inversionCount;
}

int MergeSort(int *arr, int s, int e)
{ 
  if(s>=e)
  {
    return 0;
  }

  int mid = (s+e)/2;
  
  int n = MergeSort(arr, s, mid) + MergeSort(arr, mid + 1, e);
  
  n += Merge(arr,s,mid,e);
  return n;
}

int partition(int *arr, int s, int e)
{
  int pivotelement = arr[s];
  int i = s+1;
  int j = e;

  while(i<j)
  {
    while(arr[i]<=pivotelement)
    {
      i++;
    }
    while(arr[j]>pivotelement)
    {
      j--;
    }
    if(i<j)
    {swap(arr[i],arr[j]);} 
  }

  swap(arr[s],arr[j]);
  return j;
}

void QuickSort(int *arr, int s, int e)
{
  if(s>=e)
  {
    return;
  }
  Print(arr,e-s+1);
  cout<<endl;
  int pivotPosition = partition(arr,s,e);
  Print(arr,e-s+1);
  cout<<endl;
  QuickSort(arr,s,pivotPosition-1);
  QuickSort(arr,pivotPosition+1,e);
}

int main()
{
  // string a = "manab";
  // // SwapTheString(a, 0, a.length());
  // isPalindrome(a, 0, a.length()-1);
  // SwapTheString(a, 0, a.length());
  // cout<<a<<endl;

  // int a,b;
  // cin>>a>>b;
  // cout<<Power(a,b)<<endl;

  int arr[]={3,5,2,7,9,1,13,10,30,24,26,46};
  // int inversionCount=MergeSort(arr,0,11);
  QuickSort(arr,0,11);
  for(int i=0;i<=11;i++)
  {
    cout<<arr[i]<<" ";
  }cout<<endl;

  return 0;
}