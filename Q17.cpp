#include <bits/stdc++.h>
using namespace std;
int precendence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

string infixTopostfix(string temp)
{
    string postfix = "";
    stack<char> st;
    for (char ch : temp)
    {
        if (isalpha(ch))
            postfix += ch;
        else if (ch == '(')
            st.push(ch);
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
            while (!st.empty() && precendence(ch) <= precendence(st.top()))
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

string solve(string infix)
{
    string temp = "", postfix = "";
    stack<string> stk;
    for (char c : infix)
    {
        if (c != ' ')
            temp += c;
        else
        {
            if (temp == "then")
            {
                temp = "";
                continue;
            }
            else if (temp == "if")
                stk.push(temp);
            else if (temp == "else")
                stk.push(temp);
            else
            {
                postfix += infixTopostfix(temp);
                while (!stk.empty() && stk.top() == "else")
                {
                    postfix += '?';
                    stk.pop();
                    stk.pop();
                }
            }
            temp = "";
        }
    }

    //for last token
    if (temp != "")
    {
        postfix += infixTopostfix(temp);
        while (!stk.empty() && stk.top() == "else")
        {
            postfix += '?';
            stk.pop();
            stk.pop();
        }
    }
    return postfix;
}


int main()
{
    string infix;
    cout << "Enter infix Statement: ";
    getline(cin, infix);
    cout << "Postfix: " << solve(infix);
}