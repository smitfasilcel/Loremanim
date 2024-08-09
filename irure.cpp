#include <iostream>
#include <vector>

int main() {
    // Example data
    int tmp = 10;
    std::vector<int> standardForCalc = {5, 12, 8, 11, 9};

    // Loop through each element in the vector
    for (size_t i = 0; i < standardForCalc.size(); ++i) {
        if (tmp > standardForCalc[i]) {
            std::cout << "tmp (" << tmp << ") is greater than standardForCalc[" << i << "] (" << standardForCalc[i] << ")" << std::endl;
        } else {
            std::cout << "tmp (" << tmp << ") is not greater than standardForCalc[" << i << "] (" << standardForCalc[i] << ")" << std::endl;
        }
    }

    return 0;
}
