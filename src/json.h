#ifndef JSON_H
#define JSON_H

#include "config.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

void to_json_product(const product& p, json& j);
void from_json_product(const json& j, product& p);


#endif