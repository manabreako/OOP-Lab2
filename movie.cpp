#include "Movie.h"

#include <iostream>
#include <stdexcept>

int Movie::objectCount = 0;

bool Movie::isValidTitle(const std::string& title)
{
    return !title.empty();
}

bool Movie::isValidYear(int year)
{
    return year >= 1888 && year <= 2026;
}

bool Movie::isValidRating(double rating)
{
    return rating >= 0.0 && rating <= 10.0;
}

bool Movie::isValidDuration(int duration)
{
    return duration > 0;
}

Movie::Movie()
    : title("Unknown Movie"),
      year(2026),
      rating(0.0),
      genre(Genre::Drama),
      duration(90)
{
    ++objectCount;
}

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