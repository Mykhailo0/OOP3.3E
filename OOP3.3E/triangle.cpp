// triangle.cpp
#define _USE_MATH_DEFINES
#include "triangle.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>

Triangle::Triangle()
{
    setA(1);
    setB(1);
    setC(1);
}

Triangle::Triangle(int sideA, int sideB, int sideC)
{
    setA(sideA);
    setB(sideB);
    setC(sideC);
}

Triangle::Triangle(const Triad& triad)
{
    setA(triad.getA());
    setB(triad.getB());
    setC(triad.getC());
}

double Triangle::calculateAngleA() const {
    int a = getA();
    int b = getB();
    int c = getC();

    return acos((b * b + c * c - a * a) / (2.0 * b * c)) * 180.0 / M_PI;
}

double Triangle::calculateAngleB() const {
    int a = getA();
    int b = getB();
    int c = getC();;

    return acos((a * a + c * c - b * b) / (2.0 * a * c)) * 180.0 / M_PI;
}

double Triangle::calculateAngleC() const {
    int a = getA();
    int b = getB();
    int c = getC();

    return acos((a * a + b * b - c * c) / (2.0 * a * b)) * 180.0 / M_PI;
}


double Triangle::calculateArea() const {
    double s = calculateSum() / 2.0;

    return sqrt(s * (s - getA()) * (s - getB()) * (s - getC()));
}

std::string Triangle::toString(double a) const {
    std::stringstream ss;
    ss << std::setprecision(4) << a;

    return ss.str();
}

void Triangle::Display() const
{
    std::cout << "Triangle with sides: " << toString(getA()) << ", " << toString(getB()) << ", " << toString(getC()) << std::endl;
    std::cout << "Area: " << toString(calculateArea()) << std::endl;
    std::cout << "Angles: " << toString(calculateAngleA()) << ", " << toString(calculateAngleB()) << ", " << toString(calculateAngleC()) << std::endl;
    std::cout << "Sum of sides: " << toString(calculateSum()) << std::endl;
}

void Triangle::Init(int a, int b, int c)
{
    setA(a);
    setB(b);
    setC(c);
}

void Triangle::SetSides(int a, int b, int c)
{
    Init(a, b, c);
}

Triad Triangle::GetSides()
{
    return Triad(getA(), getB(), getC());
}

void Triangle::Read()
{
    int a, b, c;
    std::cout << "Enter Triad: ";
    std::cin >> a >> b >> c;
    Init(a, b, c);
}

Triangle& Triangle::operator=(const Triangle& triangle)
{
    if (this != &triangle)
    {
        Triad::operator=(triangle);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Triangle& triangle)
{
    out << "Triangle with sides: " << triangle.toString(triangle.getA()) << ", " << triangle.toString(triangle.getB()) << ", " << triangle.toString(triangle.getC()) << std::endl;
    out << "Area: " << triangle.toString(triangle.calculateArea()) << std::endl;
    out << "Angles: " << triangle.toString(triangle.calculateAngleA()) << ", " << triangle.toString(triangle.calculateAngleB()) << ", " << triangle.toString(triangle.calculateAngleC()) << std::endl;
    out << "Sum of sides: " << triangle.toString(triangle.calculateSum()) << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Triangle& triangle)
{
    int a, b, c;
    in >> a >> b >> c;
    triangle.SetSides(a, b, c);
    return in;
}

Triangle::operator std::string() const {
    return "Triangle sides: " + std::to_string(getA()) + ", " +
        std::to_string(getB()) + ", " +
        std::to_string(getC());
}

Triangle& Triangle::operator++() {
    setA(getA() + 1);
    setB(getB() + 1);
    setC(getC() + 1);
    return *this;
}

Triangle& Triangle::operator--() {
    setA(getA() - 1);
    setB(getB() - 1);
    setC(getC() - 1);
    return *this;
}

Triangle Triangle::operator++(int) {
    Triangle t(*this);
    setA(getA() + 1);
    setB(getB() + 1);
    setC(getC() + 1);
    return t;
}

Triangle Triangle::operator--(int) {
    Triangle t(*this);
    setA(getA() - 1);
    setB(getB() - 1);
    setC(getC() - 1);
    return t;
}