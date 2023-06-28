#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "config.h"
#include "json.h"

bool file_check(ifstream& file);
// void from_json(const json& j, product& p); 
void read_file(json& data, string& filename);
void save_file(json& data, string& filename);
void print_line(product& prod, int& num);
void print_file(string& filename);
void add_to_file(product& prod, string& filename);


#endif