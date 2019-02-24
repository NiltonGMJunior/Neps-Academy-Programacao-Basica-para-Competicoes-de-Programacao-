#include <iostream>
#include <string>

// title() recebe uma string e retorna a string com o primeiro caracter de todas as palavras em maiúsculo
std::string title(const std::string &F)
{
    // Declara a string de saída
    // A string é inicializada como o primeiro caracter de F em maiusculo
    std::string saida = "";
    saida += std::toupper(F[0]);

    // Percorre os caracteres de F adicionando-os a string de saída
    for (int iii = 1; iii < F.size(); ++iii)
        // Se o caracter anterior for um espaço, adiciona o caracter atual como maiúsculo
        if (F[iii - 1] == ' ') saida += std::toupper(F[iii]);
        // Caso contrário, adiciona o caracter normalmente
        else saida += std::tolower(F[iii]);

    return saida;
}

int main()
{
    // Declara e lê a string inicial
    std::string F;
    std::getline(std::cin, F);

    // Imprime a string inicial com as adequações feitas pela função title
    std::cout << title(F) << '\n';

    return 0;
}
