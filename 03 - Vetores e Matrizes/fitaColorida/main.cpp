#include <iostream>

int main()
{
    // Lê o comprimento da fita
    int n;
    std::cin >> n;

    // Como 3 <= n <= 10000, declara uma fita com 10000 elementos (o código, entretanto, só irá iterar por n elementos)
    int fita[10000];

    // Lê os valores iniciais da fita
    for (int iii = 0; iii < n; ++iii)
    {
        std::cin >> fita[iii];
    }

    // Define um índice para o último zero à esquerda e direita da posição atual na fita, incialmente -1 pois nenhum zero foi detectado
    int ind_zero_esq = -1;
    int ind_zero_dir = -1;
    
    // Itera por todos os elementos da fita para redefinar seus valores de acordo com a distância ao zero mais próximo
    for (int iii = 0; iii < n; ++iii)
    {
        // Caso o valor da fita seja zero, o índice do zero à esquerda será redefinido pelo índice atual e perde-se a referência ao próximo zero à direita
        if (fita[iii] == 0)
        {
            ind_zero_esq = iii;
            ind_zero_dir = -1;
        }
        // Caso contrário, o valor será redefinido
        else
        {
            // São definidas as distâncias em relação ao zero da esquerda e direita inicializadas no pior caso possível
            int dist_esq = 9, dist_dir = 9;

            // Verifica se há algum zero encontrado à esquerda
            if (ind_zero_esq != -1)
            {
                // Redefine a distância à esquerda
                dist_esq = iii - ind_zero_esq;
            }
            // Verifica se há algum zero encontrado à esquerda
            if (ind_zero_dir != -1)
            {
                // Redefine a distância à direita
                dist_dir = ind_zero_dir - iii;
            }
            // Caso contrário
            else
            {
                // Busca pelo próximo zero à direita
                int jjj = iii + 1;
                while (fita[jjj] != 0 && jjj < n) ++jjj;
                // Se há zero à direita, redefine o índice de zero à direita e a distância
                if (jjj < n)
                {
                    ind_zero_dir = jjj;
                    dist_dir = ind_zero_dir;
                }
            }

            // Define o valor da fita como o mínimo entre as distâncias à esquerda, direita e 9
            if (dist_esq <= dist_dir && dist_esq < 9) fita[iii] = dist_esq;
            else if (dist_dir < dist_esq && dist_dir < 9) fita[iii] = dist_dir;
            else fita[iii] = 9;
        }
    }

    // Imprime os valores da fita
    for (int iii = 0; iii < n; ++iii) std::cout << fita[iii] << " ";

    return 0;
}

/*
// O seguinte código funcionou para os 03 test-cases da página do problema mas não passou nos testes após submissão
int main()
{
    // Lê o comprimento da fita
    int n;
    std::cin >> n;

    // Como 3 <= n <= 10000, declara uma fita com 10000 elementos (o código, entretanto, só irá iterar por n elementos)
    int fita[10000];

    // Inicializa o índice do primerio zero encontrado como -1
    int ind_primeiro_zero = -1;

    // Lê os valores iniciais da fita e define o índice do primeiro zero
    for (int iii = 0; iii < n; ++iii)
    {
        std::cin >> fita[iii];
        if (fita[iii] == 0 && ind_primeiro_zero == -1) ind_primeiro_zero = iii;
    }

    // Itera por todos os elementos da fita para redefinar seus valores de acordo com a distância ao zero mais próximo
    for (int iii = 0; iii < n; ++iii)
    {
        // Caso o valor da fita não seja 0 (isto é, foi inicializado como -1 durante a leitura)
        if (fita[iii] != 0)
        {
            // Verifica se o valor foi encontrado antes do primeiro zero, estando à esquerda do mesmo, nesse caso, o primeiro zero é o zero mais próximo
            if (iii < ind_primeiro_zero)
            {
                fita[iii] = ind_primeiro_zero - iii;
            }
            // Caso contrário, isto é, já houve ao meos um zero antes do valor, verifica se há outros zeros depois ou não
            else
            {
                // Inicializa o índice do segundo zero como -1
                int ind_segundo_zero = -1;
                // jjj é o índice inicial da busca, começando por iii
                int jjj = iii + 1;
                // O seguinte laço verifica se há algum zero após o número, parando caso o zero seja encontrado ou caso o final da fita seja encontrado
                while (jjj < n && ind_segundo_zero == -1)
                {
                    // Se algum zero for encontrado, o índice do segundo zero é redefinido
                    if (fita[jjj] == 0) ind_segundo_zero = jjj;
                    ++jjj;
                }
                // Caso nenhum zero tenha sido encontrado à direita do número, a comparação é feita com o índice do primeiro zero
                if (ind_segundo_zero == -1) fita[iii] = iii - ind_primeiro_zero;
                // Caso algum zero tenha sido encontrado à direita, comparam-se as distâncias do índice aos índices do primeiro e segundo zero, escolhendo o mínimo entre a menor destas distâncias e 9
                else
                {
                    int dist_primeiro_zero = iii - ind_primeiro_zero;
                    int dist_segundo_zero = ind_segundo_zero - iii;
                    if (dist_primeiro_zero <= dist_segundo_zero && dist_primeiro_zero < 9)
                    {
                        fita[iii] = dist_primeiro_zero;
                    }
                    else if (dist_primeiro_zero > dist_segundo_zero && dist_segundo_zero < 9)
                    {
                        fita[iii] = dist_segundo_zero;
                    }
                    else
                    {
                        fita[iii] = 9;
                    }
                }
            }
        }
        // Caso o valor da fita seja zero, o zero à esquerda dos próximos índices é redefinido pelo índice atual
        else
        {
            ind_primeiro_zero = iii;
        }
    }

    // Imprime os valores da fita
    for (int iii = 0; iii < n; ++iii) std::cout << fita[iii] << " ";

    return 0;
}
*/
