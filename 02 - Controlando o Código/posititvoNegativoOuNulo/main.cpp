#include <iostream>

int main()
{
    int x;
    std::cin >> x;
    if (x > 0) std::cout << "positivo";
    else if (x < 0) std::cout << "negativo";
    else std::cout << "nulo";
    return 0;
}