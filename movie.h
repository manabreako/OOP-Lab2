/**
 * @file Movie.h
 * @brief Объявление класса Movie.
 *
 * Содержит описание класса Movie, его полей,
 * конструкторов, методов чтения и изменения состояния,
 * а также перечисления Genre.
 *
 * @author Куртнебиев Р.Р.
 * @date 05.10.2026
 */
#pragma once
#include <string>

/**
 * @brief Перечисление жанров фильма.
 *
 * Содержит набор допустимых жанров, которые может иметь фильм.
 */
enum class Genre
{
    Action, ///< Боевик
    Comedy, ///< Комедия
    Drama,  ///< Драма
    Horror, ///< Ужасы
    Fantasy, ///< Фэнтези
    SciFi   ///< Фантастика
};

/**
 * @class Movie
 * @brief Класс, описывающий фильм.
 *
 * Класс хранит основную информацию о фильме:
 * название, год выпуска, рейтинг, жанр и продолжительность.
 *
 * Класс обеспечивает проверку корректности данных и не позволяет
 * установить недопустимые значения для основных характеристик фильма.
 *
 * Также класс содержит статический счётчик количества существующих объектов.
 *
 * @warning Название фильма не может быть пустым.
 * @warning Рейтинг должен находиться в диапазоне от 0 до 10.
 * @warning Продолжительность должна быть больше 0.
 */
class Movie
{
private:

    std::string title; ///< Название фильма.
    int year;          ///< Год выпуска фильма.
    double rating;     ///< Рейтинг фильма от 0 до 10.
    Genre genre;       ///< Жанр фильма.
    int duration;      ///< Продолжительность фильма в минутах.

    static int objectCount; ///< Количество существующих объектов класса Movie.

    /**
     * @brief Проверяет корректность названия фильма.
     *
     * @param title Название фильма.
     * @return true, если название не пустое, иначе false.
     */
    static bool isValidTitle(const std::string& title);

    /**
     * @brief Проверяет корректность года выпуска фильма.
     *
     * @param year Год выпуска фильма.
     * @return true, если год находится в допустимом диапазоне, иначе false.
     */
    static bool isValidYear(int year);

    /**
     * @brief Проверяет корректность рейтинга фильма.
     *
     * @param rating Рейтинг фильма.
     * @return true, если рейтинг находится от 0 до 10, иначе false.
     */
    static bool isValidRating(double rating);

    /**
     * @brief Проверяет корректность продолжительности фильма.
     *
     * @param duration Продолжительность фильма в минутах.
     * @return true, если продолжительность больше 0, иначе false.
     */
    static bool isValidDuration(int duration);

public:

    /**
     * @brief Конструктор по умолчанию.
     *
     * Создаёт фильм со стандартными значениями.
     */
    Movie();

    /**
     * @brief Параметризованный конструктор.
     *
     * Создаёт фильм с заданными характеристиками.
     *
     * @param title Название фильма.
     * @param year Год выпуска фильма.
     * @param rating Рейтинг фильма.
     * @param genre Жанр фильма.
     * @param duration Продолжительность фильма в минутах.
     *
     * @exception std::invalid_argument Если переданы некорректные данные.
     */
    Movie(const std::string& title, int year, double rating,
          Genre genre, int duration);

    /**
     * @brief Конструктор копирования.
     *
     * Создаёт новый объект фильма с данными другого объекта.
     *
     * @param other Объект Movie, данные которого копируются.
     */
    Movie(const Movie& other);

    /**
     * @brief Деструктор.
     *
     * Уменьшает количество существующих объектов класса Movie.
     */
    ~Movie();

    /**
     * @brief Возвращает название фильма.
     *
     * @return Название фильма.
     */
    std::string getTitle() const;

    /**
     * @brief Возвращает год выпуска фильма.
     *
     * @return Год выпуска фильма.
     */
    int getYear() const;

    /**
     * @brief Возвращает рейтинг фильма.
     *
     * @return Рейтинг фильма.
     */
    double getRating() const;

    /**
     * @brief Возвращает жанр фильма.
     *
     * @return Жанр фильма.
     */
    Genre getGenre() const;

    /**
     * @brief Возвращает продолжительность фильма.
     *
     * @return Продолжительность фильма в минутах.
     */
    int getDuration() const;

    /**
     * @brief Возвращает количество существующих объектов Movie.
     *
     * @return Количество существующих объектов.
     */
    static int getObjectCount();

    /**
     * @brief Изменяет название фильма.
     *
     * @param newTitle Новое название фильма.
     * @return true, если название успешно изменено, иначе false.
     */
    bool changeTitle(const std::string& newTitle);

    /**
     * @brief Изменяет рейтинг фильма.
     *
     * @param newRating Новый рейтинг фильма.
     * @return true, если рейтинг успешно изменён, иначе false.
     */
    bool changeRating(double newRating);

    /**
     * @brief Изменяет продолжительность фильма.
     *
     * @param newDuration Новая продолжительность в минутах.
     * @return true, если продолжительность успешно изменена, иначе false.
     */
    bool changeDuration(int newDuration);

    /**
     * @brief Выводит информацию о фильме.
     *
     * Выводит название, год выпуска, рейтинг, жанр
     * и продолжительность фильма.
     */
    void printInfo() const;
};