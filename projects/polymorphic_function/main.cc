
// main.cpp
#include <iostream>
#include <vector>

#include "declaration.h"

// ShapeSorter declaration
void ShapeSorter(std::vector<Shape *> &shapes);

int main() {
    // Create some shapes
    XYPoint origin(0, 0);

    // Circle with radius 5
    Circle *circle = new Circle(origin, 5);

    // Triangle with points at (0,0), (4,0), and (0,3)
    Triangle *triangle = new Triangle(origin, XYPoint(4, 0), XYPoint(0, 3));

    // Rectangle with points at (0,0), (3,0), (3,4), and (0,4)
    Rectangle *rectangle =
        new Rectangle(origin, XYPoint(3, 0), XYPoint(3, 4), XYPoint(0, 4));

    // Store shapes in a vector
    std::vector<Shape *> shapes = {circle, triangle, rectangle};

    // Print areas before sorting
    std::cout << "Areas before sorting:" << std::endl;
    for (const auto &shape : shapes) {
        std::cout << shape->area() << std::endl;
    }

    // Sort shapes by area
    ShapeSorter(shapes);

    // Print areas after sorting
    std::cout << "\nAreas after sorting:" << std::endl;
    for (const auto &shape : shapes) {
        std::cout << shape->area() << std::endl;
    }

    // Clean up memory
    for (auto &shape : shapes) {
        delete shape;
    }

    return 0;
}
