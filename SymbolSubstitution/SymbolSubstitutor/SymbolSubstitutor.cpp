#include "SymbolSubstitutor.h"
#include <algorithm>
#include <cctype>
#include <string>
#include <set>
std::string SymbolSubstitutor::ProcessString(const std::string& str)
{
    
    std::set<char> UsedSymbols;
    std::string ResultString = str;
    std::transform(ResultString.begin(), ResultString.end(), ResultString.begin(),
    [](unsigned char c){ return std::tolower(c); });
    
    for(auto currentSymbol = ResultString.begin();currentSymbol!=ResultString.end();++currentSymbol)
    {
        bool existInSet = false;
        auto res = UsedSymbols.find(*currentSymbol);
        existInSet = res!= UsedSymbols.end();
        
        if(existInSet)
        {
            *currentSymbol = ')';
        }
        else
        {
            UsedSymbols.insert(*currentSymbol);
            char temp = *currentSymbol;
            *currentSymbol = '(';
            for(auto symbolToCompare = currentSymbol+1;symbolToCompare!=ResultString.end();++symbolToCompare)
            {
                if(temp == *symbolToCompare)
                {
                    *currentSymbol = ')';
                    break;
                }
            }
            
            
        }
    }
    return ResultString;
}
