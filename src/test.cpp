
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

}
