#include <iostream>
#include <cmath>

// class for describing segment
class Segment {
public:
    // variables for start and end point, empty identifier
    double a;
    double b;
    bool empty;

    // default constructor for creating empty segment
    Segment() {
        a = b = 0;
        empty = true;
    }

    // function for setting empty variable
    void setEmpty(bool _empty) {
        this->empty = _empty;
    }

    // function for making segment empty
    void makeEmpty() {
        this->empty = true;
        a = b = 0;
    }

    // function for getting empty value
    bool isEmpty() const {
        return this->empty;
    }

    // function for printing segment
    void printSegment() const {
        // declaring string variable for better empty output. using ternary operator for this
        std::string emp = isEmpty() ? "true" : "false";
        std::cout << " A: " << a << ", B: " << b << ", Is empty: " << emp << std::endl;
    }

    // function for setting segment with given values
    void setSegment(double _a, double _b) {
        this->empty = false;
        this->a = _a;
        this->b = _b;
    }
};

// function for finding solution for inequality
Segment findSolution(double p, double q) {
    // x1 found with discriminant formula
    double x1 = (-p + std::sqrt(std::pow(p, 2) - 4 * q)) / 2;
    // x2 found with discriminant formula
    double x2 = (-p - std::sqrt(std::pow(p, 2) - 4 * q)) / 2;
    // showing two points that are edges of segment which represents solving for inequality
    std::cout << x1 << " " << x2 << std::endl;
    // creating segment with found points
    Segment segment;
    segment.setSegment(x1, x2);
    // returning segment
    return segment;
}

int main() {
    // searching solving for inequality with given p and q values
    Segment segment = findSolution(-2, -1);
    // printing solving
    segment.printSegment();
    return 0;
}