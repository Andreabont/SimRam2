#ifndef RAMINT_H
#define RAMINT_H

#include <vector>
#include <map>

struct instruction_t {
    std::string verb;
    std::string noun;
};

class RamInterpreter {

private:
    std::vector<instruction_t> code;
    std::map<std::string, int> label;
    std::vector<int> input;
    std::vector<int> output;
    std::map<int,int> registers;
    int program_counter = 0;

public:

    RamInterpreter(std::string filename);

};

#endif //RAMINT_H
