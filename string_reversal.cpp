#include <iostream>
#include <string>

using std::cout;
using std::string;

string reverseString(string input)
{
    if (input == "")
    {
        return input;
    }

    return reverseString(input.substr(1, input.size() - 1)) + input[0];
}
int main()
{
    cout << reverseString("HELLO");
}