#include "person.h"

using namespace std;

person::person()
{
  cout << "Person created!" << endl;
}

void person::Crawl(){
  cout<<"Crawling"<<endl;
}

void person::Run(){
  cout<<"Running"<<endl;
}

void person::Stand(){
  cout<<"Standing"<<endl;
}

void person::walk(){
  cout<<"Walking"<<endl;
}