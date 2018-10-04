//
// Created by intermis on 10/3/18.
//

#include "jsonWriter.hpp"
#include "stringUtils.hpp"
#include <experimental/filesystem>

std::vector<std::string> createJson(std::vector<std::string> rows,  std::vector<std::vector<std::string>> data, int col){
    std::vector<std::string> out;
    out.reserve(rows.size());
    for(int row = 0; row < rows.size(); row++){
        std::string pStr;
        pStr.append("\"");
        pStr.append(rows[row]);
        pStr.append("\": ");
        pStr.append(data[row][col]);
        out.push_back(pStr);
    }
    return out;
}

void JsonWriter::generate(ChemParser parser) {
    std::string* out = &(this->output);
    out->append("{");

    out->append("\"" + parser.filename + "\": [\"");
    StringUtils::appendJoin(*out, parser.columns, R"(",")");
    out->append("\"]");

    for(int col = 0; col < parser.columns.size(); col++){
        out->append(",\"" + parser.columns[col] + "\": {");
        StringUtils::appendJoin(*out, createJson(parser.rows, parser.data, col), ",");
        out->append("}");
    }

    out->append("}");

    namespace fs= std::experimental::filesystem;
    if(!fs::is_directory(parser.path) || ! fs::exists(parser.path)){
        fs::create_directory(parser.path);
    }

    this->filename = parser.path + parser.filename;
}

std::string JsonWriter::write() {

    std::ofstream out;
    out.open("./"+filename + ".json");
    out << output;

    return output;
}
