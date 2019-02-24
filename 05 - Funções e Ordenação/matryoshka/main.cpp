#include <iostream>

int main()
{
    // Lê a quantidade de bonecas
    unsigned long int n;
    std::cin >> n;

    // Lê os tamanhos de cada uma das bonecas
    unsigned long long int bonecas[100000];
    for (int iii = 0; iii < n; ++iii)
        std::cin >> bonecas[iii];

    // Declara um vetor com o tamanho das bonecas recolhidas e a quantidade
    unsigned long long int recolhidas[100000];
    unsigned long int quant_recolhida = 0;



    return 0;
}
