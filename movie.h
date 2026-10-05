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

    static bool isValidTitle(const std::string& title);
    static bool isValidYear(int year);
    static bool isValidRating(double rating);
    static bool isValidDuration(int duration);
};