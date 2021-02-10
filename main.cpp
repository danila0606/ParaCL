#include "Nodes/driver.h"

#include <gtest/gtest.h>

int main(int argc, char* argv[]) {

#ifdef GTESTS
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif

try {

    std::ifstream in{"../text.txt"};
    if (!in.is_open()) {
        std::cerr << "Cant open file!" << std::endl;
        exit(0);
    }

    yy::Driver driver{in};
    driver.parse();
    driver.Calculate();

} catch (std::exception& e) {
    std::cerr<< e.what()<<std::endl;
    exit(0);
}

    return 0;
}