#include <bits/stdc++.h>
using namespace std;
vector<string> keyword = {
    "true", "false",
    "or", "and", "xor",
    "for", "if", "else", "do", "while", "break", "continue", "switch",
    "char", "int", "string", "float", "double", "bool", "long", "unsigned", "void", "auto", "new",
    "namespace", "const", "class", "sizeof", "typedef", "main",
    "delete", "nullptr"};

vector<string> arithmetic_operator = {"+", "-", "*", "/", "%"};
vector<string> relational_operator = {"==", "!=", "<", ">", "<=", ">="};
vector<string> logical_operator = {"&&", "||", "!"};
vector<string> bitwise_operator = {"&", "|", "^", "~", "<<", ">>"};
vector<string> increment_decrement_operator = {"++", "--"};
vector<string> assignment_operator = {"=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>="};

int main()
{
    freopen("input8.txt", "r", stdin);
    string input;
    while (getline(cin, input))
    {
        bool isValid = true;
        if (find(keyword.begin(), keyword.end(), input) != keyword.end())
        {
            cout << input << ": " << "Keyword" << endl;
        }
        else if (find(arithmetic_operator.begin(), arithmetic_operator.end(), input) != arithmetic_operator.end())
        {
            cout << input << ": " << "Arithmetic operator" << endl;
        }
        else if (find(relational_operator.begin(), relational_operator.end(), input) != relational_operator.end())
        {
            cout << input << ": " << "Relational operator" << endl;
        }
        else if (find(logical_operator.begin(), logical_operator.end(), input) != logical_operator.end())
        {
            cout << input << ": " << "Logical operator" << endl;
        }
        else if (find(bitwise_operator.begin(), bitwise_operator.end(), input) != bitwise_operator.end())
        {
            cout << input << ": " << "Bitwise operator" << endl;
        }
        else if (find(assignment_operator.begin(), assignment_operator.end(), input) != assignment_operator.end())
        {
            cout << input << ": " << "Assignment operator" << endl;
        }
        else if (find(increment_decrement_operator.begin(), increment_decrement_operator.end(), input) != increment_decrement_operator.end())
        {
            cout << input << ": " << "Increment_decrement_operator" << endl;
        }

        // identifier
        else if (input[0] == '_' || isalpha(input[0]))
        {
            for (int i = 1; i < input.length(); i++)
            {
                if (input[i] != '_' && !isalnum(input[i]))
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
                cout << input << ": " << "Identifier" << endl;
        }

        // Integer
        else if (input[0] == '.' || isdigit(input[0]))
        {
            int dotcount = 0;
            for (char c : input)
            {
                if (!isdigit(c) && c != '.')
                {
                    isValid = false;
                    break;
                }
                if (c == '.')
                    dotcount++;
            }
            if (isValid && dotcount == 0)
                cout << input << ": " << "Integer" << endl;
           else if (isValid && dotcount == 1)
                cout << input << ": " << "Float" << endl;
            else
                isValid = false;
        }
        else
        {
            isValid = false;
        }
        if (!isValid)
            cout << input << ": " << "Invalid" << endl;
    }
}