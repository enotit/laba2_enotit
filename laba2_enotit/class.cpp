#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Disk
{
private:
    string title;
    string director;
    string genre;
    unsigned short int duration;
    unsigned short int year;
    string company;
    float imdb;

public:
    /* *** Сеттеры *** */
    void setTitle(string title)
    {
        this->title = title;
    };
    void setDirector(string director)
    {
        this->director = director;
    };
    void setGenre(string genre)
    {
        this->genre = genre;
    };
    void setCompany(string company)
    {
        this->company = company;
    };
    void setDuration(unsigned short int duration)
    {
        this->duration = duration;
    };
    void setYear(unsigned short int year)
    {
        this->year = year;
    };
    void setIMBD(float imdb)
    {
        this->imdb = imdb;
    };
    /* *** Геттеры *** */
    string getTitle()
    {
        return this->title;
    };
    string getDirector()
    {
        return this->director;
    };
    string getGenre()
    {
        return this->genre;
    };
    string getCompany()
    {
        return this->company;
    };
    unsigned short int getDuration()
    {
        return this->duration;
    };
    unsigned short int getYear()
    {
        return this->year;
    };
    float getIMBD()
    {
        return this->imdb;
    };
};