#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int cont = 1;
    int valorAtual;
    std::cin >> valorAtual;
    int maiorCadeia = 1;
    int cadeiaAtual = 1;

    while (cont < n)
    {
        int valor;
        std::cin >> valor;
        if (valor == valorAtual)
        {
            cadeiaAtual++;
            if (cadeiaAtual > maiorCadeia) maiorCadeia = cadeiaAtual;
        }
        else
        {
            valorAtual = valor;
            cadeiaAtual = 1;
        }
        ++cont;
    }

    std::cout << maiorCadeia;

    return 0;
}