#include <iostream>

int main()
{
    int a, m;
    std::cin >> a >> m;
    if (a + m <= 50) std::cout << "S";
    else std::cout << "N";
    return 0;
}