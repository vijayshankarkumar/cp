#include <iostream>
#include <string>
#include <unordered_set>

int longestSubstringWithNoReapeatChar(std::string str) {
    std::unordered_set<char> st;
    int i = 0, j = 0, ans = 1;
    while (j < str.size()) {
        if (!st.count(str[j])) {
            st.insert(str[j]);
            ans = std::max(ans, j - i + 1);
        }
        else {
            while (str[i] != str[j]) i++;
            i++;
            ans = std::max(ans, j - i + 1);
        }
        j++;
    }
    return ans;
}

int main() {
    std::cout << longestSubstringWithNoReapeatChar("pwwkew") << std::endl;
    return 0;
}