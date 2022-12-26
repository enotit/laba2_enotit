#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
//#include <locale>

using namespace std;

struct Disk
{
	string title;
	string director;
	string genre;
	unsigned short int duration;
	unsigned short int year;
	string company;
	float imdb;
};

void write_file(Disk arr[], int array_len, string file_name)
{
	ofstream fout(file_name);
	fout << array_len;
	for (int i = 0; i < array_len; i++)
	{
		Disk disk = arr[i];
		fout << disk.title << endl;
		fout << disk.director << endl;
		fout << disk.genre << endl;
		fout << disk.duration << endl;
		fout << disk.year << endl;
		fout << disk.company << endl;
		fout << disk.imdb << endl;
	}

	fout.close();
};

void print_disk(Disk disk)
{
	cout << "Фильм: '" << disk.title << "'\n";
	cout << "Режиссёр: '" << disk.director << "'\n";
	cout << "Жанр: '" << disk.genre << "'\n";
	cout << "Длительность(мин): '" << disk.duration << "'\n";
	cout << "Год выпуска: '" << disk.year << "'\n";
	cout << "Компания: '" << disk.company << "'\n";
	cout << "Оценка: '" << disk.imdb << "'\n";
	cout << "=========================\n";
}

Disk *disks;

Disk read_file(ifstream &file)
{
	Disk disk;
	getline(file, disk.title);
	getline(file, disk.director);
	getline(file, disk.genre);
	file >> disk.duration;
	file >> disk.year;
	file.get();
	getline(file, disk.company);
	file >> disk.imdb;
	file.get();
	print_disk(disk);
	return disk;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	// SetConsoleOutputCP(1251); // FIXME: почему то не работает( 
	//SetConsoleCP(1251); // FIXME: почему то не работает( 
	ifstream infile;
	infile.open("text.txt");

	int count;
	infile >> count;
	cout << "Прочитал:" << count << "\n";
	disks = new Disk[count];
	infile.get();

	for (int i = 0; i < count; i++)
		disks[i] = read_file(infile);
	infile.close();

	string director;
	cout << "Выведите режиссёра:";
	getline(cin, director);
	int m_year = INT_MAX;
	Disk result;
	cout << director << "\n";
	for (int i = 0; i < count; i++)
	{

		if (disks[i].year < m_year && director == disks[i].director)
		{
			result = disks[i];
			m_year = result.year;
		}
	}
	cout << result.title << " в " << m_year << endl;

	string genre;
	cout << "Выведите жанр:";
	getline(cin, genre);
	cout << "\n";

	for (int i = 0; i < count; i++)
	{
		if (disks[i].imdb >= 8.0 && genre == disks[i].genre)
		{
			cout << disks[i].title << endl;
		}
	}

	return 0;
};