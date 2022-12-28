#include <iostream>
#include <string>
#include <fstream>
#include "diskstorage.h"

using namespace std;

DiskStorage::~DiskStorage()
{
	this->count = 0;
	this->max_count = 0;
	delete this->disks;
};

void DiskStorage::add_disk(Disk disk)
{
	if (this->count >= this->max_count)
		return;
	this->disks[this->count] = disk;
	this->count++;
}

void DiskStorage::read_file_all(string filename)
{
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open())
	{
		cout << "====== Файл не найден! ======" << endl;
		system("pause");
		exit(1);
	}
	string _count;
	getline(infile, _count);
	this->count = stoi(_count.c_str());
	cout << "Прочитал:" << this->count << "\n";
	for (int i = 0; i < this->count; i++)
	{
		Disk new_disk;
		new_disk.read_file(infile);
		infile.get();
		this->add_disk(new_disk);
	}
	infile.close();
}

void DiskStorage::write_file(string file_name)
{
	ofstream fout(file_name);
	fout << this->count;
	for (int i = 0; i < this->count; i++)
	{
		Disk disk = this->disks[i];
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

DiskStorage::DiskStorage(int max_cnt)
{
	this->disks = new Disk[max_cnt];
};

void DiskStorage::display()
{
	for (int i = 0; i < this->count; i++)
	{
		this->disks[i].print_disk();
	}
}

void DiskStorage::operator+=(const Disk &disk)
{
	DiskStorage::add_disk(disk);
};