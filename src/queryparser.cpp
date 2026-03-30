

#include "queryparser.hpp"



//============================================================================
QueryStructTypeDef parseQuery(std::string stringLine){
    QueryStructTypeDef outObject;        
    std::vector<std::string> strVector;
    std::string str = "";
    std::stringstream ss(stringLine);
    // делим запрос по пробелам
    for(std::string str; std::getline(ss, str, ' ');){
        if (str != "")
            strVector.push_back(str);
    }
    std::string queryStr = strVector[1];
    std::stringstream ss2(queryStr);
    strVector.clear();
    // выделяем path и параметры запроса
    for(std::string str2; std::getline(ss2, str2, '?');){
        if (str2 != "")
            strVector.push_back(str2);
    }
    if (strVector.size() == 0){
        outObject.path = "";
    }
    else{
        if (strVector.size() == 1){ // если запрос без параметров
            outObject.path = strVector[0];
        }
        else{ // запрос с параметрами
            outObject.path = strVector[0];
            std::stringstream ss3(strVector[1]);
            strVector.clear();
            // разделяем строку параметров на отдельные пары параметр=значение
            for(std::string str3; std::getline(ss3, str3, '&');){
                strVector.push_back(str3);
            }
            for(auto cur_str: strVector){
                std::stringstream ss4(cur_str);
                std::vector<std::string> strVector2;
                // выделяем имя и значение параметра
                for(std::string str4; std::getline(ss4, str4, '=');){
                    strVector2.push_back(str4);
                }
                QueryParameterTypeDef cur_param;
                cur_param.parameterName = strVector2[0];
                cur_param.value = strVector2[1];
                outObject.parameters.push_back(cur_param);
            }
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