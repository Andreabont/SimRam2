#ifndef RAMINT_H
#define RAMINT_H

#include <vector>
#include <map>

struct instruction_t {
    std::string verb;
    std::string noun;
};

class RamInstruction {

private:
    std::vector<instruction_t> code;
    std::map<std::string, int> label;
    int lineNumber;

public:

    RamInstruction(std::string filename);
    int getLineNumber();
    int getLabelPosition(std::string name);
    instruction_t getInstruction(int line);

};

#endif //RAMINT_H
