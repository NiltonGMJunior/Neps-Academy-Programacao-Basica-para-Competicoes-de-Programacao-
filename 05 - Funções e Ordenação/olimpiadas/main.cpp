#include <iostream>
#include <algorithm>

struct Pais
{
    unsigned short int id;
    unsigned short int ouro;
    unsigned short int prata;
    unsigned short int bronze;
};

// // imprimeTabela() recebe o vetor de paises e a quantidade dos mesmos e imprime uma tabela com a quantidade de medalhas de cada tipo para cada país
// // OBS.: Essa função não é parte do desafio, foi utilizada apenas para facilitar a visualização de alguns resultados a fim de avaliar o restante do código
// void imprimeTabela(const Pais paises[], const int n)
// {
//     printf("%15s|%15s|%15s|%15s\n", "ID", "Ouro", "Prata", "Bronze");
//     for (int iii = 0; iii < n; ++iii)
//     {
//         printf("%15d|%15d|%15d|%15d\n", paises[iii].id, paises[iii].ouro, paises[iii].prata, paises[iii].bronze);
//     }
// }

// comparaPaises() é utilizada como parâmetro para a função sort da biblioteca algorithm
// São passados duas estruturas do tipo país, a função retorna true se o primeiro argumento (pais_a) é melhor classificado do que o segundo argumento (pais_b)
bool comparaPaises(const Pais &pais_a, Pais &pais_b)
{
    // Se o número de medalhas de ouro é equivalente, verifica o número de medalhas de prata para desempate
    if (pais_a.ouro == pais_b.ouro)
        // Se o número de medalhas de prata é equivalente, verifica o número de medalhas de bronze para desempate
        if (pais_a.prata == pais_b.prata)
            // Se o número de medalhas de bronze é equivalente, a maior classificação é dada ao país com o menor número de id
            if (pais_a.bronze == pais_b.bronze) return pais_a.id < pais_b.id;
            else return pais_a.bronze > pais_b.bronze;
        else return pais_a.prata > pais_b.prata;
    else return pais_a.ouro > pais_b.ouro;
}

int main()
{
    // Lê o número de países (n) e o número de modalidades esportivas (m)
    unsigned short int n, m;
    std::cin >> n >> m;

    // Cria um vetor de estruturas, cada qual armazenará a quantidade de medalhas do país i + 1, sendo i o id do país
    // Os atributos dos n países são inicializados em sequência
    Pais paises[100];
    for (int iii = 0; iii < n; ++iii)
    {
        paises[iii].id = iii + 1;
        paises[iii].ouro = 0;
        paises[iii].prata = 0;
        paises[iii].bronze = 0;
    }

    // Lê os resultades de cada modalidade, identificando que país recebeu cada medalha e incrementando a contagem de acordo
    unsigned short int ouro, prata, bronze;
    for (int iii = 0; iii < m; ++iii)
    {
        std::cin >> ouro >> prata >> bronze;
        paises[ouro - 1].ouro += 1;
        paises[prata - 1].prata += 1;
        paises[bronze - 1].bronze += 1;
    }

    // // O seguinte imprime a tabela com a quantidade de medalhas por país (apenas para efeito de verificação)
    // imprimeTabela(paises, n);

    // Ordena os países em ordem decrescente de classificação
    // std::sort(paises, paises + n, comparaPaises);
    for (int inicial = 0; inicial < n - 1; ++inicial)
    {
        int maior_indice = inicial;
        for (int atual = inicial + 1; atual < n; ++atual)
        {
            if (comparaPaises(paises[atual], paises[maior_indice]))
            {
                maior_indice = atual;
            }
        }
        Pais temp = paises[inicial];
        paises[inicial] = paises[maior_indice];
        paises[maior_indice] = temp;
    }
    
    // Imprime os ids dos países após ordenação
    for (int iii = 0; iii < n; ++iii) std::cout << paises[iii].id << " ";

    return 0;
}
