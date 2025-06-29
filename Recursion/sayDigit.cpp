#include<iostream>

using namespace std;

void sayDigit(int number, string arr[10])
{
  if (number == 0)
  {
    return;
  }
  sayDigit(number/10, arr);
  cout<<arr[number%10]<<" ";
}


int main()
{
  int number;
  cout<<"number :";
  cin>>number;

  string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  sayDigit(number, arr);

  return 0;
}