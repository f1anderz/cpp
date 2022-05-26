#include <iostream>
#include <cmath>

class Segment {
public:
    double a;
    double b;
    bool empty;

    Segment() {
        a = b = 0;
        empty = true;
    }

    void setEmpty(bool _empty) {
        this->empty = _empty;
    }

    void makeEmpty() {
        this->empty = true;
    }

    bool isEmpty() const {
        return this->empty;
    }

    void printSegment() const {
        std::string emp = isEmpty() ? "true" : "false";
        std::cout << " A: " << a << ", B: " << b << ", Is empty: " << emp << std::endl;
    }

    void setSegment(double _a, double _b) {
        this->empty = false;
        this->a = _a;
        this->b = _b;
    }
};

Segment findSolution(double p, double q) {
    double x1 = (-p + std::sqrt(std::pow(p, 2) - 4 * q)) / 2;
    double x2 = (-p - std::sqrt(std::pow(p, 2) - 4 * q)) / 2;
    std::cout << x1 << " " << x2 << std::endl;
    Segment segment;
    segment.setSegment(x1, x2);
    return segment;
}

int main() {
    Segment segment = findSolution(-2,-1);
    segment.printSegment();
    return 0;
}