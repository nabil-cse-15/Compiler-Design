#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input4.txt", "r", stdin);
    string input;
    while (getline(cin, input))
    {
        bool isValid = true;

        if (tolower(input[0]) >= 'i' && tolower(input[0]) <= 'n')
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
                cout << input << ": " << "Integer" << endl;
        }

        else if (input[0] >= '1' && input[0] <= '9')
        {
            for (int i = 1; i < input.size(); i++)
            {
                if (!isdigit(input[i]))
                {
                    isValid = false;
                    break;
                }
            }
            if (isValid)
            {
                if (input.size() < 5)
                    cout << input << ": " << "ShortInt" << endl;
                else
                    cout << input << ": " << "LongInt" << endl;
            }
        }
        else {
           cout<<input<<": "<<"Invalid"<<endl;
        }
       
    }
    
}