#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <utility>
#include <climits>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <cassert>



#define red "\x1b[31m"
#define green "\x1b[32m"
#define reset "\x1b[0m"


static int total_tests = 0;
static int passed_tests = 0;

#define ASSERT_TRUE(cond) do { total_tests++; \
    if (cond) { \
        passed_tests++; \
        std::cout << green << "PASSED: " << #cond << reset; \
    } else { \
        std::cout << red << "FAILED: " << #cond << reset; \
    } \
    cout << "in file " << __FILE__ << " on line " << __LINE__ << "" << endl; \
} while(0)

#define ASSERT_EQUAL(expected, actual) do { total_tests++; \
    if ((expected) == (actual)) { \
        passed_tests++; \
        std::cout << green << "PASSED: " << #actual << " == " << #expected << reset; \
    } else { \
        std::cout << red << "FAILED: " << #actual << " == " << #expected << reset; \
    } \
    cout << "in file " << __FILE__ << " on line " << __LINE__ << "" << endl; \
} while(0)

#define TEST_REPORT() do { \
    std::cout << "\nTotal Tests: " << total_tests << std::endl; \
    std::cout << green << "Passed: " << passed_tests << reset << std::endl; \
    std::cout << red << "Failed: " << (total_tests - passed_tests) << reset << std::endl; \
    if ((total_tests - passed_tests) == 0) { \
        std::cout << green << "TESTS PASSED" << reset << std::endl; \
    } else { \
        std::cout << red << "TESTS FAILED" << reset << std::endl; \
    } \
} while(0)