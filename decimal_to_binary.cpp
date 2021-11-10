#include <iostream>

using namespace std;

string baseConversion(int input)
{

    string output;
    if (input != 0)
    {
        output = baseConversion(input / 2) + (char)(input % 2 + '0');
    }

    return output;
}
int main()
{
    cout << baseConversion(8);
}