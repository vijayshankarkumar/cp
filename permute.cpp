#include <iostream>
#include <string>

void permute(std::string str, int idx, int n) {
    if (idx == n) std::cout << str << std::endl;;
    for (int i = idx; i <= n; i++) { 
        std::swap(str[idx], str[i]); 
        permute(str, idx + 1, n); 
        std::swap(str[idx], str[i]); 
    } 
}

int main() {
    permute("123", 0, 2);
    return 0;
}