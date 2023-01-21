#include <iostream>

#include "SymbolSubstitutor/SymbolSubstitutor.h"
int main(int argc, char* argv[])
{
    auto res = SymbolSubstitutor::ProcessString("(( @");

    std::cout<< res;
    return 0;
}
