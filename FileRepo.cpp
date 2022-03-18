//
// Created by vibii on 24/05/2021.
//

#include "FileRepo.h"

void FileRepo::read(std::vector<TI>& v) {
    std::ifstream file(R"(C:\Users\vibii\Documents\GitHub\t3-912-Chirea-Liviu\input.txt)");

    while(!file.eof()){
        int start, end;
        int pp;
        std::string desc;
        file >> start >> end >> pp >> desc;
        TI t{start, end, pp, desc};
        v.push_back(t);
    }
    file.close();
}
