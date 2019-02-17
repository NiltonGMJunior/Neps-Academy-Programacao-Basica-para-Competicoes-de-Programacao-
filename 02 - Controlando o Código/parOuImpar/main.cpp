#include <iostream>

int main()
{
    int bino, cino;
    std::cin >> bino >> cino;
    if ((bino + cino) % 2 == 0) std::cout << "Bino";
    else std::cout << "Cino";
    return 0;
}