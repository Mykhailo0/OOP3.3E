// triangle.h
#include "triad.h"
#include "Object.h"
#include <string>


class Triangle : public Triad
{

public:
    Triangle();
    Triangle(int sideA, int sideB, int sideC);
    Triangle(const Triad& triad);

    double calculateAngleA() const;
    double calculateAngleB() const;
    double calculateAngleC() const;
    double calculateArea() const;

    std::string toString(double a) const;

    Triangle& operator = (const Triangle& triangle);
    friend std::ostream& operator << (std::ostream& out, const Triangle& triangle);
    friend std::istream& operator >> (std::istream& in, Triangle& triangle);

    Triangle& operator++ ();
    Triangle& operator-- ();
    Triangle operator++ (int);
    Triangle operator-- (int);


    operator std::string() const;

    void Read();
    void Display() const;
    void Init(int a, int b, int c);
    void SetSides(int a, int b, int c);
    Triad GetSides();


};
