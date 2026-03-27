
#include "queryparser.hpp"



namespace tests{

    int test01(){
        std::cout << "Test №1" << std::endl;

        QueryStructTypeDef queryObject = parseQuery("GET /demoserver/exec?command=com&param=value HTTP/1.1");
        std::cout << queryObject.path << std::endl;
        for(auto parameter: queryObject.parameters){
            std::cout << parameter.parameterName << ": " << parameter.value << std::endl;
        }

        return 0;
    }

    int test02(){
        std::cout << "Test №2" << std::endl;

        QueryStructTypeDef queryObject = parseQuery("GET /testpage HTTP/1.1");
        std::cout << queryObject.path << std::endl;
        for(auto parameter: queryObject.parameters){
            std::cout << parameter.parameterName << ": " << parameter.value << std::endl;
        }

        return 0;
    }


    int test03(){
        std::cout << "Test №3" << std::endl;

        QueryStructTypeDef queryObject = parseQuery("GET /testpage/ HTTP/1.1");
        std::cout << queryObject.path << std::endl;
        for(auto parameter: queryObject.parameters){
            std::cout << parameter.parameterName << ": " << parameter.value << std::endl;
        }

        return 0;
    }

}
