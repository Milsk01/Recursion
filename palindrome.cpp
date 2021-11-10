#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool isPalindrome(string input)
{
    cout << input << endl;
    if (input.size() == 0 || input.size() == 1)
    {
        return true;
    }

    if (input.front() == input.back())
    {
        isPalindrome(string(input.begin() + 1, input.end() - 1));
        return true;
    }

    return false;
}
int main()
{
    string input = "madam";
    cout << isPalindrome(input);
}