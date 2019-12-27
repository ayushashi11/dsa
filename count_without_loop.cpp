#include<iostream>
using namespace std;
class A
{
public:
    static int a;
    A()
    {  cout<<a++<<endl;  }
};
int A::a = 1;
int main()
{
    int N = 10;
    A obj[N];
    return 0;
}