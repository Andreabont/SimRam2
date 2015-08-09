#include "RamExecutor.h"

RamExecutor::RamExecutor(RamInstruction code) {

    this->pc = 0;
    this->sourcecode = code;
    
}

int RamExecutor::getPC() {
    return this->pc;
}

void RamExecutor::setPC(int newPC) {
    this->pc = newPC;
}
