#ifndef RAMEXECUTOR_H
#define RAMEXECUTOR_H
#include "RamInstruction.h"
#include <map>

class RamExecutor {
    
private:
    RamInstruction sourcecode;
    std::map<int, int> registers;
    int pc;
    
public:
    RamExecutor(RamInstruction code);
    int getPC();
    void setPC(int newPC);

};

#endif // RAMEXECUTOR_H
