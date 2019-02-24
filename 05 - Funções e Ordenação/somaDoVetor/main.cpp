#include <iostream>

// soma_vetor() recebe o comprimento de um vetor e um ponteiro para o mesmo e retorna a soma de seus elementos
int soma_vetor(const unsigned long int n, const long int v[])
{
    // A função será implementada iterativamente
    int soma = 0;
    for (int iii = 0; iii < n; ++iii)
    {
        soma += v[iii];
    }

    return soma;
}

int main()
{
    // Lê o comprimento do vector
    unsigned long int n;
    std::cin >> n;

    // Popula o vector
    long int v[100000];
    for (int iii = 0; iii < n; ++iii)
    {
        std::cin >> v[iii];
    }

    // Imprime a soma dos elementos
    std::cout << soma_vetor(n, v) << '\n';

    return 0;
}
