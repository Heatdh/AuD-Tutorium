#include <iostream>
using namespace std;

void edit(int  num)
{
  num=5;
}
int main()
{
  int num=0;
  cout<<"before edit num:"<<num << '\n';
  edit(num);
  cout<<"num:cle"<<num;
  return 0;
}