#include <iostream>
#include <string.h>
using namespace std;

bool checkPalindrome(string word)
{
    int start = 0;
    int end = word.length() - 1;
    while (start < end)
    {
        if (word[start] != word[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    string input;
    cout << "Enter string : ";
    cin >> input;
    int n = input.length();

    string temp = "";
    for (int i = 0; i < input.length(); i++)
    {
        string sub = input.substr(i, n - i);
        if (checkPalindrome(sub))
        {
            // if the string is a palidrome at this point, we need to append the reverse of previous substr to this string
            input += temp;
            break;
        }
        temp = input[i] + temp; // reverse
    }

    // output final palindromic work

    cout << "Palindromic string is " << (input) << endl;
    return 0;
}
