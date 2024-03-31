#include <iostream>

long long binPow(long long x, int n) {
    long long res = 1;
    while (n) {
        if (n&1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

int main() {
    std::cout << binPow(3, 5) << std::endl;
    return 0;
}