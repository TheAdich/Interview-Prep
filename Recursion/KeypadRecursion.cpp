#include<iostream>
#include<string>

using namespace std;

string numToLetter(int n)
{
    string letters[] = {"", "", "ABC",
                        "DEF", "GHI", "JKL",
                        "MNO", "PQRS", "TUV",
                        "WXYZ"
                       };
    return letters[n];
}

void keypad(string input, string output = "")
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    string reqStr = numToLetter(input[0] - '0');

    long int len = reqStr.length();

    for (int k = 0 ; k < len ; k++)
        keypad(input.substr(1), output + reqStr[k]);
}

int main()
{


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif

    keypad("214");
}