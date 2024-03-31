#include <iostream>
#include <vector>

bool util(const std::vector<int>& arr, int idx, int sumA, int sumB) {
    if (idx == arr.size()) {
        return sumA == sumB;
    }
    return util(arr, idx + 1, sumA + arr[idx], sumB) || util(arr, idx + 1, sumA, sumB + arr[idx]);
}

bool isEqualSet(const std::vector<int>& arr) {
    return util(arr, 0, 0, 0);
}

int main() {
    std::vector<int> arr = {1, 2, 3, 5};
    std::cout << isEqualSet(arr) << std::endl;
    return 0;
}