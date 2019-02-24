#include <iostream>

int main()
{
    // Declara e lê a ordem da matriz de entrada
    int n;
    std::cin >> n;

    // Declara e lê a matriz de entrada representando o tabuleiro
    int tab[1000][1000];
    for (int lin = 0; lin < n; ++lin)
        for (int col = 0; col < n; ++col)
            std::cin >> tab[lin][col];

    // Declara e inicializa um vetor com a soma das linhas e outro com a soma das colunas
    int soma_lin[1000]{ 0 }, soma_col[1000]{ 0 };

    // Preenche os vetores com a soma das linhas e colunas
    for (int iii = 0; iii < n; ++iii)
        for (int jjj = 0; jjj < n; ++jjj)
        {
            soma_lin[iii] = tab[iii][jjj];
            soma_col[iii] = tab[jjj][iii];
        }

    // Define arbitrariamente o valor do íncide da menor soma como (0, 0)
    int min_lin = 0, min_col = 0;

    // Percorre cada posição do tabuleiro e verifica se a soma de linhas e colunas (excluindo a intersecção) é mínima
    for (int lin = 0; lin < n; ++lin)
        for (int col = 0; col < n; ++col)
            if (soma_lin[lin] + soma_col[col] - 2 * (tab[lin][col]) < soma_lin[min_lin] + soma_col[min_col] - 2 * (tab[min_lin][min_col]))
            {
                min_lin = lin;
                min_col = col;
            }

    // Imprime o valor alvo
    std::cout << soma_lin[min_lin] + soma_col[min_col] - 2 * (tab[min_lin][min_col]);

    return 0;
}
