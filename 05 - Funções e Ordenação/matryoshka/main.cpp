#include <iostream>
#include <algorithm>

int main()
{
    // Lê a quantidade de bonecas
    unsigned long int n;
    std::cin >> n;

    // Lê os tamanhos de cada uma das bonecas
    // São criados dois vetores, o desordenado e o ordenado
    // Eles serão comparadas para saber quantas trocas foram efetuadas
    unsigned long long int desordenado[100000], ordenado[100000];
    for (int iii = 0; iii < n; ++iii)
    {
        std::cin >> desordenado[iii];
        ordenado[iii] = desordenado[iii];
    }

    // Ordena o vetor ordenado, par aque o mesmo contenha as bonecas na ordem de tamanho crescente
    std::sort(ordenado, ordenado + n);

    // Declara um vetor com o tamanho das bonecas trocadas e a quantidade
    unsigned long long int trocadas[100000];
    unsigned long int quant_trocadas = 0;

    // Percorre o vetor ordenado e o compara com o desordenado para verificar quais bonecas foram trocadas
    for (int iii = 0; iii < n; ++iii)
    {
        // Caso em que a boneca foi trocada
        if (ordenado[iii] != desordenado[iii])
        {
            // Adiciona a boneca trocada ao vetor de trocadas e aumenta a quantidade de bonecas trocadas
            trocadas[quant_trocadas] = ordenado[iii];
            quant_trocadas += 1;
            // NOTA: Nessa implementação, ao se adicionar a boneca do vetor ordenado, o vetor de trocadas, por consequência, também saíra ordenado
        }
    }

    // Imprime a quantidade de bonecas trocadas e o vetor com o tamanho das mesmas ordenado
    std::cout << quant_trocadas << "\n";
    for (int iii = 0; iii < quant_trocadas; ++iii)
        std::cout << trocadas[iii] << " ";

    return 0;
}
