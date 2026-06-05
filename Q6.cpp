#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input06.txt","r",stdin);
    string input;
    while (getline(cin, input))
    {
        bool isValid = true;
        if (input.size() >= 4 && (input.substr(0, 3) == "ch_" || input.substr(0, 3) == "bn_") && isalnum(input[3]))
        {
            for (int i = 4; i < input.size(); i++)
            {
                if (!isalnum(input[i]))
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
            {
                if (input.substr(0, 3) == "ch_")
                    cout << input << ": " << "Character Variable" << endl;
                else
                    cout << input << ": " << "Binary Variable" << endl;
            }
        }
        else if (input[0] == '0' && (input[1] == '0' || input[1] == '1'))
        {
            for (int i = 2; i < input.size(); i++)
            {
                if (input[i] != '0' && input[i] != '1')
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
                cout << input << ": " << "Binary Number" << endl;
        }
        else
            isValid = false;
            if(!isValid)cout<<input<<": "<<"Invalid"<<endl;
    }
}