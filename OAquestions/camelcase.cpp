#include <bits/stdc++.h>

using namespace std;

bool checkCamelCase(vector<string>& words, string complexWord)
{
  unordered_set<string> wordSet(words.begin(),words.end());

  int n=complexWord.size();
  int start=0;
  
  vector<string> parts;
  for(int i=1; i<n; i++)
  {
    if(isupper(complexWord[i]))
    {
      string part=complexWord.substr(start,i-start);
      transform(part.begin(),part.end(),part.begin(),::tolower);
      parts.push_back(part);
      start=i;
    }
  }
  
  string part = complexWord.substr(start,n-start);
  transform(part.begin(), part.end(), part.begin(), ::tolower);
  parts.push_back(part);


  for(auto it:parts)
  {
    if(wordSet.find(it)==wordSet.end())
    {
      return false;
    }
  }

  return true;
}

int main()
{
  vector<string> words = {"camel", "case", "example", "test"};
  string complexWord = "CamelCaseExample";

  if(checkCamelCase(words, complexWord))
  {
    cout << "The complex word is valid in camel case." << endl;
  }
  else
  {
    cout << "The complex word is not valid in camel case." << endl;
  }

  return 0;
}