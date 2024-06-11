#include <iostream>

#include "triangle.hpp"

TriangleType classifyTriangle(int a, int b, int c)
{
    int match = 0;
    if (a == b)
        match += 1;
    if (a == c)
        match += 2;
    if (b == c)
        match += 3;

    if (match == 0)
    {
        if ((a + b) <= c || (b + c) <= a || (a + c) <= b)
        {
            return TriangleType::NotATriangle;
        }
        else
        {
            return TriangleType::Scalene;
        }
    }
    else if (match == 1)
    {
        if ((a + b) <= c)
        {
            return TriangleType::NotATriangle;
        }
        else
        {
            return TriangleType::Isosceles;
        }
    }
    else if (match == 2)
    {
        if ((a + c) <= b)
        {
            return TriangleType::NotATriangle;
        }
        else
        {
            return TriangleType::Isosceles;
        }
    }
    else if (match == 3)
    {
        if ((b + c) <= a)
        {
            return TriangleType::NotATriangle;
        }
        else
        {
            return TriangleType::Isosceles;
        }
    }
    return TriangleType::Equilateral;
}