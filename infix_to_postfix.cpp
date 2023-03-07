#include<stack>
#include<iostream>
#include<string>
using namespace std;
int precedence(char op){
    switch(op){
        case '+':
        case '-':
            return 4;
        case '*':
        case '/':
            return 7;
        case '^':
            return 9;
        case '(':
            return -2;
        default:
            return -300;
    }
}
int main(){
    stack<char> ops;
    string out;
    string inp;
    cout<<"enter the expression: ";
    getline(cin, inp);
    for(char c:inp){
        switch (c)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(ops.size()!=0&&precedence(ops.top())>=precedence(c)){
                out.push_back(ops.top());
                ops.pop();
            }
            ops.push(c);
            break;
        case '(':
            ops.push(c);
            break;
        case ')':
            while(ops.top()!='('){
                out.push_back(ops.top());
                ops.pop();
            }
            ops.pop();
            break;
        default:
            out.push_back(c);
            break;
        }
    }
    while(!ops.empty()){
        out.push_back(ops.top());
        ops.pop();
    }
    cout<<out<<endl;
}