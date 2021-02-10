#include <iostream>
#include <string>
#include <gtest/gtest.h>

#include "Nodes/driver.h"

extern std::stringstream ostr;

std::string MyTest(const std::string& file_name) {

    std::ifstream istr(file_name);

    if (!istr.is_open()) {
        std::cerr << "Cant open file!" << std::endl;
        exit(0);
    }

    yy::Driver driver { istr};
    driver.parse ();
    driver.Calculate();

    std::string ans;
    ostr>>ans;

    istr.close();

    return ans;
}

TEST(N1, 1) {

    EXPECT_EQ(MyTest("tests/test1.txt"), "4");
}

TEST(N1, 2) {

    EXPECT_EQ(MyTest("tests/test2.txt"), "10");
}

TEST(N1, 3) {

    EXPECT_EQ(MyTest("tests/test3.txt"), "50");
}

TEST(N1, 4) {

    EXPECT_EQ(MyTest("tests/test4.txt"), "12");
}

TEST(FUNC, 1) {


    EXPECT_EQ(MyTest("tests/func_test1.txt"),  "210");

}


TEST(FUNC, 2) {

    EXPECT_EQ(MyTest("tests/func_test2.txt"),  "115");

}

TEST(RETURN, 3) {

    EXPECT_EQ(MyTest("tests/func_test3.txt"),  "15");

}

TEST(RETURN, 4) {

    EXPECT_EQ(MyTest("tests/func_test4.txt"),  "15");

}


/*

PAR :
VARIABLE {  int x;
if (!CurScope->GetValue ($1, x))
driver->EmergencyExit(@1, yy::Errors::non_existent_variable);

// NA MOMENT KOMPILYASII ONI EHSHE PO NULYAM!!!!!!!!

if (CurScope->GetParent() == nullptr)
std::cout<<"OMG";

$$ = x; std::cout<<$1<<x<<" "<<$$<<std::endl; }
|    VALUE {    $$ = $1;}
;
*/
