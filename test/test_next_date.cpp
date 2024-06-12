#include <gtest/gtest.h>
#include "next_date.hpp"

// Test cases for nextDate1 function
TEST(NextDateTest, BoundaryTests)
{
    struct TestCase
    {
        Date input;
        Date expected;
        bool expect_exception;
    };

    std::vector<TestCase> test_cases = {
        {{.day = 1, .month = 1, .year = 1812}, {.day = 2, .month = 1, .year = 1812}, false},
        {{.day = 1, .month = 1, .year = 1813}, {.day = 2, .month = 1, .year = 1813}, false},
        {{.day = 1, .month = 1, .year = 1912}, {.day = 2, .month = 1, .year = 1912}, false},
        {{.day = 1, .month = 1, .year = 2011}, {.day = 2, .month = 1, .year = 2011}, false},
        {{.day = 1, .month = 1, .year = 2012}, {.day = 2, .month = 1, .year = 2012}, false},
        {{.day = 2, .month = 1, .year = 1812}, {.day = 3, .month = 1, .year = 1812}, false},
        {{.day = 2, .month = 1, .year = 1813}, {.day = 3, .month = 1, .year = 1813}, false},
        {{.day = 2, .month = 1, .year = 1912}, {.day = 3, .month = 1, .year = 1912}, false},
        {{.day = 2, .month = 1, .year = 2011}, {.day = 3, .month = 1, .year = 2011}, false},
        {{.day = 2, .month = 1, .year = 2012}, {.day = 3, .month = 1, .year = 2012}, false},
        {{.day = 15, .month = 1, .year = 1812}, {.day = 16, .month = 1, .year = 1812}, false},
        {{.day = 15, .month = 1, .year = 1813}, {.day = 16, .month = 1, .year = 1813}, false},
        {{.day = 15, .month = 1, .year = 1912}, {.day = 16, .month = 1, .year = 1912}, false},
        {{.day = 15, .month = 1, .year = 2011}, {.day = 16, .month = 1, .year = 2011}, false},
        {{.day = 15, .month = 1, .year = 2012}, {.day = 16, .month = 1, .year = 2012}, false},
        {{.day = 30, .month = 1, .year = 1812}, {.day = 31, .month = 1, .year = 1812}, false},
        {{.day = 30, .month = 1, .year = 1813}, {.day = 31, .month = 1, .year = 1813}, false},
        {{.day = 30, .month = 1, .year = 1912}, {.day = 31, .month = 1, .year = 1912}, false},
        {{.day = 30, .month = 1, .year = 2011}, {.day = 31, .month = 1, .year = 2011}, false},
        {{.day = 30, .month = 1, .year = 2012}, {.day = 31, .month = 1, .year = 2012}, false},
        {{.day = 31, .month = 1, .year = 1812}, {.day = 1, .month = 2, .year = 1812}, false},
        {{.day = 31, .month = 1, .year = 1813}, {.day = 1, .month = 2, .year = 1813}, false},
        {{.day = 31, .month = 1, .year = 1912}, {.day = 1, .month = 2, .year = 1912}, false},
        {{.day = 31, .month = 1, .year = 2011}, {.day = 1, .month = 2, .year = 2011}, false},
        {{.day = 31, .month = 1, .year = 2012}, {.day = 1, .month = 2, .year = 2012}, false},
        {{.day = 1, .month = 2, .year = 1812}, {.day = 2, .month = 2, .year = 1812}, false},
        {{.day = 1, .month = 2, .year = 1813}, {.day = 2, .month = 2, .year = 1813}, false},
        {{.day = 1, .month = 2, .year = 1912}, {.day = 2, .month = 2, .year = 1912}, false},
        {{.day = 1, .month = 2, .year = 2011}, {.day = 2, .month = 2, .year = 2011}, false},
        {{.day = 1, .month = 2, .year = 2012}, {.day = 2, .month = 2, .year = 2012}, false},
        {{.day = 2, .month = 2, .year = 1812}, {.day = 3, .month = 2, .year = 1812}, false},
        {{.day = 2, .month = 2, .year = 1813}, {.day = 3, .month = 2, .year = 1813}, false},
        {{.day = 2, .month = 2, .year = 1912}, {.day = 3, .month = 2, .year = 1912}, false},
        {{.day = 2, .month = 2, .year = 2011}, {.day = 3, .month = 2, .year = 2011}, false},
        {{.day = 2, .month = 2, .year = 2012}, {.day = 3, .month = 2, .year = 2012}, false},
        {{.day = 15, .month = 2, .year = 1812}, {.day = 16, .month = 2, .year = 1812}, false},
        {{.day = 15, .month = 2, .year = 1813}, {.day = 16, .month = 2, .year = 1813}, false},
        {{.day = 15, .month = 2, .year = 1912}, {.day = 16, .month = 2, .year = 1912}, false},
        {{.day = 15, .month = 2, .year = 2011}, {.day = 16, .month = 2, .year = 2011}, false},
        {{.day = 15, .month = 2, .year = 2012}, {.day = 16, .month = 2, .year = 2012}, false},
        {{.day = 30, .month = 2, .year = 1812}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 30, .month = 2, .year = 1813}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 30, .month = 2, .year = 1912}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 30, .month = 2, .year = 2011}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 30, .month = 2, .year = 2012}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 2, .year = 1812}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 2, .year = 1813}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 2, .year = 1912}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 2, .year = 2011}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 2, .year = 2012}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 1, .month = 6, .year = 1812}, {.day = 2, .month = 6, .year = 1812}, false},
        {{.day = 1, .month = 6, .year = 1813}, {.day = 2, .month = 6, .year = 1813}, false},
        {{.day = 1, .month = 6, .year = 1912}, {.day = 2, .month = 6, .year = 1912}, false},
        {{.day = 1, .month = 6, .year = 2011}, {.day = 2, .month = 6, .year = 2011}, false},
        {{.day = 1, .month = 6, .year = 2012}, {.day = 2, .month = 6, .year = 2012}, false},
        {{.day = 2, .month = 6, .year = 1812}, {.day = 3, .month = 6, .year = 1812}, false},
        {{.day = 2, .month = 6, .year = 1813}, {.day = 3, .month = 6, .year = 1813}, false},
        {{.day = 2, .month = 6, .year = 1912}, {.day = 3, .month = 6, .year = 1912}, false},
        {{.day = 2, .month = 6, .year = 2011}, {.day = 3, .month = 6, .year = 2011}, false},
        {{.day = 2, .month = 6, .year = 2012}, {.day = 3, .month = 6, .year = 2012}, false},
        {{.day = 15, .month = 6, .year = 1812}, {.day = 16, .month = 6, .year = 1812}, false},
        {{.day = 15, .month = 6, .year = 1813}, {.day = 16, .month = 6, .year = 1813}, false},
        {{.day = 15, .month = 6, .year = 1912}, {.day = 16, .month = 6, .year = 1912}, false},
        {{.day = 15, .month = 6, .year = 2011}, {.day = 16, .month = 6, .year = 2011}, false},
        {{.day = 15, .month = 6, .year = 2012}, {.day = 16, .month = 6, .year = 2012}, false},
        {{.day = 30, .month = 6, .year = 1812}, {.day = 1, .month = 7, .year = 1812}, false},
        {{.day = 30, .month = 6, .year = 1813}, {.day = 1, .month = 7, .year = 1813}, false},
        {{.day = 30, .month = 6, .year = 1912}, {.day = 1, .month = 7, .year = 1912}, false},
        {{.day = 30, .month = 6, .year = 2011}, {.day = 1, .month = 7, .year = 2011}, false},
        {{.day = 30, .month = 6, .year = 2012}, {.day = 1, .month = 7, .year = 2012}, false},
        {{.day = 31, .month = 6, .year = 1812}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 6, .year = 1813}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 6, .year = 1912}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 6, .year = 2011}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 6, .year = 2012}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 1, .month = 11, .year = 1812}, {.day = 2, .month = 11, .year = 1812}, false},
        {{.day = 1, .month = 11, .year = 1813}, {.day = 2, .month = 11, .year = 1813}, false},
        {{.day = 1, .month = 11, .year = 1912}, {.day = 2, .month = 11, .year = 1912}, false},
        {{.day = 1, .month = 11, .year = 2011}, {.day = 2, .month = 11, .year = 2011}, false},
        {{.day = 1, .month = 11, .year = 2012}, {.day = 2, .month = 11, .year = 2012}, false},
        {{.day = 2, .month = 11, .year = 1812}, {.day = 3, .month = 11, .year = 1812}, false},
        {{.day = 2, .month = 11, .year = 1813}, {.day = 3, .month = 11, .year = 1813}, false},
        {{.day = 2, .month = 11, .year = 1912}, {.day = 3, .month = 11, .year = 1912}, false},
        {{.day = 2, .month = 11, .year = 2011}, {.day = 3, .month = 11, .year = 2011}, false},
        {{.day = 2, .month = 11, .year = 2012}, {.day = 3, .month = 11, .year = 2012}, false},
        {{.day = 15, .month = 11, .year = 1812}, {.day = 16, .month = 11, .year = 1812}, false},
        {{.day = 15, .month = 11, .year = 1813}, {.day = 16, .month = 11, .year = 1813}, false},
        {{.day = 15, .month = 11, .year = 1912}, {.day = 16, .month = 11, .year = 1912}, false},
        {{.day = 15, .month = 11, .year = 2011}, {.day = 16, .month = 11, .year = 2011}, false},
        {{.day = 15, .month = 11, .year = 2012}, {.day = 16, .month = 11, .year = 2012}, false},
        {{.day = 30, .month = 11, .year = 1812}, {.day = 1, .month = 12, .year = 1812}, false},
        {{.day = 30, .month = 11, .year = 1813}, {.day = 1, .month = 12, .year = 1813}, false},
        {{.day = 30, .month = 11, .year = 1912}, {.day = 1, .month = 12, .year = 1912}, false},
        {{.day = 30, .month = 11, .year = 2011}, {.day = 1, .month = 12, .year = 2011}, false},
        {{.day = 30, .month = 11, .year = 2012}, {.day = 1, .month = 12, .year = 2012}, false},
        {{.day = 31, .month = 11, .year = 1812}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 11, .year = 1813}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 11, .year = 1912}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 11, .year = 2011}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 31, .month = 11, .year = 2012}, {.day = 0, .month = 0, .year = 0}, true},
        {{.day = 1, .month = 12, .year = 1812}, {.day = 2, .month = 12, .year = 1812}, false},
        {{.day = 1, .month = 12, .year = 1813}, {.day = 2, .month = 12, .year = 1813}, false},
        {{.day = 1, .month = 12, .year = 1912}, {.day = 2, .month = 12, .year = 1912}, false},
        {{.day = 1, .month = 12, .year = 2011}, {.day = 2, .month = 12, .year = 2011}, false},
        {{.day = 1, .month = 12, .year = 2012}, {.day = 2, .month = 12, .year = 2012}, false},
        {{.day = 2, .month = 12, .year = 1812}, {.day = 3, .month = 12, .year = 1812}, false},
        {{.day = 2, .month = 12, .year = 1813}, {.day = 3, .month = 12, .year = 1813}, false},
        {{.day = 2, .month = 12, .year = 1912}, {.day = 3, .month = 12, .year = 1912}, false},
        {{.day = 2, .month = 12, .year = 2011}, {.day = 3, .month = 12, .year = 2011}, false},
        {{.day = 2, .month = 12, .year = 2012}, {.day = 3, .month = 12, .year = 2012}, false},
        {{.day = 15, .month = 12, .year = 1812}, {.day = 16, .month = 12, .year = 1812}, false},
        {{.day = 15, .month = 12, .year = 1813}, {.day = 16, .month = 12, .year = 1813}, false},
        {{.day = 15, .month = 12, .year = 1912}, {.day = 16, .month = 12, .year = 1912}, false},
        {{.day = 15, .month = 12, .year = 2011}, {.day = 16, .month = 12, .year = 2011}, false},
        {{.day = 15, .month = 12, .year = 2012}, {.day = 16, .month = 12, .year = 2012}, false},
        {{.day = 30, .month = 12, .year = 1812}, {.day = 31, .month = 12, .year = 1812}, false},
        {{.day = 30, .month = 12, .year = 1813}, {.day = 31, .month = 12, .year = 1813}, false},
        {{.day = 30, .month = 12, .year = 1912}, {.day = 31, .month = 12, .year = 1912}, false},
        {{.day = 30, .month = 12, .year = 2011}, {.day = 31, .month = 12, .year = 2011}, false},
        {{.day = 30, .month = 12, .year = 2012}, {.day = 31, .month = 12, .year = 2012}, false},
        {{.day = 31, .month = 12, .year = 1812}, {.day = 1, .month = 1, .year = 1813}, false},
        {{.day = 31, .month = 12, .year = 1813}, {.day = 1, .month = 1, .year = 1814}, false},
        {{.day = 31, .month = 12, .year = 1912}, {.day = 1, .month = 1, .year = 1913}, false},
        {{.day = 31, .month = 12, .year = 2011}, {.day = 1, .month = 1, .year = 2012}, false},
        {{.day = 31, .month = 12, .year = 2012}, {.day = 1, .month = 1, .year = 2013}, false}};

    for (const auto &test_case : test_cases)
    {
        if (test_case.expect_exception)
        {
            EXPECT_THROW(nextDate1(test_case.input), std::out_of_range);
        }
        else
        {
            Date result = nextDate1(test_case.input);
            EXPECT_EQ(result.day, test_case.expected.day);
            EXPECT_EQ(result.month, test_case.expected.month);
            EXPECT_EQ(result.year, test_case.expected.year);
        }
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}