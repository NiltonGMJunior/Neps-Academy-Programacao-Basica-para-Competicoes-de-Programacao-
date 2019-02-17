#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    int n;
    std::cin >> n;

    int cont = 0;

    while (cont < n)
    {
        double x;
        std::cin >> x;
        std::cout << std::fixed << std::setprecision(4) << pow(x, 0.5) << "\n";
        ++cont;
    }
    return 0;
}