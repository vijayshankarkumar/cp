#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

int invalidParenthesis(const std::string& str) {
    int ans = 0, open = 0, close = 0;
    for (auto& c : str) {
        if (c == '(') open++;
        if (c == ')') close++;
        if (open < close) ans = std::max(ans, close - open);
    }
    if (open > close) ans = std::max(ans, open - close);
    return ans;
}

void removeInvalidParenthesisUtil(std::string str, int remainToRemove, std::unordered_set<std::string>& ans) {
    if (remainToRemove == 0) {
        if (invalidParenthesis(str) == 0) ans.insert(str);
        return;
    }
    for (int i = 0; i < str.size(); i++) {
        auto tmp = str;
        tmp.erase(i, 1);
        removeInvalidParenthesisUtil(tmp, remainToRemove - 1, ans);
    }
}

std::unordered_set<std::string> removeInvalidParenthesis(const std::string& str) {
    std::unordered_set<std::string> ans;
    int remainToRemove = invalidParenthesis(str);
    removeInvalidParenthesisUtil(str, remainToRemove, ans);
    return ans;
}

int main() {
    const auto& ans = removeInvalidParenthesis(std::string(")("));
    for (auto& it : ans) std::cout << it << std::endl;
    return 0;
}
