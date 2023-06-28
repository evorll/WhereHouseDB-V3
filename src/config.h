#ifndef CONFIG_H
#define CONFIG_H
#include <string>

using namespace std;

extern const int max_count_products;
extern string products_filename;

struct product
{
    string name;
    string desc; // description
    string quality;
    string cells;
};


#endif
