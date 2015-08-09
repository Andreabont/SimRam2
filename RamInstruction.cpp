#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <fstream>
#include <vector>
#include <map>
#include "RamInstruction.h"

RamInstruction::RamInstruction(std::string filename) {

    std::ifstream source_file;
    source_file.open(filename.c_str());

    this->lineNumber = 0;
    
    std::string line;
    
    while (std::getline(source_file, line)) {

    // Increment line number
	this->lineNumber++;

	// Remove all char after #
        line = line.substr(0, line.find('#'));

        // Remove all spaces preceding the instruction
        while(std::isspace(*line.begin())) {
            line.erase(line.begin());
        }

        // Remove all spaces that follow the instruction
        while(std::isspace(*line.rbegin())) {
            line.erase(line.length()-1);
        }

        // Check if there are a label
        int find = line.find(':');
        if(find != std::string::npos) {
            std::string label_name = line.substr(0, find);
            this->label[label_name] = this->lineNumber;
            line = line.substr(find, std::string::npos);

            // Remove all spaces preceding the instruction
            while(std::isspace(*line.begin())) {
                line.erase(line.begin());
            }

        }

	// Skip if empty line
	if(line.empty()) {
	   continue;
	}
	
        // Save instruction
        std::vector<std::string> temp;
        boost::algorithm::split(temp, line, boost::algorithm::is_any_of(" "));

	if(temp.size() != 2) {
	   std::cerr << "Syntax error on line " << this->lineNumber+1 << ": " << line << std::endl;
	   std::abort();
	}

        instruction_t instruction;
        instruction.verb = temp[0];
        instruction.noun = temp[1];

        this->code.push_back(instruction);

    }

    source_file.close();
}

int RamInstruction::getLineNumber() {
    return this->lineNumber;
}

instruction_t RamInstruction::getInstruction(int line) {
    return this->code[line];
}

int RamInstruction::getLabelPosition(std::string name) {
    return this->label[name];
}

