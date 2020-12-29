#include<iostream>
#include<string>

using namespace std;

string swapIndices(string str, int a, int b)
{
    char temp = str[b];
    str[b] = str[a];
    str[a] = temp;

    return str;
}

void permutation(string input, string output = "")
{
    if(input.length() <= 0)
    {
        cout<<output<<endl;
        return;
    }

    long int len = input.length();

    for(int k = 0 ; k < len ; k++)
    {
        permutation(swapIndices(input,0,k).substr(1),output+input[k]);
    }
}

int main()
{
    permutation("abc");
}