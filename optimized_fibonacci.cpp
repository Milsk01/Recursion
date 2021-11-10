#include <iostream>

using std::cout;
using std::endl;

int fib(int n)
{

    int a = 0;
    int b = 1;
    int c;

    if (n <= 0)
    {
        return -1;
    }

    if (n == 1)
    {
        return 1;
    }

    while (n > 1)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }

    return c;
}

int main()
{
    cout << fib(9);
}