#include "manage.h"

using namespace std;



/**
* Reads a product from the user and adds it to the products file. 
*/
void add_product()
{
    product prod;
    
    cout << "Write product name: ";
    getline(cin >> ws, prod.name);
    cout << "Write description: ";
    getline(cin >> ws, prod.desc);
    cout << "Write quality: ";
    getline(cin >> ws, prod.quality);
    cout << "Write product location: ";
    getline(cin >> ws, prod.cells);   
      
    add_to_file(prod, products_filename);
}



/**
* Change function to be called from command line. This function reads a file and changes the selected values of the file
*/
void change()
{
    int number;
    string key;
    json data, str;
    product prod;
    bool mark = true;

    print_file(products_filename);


    cout << endl << "Which line do you want to change: ";
    cin >> number; 
    cout << endl;

    
    read_file(data,  products_filename);
    from_json_product(data[number - 1], prod);

    system("cls");

    print_line(prod, number);


    while(mark)
    {
        cout << "Write what you whant to change:" << endl << endl;
        cout << "name        - add new product to warehouse" << endl;
        cout << "description - change information about product in warehouse" << endl;
        cout << "quality     - remoove product from warehouse " << endl;
        cout << "location    - view the load of cells" << endl;
        cout << "all         - view current products and their location" << endl << endl;
    
        cin >> key;

        // Write the product key to the console.
        if (key == "name")
        {
            cout << "Write product name: " ;
            getline(cin >> ws, prod.name);
            mark = false;
        }
        else if (key == "description")
        {
            cout << "Write description: " ;
            getline(cin >> ws, prod.desc);
            mark = false;
        }
        else if (key == "quality")
        {
            cout << "Write quality: " ;
            getline(cin >> ws, prod.quality);
            mark = false;
        }
        else if (key == "location")
        {
            cout << "Write product location: ";
            getline(cin >> ws, prod.cells);
            mark = false;
        }
        else if (key == "all")
        {
            cout << "Write product name: ";
            getline(cin >> ws, prod.name);
            cout << "Write description: ";
            getline(cin >> ws,prod.desc);
            cout << "Write quality: ";
            getline(cin >> ws, prod.quality);
            cout << "Write product location: ";
            getline(cin >> ws, prod.cells);    
  
            mark = false;
        }
        else
        {
            cout << "Wrong key, try again" << endl;
            system("cls");
        }
    }

    to_json_product(prod, str);

    data[number-1] = str;

    save_file(data, products_filename);
}



/**
* remoove a line from a file and erase it from the beginning of the vector to avoid overwriting
*/
void remoove()
{
    int number;
    json data;

    print_file(products_filename);

    cout << "Which line do you want to remoove: ";
    cin >> number; 

    read_file(data, products_filename);
    
    data.erase(number - 1);

    save_file(data, products_filename);
}
