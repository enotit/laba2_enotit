#include <iostream>
#include <string>
#include <fstream>
#include "class.h"
#include "imdb.h"

using namespace std;


/* *** Сеттеры *** */

void Disk::setTitle(string title)
{
    this->title = title;
};
void Disk::setDirector(string director)
{
    this->director = director;
};
void Disk::setGenre(string genre)
{
    this->genre = genre;
};
void Disk::setCompany(string company)
{
    this->company = company;
};
void Disk::setDuration(unsigned short int duration)
{
    this->duration = duration;
};
void Disk::setYear(unsigned short int year)
{
    this->year = year;
};
void Disk::setIMBD(float imdb)
{
    this->imdb.note = imdb;
};
/* *** Геттеры *** */
string Disk::getTitle()
{
    return this->title;
};
string Disk::getDirector()
{
    return this->director;
};
string Disk::getGenre()
{
    return this->genre;
};
string Disk::getCompany()
{
    return this->company;
};
unsigned short int Disk::getDuration()
{
    return this->duration;
};
unsigned short int Disk::getYear()
{
    return this->year;
};
float Disk::getIMBD()
{
    return this->imdb.note;
};
void Disk::print_disk()
{
    cout << "Фильм: '" << this->title << "'\n";
    cout << "Режиссёр: '" << this->director << "'\n";
    cout << "Жанр: '" << this->genre << "'\n";
    cout << "Длительность(мин): '" << this->duration << "'\n";
    cout << "Год выпуска: '" << this->year << "'\n";
    cout << "Компания: '" << this->company << "'\n";
    cout << "Оценка: '" << this->imdb.note << "'\n";
    cout << "=========================\n";
};
Disk::Disk(string title, string director, string genre, unsigned short int duration, unsigned short int year, string company, float note_imdb)
{
    this->title = title;
    this->director = director;
    this->genre = genre;
    this->duration = duration;
    this->year = year;
    this->company = company;
    this->imdb;
    this->imdb.note = note_imdb;
};
Disk::~Disk()
{
    //cout << "Фильм: \"" << this->title << "\" был удалён.\n";
}


void Disk::read_file(ifstream &file)
{
	string temp;
	getline(file, temp);
	this->setTitle(temp);
	getline(file, temp);
	this->setDirector(temp);
	getline(file, temp);
	this->setGenre(temp);
	getline(file, temp);
	this->setDuration(stoi(temp));
	getline(file, temp);
	this->setYear(stoi(temp));
	getline(file, temp);
	this->setCompany(temp);
	getline(file, temp);
	this->setIMBD(::atof(temp.c_str()));
	this->print_disk();
};

bool Disk::operator==(const Disk & another){
    return this->company.compare(another.company) && 
           this->title.compare(another.title) && 
           this->director.compare(another.director) && 
           this->genre.compare(another.genre) && 
           this->duration == another.duration &&
           this->year == another.year &&
           this->imdb.note == another.imdb.note;
};

bool Disk::operator!=(const Disk & another)
{
	return !operator==(another);
};

void Disk::Write(ostream & file) const
{
	file << "Фильм: '" << this->title << "'\n"
    << "Режиссёр: '" << this->director << "'\n"
    << "Жанр: '" << this->genre << "'\n"
    << "Длительность(мин): '" << this->duration << "'\n"
    << "Год выпуска: '" << this->year << "'\n"
    << "Компания: '" << this->company << "'\n"
    << "Оценка: '" << this->imdb.note << "'\n"
    << "=========================\n";
}

// Оператор записи в поток.
ostream& operator<<(ostream & stream, const Disk & disk)
{
	disk.Write(stream);
	return stream;
}
istream& operator>>(ifstream & stream, Disk & disk)
{
	disk.read_file(stream);
	return stream;
}