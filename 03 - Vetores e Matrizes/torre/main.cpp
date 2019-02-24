#include <iostream>

int main()
{
    // Declara e lê a ordem da matriz de entrada
    int n;
    std::cin >> n;

    // Declara e lê a matriz de entrada representando o tabuleiro
    unsigned short tab[1000][1000];
    for (int lin = 0; lin < n; ++lin)
        for (int col = 0; col < n; ++col)
            std::cin >> tab[lin][col];

    // Declara e inicializa um vetor com a soma das linhas e outro com a soma das colunas
    int soma_lin[1000]{ 0 }, soma_col[1000]{ 0 };

    // Preenche os vetores com a soma das linhas e colunas
    for (int iii = 0; iii < n; ++iii)
        for (int jjj = 0; jjj < n; ++jjj)
        {
            soma_lin[iii] += tab[iii][jjj];
            soma_col[iii] += tab[jjj][iii];
        }

    // Define arbitrariamente o valor do íncide da maior soma como (0, 0)
    int max_lin = 0, max_col = 0;

    // Percorre cada posição do tabuleiro e verifica se a soma de linhas e colunas (excluindo a intersecção) é máxima
    for (int lin = 0; lin < n; ++lin)
        for (int col = 0; col < n; ++col)
            if (soma_lin[lin] + soma_col[col] - 2 * (tab[lin][col]) > soma_lin[max_lin] + soma_col[max_col] - 2 * (tab[max_lin][max_col]))
            {
                max_lin = lin;
                max_col = col;
            }

    // Imprime o valor alvo
    std::cout << soma_lin[max_lin] + soma_col[max_col] - 2 * (tab[max_lin][max_col]);

    return 0;
}
