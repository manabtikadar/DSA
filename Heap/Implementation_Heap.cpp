#include<bits/stdc++.h>
using namespace std;

class Heap {
public:
   int arr[100];
   int size=0;

   Heap()
   {
      arr[0]=-1;
      size=0;
   }

   void insert(int value)
   {
      size=size+1;
      int index = size;
      arr[index]=value;

      while(index>1)
      {
          int parent = index/2;
          if(arr[parent]<arr[index])
          {
              swap(arr[parent],arr[index]);
              index = parent;
          }
          else
          {
              return;
          }
      }
   }

   void print()
   {
      for(int i=1; i<=size; i++)
      {
          cout << arr[i] << " ";
      }cout << endl;
   }

   void deletefromHeap()
   {
      if(size==0)
      {
        cout << "heap is empty , so nothing to delete" << endl;
        return;
      }
        
      // step 1: put last element at the root
      arr[1]=arr[size];

      // step 2: delete last element
      size--;
      
      // step 3: heapify the root node
      int index = 1;
      while(index<size)
      {
          int LeftIndex = 2*index;
          int RightIndex = 2*index + 1;

          int largest = index;

          if(LeftIndex<=size && arr[largest]<arr[LeftIndex])
          {
              largest = LeftIndex;
          }

          if(RightIndex<=size && arr[largest]<arr[RightIndex])
          {
              largest = RightIndex;
          }

          if(largest != index)
          {
            swap(arr[largest],arr[index]);
            index = largest;
          }
          else
          {
            return;
          }
      }
   }
}; 

void heapify(int arr[], int n, int i)
{
    int left = 2*i;
    int right = 2*i + 1;
    int largest = i;

    if(left<=n && arr[largest]<arr[left])
    {
      largest = left;
    }

    if(right<=n && arr[largest]<arr[right])
    {
      largest = right;
    }

    if(largest != i)
    {
      swap(arr[largest],arr[i]);
      heapify(arr,n,largest);
    }
    else
    {
      return;
    }
}

void heapSort(int arr[], int n)
{
  int size = n;

  while(size>1)
  {
    swap(arr[size],arr[1]);
    size--;

    heapify(arr,size,1);
  }
}

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
 
    h.deletefromHeap();
    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    // heap Creation
    int n = 5;
    for(int i=n/2; i>0; i--)
    {
        heapify(arr,n,i);
    }

    cout << "printing the array after heapify: " << endl;
    for(int i=1; i<=n; i++)
    {
        cout << arr[i] << " ";
    } 
    cout << endl;

    // heap sort
    heapSort(arr,n);
    cout << "printing the array after heap sort: " << endl;
    for(int i=1; i<=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}