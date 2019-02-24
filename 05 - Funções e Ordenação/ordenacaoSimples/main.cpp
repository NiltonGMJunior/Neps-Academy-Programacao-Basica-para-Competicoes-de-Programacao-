#include <iostream>
#include <algorithm>

int main()
{
    // Declara o comprimento do vetor de entrada
    unsigned long int n;
    std::cin >> n;

    // Declara e preenche o vetor de entrada
    long long int a[100000];
    for (int iii = 0; iii < n; ++iii)
        std::cin >> a[iii];

    std::sort(a, a + n);
    // O algoritmo de Buble-Sort a seguir não obteve desempenho satisfatório
    // // Bubble-Sort para o vetor inicial
    // for (int iii = 0; iii < n - 1; ++iii)
    // {
    //     bool ordenado = true;
    //     for (int jjj = 0; jjj < n - 1 - iii; ++jjj)
    //     {
    //         if (a[jjj] > a[jjj + 1])
    //         {
    //             ordenado = false;
    //             int temp = a[jjj];
    //             a[jjj] = a[jjj + 1];
    //             a[jjj + 1] = temp;
    //         }
    //     }
    //     // Caso nenhuma alteração tenha sido feita, saí do loop
    //     if (ordenado) break;
    // }

    // O algoritmo de Selection-Sort a seguir não obteve desempenho satisfatório
    // // Selection-Sort do vetor inicial
    // for (int inicial = 0; inicial < n - 1; ++inicial)
    // {
    //     int indice_menor = inicial;
    //     for (int atual = inicial + 1; atual < n; ++atual)
    //     {
    //         if (a[atual] < a[indice_menor]) indice_menor = atual;
    //     }
    //     int temp = a[inicial];
    //     a[inicial] = a[indice_menor];
    //     a[indice_menor] = temp;
    // }

    // Imprime o vetor ordenado
    for (int iii = 0; iii < n; ++iii) std::cout << a[iii] << " ";

    return 0;
}
