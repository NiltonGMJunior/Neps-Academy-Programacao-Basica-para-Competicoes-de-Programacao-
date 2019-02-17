#include <iostream>

int main()
{
    int x;
    std::cin >> x;
    
    int divX = 1;
    while(divX <= x)
    {
        if (x % divX == 0) std::cout << divX << " ";
        divX++;
    }
    return 0;
}