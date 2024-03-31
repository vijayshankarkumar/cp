#include <iostream>
#include <vector>

void moveZeros(std::vector<int>& arr) {
    int p_zero= 0;
    for(int i= 0; i< arr.size(); i++){
        if(arr[i] != 0) std::swap(arr[p_zero++], arr[i]);
    }
}

int main() {
    static const int a[] = { 1, 2, 0, 3, 0, 0, 4, 0, 5 };
    std::vector<int> arr (a, a + sizeof(a) / sizeof(a[0]));
    moveZeros(arr);
    for (auto& it : arr) std::cout << it << ", ";
    return 0;
}
