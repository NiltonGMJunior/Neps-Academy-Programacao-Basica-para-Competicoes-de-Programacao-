#include <iostream>
#include <string>

int main()
{
    // Lê o comprimento das strings de entrada
    unsigned short int n;
    std::cin >> n;

    // Lê o gabarito da prova e, em seguida as respostas do candidato
    std::string gabarito, respostas;
    std::cin >> gabarito;
    std::cin >> respostas;

    // Conta o número de acertos
    unsigned short int acertos = 0;
    for (int iii = 0; iii < n; ++iii)
        if (gabarito[iii] == respostas[iii]) ++acertos;

    // Imprime o número de acertos
    std::cout << acertos;

    return 0;
}
