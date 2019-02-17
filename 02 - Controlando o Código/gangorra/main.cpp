#include <iostream>

int main()
{
    int p1, c1, p2, c2;
    std::cin >> p1 >> c1 >> p2 >> c2;

    if (p1 * c1 == p2 * c2) std::cout << 0;
    else if (p1 * c1 > p2 * c2) std::cout << -1;
    else std::cout << 1;
    return 0;
}