#ifndef IMDB_H
#define IMDB_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class IMDB
{
public:
    float note;
    void setComment(string comment);
    IMDB() : note(0.0f), comment(""){};
    IMDB(float nt) : note(nt), comment(""){};

private:
    string comment;
};
#endif