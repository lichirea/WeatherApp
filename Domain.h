#pragma once

#include <string>

class TI{
public:
    int start, end;
    int pp;
    std::string desc;
public:
    TI(int start, int end, int pp, std::string desc);
    std::string to_str();
};