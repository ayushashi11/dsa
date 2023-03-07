#include <cmath>
#include <stack>
#include <cstring>
#include <iostream>

char *strrev(char *str)
{
    char *p1, *p2;

    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

using namespace std;
int main()
{
    stack<int> values;
    char inp[100], last_token = '\0';
    cin.getline(inp, 100);
    strrev(inp);
    cout << inp << endl;
    for (int i = 0; i < strlen(inp); i++)
    {
        cout << inp[i] << endl;
        switch (inp[i])
        {
        case '+':
        {
            int a = values.top();
            values.pop();
            int b = values.top();
            values.pop();
            values.push(b + a);
            break;
        }
        case '-':
        {
            int a = values.top();
            values.pop();
            int b = values.top();
            values.pop();
            values.push(a-b);
            break;
        }
        case '*':
        {
            int a = values.top();
            values.pop();
            int b = values.top();
            values.pop();
            values.push(a * b);
            break;
        }
        case '/':
        {
            int a = values.top();
            values.pop();
            int b = values.top();
            values.pop();
            values.push(a/b);
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
                int c = (int)log(k);
                int t = (int)pow(10, c);
                values.push((inp[i] - '0') * t + k);
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