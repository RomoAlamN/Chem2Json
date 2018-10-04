//
// Created by intermis on 10/2/18.
//

#include "include/CLI11.hpp"
#include "stringUtils.hpp"
#include "chemParser.hpp"

int main(int argc, char *argv[]) {
    std::cout << argc << std::endl;
    if (argc != 2) {
        CLI::App app{"Converts .chem to .json"};
        std::string files = "none.err";
        app.add_option("-f,--files",
                       files, "Comma separated list of .chem files to convert")
                ->required(true);

        CLI11_PARSE(app, argc, argv)

        std::vector<std::string> filesVector;
        StringUtils::split(filesVector, files, ',');

        for (const auto &file : filesVector) {
            ChemParser parser;
            // ChemWriter writer;
            std::cout << "Parsing : " << file << std::endl;
            parser.parse(file);
            std::cout << "Parsed!" << std::endl;
        }
    } else {
        std::cout << "Parsing : " << argv[1] << std::endl;
        ChemParser parser;
        parser.parse(argv[1]);
        std::cout << "Parsed!" << std::endl;
    }


}