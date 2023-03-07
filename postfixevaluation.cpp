#include <stack>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    stack<int> values;
    char inp[100], last_token = '\0';
    cin.getline(inp, 100);
    cout << inp << endl;
    for (int i = 0; i < strlen(inp); i++)
    {
        cout << inp[i] << endl;
        switch (inp[i])
        {
        case '+':
        {
            int b = values.top();
            values.pop();
            int a = values.top();
            values.pop();
            values.push(a + b);
            break;
        }
        case '-':
        {
            int b = values.top();
            values.pop();
            int a = values.top();
            values.pop();
            values.push(a - b);
            break;
        }
        case '*':
        {
            int b = values.top();
            values.pop();
            int a = values.top();
            values.pop();
            values.push(a * b);
            break;
        }
        case '/':
        {
            int b = values.top();
            values.pop();
            int a = values.top();
            values.pop();
            values.push(a / b);
            break;
        }
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            switch (last_token)
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                int k = values.top();
                values.pop();
                values.push(k * 10 + (inp[i] - '0'));
                break;
            }
            default:
                values.push(inp[i] - '0');
            }
            break;
        }
        last_token = inp[i];
    }
    cout << values.top() << endl;
}