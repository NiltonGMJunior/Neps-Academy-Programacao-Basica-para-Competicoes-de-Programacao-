#include <iostream>

int fib(const int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;

    return fib(n - 1) + fib(n - 2); 
}

int main()
{
    // Lê o valor de n
    unsigned short int n;
    std::cin >> n;

    // Imprime o valor de fib(n)
    std::cout << fib(n) << '\n';

    return 0;
}
