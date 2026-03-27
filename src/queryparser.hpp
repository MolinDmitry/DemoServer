#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cinttypes> 

// определение структур
typedef struct{
    std::string parameterName;
    std::string value;
} QueryParameterTypeDef;

typedef struct{
    std::string path;
    std::vector<QueryParameterTypeDef> parameters;
} QueryStructTypeDef;




// Прототипы функций
QueryStructTypeDef parseQuery(std::string stringLine);
std::vector<std::string> splitString(char* buf, size_t length);