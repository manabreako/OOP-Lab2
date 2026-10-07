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

    std::cout << "\n=== КОРРЕКТНЫЕ ОПЕРАЦИИ ===\n\n";

    movie1.changeTitle("Начало");
    movie1.changeRating(8.8);
    movie1.changeDuration(148);

    std::cout << "После изменения фильма 1:\n";
    movie1.printInfo();

    std::cout << "\n=== НЕКОРРЕКТНЫЕ ОПЕРАЦИИ ===\n\n";

    if (!movie1.changeTitle(""))
    {
        std::cout << "Ошибка: нельзя установить пустое название.\n";
    }

    if (!movie1.changeRating(15.0))
    {
        std::cout << "Ошибка: рейтинг не может быть больше 10.\n";
    }

    if (!movie1.changeRating(-2.0))
    {
        std::cout << "Ошибка: рейтинг не может быть отрицательным.\n";
    }

    if (!movie1.changeDuration(0))
    {
        std::cout << "Ошибка: продолжительность должна быть больше 0.\n";
    }

    std::cout << "\n=== СОСТОЯНИЕ ПОСЛЕ НЕКОРРЕКТНЫХ ОПЕРАЦИЙ ===\n\n";

    movie1.printInfo();

    std::cout << "\n=== ПРОВЕРКА НЕЗАВИСИМОСТИ ОБЪЕКТОВ ===\n\n";

    std::cout << "Фильм 2 до изменения:\n";
    movie2.printInfo();

    std::cout << "\nИзменяем только фильм 2...\n\n";

    movie2.changeTitle("Интерстеллар: Новая версия");
    movie2.changeRating(9.0);

    std::cout << "Фильм 2 после изменения:\n";
    movie2.printInfo();

    std::cout << "\nФильм 3 после изменения фильма 2:\n";
    movie3.printInfo();

    std::cout << "\n=== ПРОВЕРКА КОНСТРУКТОРА КОПИРОВАНИЯ ===\n\n";

    std::cout << "Фильм 2 и фильм 3 были созданы как отдельные объекты.\n";
    std::cout << "Изменение фильма 2 не изменило фильм 3.\n";

    std::cout << "\n=== КОНЕЦ ПРОГРАММЫ ===\n";

    std::cout << "Количество объектов перед завершением main(): "
              << Movie::getObjectCount() << '\n';

    return 0;
}