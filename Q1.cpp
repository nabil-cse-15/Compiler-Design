#include <bits/stdc++.h>
using namespace std;

bool is_digit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

bool is_letter(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    {
        return true;
    }
    return false;
}

bool is_special_char(char c)
{
    string special = ";,.-:";
    for (int i = 0; i < special.size(); i++)
        if (c == special[i])
        {
            return true;
        }
    return false;
}

int main()
{
    string s;
    getline(cin, s);
    vector<char> letter, digit, other;
    int letters = 0, digits = 0, words = 0, others = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (i < n - 1 && s[i] == ' ' && s[i + 1] != ' ')
        {
            words++;
        }
        if (is_letter(s[i]))
        {
            letters++;
            letter.push_back(s[i]);
        }
        else if (is_digit(s[i]))
        {
            digits++;
            digit.push_back(s[i]);
        }
        else if (is_special_char(s[i]))
        {
            others++;
            other.push_back(s[i]);
        }
    }
    words++;
    cout << "No. of Words: " << words << endl;
    cout << "No. of letters: " << letters << endl;
    cout << "No. of digits: " << digits << endl;
    cout << "No. of others " << others << endl;
    for (int i = 0; i < letter.size(); i++)
    {
        cout << letter[i];
        if (i == letter.size() - 1)
        {
            cout << endl;
        }
        else
            cout << ',';
    }

    for (int i = 0; i < digit.size(); i++)
    {
        cout << digit[i];
        if (i == digit.size() - 1)
        {
            cout << endl;
        }
        else
            cout << ',';
    }

     for (int i = 0; i < other.size(); i++)
    {
        cout << other[i];
        if (i == other.size() - 1)
        {
            cout << endl;
        }
        else
            cout << ' ';
    }
}
