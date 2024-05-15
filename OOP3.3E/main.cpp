// main.cpp
#include "Triangle.h"
#include <iostream>

int main() {
    Triangle triangle;

    triangle.Read();
    triangle.Display();

    triangle++;
    triangle.Display();

    triangle--;
    triangle.Display();

    std::cout << "Count:" << Object::getI() << std::endl;


    return 0;
}
