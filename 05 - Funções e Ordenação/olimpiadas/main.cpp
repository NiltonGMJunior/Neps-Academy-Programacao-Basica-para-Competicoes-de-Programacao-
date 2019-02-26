#include <iostream>

struct Pais
{
    unsigned short int ouro;
    unsigned short int prata;
    unsigned short int bronze;
}

int main()
{
    // Lê o número de países (n) e o número de modalidades esportivas (m)
    unsigned short int n, m;
    std::cin >> n, m;

    // Cria um vetor de estruturas, cada qual armazenará a quantidade de medalhas do país i + 1, sendo i o índice da estrutura correspondente ao país
    Pais paises[100] { 0, 0, 0 };

    // Para cada uma das m modalidades, identifica quem ganhou ouro, prata e bronze, modificando o valor da estrutura do país correspondente
    // Além disso, guarda o índice dos países com maior número de medalhas de ouro, prata e bronze, e verifica se houve empate em qualquer uma dessas medalhas
    unsigned short int ind_ouro = 0, ind_prata = 0, ind_bronze = 0;
    bool empate_ouro = false, empate_prata = false, empate_bronze = false;

    unsigned short int ouro, prata, bronze;
    for (int iii = 0; iii < m; ++iii)
    {
        std::cin >> ouro >> prata >> bronze;

        paises[ouro - 1].ouro += 1;
        if (paises[ouro - 1].ouro == paises[ind_ouro].ouro) empate_ouro = true;
        else if (paises[ouro - 1].ouro > paises[ind_ouro].ouro)
        {
            empate_ouro = false;
            ind_ouro = ouro - 1;
        }

        paises[prata - 1].prata += 1;
        if (paises[prata - 1].prata == paises[ind_prata].prata) empate_prata = true;
        else if (paises[prata - 1].prata > paises[ind_prata].prata)
        {
            empate_prata = false;
            ind_prata = prata - 1;
        }

        paises[bronze - 1].bronze += 1;
        if (paises[bronze - 1].bronze == paises[ind_bronze].bronze) empate_bronze = true;
        else if (paises[bronze - 1].bronze > paises[ind_bronze].bronze)
        {
            empate_bronze = false;
            ind_bronze = bronze - 1;
        }
    }

    // Verifica a ordem 

    return 0;
}