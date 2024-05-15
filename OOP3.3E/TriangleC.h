// TriangleC.h
#include "triad.h"
#include "Object.h"
#include <string>


class TriangleC : private Triad, public Object
{

public:
    TriangleC();
    TriangleC(int sideA, int sideB, int sideC);
    TriangleC(const Triad& triad);

    double calculateAngleA() const;
    double calculateAngleB() const;
    double calculateAngleC() const;
    double calculateArea() const;

    std::string toString(double a) const;

    TriangleC& operator = (const TriangleC& TriangleC);
    friend std::ostream& operator << (std::ostream& out, const TriangleC& TriangleC);
    friend std::istream& operator >> (std::istream& in, TriangleC& TriangleC);

    TriangleC& operator++ ();
    TriangleC& operator-- ();
    TriangleC operator++ (int);
    TriangleC operator-- (int);


    operator std::string() const;

    void Read();
    void Display() const;
    void Init(int a, int b, int c);
    void SetSides(int a, int b, int c);
    Triad GetSides();


};

