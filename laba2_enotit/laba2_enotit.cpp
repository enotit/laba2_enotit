#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "class.cpp"
#include "diskstorage.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	// SetConsoleOutputCP(1251); // FIXME: почему то не работает(
	SetConsoleCP(1251); // FIXME: почему то не работает(
	DiskStorage disks(20);
	disks.read_file_all("text.txt");
	disks.display();

	string director;
	cout << "Выведите режиссёра:";
	getline(cin, director);
	int m_year = INT_MAX;
	Disk result;
	cout << director << "\n";
	for (int i = 0; i < disks.count; i++)
	{

		if (disks.disks[i].getYear() < m_year && director == disks.disks[i].getDirector())
		{
			result = disks.disks[i];
			m_year = result.getYear();
		}
	}
	cout << result.getTitle() << " в " << m_year << endl;

	string genre;
	cout << "Выведите жанр:";
	getline(cin, genre);
	cout << "\n";

	for (int i = 0; i < disks.count; i++)
	{
		if (disks.disks[i].getIMBD() >= 8.0 && genre == disks.disks[i].getGenre())
		{
			cout << disks.disks[i].getTitle() << endl;
		}
	}

	return 0;
};