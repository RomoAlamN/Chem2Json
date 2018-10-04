//
// Created by intermis on 10/3/18.
//

#include <iostream>
#include "chemParser.hpp"
#include "stringUtils.hpp"

void ChemParser::parse(std::string filename) {
    std::ifstream file;
    file.open(filename);

    std::string line;
    file >> line;
    while (getline(file, line)) {
        // column definition
        if (StringUtils::startsWith(line, "#[")) {
            StringUtils::removeBeginning(line, 2);
            std::vector<std::string> cols;
            StringUtils::split(cols, line, ' ');
            this->columns = cols;
        }// this one has the filename
        else if (StringUtils::startsWith(line, "#]")) {
            StringUtils::removeBeginning(line, 2);
            this->filename = line;
        }else if(StringUtils::startsWith(line, "##")){
            StringUtils::removeBeginning(line,2);
            this->path = line +"/";
        }
        // regular data. Anything that does not start with '-' is a comment
        else if (StringUtils::startsWith(line, "-")) {
            StringUtils::removeBeginning(line, 1);
            std::vector<std::string> data;
            StringUtils::split(data, line, ' ');
            // first item is the name of that row
            this->rows.push_back(data.front());
            //push the rest of the items to the data vector
            data.erase(data.begin());
            this->data.push_back(data);
        }
    }
    std::cout << "Debug Mark" << std::endl;

}
