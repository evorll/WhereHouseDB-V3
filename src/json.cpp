#include "json.h"

using namespace std;
using json = nlohmann::json;

/**
* Converts a product to a json object. This is used to create products that are part of the game and need to be saved to the database
* 
* @param p - The product to convert.
* @param j - The json object to save to. It will be overwritten
*/
void to_json_product(const product& p, json& j) 
{
    j = json{{"name", p.name}, {"desc", p.desc}, {"quality", p.quality}, {"cells", p.cells}};

}


/**
* Copy the values of a product to a json object. This is used for converting products that are stored in the database to JSON objects
* 
* @param j - json object to copy values to
* @param p - product that will be copied values from \ a
*/
void from_json_product(const json& j, product& p) 
{
    j.at("name").get_to(p.name);
    j.at("desc").get_to(p.desc);
    j.at("quality").get_to(p.quality);
    j.at("cells").get_to(p.cells);
}

