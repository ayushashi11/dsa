#include<iostream>
using namespace std;
namespace std{
char* &fun()
{
   static char* x; 
   return x;
}
}
int main(int argc, char** argv)
{
   cout<<"ありがとう\n";
	for(int i=0;i<100;i++){
   std::fun()=*(argv+i);
   cout<<i<<' '<<std::fun()<<endl;
	}
   cout<<"ありがとう\n";
   return 0;
}