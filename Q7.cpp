#include <bits/stdc++.h>
using namespace std;
bool is_keyword(string c)
{
    vector<string> keyword = {
        "true", "false",
        "int", "float", "double", "char", "string", "long", "unsigned", "bool",
        "main", "namespace", "void", "new", "switch",
        "for", "if", "else", "do", "while", "break", "continue",
        "and", "or", "xor"};
    for (int i = 0; i < keyword.size(); i++)
    {
        if (keyword[i].compare(c) == 0)
            return true;
    }
    return false;
}

bool is_operator(string c)
{
    vector<string> operators = {
        "+", "-", "*", "/",
        "++", "--", "=", "+=", "-=", "*=", "/=", "==",
        "!", "!=", "<", ">", "<=", ">=", "!=", ",", "::"};
    for (int i = 0; i < operators.size(); i++)
    {
        if (operators[i].compare(c) == 0)
            return true;
    }
    return false;
}

bool is_identifier(string c)
{
    if (isdigit(c[0]))
        return false;
    for (char ch : c)
    {
        if (ch != '_' && !isalnum(ch))
            return false;
    }
    return true;
}

bool is_constant(string c)
{
    int cnt = 0;
    for (char ch : c)
    {
        if (ch == '.')
            cnt++;
    }
    if (cnt > 1)
        return false;
    for (int i = 0; i < c.length(); i++)
    {
        if (!isdigit(c[i]) && c[i] != '.')
            return false;
    }
    return true;
}

int main()
{
    freopen("input07.txt", "r", stdin);
    string input;
    while (getline(cin, input))
    {
        if (is_keyword(input))
            cout << input << ": " << "keyword" << endl;
        else if (is_identifier(input))
            cout << input << ": " << "Identifier" << endl;
        else if (is_operator(input))
            cout << input << ": " << "operator" << endl;
        else if (is_constant(input))
            cout << input << ": " << "Constant" << endl;
        else
            cout << input << ": " << "Invalid" << endl;
    }
}