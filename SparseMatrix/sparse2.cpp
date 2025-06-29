#include<iostream>
using namespace std;

class Element
{
  public:
     int i;
     int j;
     int x;

};

/*class Sparse
{
  private:
      int m;
      int n;
      int num;
      Element *ele;
  public:
      Sparse(int m,int n, int num )
      {
        this->m=m;
        this->n=n;
        this->num=num;
        ele = new Element[this->num];
      }
      void read(){
        cout<<"Enter non-zero element"<<endl;
        for(int i=0;i<num;i++)
            cin>>ele[i].i>>ele[i].j>>ele[i].x;
      }
      void Dispaly(){
        int k=0;
        for(int i=0;i<m;i++)
        {
          for(int j=0;j<n;j++)
          {
            if(i==ele[k].i && j==ele[k].j)
            {
              cout<<ele[k++].x<<" "; 
            }
            else cout<<"0 ";
          }
          printf("\n");
        }
      }
      ~Sparse(){
        delete [] ele;
      }    
};*/
class Sparse
{
  private:
      int m;
      int n;
      int num;
      Element *ele;
  public:
      Sparse(){
        
      }
      Sparse(int m,int n, int num )
      {
        this->m=m;
        this->n=n;
        this->num=num;
        ele = new Element[this->num];
      }
      ~Sparse(){
        delete [] ele;
      }
      // operator overloding
      friend istream & operator>>(istream &is, Sparse &s);
      friend ostream & operator<<(ostream &os, Sparse &s);
      
      Sparse operator+(Sparse &s);

};  
      Sparse Sparse::operator+(Sparse &s)
      {
        int i,j,k;
        if(m!=s.m || n!=s.n)
           return Sparse();
        Sparse *sum = new Sparse(m,n,num+s.num);

        i=k=j=0;
        while(i<num && j<s.num)
        {
          if(ele[i].i<s.ele[j].i)
             sum->ele[k++]=ele[i++];
          else if(ele[i].i>s.ele[j].i)
             sum->ele[k++]=s.ele[j++];
          else
          {
            if(ele[i].j<s.ele[j].j)
             sum->ele[k++]=ele[i++];
            else if(ele[i].j>s.ele[j].j)
             sum->ele[k++]=s.ele[j++];
            else 
             sum->ele[k]=ele[i++];
             sum->ele[k++].x+=s.ele[j++].x;
          }    
        }
        for(;i<num;i++)sum->ele[k++]=ele[i];
        for(;j<num;j++)sum->ele[k++]=s.ele[j];

        sum->num=k;

        return *sum;
      }


      istream & operator>>(istream &is, Sparse &s){
        cout<<"Enter non-zero element"<<endl;
        for(int i=0;i<s.num;i++)
            cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
        return is;    
      }
      ostream & operator<<(ostream &os, Sparse &s){
        int k=0;
        for(int i=0;i<s.m;i++)
        {
          for(int j=0;j<s.n;j++)
          {
            if(i==s.ele[k].i && j==s.ele[k].j)
            {
              cout<<s.ele[k++].x<<" "; 
            }
            else cout<<"0 ";
          }
          printf("\n");
        }
        return os;
      }
        



int main(){
  Sparse s1(5,5,5);
  //cin>>s1;
  //cout<<s1;
  //s1.~Sparse();

  Sparse s2(5,5,5);
  cin>>s1;
  cin>>s2;

  Sparse sum=s1+s2;

  cout<<"first matrix"<<endl<<s1;
  cout<<"second matrix"<<endl<<s2;
  cout<<"sum Matrix"<<endl<<sum;
  return 0;
}