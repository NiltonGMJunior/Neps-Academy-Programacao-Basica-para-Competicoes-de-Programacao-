#include <iostream>

int main()
{
    // Lê o maior número representável (valor entre 1 e 5e5)
    unsigned long int n;
    std::cin >> n;

    // Lê dois valores inteiro (entre 0 e 1e3) e um caracter representando a operação
    unsigned short int p, q;
    char op;
    std::cin >> p;
    std::cin >> op;
    std::cin >> q;

    // A operação pode ser de soma ou multiplicação e o resultado é declarado
    unsigned long int res_soma = p + q;
    unsigned long int res_mult = p * q;

    // Se for soma
    if (op == '+')
    {
        // Verifica se o resultado da soma é menor ou igual à n
        if (res_soma <= n) std::cout << "OK" << '\n';
        else std::cout << "OVERFLOW" << '\n';
    }
    // Se for multiplicação
    else if (op == '*')
    {
        // Verifica se o resultado da multiplicação é menor ou igual à n
        if (res_mult <= n) std::cout << "OK" << '\n';
        else std::cout << "OVERFLOW" << '\n';
    }
    else std::cout << "ERROR" << '\n';

    return 0;
}
