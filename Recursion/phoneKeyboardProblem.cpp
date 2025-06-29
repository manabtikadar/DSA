#include<iostream>
#include<map>
#include<vector>

using namespace std;
void PhonekeyBoard(string digits,string output,int index,vector<string>& ans, string mapping[])
{ 
  if(index >= digits.length())
  {
    cout<<"{"<<output<<"}";
    ans.push_back(output);
    return;
  }

  int num = digits[index]-'0';
  string temp = mapping[num];

  for(int i=0; i<temp.length(); i++)
  {
    output.push_back(temp[i]);
    PhonekeyBoard(digits, output, index+1, ans, mapping);
    output.pop_back();
  }
}

using namespace std;
int main()
{
  vector<string> ans;
  string output="";
  string digits="234";
  string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  int index=0;
  if(digits.length()==0)
  {
    cout<<"not possible";
  }
  PhonekeyBoard(digits, output, index, ans, mapping);
}