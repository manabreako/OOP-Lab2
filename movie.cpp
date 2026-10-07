/**
 * @file Movie.cpp
 * @brief Реализация класса Movie.
 *
 * Содержит реализацию конструкторов, деструктора,
 * методов чтения и изменения состояния объекта,
 * проверок корректности данных и вывода информации о фильме.
 *
 * @author Куртнебиев Р.Р.
 * @date 05.10.2026
 */
#include "Movie.h"
#include <iostream>
#include <stdexcept>

/**
 * @brief Инициализация статического счётчика объектов.
 *
 * Изначально объектов класса Movie не существует.
 */
int Movie::objectCount = 0;

/**
 * @brief Проверяет корректность названия фильма.
 *
 * @param title Название фильма.
 * @return true, если название не пустое, иначе false.
 */
bool Movie::isValidTitle(const std::string& title)
{
    return !title.empty();
}

/**
 * @brief Проверяет корректность года выпуска.
 *
 * Допустимый диапазон года находится от 1888 до 2026.
 *
 * @param year Год выпуска фильма.
 * @return true, если год корректный, иначе false.
 */
bool Movie::isValidYear(int year)
{
    return year >= 1888 && year <= 2026;
}

/**
 * @brief Проверяет корректность рейтинга фильма.
 *
 * Рейтинг должен находиться в диапазоне от 0 до 10.
 *
 * @param rating Рейтинг фильма.
 * @return true, если рейтинг корректный, иначе false.
 */
bool Movie::isValidRating(double rating)
{
    return rating >= 0.0 && rating <= 10.0;
}

/**
 * @brief Проверяет корректность продолжительности фильма.
 *
 * Продолжительность должна быть больше нуля.
 *
 * @param duration Продолжительность фильма в минутах.
 * @return true, если продолжительность корректная, иначе false.
 */
bool Movie::isValidDuration(int duration)
{
    return duration > 0;
}

/**
 * @brief Конструктор по умолчанию.
 * Список инициализации используется для установки стандартных значений.
 * Создаёт объект Movie со стандартными значениями:
 * название "Unknown Movie", год 2026, рейтинг 0,
 * жанр Drama и продолжительность 90 минут.
 */
Movie::Movie()
    : title("Unknown Movie"),
      year(2026),
      rating(0.0),
      genre(Genre::Drama),
      duration(90)
{
    ++objectCount;
}

/**
 * @brief Параметризованный конструктор.
 *
 * Создаёт фильм с указанными характеристиками.
 * Перед созданием объекта выполняется проверка всех переданных данных.
 *
 * @param title Название фильма.
 * @param year Год выпуска фильма.
 * @param rating Рейтинг фильма.
 * @param genre Жанр фильма.
 * @param duration Продолжительность фильма в минутах.
 *
 * @exception std::invalid_argument Выбрасывается при передаче некорректных данных.
 */
Movie::Movie(const std::string& title, int year, double rating,
             Genre genre, int duration)
    : title(title),
      year(year),
      rating(rating),
      genre(genre),
      duration(duration)
{
    if (!isValidTitle(title))
    {
        throw std::invalid_argument("Название фильма не может быть пустым.");
    }

    if (!isValidYear(year))
    {
        throw std::invalid_argument("Некорректный год выпуска.");
    }

    if (!isValidRating(rating))
    {
        throw std::invalid_argument("Рейтинг должен находиться от 0 до 10.");
    }

    if (!isValidDuration(duration))
    {
        throw std::invalid_argument("Продолжительность должна быть больше 0.");
    }

    ++objectCount;
}

/**
 * @brief Конструктор копирования.
 *
 * Создаёт новый объект Movie, копируя данные из другого объекта.
 *
 * @param other Объект Movie, данные которого копируются.
 */
Movie::Movie(const Movie& other)
    : title(other.title),
      year(other.year),
      rating(other.rating),
      genre(other.genre),
      duration(other.duration)
{
    ++objectCount;
}

/**
 * @brief Деструктор класса Movie.
 *
 * Уменьшает количество существующих объектов на единицу.
 */
Movie::~Movie()
{
    --objectCount;
    std::cout << "Объект удалён." << " Осталось объектов: " << objectCount << '\n';
}

/**
 * @brief Возвращает название фильма.
 *
 * @return Название фильма.
 */
std::string Movie::getTitle() const
{
    return title;
}

/**
 * @brief Возвращает год выпуска фильма.
 *
 * @return Год выпуска фильма.
 */
int Movie::getYear() const
{
    return year;
}

/**
 * @brief Возвращает рейтинг фильма.
 *
 * @return Рейтинг фильма.
 */
double Movie::getRating() const
{
    return rating;
}

/**
 * @brief Возвращает жанр фильма.
 *
 * @return Жанр фильма.
 */
Genre Movie::getGenre() const
{
    return genre;
}

/**
 * @brief Возвращает продолжительность фильма.
 *
 * @return Продолжительность фильма в минутах.
 */
int Movie::getDuration() const
{
    return duration;
}

/**
 * @brief Возвращает количество существующих объектов Movie.
 *
 * @return Количество существующих объектов класса Movie.
 */
int Movie::getObjectCount()
{
    return objectCount;
}

/**
 * @brief Изменяет название фильма.
 *
 * Перед изменением выполняется проверка нового названия.
 * Если название пустое, изменение не выполняется.
 *
 * @param newTitle Новое название фильма.
 * @return true, если название изменено, иначе false.
 */
bool Movie::changeTitle(const std::string& newTitle)
{
    if (!isValidTitle(newTitle))
    {
        return false;
    }

    title = newTitle;
    return true;
}

/**
 * @brief Изменяет рейтинг фильма.
 *
 * Перед изменением выполняется проверка рейтинга.
 *
 * @param newRating Новый рейтинг фильма.
 * @return true, если рейтинг изменён, иначе false.
 */
bool Movie::changeRating(double newRating)
{
    if (!isValidRating(newRating))
    {
        return false;
    }

    rating = newRating;
    return true;
}

/**
 * @brief Изменяет продолжительность фильма.
 *
 * Перед изменением выполняется проверка продолжительности.
 *
 * @param newDuration Новая продолжительность фильма в минутах.
 * @return true, если продолжительность изменена, иначе false.
 */
bool Movie::changeDuration(int newDuration)
{
    if (!isValidDuration(newDuration))
    {
        return false;
    }

    duration = newDuration;
    return true;
}

/**
 * @brief Преобразует жанр фильма в строку.
 *
 * Используется для удобного отображения жанра при выводе информации.
 *
 * @param genre Жанр фильма.
 * @return Название жанра в виде строки.
 */
static std::string genreToString(Genre genre)
{
    switch (genre)
    {
    case Genre::Action:
        return "Боевик";

    case Genre::Comedy:
        return "Комедия";

    case Genre::Drama:
        return "Драма";

    case Genre::Horror:
        return "Ужасы";

    case Genre::Fantasy:
        return "Фэнтези";

    case Genre::SciFi:
        return "Фантастика";

    default:
        return "Неизвестно";
    }
}

/**
 * @brief Выводит полную информацию о фильме.
 *
 * Выводит название, год выпуска, рейтинг, жанр
 * и продолжительность фильма.
 */
void Movie::printInfo() const
{
    std::cout << "Название: " << title << '\n';
    std::cout << "Год выпуска: " << year << '\n';
    std::cout << "Рейтинг: " << rating << '\n';
    std::cout << "Жанр: " << genreToString(genre) << '\n';
    std::cout << "Продолжительность: " << duration << " мин.\n";
}