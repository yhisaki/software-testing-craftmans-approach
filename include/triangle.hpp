#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

enum class TriangleType
{
    NotATriangle,
    Scalene,
    Isosceles,
    Equilateral
};

TriangleType classifyTriangle(int a, int b, int c);

#endif // TRIANGLE_HPP_