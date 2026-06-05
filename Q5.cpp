#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input5.txt", "r", stdin);
    string input;
    while (getline(cin, input))
    {
        bool isValid = true;
        if ((towlower(input[0]) >= 'a' && tolower(input[0]) <= 'h') || (towlower(input[0]) >= 'o' && tolower(input[0]) <= 'z'))
        {
            for (int i = 1; i < input.size(); i++)
            {
                if (!isalnum(input[i]))
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
                cout << input << ": " << "Float Variable" << endl;
        }
        else if (isdigit(input[0]))
        {
            int dot_pos = -1, dot_count = 0;
            for (int i = 1; i < input.size(); i++)
            {
                if (input[i] == '.')
                {
                    dot_pos = i;
                    dot_count++;
                }
                if (!isdigit(input[i]) && input[i] != '.')
                {
                    isValid = false;
                    break;
                }
            }
            if (dot_pos != -1 && dot_count == 1 && isValid)
            {
                int fraction = input.substr(dot_pos + 1).size();
                if (fraction == 2)
                    cout << input << ": " << "Float Number" << endl;
                else if (fraction >= 3)
                    cout << input << ": " << "Double Number" << endl;
                else
                    isValid = false;
            }
            else
                isValid = false;
        }
        else
            isValid = false;
        if (!isValid)
            cout << input << ": " << "Invalid" << endl;
    }
}