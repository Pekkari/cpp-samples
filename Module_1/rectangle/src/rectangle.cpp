#include "rectangle.hpp"

#include <iostream>

// Write you function here and test it with the main.
double area(double width, double height) {
    return width * height;
}

double circumference(double width, double height) {
    return 2 * (width + height);
}

void Rectangle() {
    double width, height;
    std::cout << "Please enter width and height" << std::endl;
    std::cin >> width;
    std::cin >> height;
    std::cout << "Area: " << area(width, height)  << std::endl;
    std::cout << "Circumference: " << circumference(width, height) << std::endl;
}

