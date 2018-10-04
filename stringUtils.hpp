//
// Created by intermis on 10/3/18.
//

#ifndef CHEM2JSON_STRINGUTILS_HPP
#define CHEM2JSON_STRINGUTILS_HPP

#endif //CHEM2JSON_STRINGUTILS_HPP

#include <string>
#include <vector>

class StringUtils {
public:
    static void split(std::vector<std::string> &split, const std::string &data, char delimiter) {
        split.clear();

        size_t index = 0;
        size_t start = 0;
        while (index < data.length()) {
            if (data[index] == delimiter) {
                if(start != index) {
                    split.push_back(data.substr(start, index - start));
                }
                start = index + 1;
            }
            index++;
        }
        if(start != data.length()){
            split.push_back(data.substr(start, data.length() - start));
        }
    }
    static bool startsWith(const std::string& data, const std::string& prefix){
        if(data.length() < prefix.length()) return false;
        for(int i = 0; i < prefix.length(); i++){
            if(data[i] != prefix[i]) return false;
        }
        return true;
    }
    static bool hasPrefix(const std::string& data, const std::string& prefix){
        return startsWith(data, prefix);
    }
    static void removeBeginning(std::string& data, unsigned int start){
        data = data.substr(start);
    }
};