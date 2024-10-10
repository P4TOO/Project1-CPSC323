#include "Project1.h"

void outputChart(vector<string> data1, vector<string> data2) {
    // Output header
    std::cout << std::setw(10) << "#"
              << std::setw(15) << "Category"
              << std::setw(40) << "Tokens" << std::endl;

    // Output elements in tabular form
    for (size_t i = 0; i < data1.size(); ++i) {
        std::cout << std::setw(10) << i + 1
                  << std::setw(15) << data1[i]
                  << std::setw(40) << data2[i] << std::endl;
    }
}