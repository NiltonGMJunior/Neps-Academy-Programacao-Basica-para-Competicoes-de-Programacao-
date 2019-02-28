#include <iostream>
#include <algorithm>

struct Piloto
{
    unsigned short int id;
    unsigned short int posicoes[100];
    unsigned short int pontos[100] { 0 };
};

// comparaPilotos() recebe duas estruturas representando pilotos: piloto_a e piloto_b. Se o piloto_a for melhor classificado num sistema de pontos s, então retorna true. Retorna false caso contrário
// No caso de empate de pontos, retorna true se a id do piloto_a for menor que a do piloto_b e false caso contrário
bool comparaPilotos(const Piloto &piloto_a, const Piloto &piloto_b, const unsigned short int s)
{
    if (piloto_a.pontos[s] == piloto_b.pontos[s]) return piloto_a.id < piloto_b.id;
    else return piloto_a.pontos[s] > piloto_b.pontos[s];
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
                for (int kkk = 0; kkk < g; ++kkk)
                {
                    // Verifica se o piloto pontuou
                    if ((pilotos[jjj].posicoes)[kkk] <= k)
                    {
                        (pilotos[jjj].pontos)[iii] += pontuacao[(pilotos[jjj].posicoes)[kkk] - 1];
                    }
                }
            }

            // Copia o veor de pilotos para outro vetor a ser ordenado de acordo com pontuação
            Piloto pilotos_ordenado[100];
            std::copy(pilotos, pilotos + p, pilotos_ordenado);

            // Ordena o vetor de piltos ordenados de acordo com a pontuacao e id
            // Selection-Sort
            for (int inicial = 0; inicial < p - 1; ++inicial)
            {
                int melhor_piloto = inicial;
                for (int atual = inicial + 1; atual < p; ++atual)
                {
                    if (comparaPilotos(pilotos_ordenado[atual], pilotos_ordenado[melhor_piloto], iii))
                    {
                        melhor_piloto = atual;
                    }
                }
                Piloto temp = pilotos_ordenado[inicial];
                pilotos_ordenado[inicial] = pilotos_ordenado[melhor_piloto];
                pilotos_ordenado[melhor_piloto] = temp;
            }

            // Avalia a pontuação do vencedor no sistema de pontos atual
            unsigned short int pontos_vencedor = (pilotos_ordenado[0]).pontos[iii];

            // Imprime a id do vencedor e dos demais pilotos com a mesma pontuação, no caso de empate no primeiro lugar
            unsigned short int jjj = 0;
            do {
                std::cout << (pilotos_ordenado[jjj]).id << ' ';
                ++jjj;
            } while((pilotos_ordenado[jjj]).pontos[iii] == pontos_vencedor);
            std::cout << '\n';
        }
    }

    return 0;
}
