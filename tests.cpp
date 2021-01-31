#include <iostream>
#include <string>
#include <gtest/gtest.h>

#include "Nodes/driver.h"

extern std::stringstream ostr;

TEST(N1, 1) {

    std::ifstream istr("tests/test1.txt");

    if (!istr.is_open()) {
        std::cerr << "Cant open file!" << std::endl;
        exit(0);
    }

    yy::Driver driver { istr};
    driver.parse ();
    driver.Calculate();

    std::string ans;
    ostr>>ans;

    EXPECT_EQ(ans, "4");

    istr.close();
}

TEST(N1, 2) {

    std::ifstream istr("tests/test2.txt");

    if (!istr.is_open()) {
        std::cerr << "Cant open file!" << std::endl;
        exit(0);
    }

    yy::Driver driver { istr};
    driver.parse ();
    driver.Calculate();

    std::string ans;
    ostr>>ans;

    EXPECT_EQ(ans,  "10");

    istr.close();
}

TEST(N1, 3) {

    std::ifstream istr("tests/test3.txt");

    if (!istr.is_open()) {
        std::cerr << "Cant open file!" << std::endl;
        exit(0);
    }

    yy::Driver driver { istr};
    driver.parse ();
    driver.Calculate();

    std::string ans;
    ostr>>ans;

    EXPECT_EQ(ans,  "50");

    istr.close();
}

TEST(N1, 4) {

    std::ifstream istr("tests/test4.txt");

    if (!istr.is_open()) {
        std::cerr << "Cant open file!" << std::endl;
        exit(0);
    }

    yy::Driver driver { istr};
    driver.parse ();
    driver.Calculate();

    std::string ans;
    ostr>>ans;

    EXPECT_EQ(ans,  "12");

    istr.close();
}