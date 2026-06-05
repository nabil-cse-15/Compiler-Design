#include <bits/stdc++.h>
using namespace std;

vector<string> subject = {"Sagor", "Selim", "Salma", "Nipu", "He", "She", "I", "You","We", "They"};
vector<string> verb = {"read", "eat", "run", "take", "write"};
vector<string> noun = {"book", "cow", "dog", "home", "grass", "rice", "mango"};

int main()
{
    freopen("input9.txt", "r", stdin);
    string input;
    while (getline(cin, input))
    {
        string word;
        vector<string> words;

        for (char c : input)
        {
            if (c != ' ')
                word += c;
            else
            {
                words.push_back(word);
                word = "";
            }
        }
        words.push_back(word);
        bool isValid = true;
        if (words.size() > 3 || words.size() < 2)
            isValid = false;
        else
        {
            if (find(subject.begin(), subject.end(), words[0]) == subject.end())
                isValid = false;
            if (find(verb.begin(), verb.end(), words[1]) == verb.end())
                isValid = false;
            if (words.size() == 3)
            {
                if (find(noun.begin(), noun.end(), words[2]) == noun.end())
                    isValid = false;
            }
        }
        if (isValid)
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }
}

