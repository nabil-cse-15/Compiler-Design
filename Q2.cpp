#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char c)
{
    return tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u';
}

int main()
{
    string input;
    getline(cin, input);
    int vowel = 0, consonant = 0;
    vector<char> vowels, consonants;
    string word = "";
    string vowel_word = "", consonant_word = "";
    for (char c : input)
    {
        if (isalpha(c))
        {
            if (is_vowel(c))
            {
                vowel++;
                vowels.push_back(c);
            }
            else
            {
                consonant++;
                consonants.push_back(c);
            }
            word += c;
        }
        else
        {
            if (word != "")
            {
                if (is_vowel(word[0]))
                    vowel_word += word + " ";
                else
                    consonant_word += word + " ";
                word = "";
            }
        }
    }
    if (word != "")
    {
        if (is_vowel(word[0]))
            vowel_word += word + " ";
        else
            consonant_word += word + " ";
    }
    cout << "No. of vowels: " << vowel << endl;
    cout << "No. of consonants: " << consonant << endl;

    cout << endl;
    cout << "Vowels: ";
    for (char c : vowels)
    {
        cout << c << " ";
    }
    cout << endl;

    cout << "consonants: ";
    for (char c : consonants)
    {
        cout << c << " ";
    }
    cout << endl;

    cout << "Vowel string: " << vowel_word << endl;
    cout << " Consonant string: " << consonant_word << endl;
}