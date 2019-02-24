#include <iostream>
#include <string>

bool verificaVogal(const char caracter)
{
    if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u')
        return true;
    return false;
}

int main()
{
    // Lê a string de entrada
    std::string risada;
    std::cin >> risada;

    // Cria a string de vogais da risada em ordem natural (esq. -> dir.) e inversa (dir. -> esq.)
    std::string risada_natural = "";
    std::string risada_inversa = "";
    for (int iii = 0; iii < risada.size(); ++iii)
    {
        if (verificaVogal(risada[iii])) risada_natural += risada[iii];
        if (verificaVogal(risada[risada.size() - 1 - iii])) risada_inversa += risada[risada.size() - 1 - iii];
    }

    // Verifica se as strings na ordem natural e inversa são equivalentes
    bool stringsIguais = true;
    for (int iii = 0; iii < risada_natural.size(); ++iii)
        if (risada_natural[iii] != risada_inversa[iii])
        {
            stringsIguais = false;
            break;
        }

    if (stringsIguais) std::cout << "S" << '\n';
    else std::cout << "N" << '\n';

    return 0;
}
