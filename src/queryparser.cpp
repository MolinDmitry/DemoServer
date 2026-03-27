

#include "queryparser.hpp"



//============================================================================
QueryStructTypeDef parseQuery(std::string stringLine){
    QueryStructTypeDef outObject;
    std::vector<std::string> strVector;
    std::string str = "";
    std::stringstream ss(stringLine);
    for(std::string str; std::getline(ss, str, ' ');){
        if (str != "")
            strVector.push_back(str);
    }
    std::string queryStr = strVector[1];
    ss.str(queryStr);
    strVector.clear();
    for(std::string str; std::getline(ss, str, '?');){
        if (str != "")
            strVector.push_back(str);
    }
    if (strVector.size() == 0){
        outObject.path = "";
    }
    else{
        outObject.path = strVector[0];
        for(size_t i = 1; i < strVector.size(); i++){

        }        

    }
    
    

    return outObject;
}

//=============================================================================
std::vector<std::string> splitString(char* buf, size_t length){
    std::vector<std::string> strVector;
    std::string str = "";
    for(size_t i = 0; i < length; i++){
        str+= buf[i];
    }
    std::stringstream ss(str);
    for(std::string str; std::getline(ss, str);){
        strVector.push_back(str);
    }
    return strVector;
}