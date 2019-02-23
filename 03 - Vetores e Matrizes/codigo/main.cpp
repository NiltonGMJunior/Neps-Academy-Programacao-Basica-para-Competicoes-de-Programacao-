#include <iostream>

int main()
{
    unsigned int n;
    std::cin >> n;

    char estado = 0x0; // cria um byte de estados, com 8 bits em 0
    int cont = 0;

    for (int iii = 0; iii < n; ++iii)
    {
        int num;
        std::cin >> num;
        if (estado == 0x2)
        {
            if (num == 0)
            {
                cont++;
                estado = 0x0;
            }
            else estado = 0x1;
        }
        else if (estado == 0x1)
        {
            if (num == 0) estado = 0x2;
        }
        else if (estado == 0x0)
        {
            if (num == 1) estado = 0x1;
        }
    }

    std::cout << cont;

    return 0;
}
