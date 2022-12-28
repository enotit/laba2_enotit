#ifndef DISKSTORAGE_H
#define DISKSTORAGE_H
#include <string>
#include <fstream>
#include "class.h"
using namespace std;

class DiskStorage
{
public:
    int count;
    Disk *disks;
    int max_count;
    void read_from(ifstream &file);
    void display();
    string get_title();
    DiskStorage(int max_cnt);
    ~DiskStorage();
    void add_disk(Disk disk);
    int get_file_str_quantity(ifstream &infile);
    void read_file_all(string filename);
    void write_file(string file_name);
    void operator +=(const Disk &disk);
};  

#endif