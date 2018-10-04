//
// Created by intermis on 10/3/18.
//

#ifndef CHEM2JSON_JSONWRITER_HPP
#define CHEM2JSON_JSONWRITER_HPP


#include <string>
#include "chemParser.hpp"

class JsonWriter {
private:
    std::string output;
    std::string filename;
public:
    void generate(ChemParser parser);
    std::string write();
};


#endif //CHEM2JSON_JSONWRITER_HPP
