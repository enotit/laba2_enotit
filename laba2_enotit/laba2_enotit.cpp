
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <locale>

using namespace std;

struct Disk {
	string title;
	string director;
	string genre;
	unsigned short int duration;
	unsigned short int year;
	string company;
	float imdb;
};

Disk *disks;

Disk read_file(ifstream &file)
{
	Disk disk;
	getline(file, disk.title);
	getline(file, disk.director);
	getline(file, disk.genre);
	file >> disk.duration;
	file >> disk.year;
	getline(file, disk.company);
	file >> disk.imdb;
	return disk;
};


void print_film(Disk disk) {
	cout << "\n Название: ";
};
int main()
{
	setlocale(LC_ALL, "rus");
	ifstream infile;
	infile.open("text.txt");

	int count;
	infile >> count;
	std::cout << count;
	disks = new Disk[count];

	for (int i = 0; i < count; i++)
		disks[i] = read_file(infile);
	infile.close();



	string director;
	std::cin >> director;
	int m_year = INT_MAX;
	Disk result;
	for (int i = 0; i < count; i++) {
		if (disks[i].year < m_year && director == disks[i].director) {
			result = disks[i];
			m_year = result.year;
		}
	}
	std::cout << result.title << std::endl;

	string genre;
	std::cin >> genre;

	for (int i = 0; i < count; i++) {
		if (disks[i].imdb >= 8.0 && genre == disks[i].genre) {
			std::cout << disks[i].title << std::endl;
		}
	}

	return 0;
};