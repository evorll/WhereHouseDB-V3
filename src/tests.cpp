#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "config.h"
#include "json.cpp"
#include "manage.cpp"
#include "file.cpp"
#include "json.hpp"

#include <fstream>
#include<windows.h>
#include<fstream>

string products_filename = "test.json";


TEST_CASE("From/to json") 
{
    json j;
    json jj = {{"cells","d"},{"desc","b"},{"name","a"},{"quality","c"}};
    product prod;
    product prodd{"a", "b", "c", "d"};

    to_json_product(prodd, j);
    from_json_product(jj, prod);

    CHECK(j == jj);
    CHECK(prod.name == prodd.name);
}


TEST_CASE("Add and read file") 
{
    json data, j;

    product prodd{"a", "b", "c", "d"};

    add_to_file(prodd, products_filename);

    read_file(data, products_filename);

    to_json_product(prodd, j);

    CHECK(j == data[0]);
}

TEST_CASE("File check") 
{
    ifstream file(products_filename);
    ifstream filee("kek.json");

    CHECK(file_check(file) == false);
    CHECK(file_check(filee) == true);

    file.close();
    filee.close();
    
    ofstream clearing(products_filename);

    clearing.close();
}


