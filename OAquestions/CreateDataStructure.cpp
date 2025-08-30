#include<bits/stdc++.h>
using namespace std;

class CustomDataStructure
{
  private:
      map<int,int> mpp;
      int keyOffSet;
      int valueOffSet;
  public:
      CustomDataStructure(){
        keyOffSet=0;
        valueOffSet=0;
      }

      void insert(int key, int value)
      {
        mpp[key-keyOffSet]=value-valueOffSet;
      }

      int get(int key)
      {
        if (mpp.find(key - keyOffSet) == mpp.end())
            return -1; 
        return mpp[key-keyOffSet]+valueOffSet;
      }

      void addTokey(int x)
      {
        keyOffSet+=x;
      }

      int addToValue(int y)
      {
        valueOffSet+=y;
      }
};

int main()
{
  CustomDataStructure ds;
  ds.insert(1, 100);
  ds.insert(2, 200);
  cout << ds.get(1) << endl;  // Output: 100
  cout << ds.get(2) << endl;  // Output: 200
  ds.addTokey(5);
  ds.addToValue(10);
  cout << ds.get(6) << endl;  // Output: 110
  cout << ds.get(7) << endl;  // Output: 210
  return 0;
}