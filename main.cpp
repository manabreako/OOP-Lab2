#include <iostream>
#include <iomanip>
#include <string>

#include "Movie.h"

int main()
{
    std::cout << std::fixed << std::setprecision(1);

    std::cout << "=== СОЗДАНИЕ ОБЪЕКТОВ ===\n\n";

    Movie movie1;

    Movie movie2(
        "Интерстеллар",
        2014,
        8.7,
        Genre::SciFi,
        169
    );

    Movie movie3(movie2);

    std::cout << "Количество существующих объектов: "
              << Movie::getObjectCount() << "\n\n";

    std::cout << "=== НАЧАЛЬНОЕ СОСТОЯНИЕ ===\n\n";

    std::cout << "Фильм 1:\n";
    movie1.printInfo();

    std::cout << "\nФильм 2:\n";
    movie2.printInfo();

    std::cout << "\nФильм 3:\n";
    movie3.printInfo();

    return 0;
}