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
                if (start != index) {
                    split.push_back(data.substr(start, index - start));
                }
                start = index + 1;
            }
            index++;
        }
        if (start != data.length()) {
            split.push_back(data.substr(start, data.length() - start));
        }
    }

    static bool startsWith(const std::string &data, const std::string &prefix) {
        if (data.length() < prefix.length()) return false;
        for (int i = 0; i < prefix.length(); i++) {
            if (data[i] != prefix[i]) return false;
        }
        return true;
    }

    static bool startsWith(const std::string &data, char prefix){
        return data[0] == prefix;
    }

    static bool hasPrefix(const std::string &data, const std::string &prefix) {
        return startsWith(data, prefix);
    }

    static bool endsWith(const std::string &data, char suffix){
        return data.back() == suffix;
    }

    static void removeBeginning(std::string &data, unsigned int start) {
        data = data.substr(start);
    }

    static void appendJoin(std::string &base, const std::vector<std::string> &data, const std::string &join) {
        std::string append;
        StringUtils::join(append, data, join);
        base.append(append);
    }

    static void join(std::string &out, const std::vector<std::string> &data, const std::string &join) {
        for (auto &line : data) {
            out.append(line);
            out.append(join);
        }
        out.erase(out.length() - join.length(), join.length());
    }

    static bool containsAny(const std::string &line, const std::string &searchChars) {
        for (auto c : line) {
            for (auto search : searchChars) {
                if (search == c) return true;
            }
        }
        return false;
    }

    static void shave(std::string &line, const std::string &shaveChars) {
        if (startsWith(line, shaveChars[0])){
            line.erase(line.begin());
        }
        if(endsWith(line, shaveChars[1])){
            line.erase(line.end()-1);
        }
    }
};