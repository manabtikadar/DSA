#include<iostream>
#include<vector>

using namespace std;

void permutationString(string a, int index, vector<string>& ans, int length)
{
  if(index>=length)
  {
    cout<<"{"<<a<<"}";
    ans.push_back(a);
    return;
  }

  for(int j=index; j<length; j++)
  {
    swap(a[index],a[j]);
    permutationString(a,index+1,ans,length);
    //backtracking
    swap(a[index],a[j]);
  }

}

int main()
{
  vector<string> ans;
  string output;
  string a ="abcd";
  int index=0;
  int length=a.length();
  permutationString(a,index,ans,length);
  return 0;
}