// TriangleC.cpp
#define _USE_MATH_DEFINES
#include "TriangleC.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>

TriangleC::TriangleC()
{
    setA(1);
    setB(1);
    setC(1);
}

TriangleC::TriangleC(int sideA, int sideB, int sideC)
{
    setA(sideA);
    setB(sideB);
    setC(sideC);
}

TriangleC::TriangleC(const Triad& triad)
{
    setA(triad.getA());
    setB(triad.getB());
    setC(triad.getC());
}

double TriangleC::calculateAngleA() const {
    int a = getA();
    int b = getB();
    int c = getC();

    return acos((b * b + c * c - a * a) / (2.0 * b * c)) * 180.0 / M_PI;
}

double TriangleC::calculateAngleB() const {
    int a = getA();
    int b = getB();
    int c = getC();;

    return acos((a * a + c * c - b * b) / (2.0 * a * c)) * 180.0 / M_PI;
}

double TriangleC::calculateAngleC() const {
    int a = getA();
    int b = getB();
    int c = getC();

    return acos((a * a + b * b - c * c) / (2.0 * a * b)) * 180.0 / M_PI;
}


double TriangleC::calculateArea() const {
    double s = calculateSum() / 2.0;

    return sqrt(s * (s - getA()) * (s - getB()) * (s - getC()));
}

std::string TriangleC::toString(double a) const {
    std::stringstream ss;
    ss << std::setprecision(4) << a;

    return ss.str();
}

void TriangleC::Display() const
{
    std::cout << "TriangleC with sides: " << toString(getA()) << ", " << toString(getB()) << ", " << toString(getC()) << std::endl;
    std::cout << "Area: " << toString(calculateArea()) << std::endl;
    std::cout << "Angles: " << toString(calculateAngleA()) << ", " << toString(calculateAngleB()) << ", " << toString(calculateAngleC()) << std::endl;
    std::cout << "Sum of sides: " << toString(calculateSum()) << std::endl;
}

void TriangleC::Init(int a, int b, int c)
{
    setA(a);
    setB(b);
    setC(c);
}

void TriangleC::SetSides(int a, int b, int c)
{
    Init(a, b, c);
}

Triad TriangleC::GetSides()
{
    return Triad(getA(), getB(), getC());
}

void TriangleC::Read()
{
    int a, b, c;
    std::cout << "Enter Triad: ";
    std::cin >> a >> b >> c;
    Init(a, b, c);
}

TriangleC& TriangleC::operator=(const TriangleC& TriangleC)
{
    if (this != &TriangleC)
    {
        Triad::operator=(TriangleC);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& out, const TriangleC& TriangleC)
{
    out << "TriangleC with sides: " << TriangleC.toString(TriangleC.getA()) << ", " << TriangleC.toString(TriangleC.getB()) << ", " << TriangleC.toString(TriangleC.getC()) << std::endl;
    out << "Area: " << TriangleC.toString(TriangleC.calculateArea()) << std::endl;
    out << "Angles: " << TriangleC.toString(TriangleC.calculateAngleA()) << ", " << TriangleC.toString(TriangleC.calculateAngleB()) << ", " << TriangleC.toString(TriangleC.calculateAngleC()) << std::endl;
    out << "Sum of sides: " << TriangleC.toString(TriangleC.calculateSum()) << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, TriangleC& TriangleC)
{
    int a, b, c;
    in >> a >> b >> c;
    TriangleC.SetSides(a, b, c);
    return in;
}

TriangleC::operator std::string() const {
    return "TriangleC sides: " + std::to_string(getA()) + ", " +
        std::to_string(getB()) + ", " +
        std::to_string(getC());
}

TriangleC& TriangleC::operator++() {
    setA(getA() + 1);
    setB(getB() + 1);
    setC(getC() + 1);
    return *this;
}

TriangleC& TriangleC::operator--() {
    setA(getA() - 1);
    setB(getB() - 1);
    setC(getC() - 1);
    return *this;
}

TriangleC TriangleC::operator++(int) {
    TriangleC t(*this);
    setA(getA() + 1);
    setB(getB() + 1);
    setC(getC() + 1);
    return t;
}

TriangleC TriangleC::operator--(int) {
    TriangleC t(*this);
    setA(getA() - 1);
    setB(getB() - 1);
    setC(getC() - 1);
    return t;
}