#include <iostream>

int main()
{
    int tab[50];
    int minas[50];

    int n;
    std::cin >> n;

    for (int iii = 0; iii < n; ++iii)
    {
        std::cin >> tab[iii];
    }

    if (n == 1) std::cout << tab[0];
    else if (n == 2) std::cout << tab[0] + tab[1] << "\n" << tab[0] + tab[1];
    else
    {
        minas[0] = tab[0] + tab[1];
        minas[n - 1] = tab[n - 2] + tab[n - 1]; 

        for (int iii = 1; iii < n - 1; ++iii)
        {
            minas[iii] = tab[iii - 1] + tab[iii] + tab[iii + 1];
        }

        for (int iii = 0; iii < n; ++iii)
        {
            std::cout << minas[iii] << "\n";
        }
    }
    return 0;
}