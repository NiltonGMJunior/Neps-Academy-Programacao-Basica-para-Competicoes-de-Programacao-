#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int cont = 0;
    int contI1 = 0;
    int contI2 = 0;

    while (cont < n)
    {
        int lamp;
        std::cin >> lamp;
        if (lamp == 2) ++contI2;
        ++contI1;
        ++cont; 
    }
    std::cout << contI1 % 2 << "\n"; 
    std::cout << contI2 % 2;

    return 0;
}