#include "json.h"

using namespace std;
using json = nlohmann::json;

void to_json_product(const product& p, json& j) 
{
    j = json{{"name", p.name}, {"desc", p.desc}, {"quality", p.quality}, {"cells", p.cells}};

}


void from_json_product(const json& j, product& p) 
{
    j.at("name").get_to(p.name);
    j.at("desc").get_to(p.desc);
    j.at("quality").get_to(p.quality);
    j.at("cells").get_to(p.cells);
}

