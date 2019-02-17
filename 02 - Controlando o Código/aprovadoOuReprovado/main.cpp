#include <iostream>

int main()
{
    double grade1, grade2;
    std::cin >> grade1 >> grade2;

    double avg = (grade1 + grade2) / 2.0;

    if (avg >= 7.0) std::cout << "Aprovado";
    else if (avg >= 4.0) std::cout << "Recuperacao";
    else std::cout << "Reprovado";

    return 0;
}