#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <fstream>
#include <vector>
#include <map>
#include "ramInterpreter.h"

RamInterpreter::RamInterpreter(std::string filename) {
    std::ifstream source_file;
    source_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    source_file.open(filename.c_str());

    int count = 0;
    std::string buffer;
    while (!source_file.eof() && std::getline(source_file, buffer)) {

        // Remove all char after #
        buffer = buffer.substr(0, buffer.find("#"));

        // Remove all spaces preceding the instruction
        while(std::isspace(*buffer.begin())) {
            buffer.erase(buffer.begin());
        }

        // Remove all spaces that follow the instruction
        while(std::isspace(*buffer.rbegin())) {
            buffer.erase(buffer.length()-1);
        }

        // Check if there are a label
        int find = buffer.find(":");
        if(find != std::string::npos) {
            std::string label_name = buffer.substr(0, find);
            label[label_name] = count;
            buffer = buffer.substr(find, std::string::npos);

            // Remove all spaces preceding the instruction
            while(std::isspace(*buffer.begin())) {
                buffer.erase(buffer.begin());
            }

        }

        // Save instruction
        std::vector<int> temp;
        boost::algorithm::split(temp, buffer, boost::algorithm::is_any_of(" "));

        instruction_t instruction;
        instruction.verb = temp[0];
        instruction.noun = temp[1];

        code.push_back(instruction);

        count++;

    }

    source_file.close();
}
