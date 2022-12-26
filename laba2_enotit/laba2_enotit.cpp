#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "class.cpp"

using namespace std;

void write_file(Disk arr[], int array_len, string file_name)
{
	ofstream fout(file_name);
	fout << array_len;
	for (int i = 0; i < array_len; i++)
	{
		Disk disk = arr[i];
		fout << disk.getTitle() << endl;
		fout << disk.getDirector() << endl;
		fout << disk.getGenre() << endl;
		fout << disk.getDuration() << endl;
		fout << disk.getYear() << endl;
		fout << disk.getCompany() << endl;
		fout << disk.getIMBD() << endl;
	}

	fout.close();
};

void print_disk(Disk disk)
{
	cout << "Фильм: '" << disk.getTitle() << "'\n";
	cout << "Режиссёр: '" << disk.getDirector() << "'\n";
	cout << "Жанр: '" << disk.getGenre() << "'\n";
	cout << "Длительность(мин): '" << disk.getDuration() << "'\n";
	cout << "Год выпуска: '" << disk.getYear() << "'\n";
	cout << "Компания: '" << disk.getCompany() << "'\n";
	cout << "Оценка: '" << disk.getIMBD() << "'\n";
	cout << "=========================\n";
}

Disk *disks;

Disk read_file(ifstream &file)
{
	Disk disk;
	string temp;
	getline(file, temp);
	disk.setTitle(temp);
	getline(file, temp);
	disk.setDirector(temp);
	getline(file, temp);
	disk.setGenre(temp);
	unsigned short int temp_usi;
	file >> temp_usi;
	disk.setDuration(temp_usi);
	file >> temp_usi;
	disk.setYear(temp_usi);
	file.get();
	getline(file, temp);
	disk.setCompany(temp);
	float temp_float;
	file >> temp_float;
	disk.setIMBD(temp_float);
	file.get();
	print_disk(disk);
	return disk;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	// SetConsoleOutputCP(1251); // FIXME: почему то не работает(
	// SetConsoleCP(1251); // FIXME: почему то не работает(
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

		if (disks[i].getYear() < m_year && director == disks[i].getDirector())
		{
			result = disks[i];
			m_year = result.getYear();
		}
	}
	cout << result.getTitle() << " в " << m_year << endl;

	string genre;
	cout << "Выведите жанр:";
	getline(cin, genre);
	cout << "\n";

	for (int i = 0; i < count; i++)
	{
		if (disks[i].getIMBD() >= 8.0 && genre == disks[i].getGenre())
		{
			cout << disks[i].getTitle() << endl;
		}
	}

	return 0;
};