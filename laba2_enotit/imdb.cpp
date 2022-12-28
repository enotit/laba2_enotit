#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "imdb.h"
using namespace std;

void IMDB::setComment(string comment) { this->comment = comment; };
IMDB::IMDB(float note)
{
    this->note = note;
    this->comment = "was created";
};
