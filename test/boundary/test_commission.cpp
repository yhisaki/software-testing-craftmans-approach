#include <gtest/gtest.h>
#include "commission.hpp"
TEST(CommissionTest, TestCases)
{
    EXPECT_DOUBLE_EQ(calculateCommission(1, 1, 1), 10.0);      // Case 1
    EXPECT_DOUBLE_EQ(calculateCommission(1, 1, 2), 12.5);      // Case 2
    EXPECT_DOUBLE_EQ(calculateCommission(1, 2, 1), 13.0);      // Case 3
    EXPECT_DOUBLE_EQ(calculateCommission(2, 1, 1), 14.5);      // Case 4
    EXPECT_DOUBLE_EQ(calculateCommission(5, 5, 5), 50.0);      // Case 5
    EXPECT_DOUBLE_EQ(calculateCommission(10, 10, 9), 97.5);    // Case 6
    EXPECT_DOUBLE_EQ(calculateCommission(10, 9, 10), 97.0);    // Case 7
    EXPECT_DOUBLE_EQ(calculateCommission(9, 10, 10), 95.5);    // Case 8
    EXPECT_DOUBLE_EQ(calculateCommission(10, 10, 10), 100.0);  // Case 9
    EXPECT_DOUBLE_EQ(calculateCommission(10, 10, 11), 103.75); // Case 10
    EXPECT_DOUBLE_EQ(calculateCommission(10, 11, 10), 104.5);  // Case 11
    EXPECT_DOUBLE_EQ(calculateCommission(11, 10, 10), 106.75); // Case 12
    EXPECT_DOUBLE_EQ(calculateCommission(14, 14, 14), 160.0);  // Case 13
    EXPECT_DOUBLE_EQ(calculateCommission(18, 18, 17), 216.25); // Case 14
    EXPECT_DOUBLE_EQ(calculateCommission(18, 17, 18), 215.5);  // Case 15
    EXPECT_DOUBLE_EQ(calculateCommission(17, 18, 18), 213.25); // Case 16
    EXPECT_DOUBLE_EQ(calculateCommission(18, 18, 18), 220.0);  // Case 17
    EXPECT_DOUBLE_EQ(calculateCommission(18, 18, 19), 225.0);  // Case 18
    EXPECT_DOUBLE_EQ(calculateCommission(18, 19, 18), 226.0);  // Case 19
    EXPECT_DOUBLE_EQ(calculateCommission(19, 18, 18), 229.0);  // Case 20
    EXPECT_DOUBLE_EQ(calculateCommission(48, 48, 48), 820.0);  // Case 21
    EXPECT_DOUBLE_EQ(calculateCommission(70, 80, 89), 1415.0); // Case 22
    EXPECT_DOUBLE_EQ(calculateCommission(70, 79, 90), 1414.0); // Case 23
    EXPECT_DOUBLE_EQ(calculateCommission(69, 80, 90), 1411.0); // Case 24
    EXPECT_DOUBLE_EQ(calculateCommission(70, 80, 90), 1420.0); // Case 25
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}