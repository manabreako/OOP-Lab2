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

public:
    Movie();

    Movie(const std::string& title, int year, double rating,
          Genre genre, int duration);

    Movie(const Movie& other);

    ~Movie();

    std::string getTitle() const;
    int getYear() const;
    double getRating() const;
    Genre getGenre() const;
    int getDuration() const;

    static int getObjectCount();

    bool changeTitle(const std::string& newTitle);
    bool changeRating(double newRating);
    bool changeDuration(int newDuration);
};