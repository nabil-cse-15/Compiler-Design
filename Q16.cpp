#include <bits/stdc++.h>
using namespace std;

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '^')
        return 3;
    return 0;
}

string infixToPostfix(string infix)
{
    string postfix = "";
    stack<char> st;

    for (char ch : infix)
    {
        if (isalpha(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() && precedence(ch) <= precedence(st.top()))
            {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix: " << infixToPostfix(infix);
}