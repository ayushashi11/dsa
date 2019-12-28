#include<stack>
#include<iostream>
using namespace std;
stack<int> st;
int main(){
    cout<<"hello\n";
    for(int i=0;i<5;i++){
        st.push(i);
    }
    cout<<(st.top()+2);
    return 0;
}