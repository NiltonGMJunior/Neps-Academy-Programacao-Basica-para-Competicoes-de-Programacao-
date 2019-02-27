#include <iostream>
#include <algorithm>

struct Piloto
{
    unsigned short int id;
    unsigned short int posicoes[100];
    unsigned short int pontos[100] { 0 };
}

int main()
{
    // Declara o número de Grandes Premios - g - e o número de pilotos - p
    unsigned short int g, p;

    // Percorre o loop até que p e g sejam ambos 0
    while (true)
    {
        // Lê o número de Grandes Premios - g - e o número de pilotos - p
        std::cin >> g >> p;

        // Condição de quebra de loop
        if (g == 0 && p == 0) break;

        // Declara um vetor de estruturas do tipo Piloto e preenche as p primeiras ids
        Piloto pilotos[100];
        for (int iii = 0; iii < p; ++iii)
        {
            pilotos[iii].id = iii + 1;
        }

        // Para cada um dos Grandes Prêmios, define a posição em que cada piloto terminou
        unsigned short int posicao;
        // Primeiro laço percorrerá os GPs
        for (int iii = 0; iii < g; ++iii)
        {
            // Segundo laço percorrerá os pilotos
            for (int jjj = 0; jjj < p; ++jjj)
            {
                std::cin >> (pilotos[jjj].posicoes)[iii];
            }
        }

        // Declara e lê a quantidade de sistemas de pontuação a serem avaliados
        unsigned short int s;
        std::cin >> s;

        // Para cada um dos sistemas, gera uma saída com o(s) vencedor(es) do campeonato
        // Caso haja mais de um vencedor, a saída será ordenada em ordem crescente do número de cada piloto ganhador
        
        // Declara o número de posições pontuadas num determinado sistema de pontuação
        unsigned short int k;

        // Declara um vetor contendo os pontos para cada posição i + 1, em que i é o índice do vetor
        unsigned short int pontuacao[100];
        
        // Percorre os sistemas produzindo as saídas apropriadas
        for (int iii = 0; iii < s; ++iii)
        {
            // Lê o número de posições em que há pontuação
            std::cin >> k;

            // Percorre o vetor de pontuação até o índice k, redefinindo a pontuação da posição correspondente
            for (int jjj = 0; jjj < k; ++jjj)
            {
                std::cin >> pontuacao[jjj];
            }

            // Percorre o vetor de pilotos, para cada GP, definindo a pontuação para o sistema de pontos atual
            // Percorrendo os pilotos
            for (int jjj = 0; jjj < p; ++jjj)
            {
                // Percorrendo os GPs
                for (int kkk = 0; kkk < g)
                {
                    // Verifica se o piloto pontuou
                    if ((pilotos[jjj].posicoes)[kkk] <= k)
                    {
                        (pilotos[jjj].pontos)[iii] += pontuacao[(pilotos[jjj].posicoes)[kkk] - 1];
                    }
                }
            }

            // Copia o veor de pilotos para outro vetor a ser ordenado de acordo com pontuacao
            Piloto pilotos_ordenado = pilotos;

            // Ordena o vetor de piltos ordenados de acordo com a pontuacao e id
            
        }
    }

    return 0;
}