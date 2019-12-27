#include<vector>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    pair<int,int> p0=pair<int,int>(1,2),p1=pair<int,int>(1,2);
    cout<<p0.first<<endl;
    cout<<(p0==p1)<<endl;
    return 0;
}
