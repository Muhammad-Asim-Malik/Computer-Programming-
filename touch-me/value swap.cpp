#include <iostream>
using namespace std;
int main()
{
  int a=1,b=2,c;

  cout<<"Before value swap : \n";
  cout<<"a : "<<a<<endl;
  cout<<"a : "<<b<<endl;
  
  // building logic //
  c=a;
  a=b;
  b=c;

  cout<<"After value swap : \n";
  cout<<"a : "<<a<<endl;
  cout<<"b : "<<b;

  return 0;
}
