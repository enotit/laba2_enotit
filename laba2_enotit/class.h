#ifndef CLASS_H
#define CLASS_H
#include <string>
#include <fstream>
#include "imdb.h"
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
    IMDB imdb;

public:
    /* *** Сеттеры *** */
    void setTitle(string title);
    void setDirector(string director);
    void setGenre(string genre);
    void setCompany(string company);
    void setDuration(unsigned short int duration);
    void setYear(unsigned short int year);
    void setIMBD(float imdb);
    /* *** Геттеры *** */
    string getTitle();
    string getDirector();
    string getGenre();
    string getCompany();
    unsigned short int getDuration();
    unsigned short int getYear();
    float getIMBD();
    void print_disk();
    Disk(): title(""), director(""), genre(""), duration(60), year(1929), company("Disney"), imdb() {};
    Disk(string title, string director, string genre, unsigned short int duration, unsigned short int year, string company, float note_imdb);
    ~Disk();
};

#endif