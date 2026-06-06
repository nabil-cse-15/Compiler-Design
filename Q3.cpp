#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("data.txt");

    if (!fin)
    {
        cout << "Cannot open data.txt" << endl;
        return 0;
    }

    map<string, string> department;
    map<char, string> year;
    map<char, string> semester;
    map<char, string> subject;
    map<char, string> type;

    string category, key;

    while (fin >> category >> key)
    {
        string value;
        getline(fin, value);

        if (!value.empty() && value[0] == ' ')
            value.erase(0, 1);

        if (category == "DEPT")
            department[key] = value;
        else if (category == "YEAR")
            year[key[0]] = value;  // key is string thats why key[0] = '1'
        else if (category == "SEM")
            semester[key[0]] = value;
        else if (category == "SUB")
            subject[key[0]] = value;
        else if (category == "COURSE")
            type[key[0]] = value;
    }

    fin.close();

    string code;
    cout << "Enter Course Code: ";
    cin >> code;

    string dept = code.substr(0, 3);

    cout << department[dept] << ", "
         << year[code[4]] << " Year, "
         << semester[code[5]] << ", "
         << subject[code[6]] << ", "
         << type[code[7]] << endl;

    return 0;
}

