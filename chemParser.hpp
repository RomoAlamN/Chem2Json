//
// Created by intermis on 10/3/18.
//

#ifndef CHEM2JSON_CHEMPARSER_HPP
#define CHEM2JSON_CHEMPARSER_HPP


#include <vector>
#include <string>
#include <fstream>

class ChemParser {
public:
    std::vector<std::string> columns;
    std::vector<std::string> rows;
    std::vector<std::vector<std::string>> data;
    std::string filename;
    std::string path;

    void parse(std::string filename);
private:

};


#endif //CHEM2JSON_CHEMPARSER_HPP
