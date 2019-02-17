#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int day = 1;
    int count = 0;
    int sum = 0;
    while (day <= n)
    {
        int a;
        std::cin >> a;
        sum += a;
        ++count;
        if (sum >= 1000000) break;
        ++day;
    }
    std::cout << count;
    return 0;
}