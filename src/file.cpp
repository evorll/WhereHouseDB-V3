#include "file.h"

using namespace std;
using json = nlohmann::json;

bool file_check(ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

void read_file(json& data, string& filename)
{
    if (filename == products_filename)
    {
        ifstream file(products_filename);

        if (file_check(file))
        {
            data = json::array();
        }
        else
        {
            data = json::parse(file);
        }  

        file.close();
    }
}



void save_file(json& data, string& filename)
{
    ofstream out(filename);

    out << data;

    out.close();
}

void print_line(product& prod, int& num)
{
    string line(170, '-');

    cout << line << endl;
    cout << "|" << setw(4) << "#" << " | " << setw(40) << "Name |" << setw(70) << "Description |" << setw(10) << "Quality |" << setw(42) << "Cells |" << endl;
    cout << line << endl;
    cout << "|" << setw(4) << "-"  << " | " << setw(40) << prod.name + " |" << setw(70) << prod.desc + " |" << setw(10) << prod.quality + " |" << setw(42) << prod.cells + " |" << endl;
    cout << line << endl;
}

void print_file(string& filename)
{
    int i = 0;
    json data, str;


    if (filename == products_filename)
    {
        product prod;
        string line(170, '-');

        read_file(data, filename);

        cout << line << endl;
        cout << "|" << setw(4) << "#" << " | " << setw(40) << "Name |" << setw(70) << "Description |" << setw(10) << "Quality |" << setw(42) << "Cells |" << endl;
        cout << line << endl;

        for (auto& str : data)
        {
            from_json_product(str, prod);

            cout << "|" << setw(4) << i + 1  << " | " << setw(40) << prod.name + " |" << setw(70) << prod.desc + " |" << setw(10) << prod.quality + " |" << setw(42) << prod.cells + " |" << endl;
            cout << line << endl;
            
            i++;
        }
        cout << endl;
    }
   
}



void add_to_file(product& prod, string& filename)
{
    json data, str;

    read_file(data, filename);

    to_json_product(prod, str);

    data.push_back(str);

    save_file(data, filename);
}


