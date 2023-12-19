#include "CantorSet.h"

CantorSet::CantorSet(const std::string& input)
{
    std::vector<char> stack;
    bool insideElement = false;

    for (const char& c : input) {
        if (c == '{') {
            insideElement = true;
        }
        else if (c == '}') {
            insideElement = false;
            addElement(std::string(stack.begin(), stack.end()));
            stack.clear();
        }
        else if (insideElement && c != ' ') {
            stack.push_back(c);
        }
    }
}
