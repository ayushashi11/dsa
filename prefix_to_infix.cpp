#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    stack<string> vals;
    string inp, out;
    cout << "enter the expression: ";
    getline(cin, inp);
    reverse(inp.begin(), inp.end());
    for (char ch : inp)
    {
        switch (ch)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        {
            string o = ")", a = vals.top();
            vals.pop();
            o += vals.top();
            vals.pop();
            o.push_back(ch);
            o += a;
            o.push_back('(');
            vals.push(o);
            break;
        }

        default:
        {
            string o = "";
            o.push_back(ch);
            vals.push(o);
        }
        break;
        }
    }
    string k = vals.top();
    reverse(k.begin(), k.end());
    cout << k << endl;
}