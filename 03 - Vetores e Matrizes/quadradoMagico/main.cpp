#include <iostream>

int main()
{
    // Lê a ordem da matriz
    int n;
    std::cin >> n;

    // Declara uma matriz de inteiros 10x10 (máximo n é 10)
    int mat[10][10];

    // Preenche a matriz
    for (int lin = 0; lin < n; ++lin)
        for (int col = 0; col < n; ++col)
            std::cin >> mat[lin][col];

    // Verifica a soma da diagonal principal e secundária
    int diag_pri = 0;
    int diag_sec = 0;
    for (int iii = 0; iii < n; ++iii)
    {
        diag_pri += mat[iii][iii];
        diag_sec += mat[iii][n - 1 - iii];
    }

    // Verifica se a soma das diagonais é igual
    if (diag_pri != diag_sec) std::cout << -1;
    else
    {
        // Cria a condição que indica a validade do quadrado mágico
        bool cond = true;
        // Verifica se a soma das linhas e colunas é igual a soma das diagonais
        for (int iii = 0; iii < n; ++iii)
        {
            int linha = 0, coluna = 0;
            for (int jjj = 0; jjj < n; ++jjj)
            {
                linha += mat[iii][jjj];
                coluna += mat[jjj][iii];
            }
            // Verifica se o valor da soma da linha ou da coluna é diferente das diagonais
            if (linha != diag_pri || coluna != diag_pri)
            {
                 std::cout << -1;
                 cond = false;
                 break;
            }
        }
        // Caso a condição de validade não tenha sido violada, imprime a soma
        if (cond) std::cout << diag_pri;
    }

    return 0;
}
