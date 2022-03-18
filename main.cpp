
#include <iostream>
#include "GUI.h"

int main(int argc, char* argv[]){
    std::cout << "Hello!!!! ";

    QApplication a(argc, argv);
    auto* i = new GUI;
    i->show();
    return a.exec();
}