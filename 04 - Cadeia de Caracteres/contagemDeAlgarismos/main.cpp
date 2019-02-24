#include <iostream>
#include <string>

int main()
{
    // Lê a quantidade de números a serem lidos
    int n;
    std::cin >> n;

    // Inicializa um vetor com a quantidade de algarismos nos números de entrada
    int algarismos[10] = { 0 };

    // Lê cada um dos números e incrementa o vetor de contagem de algarismos
    for (int _ = 0; _ < n; ++_)
    {
        // Os números são lidos como strings para que seja possível iterar ao longo dos algarismos
        std::string num;
        std::cin >> num;

        // O algarismo, na forma de um caracter, é convertido para seu valor inteiro e incrementa-se o vetor de contagem
        for (int iii = 0; iii < num.size(); ++iii)
            algarismos[num[iii] - '0']++;
    }

    // Imprime a tabela com a contagem de algarismos
    for (int iii = 0; iii < 10; ++iii)
        std::cout << iii << " - " << algarismos[iii] << "\n";

    return 0;
}
