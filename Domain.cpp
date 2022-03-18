#include "Domain.h"

#include <utility>
using namespace std;

TI::TI(int start, int end, int pp, std::string desc) {
    this->start = start;
    this->end = end;
    this->pp = pp;
    this->desc = std::move(desc);
}

std::string TI::to_str() {
    return "From " + to_string(start) +" to " + to_string(end) + " ; Precipitation: " +to_string(pp) + "%; " +desc;
}
