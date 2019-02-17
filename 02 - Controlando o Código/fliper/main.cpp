#include <iostream>

int main()
{
    int pFlipper, rFlipper;
    std::cin >> pFlipper >> rFlipper;
    if (pFlipper == 0) std::cout << "C";
    else if (rFlipper == 0) std::cout << "B";
    else std::cout << "A";
    return 0;
}