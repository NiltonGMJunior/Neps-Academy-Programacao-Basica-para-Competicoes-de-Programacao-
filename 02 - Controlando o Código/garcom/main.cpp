#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int cont = 1;
    int coposQuebrados = 0;
    while (cont <= n)
    {
        int l, c;
        std::cin >> l >> c;
        if (l > c) coposQuebrados += c;
        ++cont;
    }

    std::cout << coposQuebrados;

    return 0;
}