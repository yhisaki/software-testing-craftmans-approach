#include <gtest/gtest.h>
#include "triangle.hpp"

TEST(TriangleTest, NormalBoundaryValueTestCases)
{
    // Case 1
    EXPECT_EQ(classifyTriangle(100, 100, 1), TriangleType::Isosceles);

    // Case 2
    EXPECT_EQ(classifyTriangle(100, 100, 2), TriangleType::Isosceles);

    // Case 3
    EXPECT_EQ(classifyTriangle(100, 100, 100), TriangleType::Equilateral);

    // Case 4
    EXPECT_EQ(classifyTriangle(100, 100, 199), TriangleType::Isosceles);

    // Case 5
    EXPECT_EQ(classifyTriangle(100, 100, 200), TriangleType::NotATriangle);

    // Case 6
    EXPECT_EQ(classifyTriangle(100, 1, 100), TriangleType::Isosceles);

    // Case 7
    EXPECT_EQ(classifyTriangle(100, 2, 100), TriangleType::Isosceles);

    // Case 8
    EXPECT_EQ(classifyTriangle(100, 100, 100), TriangleType::Equilateral);

    // Case 9
    EXPECT_EQ(classifyTriangle(100, 199, 100), TriangleType::Isosceles);

    // Case 10
    EXPECT_EQ(classifyTriangle(100, 200, 100), TriangleType::NotATriangle);

    // Case 11
    EXPECT_EQ(classifyTriangle(1, 100, 100), TriangleType::Isosceles);

    // Case 12
    EXPECT_EQ(classifyTriangle(2, 100, 100), TriangleType::Isosceles);

    // Case 13
    EXPECT_EQ(classifyTriangle(100, 100, 100), TriangleType::Equilateral);

    // Case 14
    EXPECT_EQ(classifyTriangle(199, 100, 100), TriangleType::Isosceles);

    // Case 15
    EXPECT_EQ(classifyTriangle(200, 100, 100), TriangleType::NotATriangle);
}

TEST(TriangleTest, WorstCaseBoundaryValueTestCases)
{
    // Case 1
    EXPECT_EQ(classifyTriangle(1, 1, 1), TriangleType::Equilateral);

    // Case 2
    EXPECT_EQ(classifyTriangle(1, 1, 2), TriangleType::NotATriangle);

    // Case 3
    EXPECT_EQ(classifyTriangle(1, 1, 100), TriangleType::NotATriangle);

    // Case 4
    EXPECT_EQ(classifyTriangle(1, 1, 199), TriangleType::NotATriangle);

    // Case 5
    EXPECT_EQ(classifyTriangle(1, 1, 200), TriangleType::NotATriangle);

    // Case 6
    EXPECT_EQ(classifyTriangle(1, 2, 1), TriangleType::NotATriangle);

    // Case 7
    EXPECT_EQ(classifyTriangle(1, 2, 2), TriangleType::Isosceles);

    // Case 8
    EXPECT_EQ(classifyTriangle(1, 2, 100), TriangleType::NotATriangle);

    // Case 9
    EXPECT_EQ(classifyTriangle(1, 2, 199), TriangleType::NotATriangle);

    // Case 10
    EXPECT_EQ(classifyTriangle(1, 2, 200), TriangleType::NotATriangle);

    // Case 11
    EXPECT_EQ(classifyTriangle(1, 100, 1), TriangleType::NotATriangle);

    // Case 12
    EXPECT_EQ(classifyTriangle(1, 100, 2), TriangleType::NotATriangle);

    // Case 13
    EXPECT_EQ(classifyTriangle(1, 100, 100), TriangleType::Isosceles);

    // Case 14
    EXPECT_EQ(classifyTriangle(1, 100, 199), TriangleType::NotATriangle);

    // Case 15
    EXPECT_EQ(classifyTriangle(1, 100, 200), TriangleType::NotATriangle);

    // Case 16
    EXPECT_EQ(classifyTriangle(1, 199, 1), TriangleType::NotATriangle);

    // Case 17
    EXPECT_EQ(classifyTriangle(1, 199, 2), TriangleType::NotATriangle);

    // Case 18
    EXPECT_EQ(classifyTriangle(1, 199, 100), TriangleType::NotATriangle);

    // Case 19
    EXPECT_EQ(classifyTriangle(1, 199, 199), TriangleType::Isosceles);

    // Case 20
    EXPECT_EQ(classifyTriangle(1, 199, 200), TriangleType::NotATriangle);

    // Case 21
    EXPECT_EQ(classifyTriangle(1, 200, 1), TriangleType::NotATriangle);

    // Case 22
    EXPECT_EQ(classifyTriangle(1, 200, 2), TriangleType::NotATriangle);

    // Case 23
    EXPECT_EQ(classifyTriangle(1, 200, 100), TriangleType::NotATriangle);

    // Case 24
    EXPECT_EQ(classifyTriangle(1, 200, 199), TriangleType::NotATriangle);

    // Case 25
    EXPECT_EQ(classifyTriangle(1, 200, 200), TriangleType::Isosceles);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}