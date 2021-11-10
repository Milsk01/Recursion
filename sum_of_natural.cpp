#include <iostream>

using std::cout;

int recursiveSummation(int inputNumber)
{
    if (inputNumber == 1)
    {
        return 1;
    }

    return inputNumber + recursiveSummation(inputNumber - 1);
}

int main()
{
    cout << recursiveSummation(5);
}
