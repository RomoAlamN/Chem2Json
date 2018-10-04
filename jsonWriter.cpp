//
// Created by intermis on 10/3/18.
//

#include "jsonWriter.hpp"



void JsonWriter::generate(ChemParser parser) {
    std::string* out = &(this->output);
    out->append("{");



    out->append("}");

}

std::string JsonWriter::write() {
    return std::__cxx11::string();
}
