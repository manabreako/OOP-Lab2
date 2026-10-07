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