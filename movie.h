#pragma once

#include <string>

enum class Genre
{
    Action,
    Comedy,
    Drama,
    Horror,
    Fantasy,
    SciFi
};

class Movie
{
private:
    std::string title;
    int year;
    double rating;
    Genre genre;
    int duration;

    static int objectCount;
};