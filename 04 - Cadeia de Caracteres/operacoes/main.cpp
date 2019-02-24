#include <iostream>
#include <iomanip>

int main()
{
    // Lê o caracter que representa a operação aritmética a ser efetuada
    char op;
    std::cin >> op;

    // Lê os dois números reais sobre os quais a operação será efetuada
    double num1, num2;
    std::cin >> num1 >> num2;

    // Imprime a saída
    switch (op)
    {
        case 'M':
            std::cout << std::fixed << std::setprecision(2) << num1 * num2;
            break;
        case 'D':
            std::cout << std::fixed << std::setprecision(2) << static_cast<double> (num1) / num2;
            break;
    }

    return 0;
}
