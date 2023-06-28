#include <windows.h>

#include "manage.h"
#include "json.h"
#include "file.h"


string products_filename = "lol.json";



/**
* Main function to run as a console application. Prints a message to the user and waits for user input.
* 
* 
* Returns: 
* 	 Returns 0 if everything is fine or non - zero in case of error. This function is called by the program
*/
int main ()
{
    system("cls");
    system("mode 650");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    // This is a loop that is run in a loop.
    while (true)
    {
        string key;

        cout << "What you whant to do?" << endl;

        cout << "add          - add new product to warehouse" << endl;
        cout << "change       - change information about product in warehouse" << endl;
        cout << "remoove      - remoove product from warehouse " << endl;
        cout << "checkremains - view current products and their location" << endl;
        cout << "exit         - exit" << endl << endl;
        cin >> key;

        // Set the system class to the specified key.
        if (key == "add")
        {
            system("cls");
            add_product();
        }
        else if (key == "change")
        {
            system("cls");
            change();
        }
        else if (key == "remoove")
        {
            system("cls");
            remoove();
        }
        else if (key == "checkremains")
        {
            system("cls");
            print_file(products_filename);
            system("pause");
        }
        else if (key == "exit")
        {
            exit(0);
        }
        else
        {
            system("cls");
        }
        system("cls");
    }
    return 0;
}