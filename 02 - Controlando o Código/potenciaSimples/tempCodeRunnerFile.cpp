#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double x, y;
    std::cin >> x >> y;

    std::cout << std::fixed << std::setprecision(4) << pow(x, y);

    return 0;
}