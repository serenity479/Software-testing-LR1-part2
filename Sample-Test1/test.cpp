#include "pch.h"
#include <iostream>
#include <vector>

std::vector<double> result;



std::vector<double> arraySumModifier(std::vector<double>& arr) {

    if (arr.empty()) {
        throw std::invalid_argument("Error: empty array");
    }

    int n = arr.size();
    std::vector<double> sums;

    // Calculate the sums of pairs of elements
    for (int i = 0; i < n / 2; ++i) {
        sums.push_back(arr[i] + arr[n - 1 - i]);
    }

    // Multiply the central element by 2 if the array is odd and add it to the sum array
    if (n % 2 != 0) {
        int centralIndex = n / 2;
        arr[centralIndex] *= 2;
        sums.push_back(arr[centralIndex]);
    }

    return sums;
}



double arrayMaxFinder(std::vector<double>& sums) {

    // Finding the maximum among sums
    double maxSum = std::numeric_limits<double>::lowest();
    for (double sum : sums) {
        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}





TEST(ArraySumModifierTests, BasicTest) {
    std::vector<double> arr = { 1, 2, 4, 7, 5, 12, 27, 1, 8, 9, 14 };
    std::vector<double> expected = { 15, 11, 12, 8, 32, 24 };
    std::vector<double> actual;
    actual = arraySumModifier(arr);
    EXPECT_EQ(actual, expected);
  EXPECT_TRUE(true);
}

TEST(ArraySumModifierTests, SingleElementTest) {
    std::vector<double> arr = { 1 };
    std::vector<double> expected = { 2 };
    std::vector<double> actual;
    actual = arraySumModifier(arr);
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(true);
}

TEST(ArraySumModifierTests, EmptyArrayTest) {
    std::vector<double> arr = { };
    std::string expected = "Error: empty array";
    std::string actual;
    try {
        arraySumModifier(arr);
    }
    catch (const std::invalid_argument& e) {
        actual = e.what();
    }
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(true);
}

TEST(ArraySumModifierTests, MultipleNumbersFitTest) {
    std::vector<double> arr = { 1, 2, 4, 2, 1, 2, 1, 3, 4 };
    std::vector<double> expected = { 5, 5, 5, 4, 2 };
    std::vector<double> actual;
    actual = arraySumModifier(arr);
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(true);
}

TEST(ArraySumModifierTests, NegativeNumbersTest) {
    std::vector<double> arr = { -4, -5, -12, -7, -11, -21, -4, -10, -17 };
    std::vector<double> expected = { -21, -15, -16, -28, -22 };
    std::vector<double> actual;
    actual = arraySumModifier(arr);
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(true);
}


TEST(ArraySumModifierTests, LargeArrayTest) {
    std::vector<double> arr = { 12, 25, 8, 17, 4, 6, 7, 8, 9, 28, 42, -7, 62, 11, 47, -7, 24, 5, 0, 45 };
    std::vector<double> expected = { 57, 25, 13, 41, -3, 53, 18, 70, 2, 70 };
    std::vector<double> actual;
    actual = arraySumModifier(arr);
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(true);
}







TEST(ArrayMaxFinderTests, BasicTest) {
    std::vector<double> arr = { 1, 2, 4, 7, 5, 12, 27, 1, 8, 9, 14 };
    std::vector<double> afterModifier;
    double expected = 32;
    double actual;
    afterModifier = arraySumModifier(arr);
    actual = arrayMaxFinder(afterModifier);
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(true);
}


TEST(ArrayMaxFinderTests, SingleElementTest) {
    std::vector<double> arr = {1};
    std::vector<double> afterModifier;
    double expected = 2;
    double actual;
    afterModifier = arraySumModifier(arr);
    actual = arrayMaxFinder(afterModifier);
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(true);
}


TEST(ArrayMaxFinderTests, EmptyArrayTest) {
    std::vector<double> arr = {};
    std::string expected = "Error: empty array";
    std::string actual;
    std::vector<double> afterModifier;
    try {
        afterModifier = arraySumModifier(arr);
        actual = arrayMaxFinder(afterModifier);
    }
    catch (const std::invalid_argument& e) {
        actual = e.what();
    }
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(true);
}


TEST(ArrayMaxFinderTests, MultipleNumbersFitTest) {
    std::vector<double> arr = { 1, 2, 4, 2, 1, 2, 1, 3, 4 };
    std::vector<double> afterModifier;
    double expected = 5;
    double actual;
    afterModifier = arraySumModifier(arr);
    actual = arrayMaxFinder(afterModifier);
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(true);
}


TEST(ArrayMaxFinderTests, NegativeNumbersFitTest) {
    std::vector<double> arr = { -4, -5, -12, -7, -11, -21, -4, -10, -17 };
    std::vector<double> afterModifier;
    double expected = -15;
    double actual;
    afterModifier = arraySumModifier(arr);
    actual = arrayMaxFinder(afterModifier);
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(true);
}


TEST(ArrayMaxFinderTests, LargeArrayTest) {
    std::vector<double> arr = { 12, 25, 8, 17, 4, 6, 7, 8, 9, 28, 42, -7, 62, 11, 47, -7, 24, 5, 0, 45 };
    std::vector<double> afterModifier;
    double expected = 70;
    double actual;
    afterModifier = arraySumModifier(arr);
    actual = arrayMaxFinder(afterModifier);
    EXPECT_EQ(actual, expected);
    EXPECT_TRUE(true);
}
