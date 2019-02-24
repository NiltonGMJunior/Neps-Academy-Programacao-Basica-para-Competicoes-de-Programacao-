#include <iostream>

bool eh_primo(int x)
{
    // Se x <= 1, retorna falso
    if (x <= 1) return false;
    // Se x for 2 ou 3, retorna verdadeiro
    if (x <= 3) return true;
    // Verifica se x é par
    if (x % 2 == 0) return false;

    // Percorre os números ímpares à partir de 3 em busca de divisores de x
    for (int div = 3; div < x; div += 2)
        if (x % div == 0) return false;

    return true;
}

int main()
{
    // Lê o número
    int x;
    std::cin >> x;

    // Verifica se o mesmo é primo, imprimindo "S". Caso contrário, imprime "N"
    if (eh_primo(x)) std::cout << "S" << '\n';
    else std::cout << "N" << '\n';

    return 0;
}
