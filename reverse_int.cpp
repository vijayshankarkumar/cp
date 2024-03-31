#include <iostream>

int reverse_int(int i) {
    int res = 0;
    while (i) {
        res = res * 10 + i % 10;
        i /= 10;
    }
    return res;
}

int main() {
    std::cout << reverse_int(-1234) << std::endl;
    return 0;
}