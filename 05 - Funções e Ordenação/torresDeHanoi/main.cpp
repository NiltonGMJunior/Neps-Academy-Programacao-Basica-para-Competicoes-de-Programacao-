#include <iostream>

int conta_hanoi(const int n)
{
    if (n == 1) return 1;

    return 1 + 2 * conta_hanoi(n - 1);
}

int main()
{
    // Declara o número de discos
    int n;

    // Declara o teste atual
    int teste = 1;

    // Laço que faz as chamadas necessárias para a realização de cada teste
    while (true)
    {
        // Lê o número de discos
        std::cin >> n;

        // Se n for 0, termina o programa
        if (n == 0) break;

        // Se não, imprime a resposta
        std::cout << "Teste " << teste << '\n';
        std::cout << conta_hanoi(n) << '\n';
        std::cout << '\n';
        ++teste;
    }

    return 0;
}
