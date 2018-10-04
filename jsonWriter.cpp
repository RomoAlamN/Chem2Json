//
// Created by intermis on 10/3/18.
//

#include "jsonWriter.hpp"
#include "stringUtils.hpp"
#include <experimental/filesystem>

void compileArray(std::string& out, const std::string& row, const std::vector<std::string> &parts){
    out.append("\"" + row + "\": [");
    StringUtils::join(out, parts, ",");
    out.append("]");
}

std::vector<std::string> createJson(std::vector<std::string> rows,  std::vector<std::vector<std::string>> data, int col){
    std::vector<std::string> out;
    out.reserve(rows.size());
    for(int row = 0; row < rows.size(); row++){
        if(StringUtils::containsAny(data[row][col],"[:]")){
            std::string datum = data[row][col];
            StringUtils::shave(datum,"[]");
            std::vector<std::string> parts;
            StringUtils::split(parts, datum, ':');
            std::string temp;
            compileArray(temp, rows[row], parts);
            out.push_back(temp);
        }else {
            out.push_back("\"" + rows[row] + "\": " + data[row][col]);
        }
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
