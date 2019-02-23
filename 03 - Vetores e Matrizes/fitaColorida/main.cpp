#include <iostream>

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
